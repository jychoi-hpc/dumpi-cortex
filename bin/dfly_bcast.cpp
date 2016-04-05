#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <algorithm>
#include <mpi.h>
#include "stdint.h"
#include "stdlib.h"
#include "codes/dragonfly-cortex-api.h"
#include "codes/codes.h"
#include "codes/configuration.h"

struct placement_info {

	rank_t		rank;
	terminal_id_t	terminal;
	router_id_t	router;
	group_id_t 	group;

	bool operator==(const placement_info& other) const {
		return (rank == other.rank) && (terminal == other.terminal)
		       && (router == other.router) && (group == other.group);
	}
};

typedef std::vector<rank_t> rank_vector_t;
typedef std::map<router_id_t, rank_vector_t> router_map_t;
typedef std::map<group_id_t, router_map_t> group_map_t;
typedef std::pair<rank_t, rank_t> couple_t;

static int print_topo(group_map_t& topo) {
	group_map_t::iterator g = topo.begin();
	for(; g != topo.end(); g++) {
		std::cout << "Group " << g->first << ":" << std::endl;
		router_map_t::iterator r = g->second.begin();
		for(; r != g->second.end(); r++) {
			std::cout << "   Router " << r->first << ":";
			rank_vector_t::iterator t = r->second.begin();
			for(; t != r->second.end(); t++) {
				std::cout << " " << *t;
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
	return 0;
}

#define CN_BW 1.0// (10.0/5.25)
#define LOCAL_BW 1.0 //(10.0/5.25)
#define GLOBAL_BW 1.0 //(10.0/4.7)

static double cost(job_id_t jid, rank_t rank1, rank_t rank2) {
	terminal_id_t t1, t2;
	router_id_t r1, r2;
	group_id_t g1, g2;

	cortex_dfly_job_get_terminal_from_rank(jid, rank1, &t1);
	cortex_dfly_job_get_terminal_from_rank(jid, rank2, &t2);
	cortex_dfly_get_router_from_terminal(t1,&r1);
	cortex_dfly_get_router_from_terminal(t2,&r2);
	cortex_dfly_get_group_from_router(r1,&g1);
	cortex_dfly_get_group_from_router(r2,&g2);

	if(t1 == t2) return 0.0; // same terminal
	if(r1 == r2) return 2*CN_BW; // same router
	if(g1 == g2) return 2*CN_BW+LOCAL_BW; // same group
	double b = 2*CN_BW + GLOBAL_BW;
	
	router_id_t r3, r4;
	cortex_dfly_get_group_link_list(g1, g2, &r3, &r4);
	if(r3 != r1) b += LOCAL_BW;
	if(r4 != r2) b += LOCAL_BW;
	return b;
}

/**
 * This function prints the steps of a tree-based broadcast across the processes of
 * the ranks array. The root of the broadcast is ranks[0].
 * input ranks : array of ranks participating in the broadcast.
 */
static int dfly_bcast_tree(job_id_t jid, const std::vector<rank_t>& ranks) {
	for(int i=0; i<ranks.size(); i++) {
		int mask = 0x1;
		while(mask < ranks.size()) {
			if(i & mask) break;
			mask = mask << 1;
		}
		mask = mask >> 1;
		while(mask > 0) {
			if(i + mask < ranks.size()) {
				std::cout << "SEND " << ranks[i] << " ==> " << ranks[i+mask] << 
					" cost = " << cost(jid,ranks[i],ranks[i+mask]) << std::endl;
			}
			mask = mask >> 1;
		}
	}
	return 0;
}

/** 
 * This function builds the topology structure. 
 * input job_id : the job id
 * input ranks : the list of ranks involved
 * output topo : the topology
 * The topology is a map associating group_ids involved in the job with router_maps.
 * A router_map is a map associating router_ids involved in the job with a vector of ranks handled by this router.
 */
static int dfly_build_topology(group_map_t& topo, job_id_t job_id, const std::vector<rank_t>& ranks) {
	
	topo.clear();
	for(int i=0; i<ranks.size(); i++) {
		terminal_id_t t;
		router_id_t   r;
		group_id_t    g;
		cortex_dfly_job_get_terminal_from_rank(job_id, ranks[i], &t);
		cortex_dfly_get_router_from_terminal(t,&r);
		cortex_dfly_get_group_from_router(r,&g);
//		std::cout << "pushing rank " << ranks[i] << " in group " << g << " router " << r << " terminal " << t << std::endl;
		topo[g][r].push_back(ranks[i]);
	}

	return 0;
}

/** 
 * This function builds a team for group g based on the given topology.
 * output team : vector of ranks belonging to the group and composing the team
 * input topo : topology structure
 * input job_id : id of the job
 * input root : placement information for the root process
 * input g : group for which to build a team
 * The root rank is necessarily a team member if the group contains it.
 */
static int dfly_build_team(std::vector<rank_t>& team, 
			   group_map_t& topo, job_id_t job_id, 
			   const placement_info& root, group_id_t g) {

	// clear the team
	team.clear();
	// the considered group must have some processes of the job in it
	if(topo.count(g) == 0) return 0;

	// get the routers in this group that have processes of this job
	const router_map_t &rmap = topo[g];

	// for all routers ...
	router_map_t::const_iterator r = rmap.begin();
	for(; r != rmap.end(); r++) {
		// if router's id is the root router, insert the root rank of the bcast
		if(r->first == root.router) {
			team.insert(team.begin(),root.rank);
		} else {
			team.push_back(r->second[0]);
		}
	}
	return 0;
}

/**
 * This function builds the set of couples. A couple is a pair of
 * ranks such that the first element is in the root group and the second element
 * is in the remote group.
 * output couples : array of couples built
 * input topo : topology structure
 * input job_id : id of the job
 * input root : placement of the root process.
 */
static int dfly_build_couples(std::vector<couple_t>& couples,
		group_map_t& topo, job_id_t job_id,
		const placement_info& root) {
	// build the team ranks used in the root group
	std::vector<rank_t> root_team_ranks_vec;
	dfly_build_team(root_team_ranks_vec, topo, job_id, root, root.group);
	// convert it into a set
	std::set<rank_t> root_team_ranks_set(root_team_ranks_vec.begin(), root_team_ranks_vec.end());

	// divide groups into different levels depending on whether they can be reached directly
	// from the root group or not
	std::set<group_id_t> distant_groups;
	// iterator over all non-root groups
	for(group_map_t::const_iterator g = topo.begin(); g != topo.end(); g++) {
		if(g->first == root.group) continue; // root group, do nothing

		// get a router r1 in g1 and r2 in root group that are connected		
		group_id_t g1 = g->first;
		router_id_t r1, r2;
		cortex_dfly_get_group_link_list(g1, root.group, &r1, &r2);

		// check if r2 is used by the job
		if(topo[root.group].count(r2) == 0) { // r2 is not used, the group g1 is distant
			// and will be handled later
			distant_groups.insert(g1);
			continue;
		}
		// here we know that r2 is used by the job, we take the first terminal of the job
		// that belongs to r2 for the pair,
		// unless the router contains the root rank in which case we choose it
		couple_t couple;
		couple.first = (r2 == root.router) ? root.rank : topo[root.group][r2][0];

		if(topo[g1].count(r1)) { // r1 in g1 is used by the job
			// take the first rank in g1 that belongs to the job
			couple.second = topo[g1][r1][0];
		} else { // r1 is not used by the job, we take the first rank in the first router used
			// in g1 instead
			couple.second = topo[g1].begin()->second[0]; // take the first router instead
		}
		// insert in couples
		couples.push_back(couple);
		// remove the rank used in root group from the root_team_ranks_set
		// so that it won't be used for distant groups unless it's really necessary
		root_team_ranks_set.erase(couple.first);
	}
	
	// for all distant groups, build a pair
	int i = 0; // index to do a round-robin in root_team_ranks_vec
		   // after we have emptied root_ream_ranks_set
	for(std::set<group_id_t>::iterator g = distant_groups.begin(); g != distant_groups.end(); g++) {
		group_id_t g1 = *g; // get the distant group's id
		router_id_t r1, r2; // find the routers that connect it to the root group
		cortex_dfly_get_group_link_list(g1, root.group, &r1, &r2);
		
		rank_t rkr, rk1;

		if(root_team_ranks_set.size() != 0) {
			rkr = *(root_team_ranks_set.begin());
			root_team_ranks_set.erase(rkr);
		} else {
			rkr = root_team_ranks_vec[i];
			i += 1;
			i %= root_team_ranks_vec.size();
		}
		
		if(topo[g1].count(r1)) { // r1 is in g1 
			rk1 = topo[g1][r1][0];
		} else {
			rk1 = topo[g1].begin()->second[0]; // take the first router instead
		}
		// insert in couples
		couples.push_back(couple_t(rkr,rk1));
	}

	return 0;
}

extern "C" int dfly_broadcast_rgt(job_id_t job_id, rank_t* ranks, size_t num_ranks, rank_t my_rank) {
	rank_t root_rank = ranks[0];
	// get the placement of the root process
	placement_info 	root;
	terminal_id_t 	root_terminal;
	router_id_t 	root_router;
	group_id_t 	root_group;
	cortex_dfly_job_get_terminal_from_rank(job_id,root_rank,&root_terminal);
	cortex_dfly_get_router_from_terminal(root_terminal,&root_router);
	cortex_dfly_get_group_from_router(root_router,&root_group);
	root.rank 	= root_rank;
	root.terminal 	= root_terminal;
	root.router 	= root_router;
	root.group 	= root_group;

	// build the topology
	group_map_t topo;
	std::vector<rank_t> ranks_vec(ranks,ranks+num_ranks);
	dfly_build_topology(topo, job_id, ranks_vec);

	//print_topo(topo);
	// teams
	std::map<group_id_t, std::vector<rank_t> > teams;

	// get the groups involved and build the teams
	std::vector<group_id_t> groups(topo.size());
	group_map_t::iterator g = topo.begin();
	int i = 0;
	for(; g != topo.end(); g++, i++) {
		group_id_t g1 = g->first;
		groups[i] = g1;
		// build the team for group g1
		dfly_build_team(teams[g1], topo, job_id, root, g1);
	}

	// build couples
	std::vector<couple_t> couples;
	dfly_build_couples(couples,topo,job_id,root);

	// do a broadcast in the team of the root group
	std::cout << "Phase 1: broadcast in the team of the root group" << std::endl;
	std::vector<rank_t>& root_team = teams[root.group];
	// make sure to put the 
	dfly_bcast_tree(job_id, root_team);

	// send in couples
	std::cout << "Phase 2: broadcast across couples" << std::endl;
	for(i=0; i<couples.size(); i++) {
		couple_t& c = couples[i];
		std::cout << "SEND " << c.first << " ==> " << c.second 
			<< " cost = " << cost(job_id, c.first, c.second) << std::endl;
	}

	// do a broadcast in the non-root teams
	// first we need to make sure that the first rank in a team is the end of a couple
	std::cout << "Phase 3: broadcast inside each group" << std::endl;
	for(i=0; i<couples.size(); i++) {
		// locate the end of the couple
		couple_t& c = couples[i];
		terminal_id_t t;
		router_id_t r;
		group_id_t g;
		cortex_dfly_job_get_terminal_from_rank(job_id,c.second,&t);
		cortex_dfly_get_router_from_terminal(t,&r);
		cortex_dfly_get_group_from_router(r,&g);
		// get the team of its group
		std::vector<rank_t>& team = teams[g];
		if(team[0] != c.second) {
			std::vector<rank_t>::iterator it = std::find(team.begin(),team.end(),c.second);
			if(it == team.end()) {
				std::cerr << "A - Error here..." << std::endl;
			}
			*it = team[0];
			team[0] = c.second;
		}
		// do the actual broadcast
		std::cout << "Inside group " << g << std::endl;
		dfly_bcast_tree(job_id,team);
	}
	
	// do a broadcast in each router
	std::cout << "Phase 4: broadcast inside each router of each group" << std::endl;
	g = topo.begin();
	for(; g != topo.end(); g++) {
		// get an iterator over the routers in this group
		router_map_t::iterator r = g->second.begin();
		for(; r != g->second.end(); r++) {
			// get the router id
			router_id_t r_id = r->first;
			// get the list of ranks
			rank_vector_t& processes = r->second;
			// if this router contains the root rank
			if(r_id == root.router) {
				// find it
				rank_vector_t::iterator it = std::find(processes.begin(),processes.end(),root.rank);
				if(it == processes.end()) {
					std::cerr << "B - Error here..." << std::endl;
				}
				// exchange the first element
				*it = processes[0];
				processes[0] = root.rank;
			}
			std::cout << "Inside router " << r_id << std::endl;
			// do a broadcast
			dfly_bcast_tree(job_id,processes);
		}
	}

	return 0;
}

extern "C" int dfly_broadcast_grt(job_id_t job_id, rank_t* ranks, size_t num_ranks, rank_t my_rank) {
	rank_t root_rank = ranks[0];
	// get the placement of the root process
	placement_info  root;
	terminal_id_t   root_terminal;
	router_id_t     root_router;
	group_id_t      root_group;
	cortex_dfly_job_get_terminal_from_rank(job_id,root_rank,&root_terminal);
	cortex_dfly_get_router_from_terminal(root_terminal,&root_router);
	cortex_dfly_get_group_from_router(root_router,&root_group);
	root.rank       = root_rank;
	root.terminal   = root_terminal;
	root.router     = root_router;
	root.group      = root_group;

	// build the topology
	group_map_t topo;
	std::vector<rank_t> ranks_vec(ranks,ranks+num_ranks);
	dfly_build_topology(topo, job_id, ranks_vec);

	// do a broadcast across groups
	std::vector<rank_t> group_ranks;
	group_ranks.push_back(root.rank);
	for(group_map_t::iterator g = topo.begin(); g != topo.end(); g++) {
		if(g->first == root.group) continue;
		group_ranks.push_back(g->second.begin()->second[0]);
	}
	dfly_bcast_tree(job_id,group_ranks);

	// within each group, do a broadcast across routers
	for(group_map_t::iterator g = topo.begin(); g != topo.end(); g++) {
		std::vector<rank_t> router_ranks;
		if(g->first == root.group) {
			router_ranks.push_back(root.rank);
		}
		for(router_map_t::iterator r = g->second.begin(); r != g->second.end(); r++) {
			if(r->first == root.router) continue;
			router_ranks.push_back(r->second[0]);
		}
		dfly_bcast_tree(job_id,router_ranks);
	}

	// within each router, do a broadcast across terminals
	for(group_map_t::iterator g = topo.begin(); g != topo.end(); g++) {
	for(router_map_t::iterator r = g->second.begin(); r != g->second.end(); r++) {
		std::vector<rank_t> terminal_ranks;
		if(r->first == root.router) {
			terminal_ranks.push_back(root.rank);
		}
		for(std::vector<rank_t>::iterator t = r->second.begin(); t != r->second.end(); t++) {
			if(*t == root.rank) continue;
			terminal_ranks.push_back(*t);
		}
		dfly_bcast_tree(job_id,terminal_ranks);
	}
	}

	return 0;
}

int main(int argc, char** argv) {

	if(argc != 4) {
		std::cerr << "Usage: " << argv[0] << " num_procs dfly_config alloc_config";
		exit(-1);
	}

	MPI_Init(&argc,&argv);

	int n = atoi(argv[1]);
	std::string dfly_config(argv[2]);
	std::string alloc_config(argv[3]);

	configuration_load(dfly_config.c_str(), MPI_COMM_WORLD, &config);
	cortex_dfly_topology_init();
	cortex_dfly_set_jobmap((char*)alloc_config.c_str());
	
	std::vector<rank_t> ranks(n);
	for(int i=0; i<n; i++) {
		ranks[i] = i;
	}

	dfly_broadcast_grt(0, &ranks[0], n, 0);
//	dfly_broadcast_rgt(0, &ranks[0], n, 0);
//	dfly_bcast_tree(0,ranks);
	MPI_Finalize();
	return 0;
}
