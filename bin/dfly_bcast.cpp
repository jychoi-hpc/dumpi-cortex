#include <vector>
#include <map>
#include <set>
#include "stdint.h"
#include "stdlib.h"
#include "cortex/dragonfly.h"

typedef std::vector<rank_t> rank_vector_t;
typedef std::map<router_id_t, rank_vector_t> router_map_t;
typedef std::map<group_id_t, router_map_t> group_map_t;

/* This function builds the topology structure */
static int dfly_build_topology(group_map_t& topo, job_id_t job_id, const std::vector<rank_t>& ranks) {
	
	topo.clear();
	for(int i=0; i<ranks.size(); i++) {
		terminal_id_t t;
		router_id_t   r;
		group_id_t    g;
		cortex_dfly_job_get_terminal_from_rank(job_id, ranks[i], &t);
		cortex_dfly_get_router_from_terminal(t,&r);
		cortex_dfly_get_group_from_router(r,&g);
		topo[g][r].push_back(ranks[i]);
	}

	return 0;
}

/* This function builds a team for group g based on the given topology. */
static int dfly_build_team(group_map_t& topo, std::vector<rank_t>& team, job_id_t job_id, group_id_t g, rank_t root_rank) {

	// get information about the root process's location
	router_id_t   r_root;
	terminal_id_t t_root;
	cortex_dfly_job_get_terminal_from_rank(job_id, root_rank, &t_root);
	cortex_dfly_get_router_from_terminal(t_root,&r_root);

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
		if(r->first == r_root) {
			team.push_back(root_rank);
		} else {
			team.push_back(r->second[0]);
		}
	}
	return 0;
}

static int dfly_build_couples(group_map_t& topo, 
		std::vector<std::pair<rank_t,rank_t> >& couples,
		job_id_t job_id, rank_t root_rank) {
	// get root rank information (group, router, terminal)
	group_id_t    g_root;
	router_id_t   r_root;
	terminal_id_t t_root;
	cortex_dfly_job_get_terminal_from_rank(job_id, root_rank, &t_root);
	cortex_dfly_get_router_from_terminal(t_root,&r_root);
	cortex_dfly_get_group_from_router(r_root,&g_root);

	// build the team ranks used in the root group
	std::vector<rank_t> root_team_ranks_vec;
	dfly_build_team(topo, root_team_ranks_vec, job_id, g_root, root_rank);
	std::set<rank_t> root_ream_ranks_set(root_team_ranks_vec.begin(), root_team_ranks_vec.end());

	// divide groups into different levels
	std::set<group_id_t> distant_groups;
	// iterator over all non-root groups
	for(group_map_t::const_iterator g = topo.begin(); g != topo.end(); g++) {
		if(g->first != g_root) {
			group_id_t g1 = g->first;
			router_id_t r1, r2;
			cortex_dfly_get_group_link_list(g1, g_root, &r1, &r2);
			if(topo[g_root].count(r2) == 0) { // r2 is not in g_root, the group g1 is distant
				distant_groups.insert(g1);
				continue;
			}
			// here we know that r2 is in g_root, we take the first terminal of r2 for the pair,
			// unless the router contains the root rank in which case we choose it
			std::pair<rank_t,rank_t> couple;
			couple.first = r2 == r_root ? root_rank : topo[g_root][r2][0];
			if(topo[g1].count(r1)) { // r1 is in g1
				couple.second = topo[g1][r1][0];
			} else { // r1 is not in g1
				couple.second = topo[g1].begin()->second[0]; // take the first router instead
			}
			// insert in couples
			couples.push_back(couple);
			// remove the rank used in g_root from the root_team_ranks_set
			root_ream_ranks_set.erase(couple.first);
		}
	}
	
	// for all distant groups, build a pair
	int i = 0; // index to do a round-robin in root_team_ranks_vec
	for(std::set<group_id_t>::iterator g = distant_groups.begin(); g != distant_groups.end(); g++) {
		group_id_t g1 = *g;
		router_id_t r1, r2;
		cortex_dfly_get_group_link_list(g1, g_root, &r1, &r2);
		
		std::pair<rank_t,rank_t> couple;
		rank_t rk1, rk2;
		if(root_ream_ranks_set.size() != 0) {
			rk2 = *(root_ream_ranks_set.begin());
			root_ream_ranks_set.erase(rk1);
		} else {
			rk2 = root_team_ranks_vec[i];
			i += 1;
			i %= root_team_ranks_vec.size();
		}
		couple.first = rk2;
		
		if(topo[g1].count(r1)) { // r1 is in g1 
			rk1 = topo[g1][r1][0];
		} else {
			rk1 = topo[g1].begin()->second[0]; // take the first router instead
		}
		// insert in couples
		couples.push_back(couple);
	}

	return 0;
}

extern "C" int dfly_broadcast_rgt(job_id_t job_id, rank_t* ranks, size_t num_ranks, rank_t my_rank) {
	rank_t root_rank = ranks[0];

	// build the topology
	group_map_t topo;
	std::vector<rank_t> ranks_vec(ranks,ranks+num_ranks);
	dfly_build_topology(topo, job_id, ranks_vec);

	// get the groups involved
	std::vector<group_id_t> groups(topo.size());
	group_map_t::iterator g = topo.begin();
	int i = 0;
	for(; g != topo.end(); g++, i++) {
		groups[i] = g->first;
	}

	// for


	return 0;
}
