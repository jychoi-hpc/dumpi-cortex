#include <boost/python.hpp>
#include <cstdlib>
#include <cortex/cortex.h>
#include <cortex/comm.h>
#include <cortex/datatype.h>
#include <cortex/cortex-python.h>
#include "cortex/debug.h"

namespace bp = boost::python;

bool cortex_python_initialized = false;
bp::object user_python_module;
bp::object cortex_python_module;
bp::object user_python_translator;
void* cortex_python_current_uarg = NULL;
const dumpi_time* cortex_python_current_cpu  = NULL;
const dumpi_time* cortex_python_current_wall = NULL;
const dumpi_perfinfo* cortex_python_current_perf = NULL;

//  dumpi_send
static void pycortex_post_dumpi_send(int thread, int count, dumpi_datatype datatype, int dest, int tag, dumpi_comm comm) {
	dumpi_send prm;


	prm.count = count;
	prm.datatype = datatype;
	prm.dest = dest;
	prm.tag = tag;
	prm.comm = comm;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Send, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_recv
static void pycortex_post_dumpi_recv(int thread, int count, dumpi_datatype datatype, int source, int tag, dumpi_comm comm,const bp::object& status) {
	dumpi_recv prm;


	prm.count = count;
	prm.datatype = datatype;
	prm.source = source;
	prm.tag = tag;
	prm.comm = comm;
	prm.status = (dumpi_status*)malloc(sizeof(dumpi_status));
	*prm.status = bp::extract<dumpi_status>(status);


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Recv, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_get_count
static void pycortex_post_dumpi_get_count(int thread,const bp::object& status, dumpi_datatype datatype, int count) {
	dumpi_get_count prm;


	prm.status = (dumpi_status*)malloc(sizeof(dumpi_status));
	*prm.status = bp::extract<dumpi_status>(status);
	prm.datatype = datatype;
	prm.count = count;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Get_count, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_bsend
static void pycortex_post_dumpi_bsend(int thread, int count, dumpi_datatype datatype, int dest, int tag, dumpi_comm comm) {
	dumpi_bsend prm;


	prm.count = count;
	prm.datatype = datatype;
	prm.dest = dest;
	prm.tag = tag;
	prm.comm = comm;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Bsend, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_ssend
static void pycortex_post_dumpi_ssend(int thread, int count, dumpi_datatype datatype, int dest, int tag, dumpi_comm comm) {
	dumpi_ssend prm;


	prm.count = count;
	prm.datatype = datatype;
	prm.dest = dest;
	prm.tag = tag;
	prm.comm = comm;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Ssend, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_rsend
static void pycortex_post_dumpi_rsend(int thread, int count, dumpi_datatype datatype, int dest, int tag, dumpi_comm comm) {
	dumpi_rsend prm;


	prm.count = count;
	prm.datatype = datatype;
	prm.dest = dest;
	prm.tag = tag;
	prm.comm = comm;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Rsend, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_buffer_attach
static void pycortex_post_dumpi_buffer_attach(int thread, int size) {
	dumpi_buffer_attach prm;


	prm.size = size;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Buffer_attach, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_buffer_detach
static void pycortex_post_dumpi_buffer_detach(int thread, int size) {
	dumpi_buffer_detach prm;


	prm.size = size;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Buffer_detach, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_isend
static void pycortex_post_dumpi_isend(int thread, int count, dumpi_datatype datatype, int dest, int tag, dumpi_comm comm, dumpi_request request) {
	dumpi_isend prm;


	prm.count = count;
	prm.datatype = datatype;
	prm.dest = dest;
	prm.tag = tag;
	prm.comm = comm;
	prm.request = request;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Isend, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_ibsend
static void pycortex_post_dumpi_ibsend(int thread, int count, dumpi_datatype datatype, int dest, int tag, dumpi_comm comm, dumpi_request request) {
	dumpi_ibsend prm;


	prm.count = count;
	prm.datatype = datatype;
	prm.dest = dest;
	prm.tag = tag;
	prm.comm = comm;
	prm.request = request;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Ibsend, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_issend
static void pycortex_post_dumpi_issend(int thread, int count, dumpi_datatype datatype, int dest, int tag, dumpi_comm comm, dumpi_request request) {
	dumpi_issend prm;


	prm.count = count;
	prm.datatype = datatype;
	prm.dest = dest;
	prm.tag = tag;
	prm.comm = comm;
	prm.request = request;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Issend, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_irsend
static void pycortex_post_dumpi_irsend(int thread, int count, dumpi_datatype datatype, int dest, int tag, dumpi_comm comm, dumpi_request request) {
	dumpi_irsend prm;


	prm.count = count;
	prm.datatype = datatype;
	prm.dest = dest;
	prm.tag = tag;
	prm.comm = comm;
	prm.request = request;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Irsend, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_irecv
static void pycortex_post_dumpi_irecv(int thread, int count, dumpi_datatype datatype, int source, int tag, dumpi_comm comm, dumpi_request request) {
	dumpi_irecv prm;


	prm.count = count;
	prm.datatype = datatype;
	prm.source = source;
	prm.tag = tag;
	prm.comm = comm;
	prm.request = request;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Irecv, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_wait
static void pycortex_post_dumpi_wait(int thread, dumpi_request request,const bp::object& status) {
	dumpi_wait prm;


	prm.request = request;
	prm.status = (dumpi_status*)malloc(sizeof(dumpi_status));
	*prm.status = bp::extract<dumpi_status>(status);


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Wait, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_test
static void pycortex_post_dumpi_test(int thread, dumpi_request request, int flag,const bp::object& status) {
	dumpi_test prm;


	prm.request = request;
	prm.flag = flag;
	prm.status = (dumpi_status*)malloc(sizeof(dumpi_status));
	*prm.status = bp::extract<dumpi_status>(status);


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Test, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_request_free
static void pycortex_post_dumpi_request_free(int thread, dumpi_request request) {
	dumpi_request_free prm;


	prm.request = request;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Request_free, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_waitany
static void pycortex_post_dumpi_waitany(int thread, int count, const bp::list& requests, int index,const bp::object& status) {
	dumpi_waitany prm;


	prm.count = count;
	if(prm.count != bp::len(requests)) ERROR("len(requests) != count");
	prm.requests = (dumpi_request*)malloc(sizeof(dumpi_request)*bp::len(requests));
	for(int i=0; i < bp::len(requests); i++)
		prm.requests[i] = bp::extract<dumpi_request>(requests[i]);
	prm.index = index;
	prm.status = (dumpi_status*)malloc(sizeof(dumpi_status));
	*prm.status = bp::extract<dumpi_status>(status);


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Waitany, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_testany
static void pycortex_post_dumpi_testany(int thread, int count, const bp::list& requests, int index, int flag,const bp::object& status) {
	dumpi_testany prm;


	prm.count = count;
	if(prm.count != bp::len(requests)) ERROR("len(requests) != count");
	prm.requests = (dumpi_request*)malloc(sizeof(dumpi_request)*bp::len(requests));
	for(int i=0; i < bp::len(requests); i++)
		prm.requests[i] = bp::extract<dumpi_request>(requests[i]);
	prm.index = index;
	prm.flag = flag;
	prm.status = (dumpi_status*)malloc(sizeof(dumpi_status));
	*prm.status = bp::extract<dumpi_status>(status);


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Testany, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_waitall
static void pycortex_post_dumpi_waitall(int thread, int count, const bp::list& requests, const bp::list& statuses) {
	dumpi_waitall prm;


	prm.count = count;
	if(prm.count != bp::len(requests)) ERROR("len(requests) != count");
	prm.requests = (dumpi_request*)malloc(sizeof(dumpi_request)*bp::len(requests));
	for(int i=0; i < bp::len(requests); i++)
		prm.requests[i] = bp::extract<dumpi_request>(requests[i]);
	if(prm.count != bp::len(statuses)) ERROR("len(statuses) != count");
	prm.statuses = (dumpi_status*)malloc(sizeof(dumpi_status)*bp::len(statuses));
	for(int i=0; i < bp::len(statuses); i++)
		prm.statuses[i] = bp::extract<dumpi_status>(statuses[i]);


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Waitall, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_testall
static void pycortex_post_dumpi_testall(int thread, int count, const bp::list& requests, int flag, const bp::list& statuses) {
	dumpi_testall prm;


	prm.count = count;
	if(prm.count != bp::len(requests)) ERROR("len(requests) != count");
	prm.requests = (dumpi_request*)malloc(sizeof(dumpi_request)*bp::len(requests));
	for(int i=0; i < bp::len(requests); i++)
		prm.requests[i] = bp::extract<dumpi_request>(requests[i]);
	prm.flag = flag;
	if(prm.count != bp::len(statuses)) ERROR("len(statuses) != count");
	prm.statuses = (dumpi_status*)malloc(sizeof(dumpi_status)*bp::len(statuses));
	for(int i=0; i < bp::len(statuses); i++)
		prm.statuses[i] = bp::extract<dumpi_status>(statuses[i]);


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Testall, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_waitsome
static void pycortex_post_dumpi_waitsome(int thread, int count, const bp::list& requests, int outcount, const bp::list& indices, const bp::list& statuses) {
	dumpi_waitsome prm;


	prm.count = count;
	if(prm.count != bp::len(requests)) ERROR("len(requests) != count");
	prm.requests = (dumpi_request*)malloc(sizeof(dumpi_request)*bp::len(requests));
	for(int i=0; i < bp::len(requests); i++)
		prm.requests[i] = bp::extract<dumpi_request>(requests[i]);
	prm.outcount = outcount;
	if(prm.outcount != bp::len(indices)) ERROR("len(indices) != outcount");
	prm.indices = (int*)malloc(sizeof(int)*bp::len(indices));
	for(int i=0; i < bp::len(indices); i++)
		prm.indices[i] = bp::extract<int>(indices[i]);
	if(prm.outcount != bp::len(statuses)) ERROR("len(statuses) != outcount");
	prm.statuses = (dumpi_status*)malloc(sizeof(dumpi_status)*bp::len(statuses));
	for(int i=0; i < bp::len(statuses); i++)
		prm.statuses[i] = bp::extract<dumpi_status>(statuses[i]);


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Waitsome, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_testsome
static void pycortex_post_dumpi_testsome(int thread, int count, const bp::list& requests, int outcount, const bp::list& indices, const bp::list& statuses) {
	dumpi_testsome prm;


	prm.count = count;
	if(prm.count != bp::len(requests)) ERROR("len(requests) != count");
	prm.requests = (dumpi_request*)malloc(sizeof(dumpi_request)*bp::len(requests));
	for(int i=0; i < bp::len(requests); i++)
		prm.requests[i] = bp::extract<dumpi_request>(requests[i]);
	prm.outcount = outcount;
	if(prm.outcount != bp::len(indices)) ERROR("len(indices) != outcount");
	prm.indices = (int*)malloc(sizeof(int)*bp::len(indices));
	for(int i=0; i < bp::len(indices); i++)
		prm.indices[i] = bp::extract<int>(indices[i]);
	if(prm.outcount != bp::len(statuses)) ERROR("len(statuses) != outcount");
	prm.statuses = (dumpi_status*)malloc(sizeof(dumpi_status)*bp::len(statuses));
	for(int i=0; i < bp::len(statuses); i++)
		prm.statuses[i] = bp::extract<dumpi_status>(statuses[i]);


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Testsome, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_iprobe
static void pycortex_post_dumpi_iprobe(int thread, int source, int tag, dumpi_comm comm, int flag,const bp::object& status) {
	dumpi_iprobe prm;


	prm.source = source;
	prm.tag = tag;
	prm.comm = comm;
	prm.flag = flag;
	prm.status = (dumpi_status*)malloc(sizeof(dumpi_status));
	*prm.status = bp::extract<dumpi_status>(status);


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Iprobe, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_probe
static void pycortex_post_dumpi_probe(int thread, int source, int tag, dumpi_comm comm,const bp::object& status) {
	dumpi_probe prm;


	prm.source = source;
	prm.tag = tag;
	prm.comm = comm;
	prm.status = (dumpi_status*)malloc(sizeof(dumpi_status));
	*prm.status = bp::extract<dumpi_status>(status);


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Probe, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_cancel
static void pycortex_post_dumpi_cancel(int thread, dumpi_request request) {
	dumpi_cancel prm;


	prm.request = request;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Cancel, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_test_cancelled
static void pycortex_post_dumpi_test_cancelled(int thread,const bp::object& status, int cancelled) {
	dumpi_test_cancelled prm;


	prm.status = (dumpi_status*)malloc(sizeof(dumpi_status));
	*prm.status = bp::extract<dumpi_status>(status);
	prm.cancelled = cancelled;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Test_cancelled, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_send_init
static void pycortex_post_dumpi_send_init(int thread, int count, dumpi_datatype datatype, int dest, int tag, dumpi_comm comm, dumpi_request request) {
	dumpi_send_init prm;


	prm.count = count;
	prm.datatype = datatype;
	prm.dest = dest;
	prm.tag = tag;
	prm.comm = comm;
	prm.request = request;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Send_init, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_bsend_init
static void pycortex_post_dumpi_bsend_init(int thread, int count, dumpi_datatype datatype, int dest, int tag, dumpi_comm comm, dumpi_request request) {
	dumpi_bsend_init prm;


	prm.count = count;
	prm.datatype = datatype;
	prm.dest = dest;
	prm.tag = tag;
	prm.comm = comm;
	prm.request = request;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Bsend_init, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_ssend_init
static void pycortex_post_dumpi_ssend_init(int thread, int count, dumpi_datatype datatype, int dest, int tag, dumpi_comm comm, dumpi_request request) {
	dumpi_ssend_init prm;


	prm.count = count;
	prm.datatype = datatype;
	prm.dest = dest;
	prm.tag = tag;
	prm.comm = comm;
	prm.request = request;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Ssend_init, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_rsend_init
static void pycortex_post_dumpi_rsend_init(int thread, int count, dumpi_datatype datatype, int dest, int tag, dumpi_comm comm, dumpi_request request) {
	dumpi_rsend_init prm;


	prm.count = count;
	prm.datatype = datatype;
	prm.dest = dest;
	prm.tag = tag;
	prm.comm = comm;
	prm.request = request;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Rsend_init, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_recv_init
static void pycortex_post_dumpi_recv_init(int thread, int count, dumpi_datatype datatype, int source, int tag, dumpi_comm comm, dumpi_request request) {
	dumpi_recv_init prm;


	prm.count = count;
	prm.datatype = datatype;
	prm.source = source;
	prm.tag = tag;
	prm.comm = comm;
	prm.request = request;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Recv_init, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_start
static void pycortex_post_dumpi_start(int thread, dumpi_request request) {
	dumpi_start prm;


	prm.request = request;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Start, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_startall
static void pycortex_post_dumpi_startall(int thread, int count, const bp::list& requests) {
	dumpi_startall prm;


	prm.count = count;
	if(prm.count != bp::len(requests)) ERROR("len(requests) != count");
	prm.requests = (dumpi_request*)malloc(sizeof(dumpi_request)*bp::len(requests));
	for(int i=0; i < bp::len(requests); i++)
		prm.requests[i] = bp::extract<dumpi_request>(requests[i]);


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Startall, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_sendrecv
static void pycortex_post_dumpi_sendrecv(int thread, int sendcount, dumpi_datatype sendtype, int dest, int sendtag, int recvcount, dumpi_datatype recvtype, int source, int recvtag, dumpi_comm comm,const bp::object& status) {
	dumpi_sendrecv prm;


	prm.sendcount = sendcount;
	prm.sendtype = sendtype;
	prm.dest = dest;
	prm.sendtag = sendtag;
	prm.recvcount = recvcount;
	prm.recvtype = recvtype;
	prm.source = source;
	prm.recvtag = recvtag;
	prm.comm = comm;
	prm.status = (dumpi_status*)malloc(sizeof(dumpi_status));
	*prm.status = bp::extract<dumpi_status>(status);


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Sendrecv, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_sendrecv_replace
static void pycortex_post_dumpi_sendrecv_replace(int thread, int count, dumpi_datatype datatype, int dest, int sendtag, int source, int recvtag, dumpi_comm comm,const bp::object& status) {
	dumpi_sendrecv_replace prm;


	prm.count = count;
	prm.datatype = datatype;
	prm.dest = dest;
	prm.sendtag = sendtag;
	prm.source = source;
	prm.recvtag = recvtag;
	prm.comm = comm;
	prm.status = (dumpi_status*)malloc(sizeof(dumpi_status));
	*prm.status = bp::extract<dumpi_status>(status);


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Sendrecv_replace, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_type_contiguous
static void pycortex_post_dumpi_type_contiguous(int thread, int count, dumpi_datatype oldtype, dumpi_datatype newtype) {
	dumpi_type_contiguous prm;


	prm.count = count;
	prm.oldtype = oldtype;
	prm.newtype = newtype;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Type_contiguous, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_type_vector
static void pycortex_post_dumpi_type_vector(int thread, int count, int blocklength, int stride, dumpi_datatype oldtype, dumpi_datatype newtype) {
	dumpi_type_vector prm;


	prm.count = count;
	prm.blocklength = blocklength;
	prm.stride = stride;
	prm.oldtype = oldtype;
	prm.newtype = newtype;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Type_vector, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_type_hvector
static void pycortex_post_dumpi_type_hvector(int thread, int count, int blocklength, int stride, dumpi_datatype oldtype, dumpi_datatype newtype) {
	dumpi_type_hvector prm;


	prm.count = count;
	prm.blocklength = blocklength;
	prm.stride = stride;
	prm.oldtype = oldtype;
	prm.newtype = newtype;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Type_hvector, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_type_indexed
static void pycortex_post_dumpi_type_indexed(int thread, int count, const bp::list& lengths, const bp::list& indices, dumpi_datatype oldtype, dumpi_datatype newtype) {
	dumpi_type_indexed prm;


	prm.count = count;
	if(prm.count != bp::len(lengths)) ERROR("len(lengths) != count");
	prm.lengths = (int*)malloc(sizeof(int)*bp::len(lengths));
	for(int i=0; i < bp::len(lengths); i++)
		prm.lengths[i] = bp::extract<int>(lengths[i]);
	if(prm.count != bp::len(indices)) ERROR("len(indices) != count");
	prm.indices = (int*)malloc(sizeof(int)*bp::len(indices));
	for(int i=0; i < bp::len(indices); i++)
		prm.indices[i] = bp::extract<int>(indices[i]);
	prm.oldtype = oldtype;
	prm.newtype = newtype;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Type_indexed, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_type_hindexed
static void pycortex_post_dumpi_type_hindexed(int thread, int count, const bp::list& lengths, const bp::list& indices, dumpi_datatype oldtype, dumpi_datatype newtype) {
	dumpi_type_hindexed prm;


	prm.count = count;
	if(prm.count != bp::len(lengths)) ERROR("len(lengths) != count");
	prm.lengths = (int*)malloc(sizeof(int)*bp::len(lengths));
	for(int i=0; i < bp::len(lengths); i++)
		prm.lengths[i] = bp::extract<int>(lengths[i]);
	if(prm.count != bp::len(indices)) ERROR("len(indices) != count");
	prm.indices = (int*)malloc(sizeof(int)*bp::len(indices));
	for(int i=0; i < bp::len(indices); i++)
		prm.indices[i] = bp::extract<int>(indices[i]);
	prm.oldtype = oldtype;
	prm.newtype = newtype;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Type_hindexed, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_type_struct
static void pycortex_post_dumpi_type_struct(int thread, int count, const bp::list& lengths, const bp::list& indices, const bp::list& oldtypes, dumpi_datatype newtype) {
	dumpi_type_struct prm;


	prm.count = count;
	if(prm.count != bp::len(lengths)) ERROR("len(lengths) != count");
	prm.lengths = (int*)malloc(sizeof(int)*bp::len(lengths));
	for(int i=0; i < bp::len(lengths); i++)
		prm.lengths[i] = bp::extract<int>(lengths[i]);
	if(prm.count != bp::len(indices)) ERROR("len(indices) != count");
	prm.indices = (int*)malloc(sizeof(int)*bp::len(indices));
	for(int i=0; i < bp::len(indices); i++)
		prm.indices[i] = bp::extract<int>(indices[i]);
	if(prm.count != bp::len(oldtypes)) ERROR("len(oldtypes) != count");
	prm.oldtypes = (dumpi_datatype*)malloc(sizeof(dumpi_datatype)*bp::len(oldtypes));
	for(int i=0; i < bp::len(oldtypes); i++)
		prm.oldtypes[i] = bp::extract<dumpi_datatype>(oldtypes[i]);
	prm.newtype = newtype;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Type_struct, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_address
static void pycortex_post_dumpi_address(int thread, int address) {
	dumpi_address prm;


	prm.address = address;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Address, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_type_extent
static void pycortex_post_dumpi_type_extent(int thread, dumpi_datatype datatype, int extent) {
	dumpi_type_extent prm;


	prm.datatype = datatype;
	prm.extent = extent;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Type_extent, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_type_size
static void pycortex_post_dumpi_type_size(int thread, dumpi_datatype datatype, int size) {
	dumpi_type_size prm;


	prm.datatype = datatype;
	prm.size = size;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Type_size, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_type_lb
static void pycortex_post_dumpi_type_lb(int thread, dumpi_datatype datatype, int lb) {
	dumpi_type_lb prm;


	prm.datatype = datatype;
	prm.lb = lb;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Type_lb, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_type_ub
static void pycortex_post_dumpi_type_ub(int thread, dumpi_datatype datatype, int ub) {
	dumpi_type_ub prm;


	prm.datatype = datatype;
	prm.ub = ub;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Type_ub, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_type_commit
static void pycortex_post_dumpi_type_commit(int thread, dumpi_datatype datatype) {
	dumpi_type_commit prm;


	prm.datatype = datatype;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Type_commit, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_type_free
static void pycortex_post_dumpi_type_free(int thread, dumpi_datatype datatype) {
	dumpi_type_free prm;


	prm.datatype = datatype;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Type_free, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_get_elements
static void pycortex_post_dumpi_get_elements(int thread,const bp::object& status, dumpi_datatype datatype, int elements) {
	dumpi_get_elements prm;


	prm.status = (dumpi_status*)malloc(sizeof(dumpi_status));
	*prm.status = bp::extract<dumpi_status>(status);
	prm.datatype = datatype;
	prm.elements = elements;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Get_elements, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_pack
static void pycortex_post_dumpi_pack(int thread, int incount, dumpi_datatype datatype, int outcount, const bp::dict& position, dumpi_comm comm) {
	dumpi_pack prm;


	prm.incount = incount;
	prm.datatype = datatype;
	prm.outcount = outcount;
	prm.position.in = bp::extract<int>(position["in"]);
	prm.position.out = bp::extract<int>(position["out"]);
	prm.comm = comm;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Pack, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_unpack
static void pycortex_post_dumpi_unpack(int thread, int incount, const bp::dict& position, int outcount, dumpi_datatype datatype, dumpi_comm comm) {
	dumpi_unpack prm;


	prm.incount = incount;
	prm.position.in = bp::extract<int>(position["in"]);
	prm.position.out = bp::extract<int>(position["out"]);
	prm.outcount = outcount;
	prm.datatype = datatype;
	prm.comm = comm;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Unpack, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_pack_size
static void pycortex_post_dumpi_pack_size(int thread, int incount, dumpi_datatype datatype, dumpi_comm comm, int size) {
	dumpi_pack_size prm;


	prm.incount = incount;
	prm.datatype = datatype;
	prm.comm = comm;
	prm.size = size;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Pack_size, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_barrier
static void pycortex_post_dumpi_barrier(int thread, dumpi_comm comm) {
	dumpi_barrier prm;


	prm.comm = comm;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Barrier, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_bcast
static void pycortex_post_dumpi_bcast(int thread, int count, dumpi_datatype datatype, int root, dumpi_comm comm) {
	dumpi_bcast prm;


	prm.count = count;
	prm.datatype = datatype;
	prm.root = root;
	prm.comm = comm;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Bcast, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_gather
static void pycortex_post_dumpi_gather(int thread, int commrank, int sendcount, dumpi_datatype sendtype, int recvcount, dumpi_datatype recvtype, int root, dumpi_comm comm) {
	dumpi_gather prm;


	prm.commrank = commrank;
	prm.sendcount = sendcount;
	prm.sendtype = sendtype;
	prm.recvcount = recvcount;
	prm.recvtype = recvtype;
	prm.root = root;
	prm.comm = comm;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Gather, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_gatherv
static void pycortex_post_dumpi_gatherv(int thread, int commrank, int commsize, int sendcount, dumpi_datatype sendtype, const bp::list& recvcounts, const bp::list& displs, dumpi_datatype recvtype, int root, dumpi_comm comm) {
	dumpi_gatherv prm;


	prm.commrank = commrank;
	prm.commsize = commsize;
	prm.sendcount = sendcount;
	prm.sendtype = sendtype;
	if(prm.commsize != bp::len(recvcounts)) ERROR("len(recvcounts) != commsize");
	prm.recvcounts = (int*)malloc(sizeof(int)*bp::len(recvcounts));
	for(int i=0; i < bp::len(recvcounts); i++)
		prm.recvcounts[i] = bp::extract<int>(recvcounts[i]);
	if(prm.commsize != bp::len(displs)) ERROR("len(displs) != commsize");
	prm.displs = (int*)malloc(sizeof(int)*bp::len(displs));
	for(int i=0; i < bp::len(displs); i++)
		prm.displs[i] = bp::extract<int>(displs[i]);
	prm.recvtype = recvtype;
	prm.root = root;
	prm.comm = comm;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Gatherv, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_scatter
static void pycortex_post_dumpi_scatter(int thread, int commrank, int sendcount, dumpi_datatype sendtype, int recvcount, dumpi_datatype recvtype, int root, dumpi_comm comm) {
	dumpi_scatter prm;


	prm.commrank = commrank;
	prm.sendcount = sendcount;
	prm.sendtype = sendtype;
	prm.recvcount = recvcount;
	prm.recvtype = recvtype;
	prm.root = root;
	prm.comm = comm;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Scatter, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_scatterv
static void pycortex_post_dumpi_scatterv(int thread, int commrank, int commsize, const bp::list& sendcounts, const bp::list& displs, dumpi_datatype sendtype, int recvcount, dumpi_datatype recvtype, int root, dumpi_comm comm) {
	dumpi_scatterv prm;


	prm.commrank = commrank;
	prm.commsize = commsize;
	if(prm.commsize != bp::len(sendcounts)) ERROR("len(sendcounts) != commsize");
	prm.sendcounts = (int*)malloc(sizeof(int)*bp::len(sendcounts));
	for(int i=0; i < bp::len(sendcounts); i++)
		prm.sendcounts[i] = bp::extract<int>(sendcounts[i]);
	if(prm.commsize != bp::len(displs)) ERROR("len(displs) != commsize");
	prm.displs = (int*)malloc(sizeof(int)*bp::len(displs));
	for(int i=0; i < bp::len(displs); i++)
		prm.displs[i] = bp::extract<int>(displs[i]);
	prm.sendtype = sendtype;
	prm.recvcount = recvcount;
	prm.recvtype = recvtype;
	prm.root = root;
	prm.comm = comm;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Scatterv, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_allgather
static void pycortex_post_dumpi_allgather(int thread, int sendcount, dumpi_datatype sendtype, int recvcount, dumpi_datatype recvtype, dumpi_comm comm) {
	dumpi_allgather prm;


	prm.sendcount = sendcount;
	prm.sendtype = sendtype;
	prm.recvcount = recvcount;
	prm.recvtype = recvtype;
	prm.comm = comm;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Allgather, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_allgatherv
static void pycortex_post_dumpi_allgatherv(int thread, int commsize, int sendcount, dumpi_datatype sendtype, const bp::list& recvcounts, const bp::list& displs, dumpi_datatype recvtype, dumpi_comm comm) {
	dumpi_allgatherv prm;


	prm.commsize = commsize;
	prm.sendcount = sendcount;
	prm.sendtype = sendtype;
	if(prm.commsize != bp::len(recvcounts)) ERROR("len(recvcounts) != commsize");
	prm.recvcounts = (int*)malloc(sizeof(int)*bp::len(recvcounts));
	for(int i=0; i < bp::len(recvcounts); i++)
		prm.recvcounts[i] = bp::extract<int>(recvcounts[i]);
	if(prm.commsize != bp::len(displs)) ERROR("len(displs) != commsize");
	prm.displs = (int*)malloc(sizeof(int)*bp::len(displs));
	for(int i=0; i < bp::len(displs); i++)
		prm.displs[i] = bp::extract<int>(displs[i]);
	prm.recvtype = recvtype;
	prm.comm = comm;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Allgatherv, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_alltoall
static void pycortex_post_dumpi_alltoall(int thread, int sendcount, dumpi_datatype sendtype, int recvcount, dumpi_datatype recvtype, dumpi_comm comm) {
	dumpi_alltoall prm;


	prm.sendcount = sendcount;
	prm.sendtype = sendtype;
	prm.recvcount = recvcount;
	prm.recvtype = recvtype;
	prm.comm = comm;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Alltoall, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_alltoallv
static void pycortex_post_dumpi_alltoallv(int thread, int commsize, const bp::list& sendcounts, const bp::list& senddispls, dumpi_datatype sendtype, const bp::list& recvcounts, const bp::list& recvdispls, dumpi_datatype recvtype, dumpi_comm comm) {
	dumpi_alltoallv prm;


	prm.commsize = commsize;
	if(prm.commsize != bp::len(sendcounts)) ERROR("len(sendcounts) != commsize");
	prm.sendcounts = (int*)malloc(sizeof(int)*bp::len(sendcounts));
	for(int i=0; i < bp::len(sendcounts); i++)
		prm.sendcounts[i] = bp::extract<int>(sendcounts[i]);
	if(prm.commsize != bp::len(senddispls)) ERROR("len(senddispls) != commsize");
	prm.senddispls = (int*)malloc(sizeof(int)*bp::len(senddispls));
	for(int i=0; i < bp::len(senddispls); i++)
		prm.senddispls[i] = bp::extract<int>(senddispls[i]);
	prm.sendtype = sendtype;
	if(prm.commsize != bp::len(recvcounts)) ERROR("len(recvcounts) != commsize");
	prm.recvcounts = (int*)malloc(sizeof(int)*bp::len(recvcounts));
	for(int i=0; i < bp::len(recvcounts); i++)
		prm.recvcounts[i] = bp::extract<int>(recvcounts[i]);
	if(prm.commsize != bp::len(recvdispls)) ERROR("len(recvdispls) != commsize");
	prm.recvdispls = (int*)malloc(sizeof(int)*bp::len(recvdispls));
	for(int i=0; i < bp::len(recvdispls); i++)
		prm.recvdispls[i] = bp::extract<int>(recvdispls[i]);
	prm.recvtype = recvtype;
	prm.comm = comm;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Alltoallv, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_reduce
static void pycortex_post_dumpi_reduce(int thread, int count, dumpi_datatype datatype, dumpi_op op, int root, dumpi_comm comm) {
	dumpi_reduce prm;


	prm.count = count;
	prm.datatype = datatype;
	prm.op = op;
	prm.root = root;
	prm.comm = comm;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Reduce, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_op_create
static void pycortex_post_dumpi_op_create(int thread, int commute, dumpi_op op) {
	dumpi_op_create prm;


	prm.commute = commute;
	prm.op = op;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Op_create, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_op_free
static void pycortex_post_dumpi_op_free(int thread, dumpi_op op) {
	dumpi_op_free prm;


	prm.op = op;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Op_free, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_allreduce
static void pycortex_post_dumpi_allreduce(int thread, int count, dumpi_datatype datatype, dumpi_op op, dumpi_comm comm) {
	dumpi_allreduce prm;


	prm.count = count;
	prm.datatype = datatype;
	prm.op = op;
	prm.comm = comm;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Allreduce, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_reduce_scatter
static void pycortex_post_dumpi_reduce_scatter(int thread, int commsize, const bp::list& recvcounts, dumpi_datatype datatype, dumpi_op op, dumpi_comm comm) {
	dumpi_reduce_scatter prm;


	prm.commsize = commsize;
	if(prm.commsize != bp::len(recvcounts)) ERROR("len(recvcounts) != commsize");
	prm.recvcounts = (int*)malloc(sizeof(int)*bp::len(recvcounts));
	for(int i=0; i < bp::len(recvcounts); i++)
		prm.recvcounts[i] = bp::extract<int>(recvcounts[i]);
	prm.datatype = datatype;
	prm.op = op;
	prm.comm = comm;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Reduce_scatter, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_scan
static void pycortex_post_dumpi_scan(int thread, int count, dumpi_datatype datatype, dumpi_op op, dumpi_comm comm) {
	dumpi_scan prm;


	prm.count = count;
	prm.datatype = datatype;
	prm.op = op;
	prm.comm = comm;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Scan, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_group_size
static void pycortex_post_dumpi_group_size(int thread, dumpi_group group, int size) {
	dumpi_group_size prm;


	prm.group = group;
	prm.size = size;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Group_size, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_group_rank
static void pycortex_post_dumpi_group_rank(int thread, dumpi_group group, int rank) {
	dumpi_group_rank prm;


	prm.group = group;
	prm.rank = rank;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Group_rank, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_group_translate_ranks
static void pycortex_post_dumpi_group_translate_ranks(int thread, dumpi_group group1, int count, const bp::list& ranks1, dumpi_group group2, const bp::list& ranks2) {
	dumpi_group_translate_ranks prm;


	prm.group1 = group1;
	prm.count = count;
	if(prm.count != bp::len(ranks1)) ERROR("len(ranks1) != count");
	prm.ranks1 = (int*)malloc(sizeof(int)*bp::len(ranks1));
	for(int i=0; i < bp::len(ranks1); i++)
		prm.ranks1[i] = bp::extract<int>(ranks1[i]);
	prm.group2 = group2;
	if(prm.count != bp::len(ranks2)) ERROR("len(ranks2) != count");
	prm.ranks2 = (int*)malloc(sizeof(int)*bp::len(ranks2));
	for(int i=0; i < bp::len(ranks2); i++)
		prm.ranks2[i] = bp::extract<int>(ranks2[i]);


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Group_translate_ranks, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_group_compare
static void pycortex_post_dumpi_group_compare(int thread, dumpi_group group1, dumpi_group group2, int result) {
	dumpi_group_compare prm;


	prm.group1 = group1;
	prm.group2 = group2;
	prm.result = result;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Group_compare, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_comm_group
static void pycortex_post_dumpi_comm_group(int thread, dumpi_comm comm, dumpi_group group) {
	dumpi_comm_group prm;


	prm.comm = comm;
	prm.group = group;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Comm_group, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_group_union
static void pycortex_post_dumpi_group_union(int thread, dumpi_group group1, dumpi_group group2, dumpi_group newgroup) {
	dumpi_group_union prm;


	prm.group1 = group1;
	prm.group2 = group2;
	prm.newgroup = newgroup;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Group_union, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_group_intersection
static void pycortex_post_dumpi_group_intersection(int thread, dumpi_group group1, dumpi_group group2, dumpi_group newgroup) {
	dumpi_group_intersection prm;


	prm.group1 = group1;
	prm.group2 = group2;
	prm.newgroup = newgroup;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Group_intersection, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_group_difference
static void pycortex_post_dumpi_group_difference(int thread, dumpi_group group1, dumpi_group group2, dumpi_group newgroup) {
	dumpi_group_difference prm;


	prm.group1 = group1;
	prm.group2 = group2;
	prm.newgroup = newgroup;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Group_difference, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_group_incl
static void pycortex_post_dumpi_group_incl(int thread, dumpi_group group, int count, const bp::list& ranks, dumpi_group newgroup) {
	dumpi_group_incl prm;


	prm.group = group;
	prm.count = count;
	if(prm.count != bp::len(ranks)) ERROR("len(ranks) != count");
	prm.ranks = (int*)malloc(sizeof(int)*bp::len(ranks));
	for(int i=0; i < bp::len(ranks); i++)
		prm.ranks[i] = bp::extract<int>(ranks[i]);
	prm.newgroup = newgroup;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Group_incl, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_group_excl
static void pycortex_post_dumpi_group_excl(int thread, dumpi_group group, int count, const bp::list& ranks, dumpi_group newgroup) {
	dumpi_group_excl prm;


	prm.group = group;
	prm.count = count;
	if(prm.count != bp::len(ranks)) ERROR("len(ranks) != count");
	prm.ranks = (int*)malloc(sizeof(int)*bp::len(ranks));
	for(int i=0; i < bp::len(ranks); i++)
		prm.ranks[i] = bp::extract<int>(ranks[i]);
	prm.newgroup = newgroup;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Group_excl, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_group_range_incl
static void pycortex_post_dumpi_group_range_incl(int thread, dumpi_group group, int count, const bp::list& ranges, dumpi_group newgroup) {
	dumpi_group_range_incl prm;


	prm.group = group;
	prm.count = count;
	prm.ranges = (int**)malloc(sizeof(int*)*bp::len(ranges));
	for(int i=0; i < bp::len(ranges); i++) {
		prm.ranges[i] = (int*)malloc(sizeof(int)*3);
		for(int j=0; j<3; j++) prm.ranges[i][j] = bp::extract<int>(ranges[i][j]);
	}
	prm.newgroup = newgroup;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Group_range_incl, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_group_range_excl
static void pycortex_post_dumpi_group_range_excl(int thread, dumpi_group group, int count, const bp::list& ranges, dumpi_group newgroup) {
	dumpi_group_range_excl prm;


	prm.group = group;
	prm.count = count;
	prm.ranges = (int**)malloc(sizeof(int*)*bp::len(ranges));
	for(int i=0; i < bp::len(ranges); i++) {
		prm.ranges[i] = (int*)malloc(sizeof(int)*3);
		for(int j=0; j<3; j++) prm.ranges[i][j] = bp::extract<int>(ranges[i][j]);
	}
	prm.newgroup = newgroup;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Group_range_excl, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_group_free
static void pycortex_post_dumpi_group_free(int thread, dumpi_group group) {
	dumpi_group_free prm;


	prm.group = group;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Group_free, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_comm_size
static void pycortex_post_dumpi_comm_size(int thread, dumpi_comm comm, int size) {
	dumpi_comm_size prm;


	prm.comm = comm;
	prm.size = size;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Comm_size, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_comm_rank
static void pycortex_post_dumpi_comm_rank(int thread, dumpi_comm comm, int rank) {
	dumpi_comm_rank prm;


	prm.comm = comm;
	prm.rank = rank;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Comm_rank, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_comm_compare
static void pycortex_post_dumpi_comm_compare(int thread, dumpi_comm comm1, dumpi_comm comm2, int result) {
	dumpi_comm_compare prm;


	prm.comm1 = comm1;
	prm.comm2 = comm2;
	prm.result = result;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Comm_compare, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_comm_dup
static void pycortex_post_dumpi_comm_dup(int thread, dumpi_comm oldcomm, dumpi_comm newcomm) {
	dumpi_comm_dup prm;


	prm.oldcomm = oldcomm;
	prm.newcomm = newcomm;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Comm_dup, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_comm_create
static void pycortex_post_dumpi_comm_create(int thread, dumpi_comm oldcomm, dumpi_group group, dumpi_comm newcomm) {
	dumpi_comm_create prm;


	prm.oldcomm = oldcomm;
	prm.group = group;
	prm.newcomm = newcomm;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Comm_create, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_comm_split
static void pycortex_post_dumpi_comm_split(int thread, dumpi_comm oldcomm, int color, int key, dumpi_comm newcomm) {
	dumpi_comm_split prm;


	prm.oldcomm = oldcomm;
	prm.color = color;
	prm.key = key;
	prm.newcomm = newcomm;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Comm_split, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_comm_free
static void pycortex_post_dumpi_comm_free(int thread, dumpi_comm comm) {
	dumpi_comm_free prm;


	prm.comm = comm;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Comm_free, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_comm_test_inter
static void pycortex_post_dumpi_comm_test_inter(int thread, dumpi_comm comm, int inter) {
	dumpi_comm_test_inter prm;


	prm.comm = comm;
	prm.inter = inter;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Comm_test_inter, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_comm_remote_size
static void pycortex_post_dumpi_comm_remote_size(int thread, dumpi_comm comm, int size) {
	dumpi_comm_remote_size prm;


	prm.comm = comm;
	prm.size = size;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Comm_remote_size, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_comm_remote_group
static void pycortex_post_dumpi_comm_remote_group(int thread, dumpi_comm comm, dumpi_group group) {
	dumpi_comm_remote_group prm;


	prm.comm = comm;
	prm.group = group;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Comm_remote_group, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_intercomm_create
static void pycortex_post_dumpi_intercomm_create(int thread, dumpi_comm localcomm, int localleader, dumpi_comm remotecomm, int remoteleader, int tag, dumpi_comm newcomm) {
	dumpi_intercomm_create prm;


	prm.localcomm = localcomm;
	prm.localleader = localleader;
	prm.remotecomm = remotecomm;
	prm.remoteleader = remoteleader;
	prm.tag = tag;
	prm.newcomm = newcomm;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Intercomm_create, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_intercomm_merge
static void pycortex_post_dumpi_intercomm_merge(int thread, dumpi_comm comm, int high, dumpi_comm newcomm) {
	dumpi_intercomm_merge prm;


	prm.comm = comm;
	prm.high = high;
	prm.newcomm = newcomm;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Intercomm_merge, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_keyval_create
static void pycortex_post_dumpi_keyval_create(int thread, dumpi_keyval key) {
	dumpi_keyval_create prm;


	prm.key = key;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Keyval_create, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_keyval_free
static void pycortex_post_dumpi_keyval_free(int thread, int key) {
	dumpi_keyval_free prm;


	prm.key = key;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Keyval_free, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_attr_put
static void pycortex_post_dumpi_attr_put(int thread, dumpi_comm comm, int key) {
	dumpi_attr_put prm;


	prm.comm = comm;
	prm.key = key;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Attr_put, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_attr_get
static void pycortex_post_dumpi_attr_get(int thread, dumpi_comm comm, int key, int flag) {
	dumpi_attr_get prm;


	prm.comm = comm;
	prm.key = key;
	prm.flag = flag;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Attr_get, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_attr_delete
static void pycortex_post_dumpi_attr_delete(int thread, dumpi_comm comm, int key) {
	dumpi_attr_delete prm;


	prm.comm = comm;
	prm.key = key;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Attr_delete, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_topo_test
static void pycortex_post_dumpi_topo_test(int thread, dumpi_comm comm, dumpi_topology topo) {
	dumpi_topo_test prm;


	prm.comm = comm;
	prm.topo = topo;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Topo_test, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_cart_create
static void pycortex_post_dumpi_cart_create(int thread, dumpi_comm oldcomm, int ndim, const bp::list& dims, const bp::list& periods, int reorder, dumpi_comm newcomm) {
	dumpi_cart_create prm;


	prm.oldcomm = oldcomm;
	prm.ndim = ndim;
	if(prm.ndim != bp::len(dims)) ERROR("len(dims) != ndim");
	prm.dims = (int*)malloc(sizeof(int)*bp::len(dims));
	for(int i=0; i < bp::len(dims); i++)
		prm.dims[i] = bp::extract<int>(dims[i]);
	if(prm.ndim != bp::len(periods)) ERROR("len(periods) != ndim");
	prm.periods = (int*)malloc(sizeof(int)*bp::len(periods));
	for(int i=0; i < bp::len(periods); i++)
		prm.periods[i] = bp::extract<int>(periods[i]);
	prm.reorder = reorder;
	prm.newcomm = newcomm;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Cart_create, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_dims_create
static void pycortex_post_dumpi_dims_create(int thread, int nodes, int ndim, const bp::dict& dims) {
	dumpi_dims_create prm;


	prm.nodes = nodes;
	prm.ndim = ndim;
	bp::list in = bp::extract<bp::list>(dims["in"]);
	bp::list out = bp::extract<bp::list>(dims["out"]);
	
	prm.dims.in = (int*)malloc(sizeof(int)*bp::len(in));
	for(int i=0; i<bp::len(in); i++) prm.dims.in[i] = bp::extract<int>(in[i]);
	prm.dims.out = (int*)malloc(sizeof(int)*bp::len(out));
	for(int i=0; i<bp::len(out); i++) prm.dims.out[i] = bp::extract<int>(out[i]);

	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Dims_create, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_graph_create
static void pycortex_post_dumpi_graph_create(int thread, int numedges, dumpi_comm oldcomm, int nodes, const bp::list& index, const bp::list& edges, int reorder, dumpi_comm newcomm) {
	dumpi_graph_create prm;


	prm.numedges = numedges;
	prm.oldcomm = oldcomm;
	prm.nodes = nodes;
	if(prm.nodes != bp::len(index)) ERROR("len(index) != nodes");
	prm.index = (int*)malloc(sizeof(int)*bp::len(index));
	for(int i=0; i < bp::len(index); i++)
		prm.index[i] = bp::extract<int>(index[i]);
	if(prm.numedges != bp::len(edges)) ERROR("len(edges) != numedges");
	prm.edges = (int*)malloc(sizeof(int)*bp::len(edges));
	for(int i=0; i < bp::len(edges); i++)
		prm.edges[i] = bp::extract<int>(edges[i]);
	prm.reorder = reorder;
	prm.newcomm = newcomm;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Graph_create, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_graphdims_get
static void pycortex_post_dumpi_graphdims_get(int thread, dumpi_comm comm, int nodes, int edges) {
	dumpi_graphdims_get prm;


	prm.comm = comm;
	prm.nodes = nodes;
	prm.edges = edges;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Graphdims_get, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_graph_get
static void pycortex_post_dumpi_graph_get(int thread, int totedges, int totnodes, dumpi_comm comm, int maxindex, int maxedges, const bp::list& index, const bp::list& edges) {
	dumpi_graph_get prm;


	prm.totedges = totedges;
	prm.totnodes = totnodes;
	prm.comm = comm;
	prm.maxindex = maxindex;
	prm.maxedges = maxedges;
	if(prm.totnodes != bp::len(index)) ERROR("len(index) != totnodes");
	prm.index = (int*)malloc(sizeof(int)*bp::len(index));
	for(int i=0; i < bp::len(index); i++)
		prm.index[i] = bp::extract<int>(index[i]);
	if(prm.totedges != bp::len(edges)) ERROR("len(edges) != totedges");
	prm.edges = (int*)malloc(sizeof(int)*bp::len(edges));
	for(int i=0; i < bp::len(edges); i++)
		prm.edges[i] = bp::extract<int>(edges[i]);


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Graph_get, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_cartdim_get
static void pycortex_post_dumpi_cartdim_get(int thread, dumpi_comm comm, int ndim) {
	dumpi_cartdim_get prm;


	prm.comm = comm;
	prm.ndim = ndim;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Cartdim_get, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_cart_get
static void pycortex_post_dumpi_cart_get(int thread, int ndim, dumpi_comm comm, int maxdims, const bp::list& dims, const bp::list& periods, const bp::list& coords) {
	dumpi_cart_get prm;


	prm.ndim = ndim;
	prm.comm = comm;
	prm.maxdims = maxdims;
	if(prm.ndim != bp::len(dims)) ERROR("len(dims) != ndim");
	prm.dims = (int*)malloc(sizeof(int)*bp::len(dims));
	for(int i=0; i < bp::len(dims); i++)
		prm.dims[i] = bp::extract<int>(dims[i]);
	if(prm.ndim != bp::len(periods)) ERROR("len(periods) != ndim");
	prm.periods = (int*)malloc(sizeof(int)*bp::len(periods));
	for(int i=0; i < bp::len(periods); i++)
		prm.periods[i] = bp::extract<int>(periods[i]);
	if(prm.ndim != bp::len(coords)) ERROR("len(coords) != ndim");
	prm.coords = (int*)malloc(sizeof(int)*bp::len(coords));
	for(int i=0; i < bp::len(coords); i++)
		prm.coords[i] = bp::extract<int>(coords[i]);


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Cart_get, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_cart_rank
static void pycortex_post_dumpi_cart_rank(int thread, int ndim, dumpi_comm comm, const bp::list& coords, int rank) {
	dumpi_cart_rank prm;


	prm.ndim = ndim;
	prm.comm = comm;
	if(prm.ndim != bp::len(coords)) ERROR("len(coords) != ndim");
	prm.coords = (int*)malloc(sizeof(int)*bp::len(coords));
	for(int i=0; i < bp::len(coords); i++)
		prm.coords[i] = bp::extract<int>(coords[i]);
	prm.rank = rank;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Cart_rank, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_cart_coords
static void pycortex_post_dumpi_cart_coords(int thread, int ndim, dumpi_comm comm, int rank, int maxdims, const bp::list& coords) {
	dumpi_cart_coords prm;


	prm.ndim = ndim;
	prm.comm = comm;
	prm.rank = rank;
	prm.maxdims = maxdims;
	if(prm.ndim != bp::len(coords)) ERROR("len(coords) != ndim");
	prm.coords = (int*)malloc(sizeof(int)*bp::len(coords));
	for(int i=0; i < bp::len(coords); i++)
		prm.coords[i] = bp::extract<int>(coords[i]);


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Cart_coords, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_graph_neighbors_count
static void pycortex_post_dumpi_graph_neighbors_count(int thread, dumpi_comm comm, int rank, int nneigh) {
	dumpi_graph_neighbors_count prm;


	prm.comm = comm;
	prm.rank = rank;
	prm.nneigh = nneigh;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Graph_neighbors_count, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_graph_neighbors
static void pycortex_post_dumpi_graph_neighbors(int thread, int nneigh, dumpi_comm comm, int rank, int maxneighbors, const bp::list& neighbors) {
	dumpi_graph_neighbors prm;


	prm.nneigh = nneigh;
	prm.comm = comm;
	prm.rank = rank;
	prm.maxneighbors = maxneighbors;
	if(prm.nneigh != bp::len(neighbors)) ERROR("len(neighbors) != nneigh");
	prm.neighbors = (int*)malloc(sizeof(int)*bp::len(neighbors));
	for(int i=0; i < bp::len(neighbors); i++)
		prm.neighbors[i] = bp::extract<int>(neighbors[i]);


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Graph_neighbors, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_cart_shift
static void pycortex_post_dumpi_cart_shift(int thread, dumpi_comm comm, int direction, int displ, int source, int dest) {
	dumpi_cart_shift prm;


	prm.comm = comm;
	prm.direction = direction;
	prm.displ = displ;
	prm.source = source;
	prm.dest = dest;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Cart_shift, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_cart_sub
static void pycortex_post_dumpi_cart_sub(int thread, int ndim, dumpi_comm oldcomm, const bp::list& remain_dims, dumpi_comm newcomm) {
	dumpi_cart_sub prm;


	prm.ndim = ndim;
	prm.oldcomm = oldcomm;
	if(prm.ndim != bp::len(remain_dims)) ERROR("len(remain_dims) != ndim");
	prm.remain_dims = (int*)malloc(sizeof(int)*bp::len(remain_dims));
	for(int i=0; i < bp::len(remain_dims); i++)
		prm.remain_dims[i] = bp::extract<int>(remain_dims[i]);
	prm.newcomm = newcomm;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Cart_sub, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_cart_map
static void pycortex_post_dumpi_cart_map(int thread, dumpi_comm comm, int ndim, const bp::list& dims, const bp::list& period, int newrank) {
	dumpi_cart_map prm;


	prm.comm = comm;
	prm.ndim = ndim;
	if(prm.ndim != bp::len(dims)) ERROR("len(dims) != ndim");
	prm.dims = (int*)malloc(sizeof(int)*bp::len(dims));
	for(int i=0; i < bp::len(dims); i++)
		prm.dims[i] = bp::extract<int>(dims[i]);
	if(prm.ndim != bp::len(period)) ERROR("len(period) != ndim");
	prm.period = (int*)malloc(sizeof(int)*bp::len(period));
	for(int i=0; i < bp::len(period); i++)
		prm.period[i] = bp::extract<int>(period[i]);
	prm.newrank = newrank;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Cart_map, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_graph_map
static void pycortex_post_dumpi_graph_map(int thread, int numedges, dumpi_comm comm, int nodes, const bp::list& index, const bp::list& edges, int newrank) {
	dumpi_graph_map prm;


	prm.numedges = numedges;
	prm.comm = comm;
	prm.nodes = nodes;
	if(prm.nodes != bp::len(index)) ERROR("len(index) != nodes");
	prm.index = (int*)malloc(sizeof(int)*bp::len(index));
	for(int i=0; i < bp::len(index); i++)
		prm.index[i] = bp::extract<int>(index[i]);
	if(prm.numedges != bp::len(edges)) ERROR("len(edges) != numedges");
	prm.edges = (int*)malloc(sizeof(int)*bp::len(edges));
	for(int i=0; i < bp::len(edges); i++)
		prm.edges[i] = bp::extract<int>(edges[i]);
	prm.newrank = newrank;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Graph_map, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_get_processor_name
static void pycortex_post_dumpi_get_processor_name(int thread, const std::string& name, int resultlen) {
	dumpi_get_processor_name prm;


	prm.name = (char*)malloc(sizeof(char)*(name.size()+1));
	strcpy(prm.name,name.c_str());
	prm.resultlen = resultlen;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Get_processor_name, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_get_version
static void pycortex_post_dumpi_get_version(int thread, int version, int subversion) {
	dumpi_get_version prm;


	prm.version = version;
	prm.subversion = subversion;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Get_version, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_errhandler_create
static void pycortex_post_dumpi_errhandler_create(int thread, dumpi_errhandler errhandler) {
	dumpi_errhandler_create prm;


	prm.errhandler = errhandler;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Errhandler_create, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_errhandler_set
static void pycortex_post_dumpi_errhandler_set(int thread, dumpi_comm comm, dumpi_errhandler errhandler) {
	dumpi_errhandler_set prm;


	prm.comm = comm;
	prm.errhandler = errhandler;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Errhandler_set, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_errhandler_get
static void pycortex_post_dumpi_errhandler_get(int thread, dumpi_comm comm, dumpi_errhandler errhandler) {
	dumpi_errhandler_get prm;


	prm.comm = comm;
	prm.errhandler = errhandler;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Errhandler_get, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_errhandler_free
static void pycortex_post_dumpi_errhandler_free(int thread, dumpi_errhandler errhandler) {
	dumpi_errhandler_free prm;


	prm.errhandler = errhandler;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Errhandler_free, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_error_string
static void pycortex_post_dumpi_error_string(int thread, int errorcode, const std::string& errorstring, int resultlen) {
	dumpi_error_string prm;


	prm.errorcode = errorcode;
	prm.errorstring = (char*)malloc(sizeof(char)*(errorstring.size()+1));
	strcpy(prm.errorstring,errorstring.c_str());
	prm.resultlen = resultlen;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Error_string, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_error_class
static void pycortex_post_dumpi_error_class(int thread, int errorcode, int errorclass) {
	dumpi_error_class prm;


	prm.errorcode = errorcode;
	prm.errorclass = errorclass;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Error_class, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_wtime
static void pycortex_post_dumpi_wtime(int thread, uint64_t psec) {
	dumpi_wtime prm;


	prm.psec = psec;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Wtime, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_wtick
static void pycortex_post_dumpi_wtick(int thread, uint64_t psec) {
	dumpi_wtick prm;


	prm.psec = psec;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Wtick, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_init
static void pycortex_post_dumpi_init(int thread, int argc, const bp::list& argv) {
	dumpi_init prm;


	prm.argc = argc;
	if(prm.argc != bp::len(argv)) ERROR("len(argv) != argc");
	prm.argv = (char**)calloc(bp::len(argv)*sizeof(char*),1);
	for(int i=0; i < bp::len(argv); i++) {
		std::string s = bp::extract<std::string>(argv[i]);
		prm.argv[i] = (char*)malloc(sizeof(char)*(s.size()+1));
		strcpy(prm.argv[i], s.c_str());
	}


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Init, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_finalize
static void pycortex_post_dumpi_finalize(int thread, int dummy) {
	dumpi_finalize prm;


	prm.dummy = dummy;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Finalize, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_initialized
static void pycortex_post_dumpi_initialized(int thread, int result) {
	dumpi_initialized prm;


	prm.result = result;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Initialized, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_abort
static void pycortex_post_dumpi_abort(int thread, dumpi_comm comm, int errorcode) {
	dumpi_abort prm;


	prm.comm = comm;
	prm.errorcode = errorcode;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Abort, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_close_port
static void pycortex_post_dumpi_close_port(int thread, const std::string& portname) {
	dumpi_close_port prm;


	prm.portname = (char*)malloc(sizeof(char)*(portname.size()+1));
	strcpy(prm.portname,portname.c_str());


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Close_port, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_comm_accept
static void pycortex_post_dumpi_comm_accept(int thread, const std::string& portname, dumpi_info info, int root, dumpi_comm oldcomm, dumpi_comm newcomm) {
	dumpi_comm_accept prm;


	prm.portname = (char*)malloc(sizeof(char)*(portname.size()+1));
	strcpy(prm.portname,portname.c_str());
	prm.info = info;
	prm.root = root;
	prm.oldcomm = oldcomm;
	prm.newcomm = newcomm;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Comm_accept, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_comm_connect
static void pycortex_post_dumpi_comm_connect(int thread, const std::string& portname, dumpi_info info, int root, dumpi_comm oldcomm, dumpi_comm newcomm) {
	dumpi_comm_connect prm;


	prm.portname = (char*)malloc(sizeof(char)*(portname.size()+1));
	strcpy(prm.portname,portname.c_str());
	prm.info = info;
	prm.root = root;
	prm.oldcomm = oldcomm;
	prm.newcomm = newcomm;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Comm_connect, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_comm_disconnect
static void pycortex_post_dumpi_comm_disconnect(int thread, dumpi_comm comm) {
	dumpi_comm_disconnect prm;


	prm.comm = comm;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Comm_disconnect, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_comm_get_parent
static void pycortex_post_dumpi_comm_get_parent(int thread, dumpi_comm parent) {
	dumpi_comm_get_parent prm;


	prm.parent = parent;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Comm_get_parent, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_comm_join
static void pycortex_post_dumpi_comm_join(int thread, int fd, dumpi_comm comm) {
	dumpi_comm_join prm;


	prm.fd = fd;
	prm.comm = comm;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Comm_join, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_comm_spawn
static void pycortex_post_dumpi_comm_spawn(int thread, int oldcommrank, const std::string& command, const bp::list& argv, int maxprocs, dumpi_info info, int root, dumpi_comm oldcomm, dumpi_comm newcomm, const bp::list& errcodes) {
	dumpi_comm_spawn prm;


	prm.oldcommrank = oldcommrank;
	prm.command = (char*)malloc(sizeof(char)*(command.size()+1));
	strcpy(prm.command,command.c_str());
	prm.argv = (char**)calloc(sizeof(char*)*(bp::len(argv)+1),1);
	for(int i=0; i < bp::len(argv); i++) {
		std::string s = bp::extract<std::string>(argv[i]);
		prm.argv[i] = (char*)malloc(sizeof(char)*(s.size()+1));
		strcpy(prm.argv[i], s.c_str());
	}
	prm.maxprocs = maxprocs;
	prm.info = info;
	prm.root = root;
	prm.oldcomm = oldcomm;
	prm.newcomm = newcomm;
	if(prm.maxprocs != bp::len(errcodes)) ERROR("len(errcodes) != maxprocs");
	prm.errcodes = (int*)malloc(sizeof(int)*bp::len(errcodes));
	for(int i=0; i < bp::len(errcodes); i++)
		prm.errcodes[i] = bp::extract<int>(errcodes[i]);


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Comm_spawn, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_comm_spawn_multiple
static void pycortex_post_dumpi_comm_spawn_multiple(int thread, int totprocs, int oldcommrank, int count, const bp::list& commands, const bp::list& argvs, const bp::list& maxprocs, const bp::list& info, int root, dumpi_comm oldcomm, dumpi_comm newcomm, const bp::list& errcodes) {
	dumpi_comm_spawn_multiple prm;


	prm.totprocs = totprocs;
	prm.oldcommrank = oldcommrank;
	prm.count = count;
	if(prm.count != bp::len(commands)) ERROR("len(commands) != count");
	prm.commands = (char**)calloc(bp::len(commands)*sizeof(char*),1);
	for(int i=0; i < bp::len(commands); i++) {
		std::string s = bp::extract<std::string>(commands[i]);
		prm.commands[i] = (char*)malloc(sizeof(char)*(s.size()+1));
		strcpy(prm.commands[i], s.c_str());
	}

        if(prm.count != bp::len(argvs)) ERROR("len(argvs) != count");
        prm.argvs = (char***)calloc(count*sizeof(char**),1);
	for(int i=0; i < count; i++) {
		bp::list l = bp::extract<bp::list>(argvs[i]);
		prm.argvs[i] = (char**)calloc(sizeof(char*)*(bp::len(l)+1),1);
		for(int j=0; j < bp::len(l); j++) {
			std::string s = bp::extract<std::string>(argvs[i][j]);
			prm.argvs[i][j] = (char*)calloc(sizeof(char)*(s.size()+1),1);
			strcpy(prm.argvs[i][j], s.c_str());
		}
	}

	if(prm.count != bp::len(maxprocs)) ERROR("len(maxprocs) != count");
	prm.maxprocs = (int*)malloc(sizeof(int)*bp::len(maxprocs));
	for(int i=0; i < bp::len(maxprocs); i++)
		prm.maxprocs[i] = bp::extract<int>(maxprocs[i]);
	if(prm.count != bp::len(info)) ERROR("len(info) != count");
	prm.info = (dumpi_info*)malloc(sizeof(dumpi_info)*bp::len(info));
	for(int i=0; i < bp::len(info); i++)
		prm.info[i] = bp::extract<dumpi_info>(info[i]);
	prm.root = root;
	prm.oldcomm = oldcomm;
	prm.newcomm = newcomm;
	prm.errcodes = (int*)malloc(sizeof(int)*bp::len(errcodes));
	for(int i=0; i<bp::len(errcodes); i++) prm.errcodes[i] = bp::extract<int>(errcodes[i]);

	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Comm_spawn_multiple, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_lookup_name
static void pycortex_post_dumpi_lookup_name(int thread, const std::string& servicename, dumpi_info info, const std::string& portname) {
	dumpi_lookup_name prm;


	prm.servicename = (char*)malloc(sizeof(char)*(servicename.size()+1));
	strcpy(prm.servicename,servicename.c_str());
	prm.info = info;
	prm.portname = (char*)malloc(sizeof(char)*(portname.size()+1));
	strcpy(prm.portname,portname.c_str());


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Lookup_name, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_open_port
static void pycortex_post_dumpi_open_port(int thread, dumpi_info info, const std::string& portname) {
	dumpi_open_port prm;


	prm.info = info;
	prm.portname = (char*)malloc(sizeof(char)*(portname.size()+1));
	strcpy(prm.portname,portname.c_str());


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Open_port, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_publish_name
static void pycortex_post_dumpi_publish_name(int thread, const std::string& servicename, dumpi_info info, const std::string& portname) {
	dumpi_publish_name prm;


	prm.servicename = (char*)malloc(sizeof(char)*(servicename.size()+1));
	strcpy(prm.servicename,servicename.c_str());
	prm.info = info;
	prm.portname = (char*)malloc(sizeof(char)*(portname.size()+1));
	strcpy(prm.portname,portname.c_str());


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Publish_name, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_unpublish_name
static void pycortex_post_dumpi_unpublish_name(int thread, const std::string& servicename, dumpi_info info, const std::string& portname) {
	dumpi_unpublish_name prm;


	prm.servicename = (char*)malloc(sizeof(char)*(servicename.size()+1));
	strcpy(prm.servicename,servicename.c_str());
	prm.info = info;
	prm.portname = (char*)malloc(sizeof(char)*(portname.size()+1));
	strcpy(prm.portname,portname.c_str());


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Unpublish_name, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_accumulate
static void pycortex_post_dumpi_accumulate(int thread, int origincount, dumpi_datatype origintype, int targetrank, int targetdisp, int targetcount, dumpi_datatype targettype, dumpi_op op, dumpi_win win) {
	dumpi_accumulate prm;


	prm.origincount = origincount;
	prm.origintype = origintype;
	prm.targetrank = targetrank;
	prm.targetdisp = targetdisp;
	prm.targetcount = targetcount;
	prm.targettype = targettype;
	prm.op = op;
	prm.win = win;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Accumulate, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_get
static void pycortex_post_dumpi_get(int thread, int origincount, dumpi_datatype origintype, int targetrank, int targetdisp, int targetcount, dumpi_datatype targettype, dumpi_win win) {
	dumpi_get prm;


	prm.origincount = origincount;
	prm.origintype = origintype;
	prm.targetrank = targetrank;
	prm.targetdisp = targetdisp;
	prm.targetcount = targetcount;
	prm.targettype = targettype;
	prm.win = win;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Get, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_put
static void pycortex_post_dumpi_put(int thread, int origincount, dumpi_datatype origintype, int targetrank, int targetdisp, int targetcount, dumpi_datatype targettype, dumpi_win win) {
	dumpi_put prm;


	prm.origincount = origincount;
	prm.origintype = origintype;
	prm.targetrank = targetrank;
	prm.targetdisp = targetdisp;
	prm.targetcount = targetcount;
	prm.targettype = targettype;
	prm.win = win;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Put, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_win_complete
static void pycortex_post_dumpi_win_complete(int thread, dumpi_win win) {
	dumpi_win_complete prm;


	prm.win = win;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Win_complete, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_win_create
static void pycortex_post_dumpi_win_create(int thread, int size, int dispunit, dumpi_info info, dumpi_comm comm, dumpi_win win) {
	dumpi_win_create prm;


	prm.size = size;
	prm.dispunit = dispunit;
	prm.info = info;
	prm.comm = comm;
	prm.win = win;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Win_create, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_win_fence
static void pycortex_post_dumpi_win_fence(int thread, int assertion, dumpi_win win) {
	dumpi_win_fence prm;


	prm.assertion = assertion;
	prm.win = win;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Win_fence, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_win_free
static void pycortex_post_dumpi_win_free(int thread, dumpi_win win) {
	dumpi_win_free prm;


	prm.win = win;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Win_free, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_win_get_group
static void pycortex_post_dumpi_win_get_group(int thread, dumpi_win win, dumpi_group group) {
	dumpi_win_get_group prm;


	prm.win = win;
	prm.group = group;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Win_get_group, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_win_lock
static void pycortex_post_dumpi_win_lock(int thread, int locktype, int winrank, int assertion, dumpi_win win) {
	dumpi_win_lock prm;


	prm.locktype = locktype;
	prm.winrank = winrank;
	prm.assertion = assertion;
	prm.win = win;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Win_lock, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_win_post
static void pycortex_post_dumpi_win_post(int thread, dumpi_group group, int assertion, dumpi_win win) {
	dumpi_win_post prm;


	prm.group = group;
	prm.assertion = assertion;
	prm.win = win;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Win_post, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_win_start
static void pycortex_post_dumpi_win_start(int thread, dumpi_group group, int assertion, dumpi_win win) {
	dumpi_win_start prm;


	prm.group = group;
	prm.assertion = assertion;
	prm.win = win;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Win_start, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_win_test
static void pycortex_post_dumpi_win_test(int thread, dumpi_win win, int flag) {
	dumpi_win_test prm;


	prm.win = win;
	prm.flag = flag;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Win_test, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_win_unlock
static void pycortex_post_dumpi_win_unlock(int thread, int winrank, dumpi_win win) {
	dumpi_win_unlock prm;


	prm.winrank = winrank;
	prm.win = win;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Win_unlock, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_win_wait
static void pycortex_post_dumpi_win_wait(int thread, dumpi_win win) {
	dumpi_win_wait prm;


	prm.win = win;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Win_wait, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_alltoallw
static void pycortex_post_dumpi_alltoallw(int thread, int commsize, const bp::list& sendcounts, const bp::list& senddispls, const bp::list& sendtypes, const bp::list& recvcounts, const bp::list& recvdispls, const bp::list& recvtypes, dumpi_comm comm) {
	dumpi_alltoallw prm;


	prm.commsize = commsize;
	if(prm.commsize != bp::len(sendcounts)) ERROR("len(sendcounts) != commsize");
	prm.sendcounts = (int*)malloc(sizeof(int)*bp::len(sendcounts));
	for(int i=0; i < bp::len(sendcounts); i++)
		prm.sendcounts[i] = bp::extract<int>(sendcounts[i]);
	if(prm.commsize != bp::len(senddispls)) ERROR("len(senddispls) != commsize");
	prm.senddispls = (int*)malloc(sizeof(int)*bp::len(senddispls));
	for(int i=0; i < bp::len(senddispls); i++)
		prm.senddispls[i] = bp::extract<int>(senddispls[i]);
	if(prm.commsize != bp::len(sendtypes)) ERROR("len(sendtypes) != commsize");
	prm.sendtypes = (dumpi_datatype*)malloc(sizeof(dumpi_datatype)*bp::len(sendtypes));
	for(int i=0; i < bp::len(sendtypes); i++)
		prm.sendtypes[i] = bp::extract<dumpi_datatype>(sendtypes[i]);
	if(prm.commsize != bp::len(recvcounts)) ERROR("len(recvcounts) != commsize");
	prm.recvcounts = (int*)malloc(sizeof(int)*bp::len(recvcounts));
	for(int i=0; i < bp::len(recvcounts); i++)
		prm.recvcounts[i] = bp::extract<int>(recvcounts[i]);
	if(prm.commsize != bp::len(recvdispls)) ERROR("len(recvdispls) != commsize");
	prm.recvdispls = (int*)malloc(sizeof(int)*bp::len(recvdispls));
	for(int i=0; i < bp::len(recvdispls); i++)
		prm.recvdispls[i] = bp::extract<int>(recvdispls[i]);
	if(prm.commsize != bp::len(recvtypes)) ERROR("len(recvtypes) != commsize");
	prm.recvtypes = (dumpi_datatype*)malloc(sizeof(dumpi_datatype)*bp::len(recvtypes));
	for(int i=0; i < bp::len(recvtypes); i++)
		prm.recvtypes[i] = bp::extract<dumpi_datatype>(recvtypes[i]);
	prm.comm = comm;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Alltoallw, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_exscan
static void pycortex_post_dumpi_exscan(int thread, int count, dumpi_datatype datatype, dumpi_op op, dumpi_comm comm) {
	dumpi_exscan prm;


	prm.count = count;
	prm.datatype = datatype;
	prm.op = op;
	prm.comm = comm;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Exscan, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_add_error_class
static void pycortex_post_dumpi_add_error_class(int thread, int errorclass) {
	dumpi_add_error_class prm;


	prm.errorclass = errorclass;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Add_error_class, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_add_error_code
static void pycortex_post_dumpi_add_error_code(int thread, int errorclass, int errorcode) {
	dumpi_add_error_code prm;


	prm.errorclass = errorclass;
	prm.errorcode = errorcode;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Add_error_code, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_add_error_string
static void pycortex_post_dumpi_add_error_string(int thread, int errorcode, const std::string& errorstring) {
	dumpi_add_error_string prm;


	prm.errorcode = errorcode;
	prm.errorstring = (char*)malloc(sizeof(char)*(errorstring.size()+1));
	strcpy(prm.errorstring,errorstring.c_str());


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Add_error_string, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_comm_call_errhandler
static void pycortex_post_dumpi_comm_call_errhandler(int thread, dumpi_comm comm, int errorcode) {
	dumpi_comm_call_errhandler prm;


	prm.comm = comm;
	prm.errorcode = errorcode;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Comm_call_errhandler, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_comm_create_keyval
static void pycortex_post_dumpi_comm_create_keyval(int thread, int keyval) {
	dumpi_comm_create_keyval prm;


	prm.keyval = keyval;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Comm_create_keyval, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_comm_delete_attr
static void pycortex_post_dumpi_comm_delete_attr(int thread, dumpi_comm comm, int keyval) {
	dumpi_comm_delete_attr prm;


	prm.comm = comm;
	prm.keyval = keyval;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Comm_delete_attr, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_comm_free_keyval
static void pycortex_post_dumpi_comm_free_keyval(int thread, int keyval) {
	dumpi_comm_free_keyval prm;


	prm.keyval = keyval;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Comm_free_keyval, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_comm_get_attr
static void pycortex_post_dumpi_comm_get_attr(int thread, dumpi_comm comm, int keyval, int flag) {
	dumpi_comm_get_attr prm;


	prm.comm = comm;
	prm.keyval = keyval;
	prm.flag = flag;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Comm_get_attr, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_comm_get_name
static void pycortex_post_dumpi_comm_get_name(int thread, dumpi_comm comm, const std::string& name, int resultlen) {
	dumpi_comm_get_name prm;


	prm.comm = comm;
	prm.name = (char*)malloc(sizeof(char)*(name.size()+1));
	strcpy(prm.name,name.c_str());
	prm.resultlen = resultlen;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Comm_get_name, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_comm_set_attr
static void pycortex_post_dumpi_comm_set_attr(int thread, dumpi_comm comm, int keyval) {
	dumpi_comm_set_attr prm;


	prm.comm = comm;
	prm.keyval = keyval;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Comm_set_attr, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_comm_set_name
static void pycortex_post_dumpi_comm_set_name(int thread, dumpi_comm comm, const std::string& name) {
	dumpi_comm_set_name prm;


	prm.comm = comm;
	prm.name = (char*)malloc(sizeof(char)*(name.size()+1));
	strcpy(prm.name,name.c_str());


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Comm_set_name, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_file_call_errhandler
static void pycortex_post_dumpi_file_call_errhandler(int thread, dumpi_file file, int errorcode) {
	dumpi_file_call_errhandler prm;


	prm.file = file;
	prm.errorcode = errorcode;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_File_call_errhandler, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_grequest_complete
static void pycortex_post_dumpi_grequest_complete(int thread, dumpi_request request) {
	dumpi_grequest_complete prm;


	prm.request = request;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Grequest_complete, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_grequest_start
static void pycortex_post_dumpi_grequest_start(int thread, dumpi_request request) {
	dumpi_grequest_start prm;


	prm.request = request;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Grequest_start, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_init_thread
static void pycortex_post_dumpi_init_thread(int thread, int argc, const bp::list& argv, int required, int provided) {
	dumpi_init_thread prm;


	prm.argc = argc;
	if(prm.argc != bp::len(argv)) ERROR("len(argv) != argc");
	prm.argv = (char**)calloc(bp::len(argv)*sizeof(char*),1);
	for(int i=0; i < bp::len(argv); i++) {
		std::string s = bp::extract<std::string>(argv[i]);
		prm.argv[i] = (char*)malloc(sizeof(char)*(s.size()+1));
		strcpy(prm.argv[i], s.c_str());
	}
	prm.required = required;
	prm.provided = provided;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Init_thread, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_is_thread_main
static void pycortex_post_dumpi_is_thread_main(int thread, int flag) {
	dumpi_is_thread_main prm;


	prm.flag = flag;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Is_thread_main, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_query_thread
static void pycortex_post_dumpi_query_thread(int thread, int supported) {
	dumpi_query_thread prm;


	prm.supported = supported;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Query_thread, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_status_set_cancelled
static void pycortex_post_dumpi_status_set_cancelled(int thread,const bp::object& status, int flag) {
	dumpi_status_set_cancelled prm;


	prm.status = (dumpi_status*)malloc(sizeof(dumpi_status));
	*prm.status = bp::extract<dumpi_status>(status);
	prm.flag = flag;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Status_set_cancelled, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_status_set_elements
static void pycortex_post_dumpi_status_set_elements(int thread,const bp::object& status, dumpi_datatype datatype, int count) {
	dumpi_status_set_elements prm;


	prm.status = (dumpi_status*)malloc(sizeof(dumpi_status));
	*prm.status = bp::extract<dumpi_status>(status);
	prm.datatype = datatype;
	prm.count = count;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Status_set_elements, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_type_create_keyval
static void pycortex_post_dumpi_type_create_keyval(int thread, int keyval) {
	dumpi_type_create_keyval prm;


	prm.keyval = keyval;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Type_create_keyval, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_type_delete_attr
static void pycortex_post_dumpi_type_delete_attr(int thread, dumpi_datatype datatype, int keyval) {
	dumpi_type_delete_attr prm;


	prm.datatype = datatype;
	prm.keyval = keyval;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Type_delete_attr, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_type_dup
static void pycortex_post_dumpi_type_dup(int thread, dumpi_datatype oldtype, dumpi_datatype newtype) {
	dumpi_type_dup prm;


	prm.oldtype = oldtype;
	prm.newtype = newtype;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Type_dup, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_type_free_keyval
static void pycortex_post_dumpi_type_free_keyval(int thread, int keyval) {
	dumpi_type_free_keyval prm;


	prm.keyval = keyval;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Type_free_keyval, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_type_get_attr
static void pycortex_post_dumpi_type_get_attr(int thread, dumpi_datatype datatype, int keyval, int flag) {
	dumpi_type_get_attr prm;


	prm.datatype = datatype;
	prm.keyval = keyval;
	prm.flag = flag;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Type_get_attr, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_type_get_contents
static void pycortex_post_dumpi_type_get_contents(int thread, int numdatatypes, int numaddresses, int numintegers, dumpi_datatype datatype, int maxintegers, int maxaddresses, int maxdatatypes, const bp::list& arrintegers, const bp::list& arraddresses, const bp::list& arrdatatypes) {
	dumpi_type_get_contents prm;


	prm.numdatatypes = numdatatypes;
	prm.numaddresses = numaddresses;
	prm.numintegers = numintegers;
	prm.datatype = datatype;
	prm.maxintegers = maxintegers;
	prm.maxaddresses = maxaddresses;
	prm.maxdatatypes = maxdatatypes;
	if(prm.numintegers != bp::len(arrintegers)) ERROR("len(arrintegers) != numintegers");
	prm.arrintegers = (int*)malloc(sizeof(int)*bp::len(arrintegers));
	for(int i=0; i < bp::len(arrintegers); i++)
		prm.arrintegers[i] = bp::extract<int>(arrintegers[i]);
	if(prm.numaddresses != bp::len(arraddresses)) ERROR("len(arraddresses) != numaddresses");
	prm.arraddresses = (int*)malloc(sizeof(int)*bp::len(arraddresses));
	for(int i=0; i < bp::len(arraddresses); i++)
		prm.arraddresses[i] = bp::extract<int>(arraddresses[i]);
	if(prm.numdatatypes != bp::len(arrdatatypes)) ERROR("len(arrdatatypes) != numdatatypes");
	prm.arrdatatypes = (dumpi_datatype*)malloc(sizeof(dumpi_datatype)*bp::len(arrdatatypes));
	for(int i=0; i < bp::len(arrdatatypes); i++)
		prm.arrdatatypes[i] = bp::extract<dumpi_datatype>(arrdatatypes[i]);


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Type_get_contents, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_type_get_envelope
static void pycortex_post_dumpi_type_get_envelope(int thread, dumpi_datatype datatype, int numintegers, int numaddresses, int numdatatypes, int combiner) {
	dumpi_type_get_envelope prm;


	prm.datatype = datatype;
	prm.numintegers = numintegers;
	prm.numaddresses = numaddresses;
	prm.numdatatypes = numdatatypes;
	prm.combiner = combiner;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Type_get_envelope, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_type_get_name
static void pycortex_post_dumpi_type_get_name(int thread, dumpi_datatype datatype, const std::string& name, int resultlen) {
	dumpi_type_get_name prm;


	prm.datatype = datatype;
	prm.name = (char*)malloc(sizeof(char)*(name.size()+1));
	strcpy(prm.name,name.c_str());
	prm.resultlen = resultlen;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Type_get_name, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_type_set_attr
static void pycortex_post_dumpi_type_set_attr(int thread, dumpi_datatype datatype, int keyval) {
	dumpi_type_set_attr prm;


	prm.datatype = datatype;
	prm.keyval = keyval;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Type_set_attr, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_type_set_name
static void pycortex_post_dumpi_type_set_name(int thread, dumpi_datatype datatype, const std::string& name) {
	dumpi_type_set_name prm;


	prm.datatype = datatype;
	prm.name = (char*)malloc(sizeof(char)*(name.size()+1));
	strcpy(prm.name,name.c_str());


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Type_set_name, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_type_match_size
static void pycortex_post_dumpi_type_match_size(int thread, int typeclass, int size, dumpi_datatype datatype) {
	dumpi_type_match_size prm;


	prm.typeclass = typeclass;
	prm.size = size;
	prm.datatype = datatype;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Type_match_size, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_win_call_errhandler
static void pycortex_post_dumpi_win_call_errhandler(int thread, dumpi_win win, int errorcode) {
	dumpi_win_call_errhandler prm;


	prm.win = win;
	prm.errorcode = errorcode;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Win_call_errhandler, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_win_create_keyval
static void pycortex_post_dumpi_win_create_keyval(int thread, int keyval) {
	dumpi_win_create_keyval prm;


	prm.keyval = keyval;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Win_create_keyval, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_win_delete_attr
static void pycortex_post_dumpi_win_delete_attr(int thread, dumpi_win win, int keyval) {
	dumpi_win_delete_attr prm;


	prm.win = win;
	prm.keyval = keyval;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Win_delete_attr, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_win_free_keyval
static void pycortex_post_dumpi_win_free_keyval(int thread, int keyval) {
	dumpi_win_free_keyval prm;


	prm.keyval = keyval;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Win_free_keyval, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_win_get_attr
static void pycortex_post_dumpi_win_get_attr(int thread, dumpi_win win, int keyval, int flag) {
	dumpi_win_get_attr prm;


	prm.win = win;
	prm.keyval = keyval;
	prm.flag = flag;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Win_get_attr, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_win_get_name
static void pycortex_post_dumpi_win_get_name(int thread, dumpi_win win, const std::string& name, int resultlen) {
	dumpi_win_get_name prm;


	prm.win = win;
	prm.name = (char*)malloc(sizeof(char)*(name.size()+1));
	strcpy(prm.name,name.c_str());
	prm.resultlen = resultlen;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Win_get_name, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_win_set_attr
static void pycortex_post_dumpi_win_set_attr(int thread, dumpi_win win, int keyval) {
	dumpi_win_set_attr prm;


	prm.win = win;
	prm.keyval = keyval;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Win_set_attr, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_win_set_name
static void pycortex_post_dumpi_win_set_name(int thread, dumpi_win win, const std::string& name) {
	dumpi_win_set_name prm;


	prm.win = win;
	prm.name = (char*)malloc(sizeof(char)*(name.size()+1));
	strcpy(prm.name,name.c_str());


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Win_set_name, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_alloc_mem
static void pycortex_post_dumpi_alloc_mem(int thread, int size, dumpi_info info) {
	dumpi_alloc_mem prm;


	prm.size = size;
	prm.info = info;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Alloc_mem, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_comm_create_errhandler
static void pycortex_post_dumpi_comm_create_errhandler(int thread, dumpi_errhandler errhandler) {
	dumpi_comm_create_errhandler prm;


	prm.errhandler = errhandler;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Comm_create_errhandler, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_comm_get_errhandler
static void pycortex_post_dumpi_comm_get_errhandler(int thread, dumpi_comm comm, dumpi_errhandler errhandler) {
	dumpi_comm_get_errhandler prm;


	prm.comm = comm;
	prm.errhandler = errhandler;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Comm_get_errhandler, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_comm_set_errhandler
static void pycortex_post_dumpi_comm_set_errhandler(int thread, dumpi_comm comm, dumpi_errhandler errhandler) {
	dumpi_comm_set_errhandler prm;


	prm.comm = comm;
	prm.errhandler = errhandler;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Comm_set_errhandler, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_file_create_errhandler
static void pycortex_post_dumpi_file_create_errhandler(int thread, dumpi_errhandler errhandler) {
	dumpi_file_create_errhandler prm;


	prm.errhandler = errhandler;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_File_create_errhandler, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_file_get_errhandler
static void pycortex_post_dumpi_file_get_errhandler(int thread, dumpi_file file, dumpi_errhandler errhandler) {
	dumpi_file_get_errhandler prm;


	prm.file = file;
	prm.errhandler = errhandler;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_File_get_errhandler, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_file_set_errhandler
static void pycortex_post_dumpi_file_set_errhandler(int thread, dumpi_file file, dumpi_errhandler errhandler) {
	dumpi_file_set_errhandler prm;


	prm.file = file;
	prm.errhandler = errhandler;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_File_set_errhandler, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_finalized
static void pycortex_post_dumpi_finalized(int thread, int flag) {
	dumpi_finalized prm;


	prm.flag = flag;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Finalized, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_free_mem
static void pycortex_post_dumpi_free_mem(int thread, int dummy) {
	dumpi_free_mem prm;


	prm.dummy = dummy;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Free_mem, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_get_address
static void pycortex_post_dumpi_get_address(int thread, int address) {
	dumpi_get_address prm;


	prm.address = address;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Get_address, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_info_create
static void pycortex_post_dumpi_info_create(int thread, dumpi_info info) {
	dumpi_info_create prm;


	prm.info = info;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Info_create, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_info_delete
static void pycortex_post_dumpi_info_delete(int thread, dumpi_info info, const std::string& key) {
	dumpi_info_delete prm;


	prm.info = info;
	prm.key = (char*)malloc(sizeof(char)*(key.size()+1));
	strcpy(prm.key,key.c_str());


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Info_delete, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_info_dup
static void pycortex_post_dumpi_info_dup(int thread, dumpi_info oldinfo, dumpi_info newinfo) {
	dumpi_info_dup prm;


	prm.oldinfo = oldinfo;
	prm.newinfo = newinfo;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Info_dup, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_info_free
static void pycortex_post_dumpi_info_free(int thread, dumpi_info info) {
	dumpi_info_free prm;


	prm.info = info;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Info_free, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_info_get
static void pycortex_post_dumpi_info_get(int thread, dumpi_info info, const std::string& key, int valuelength, const std::string& value, int flag) {
	dumpi_info_get prm;


	prm.info = info;
	prm.key = (char*)malloc(sizeof(char)*(key.size()+1));
	strcpy(prm.key,key.c_str());
	prm.valuelength = valuelength;
	prm.value = (char*)malloc(sizeof(char)*(value.size()+1));
	strcpy(prm.value,value.c_str());
	prm.flag = flag;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Info_get, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_info_get_nkeys
static void pycortex_post_dumpi_info_get_nkeys(int thread, dumpi_info info, int nkeys) {
	dumpi_info_get_nkeys prm;


	prm.info = info;
	prm.nkeys = nkeys;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Info_get_nkeys, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_info_get_nthkey
static void pycortex_post_dumpi_info_get_nthkey(int thread, dumpi_info info, int n, const std::string& key) {
	dumpi_info_get_nthkey prm;


	prm.info = info;
	prm.n = n;
	prm.key = (char*)malloc(sizeof(char)*(key.size()+1));
	strcpy(prm.key,key.c_str());


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Info_get_nthkey, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_info_get_valuelen
static void pycortex_post_dumpi_info_get_valuelen(int thread, dumpi_info info, const std::string& key, int valuelen, int flag) {
	dumpi_info_get_valuelen prm;


	prm.info = info;
	prm.key = (char*)malloc(sizeof(char)*(key.size()+1));
	strcpy(prm.key,key.c_str());
	prm.valuelen = valuelen;
	prm.flag = flag;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Info_get_valuelen, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_info_set
static void pycortex_post_dumpi_info_set(int thread, dumpi_info info, const std::string& key, const std::string& value) {
	dumpi_info_set prm;


	prm.info = info;
	prm.key = (char*)malloc(sizeof(char)*(key.size()+1));
	strcpy(prm.key,key.c_str());
	prm.value = (char*)malloc(sizeof(char)*(value.size()+1));
	strcpy(prm.value,value.c_str());


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Info_set, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_pack_external
static void pycortex_post_dumpi_pack_external(int thread, const std::string& datarep, int incount, dumpi_datatype intype, int outcount, const bp::dict& position) {
	dumpi_pack_external prm;


	prm.datarep = (char*)malloc(sizeof(char)*(datarep.size()+1));
	strcpy(prm.datarep,datarep.c_str());
	prm.incount = incount;
	prm.intype = intype;
	prm.outcount = outcount;
	prm.position.in = bp::extract<int>(position["in"]);
	prm.position.out = bp::extract<int>(position["out"]);

	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Pack_external, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_pack_external_size
static void pycortex_post_dumpi_pack_external_size(int thread, const std::string& datarep, int incount, dumpi_datatype datatype, int size) {
	dumpi_pack_external_size prm;


	prm.datarep = (char*)malloc(sizeof(char)*(datarep.size()+1));
	strcpy(prm.datarep,datarep.c_str());
	prm.incount = incount;
	prm.datatype = datatype;
	prm.size = size;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Pack_external_size, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_request_get_status
static void pycortex_post_dumpi_request_get_status(int thread, dumpi_request request, int flag,const bp::object& status) {
	dumpi_request_get_status prm;


	prm.request = request;
	prm.flag = flag;
	prm.status = (dumpi_status*)malloc(sizeof(dumpi_status));
	*prm.status = bp::extract<dumpi_status>(status);


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Request_get_status, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_type_create_darray
static void pycortex_post_dumpi_type_create_darray(int thread, int size, int rank, int ndims, const bp::list& gsizes, const bp::list& distribs, const bp::list& dargs, const bp::list& psizes, int order, dumpi_datatype oldtype, dumpi_datatype newtype) {
	dumpi_type_create_darray prm;


	prm.size = size;
	prm.rank = rank;
	prm.ndims = ndims;
	if(prm.ndims != bp::len(gsizes)) ERROR("len(gsizes) != ndims");
	prm.gsizes = (int*)malloc(sizeof(int)*bp::len(gsizes));
	for(int i=0; i < bp::len(gsizes); i++)
		prm.gsizes[i] = bp::extract<int>(gsizes[i]);
	if(prm.ndims != bp::len(distribs)) ERROR("len(distribs) != ndims");
	prm.distribs = (dumpi_distribution*)malloc(sizeof(dumpi_distribution)*bp::len(distribs));
	for(int i=0; i < bp::len(distribs); i++)
		prm.distribs[i] = bp::extract<dumpi_distribution>(distribs[i]);
	if(prm.ndims != bp::len(dargs)) ERROR("len(dargs) != ndims");
	prm.dargs = (int*)malloc(sizeof(int)*bp::len(dargs));
	for(int i=0; i < bp::len(dargs); i++)
		prm.dargs[i] = bp::extract<int>(dargs[i]);
	if(prm.ndims != bp::len(psizes)) ERROR("len(psizes) != ndims");
	prm.psizes = (int*)malloc(sizeof(int)*bp::len(psizes));
	for(int i=0; i < bp::len(psizes); i++)
		prm.psizes[i] = bp::extract<int>(psizes[i]);
	prm.order = order;
	prm.oldtype = oldtype;
	prm.newtype = newtype;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Type_create_darray, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_type_create_hindexed
static void pycortex_post_dumpi_type_create_hindexed(int thread, int count, const bp::list& blocklengths, const bp::list& displacements, dumpi_datatype oldtype, dumpi_datatype newtype) {
	dumpi_type_create_hindexed prm;


	prm.count = count;
	if(prm.count != bp::len(blocklengths)) ERROR("len(blocklengths) != count");
	prm.blocklengths = (int*)malloc(sizeof(int)*bp::len(blocklengths));
	for(int i=0; i < bp::len(blocklengths); i++)
		prm.blocklengths[i] = bp::extract<int>(blocklengths[i]);
	if(prm.count != bp::len(displacements)) ERROR("len(displacements) != count");
	prm.displacements = (int*)malloc(sizeof(int)*bp::len(displacements));
	for(int i=0; i < bp::len(displacements); i++)
		prm.displacements[i] = bp::extract<int>(displacements[i]);
	prm.oldtype = oldtype;
	prm.newtype = newtype;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Type_create_hindexed, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_type_create_hvector
static void pycortex_post_dumpi_type_create_hvector(int thread, int count, int blocklength, int stride, dumpi_datatype oldtype, dumpi_datatype newtype) {
	dumpi_type_create_hvector prm;


	prm.count = count;
	prm.blocklength = blocklength;
	prm.stride = stride;
	prm.oldtype = oldtype;
	prm.newtype = newtype;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Type_create_hvector, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_type_create_indexed_block
static void pycortex_post_dumpi_type_create_indexed_block(int thread, int count, int blocklength, const bp::list& displacments, dumpi_datatype oldtype, dumpi_datatype newtype) {
	dumpi_type_create_indexed_block prm;


	prm.count = count;
	prm.blocklength = blocklength;
	if(prm.count != bp::len(displacments)) ERROR("len(displacments) != count");
	prm.displacments = (int*)malloc(sizeof(int)*bp::len(displacments));
	for(int i=0; i < bp::len(displacments); i++)
		prm.displacments[i] = bp::extract<int>(displacments[i]);
	prm.oldtype = oldtype;
	prm.newtype = newtype;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Type_create_indexed_block, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_type_create_resized
static void pycortex_post_dumpi_type_create_resized(int thread, dumpi_datatype oldtype, int lb, int extent, dumpi_datatype newtype) {
	dumpi_type_create_resized prm;


	prm.oldtype = oldtype;
	prm.lb = lb;
	prm.extent = extent;
	prm.newtype = newtype;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Type_create_resized, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_type_create_struct
static void pycortex_post_dumpi_type_create_struct(int thread, int count, const bp::list& blocklengths, const bp::list& displacements, const bp::list& oldtypes, dumpi_datatype newtype) {
	dumpi_type_create_struct prm;


	prm.count = count;
	if(prm.count != bp::len(blocklengths)) ERROR("len(blocklengths) != count");
	prm.blocklengths = (int*)malloc(sizeof(int)*bp::len(blocklengths));
	for(int i=0; i < bp::len(blocklengths); i++)
		prm.blocklengths[i] = bp::extract<int>(blocklengths[i]);
	if(prm.count != bp::len(displacements)) ERROR("len(displacements) != count");
	prm.displacements = (int*)malloc(sizeof(int)*bp::len(displacements));
	for(int i=0; i < bp::len(displacements); i++)
		prm.displacements[i] = bp::extract<int>(displacements[i]);
	if(prm.count != bp::len(oldtypes)) ERROR("len(oldtypes) != count");
	prm.oldtypes = (dumpi_datatype*)malloc(sizeof(dumpi_datatype)*bp::len(oldtypes));
	for(int i=0; i < bp::len(oldtypes); i++)
		prm.oldtypes[i] = bp::extract<dumpi_datatype>(oldtypes[i]);
	prm.newtype = newtype;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Type_create_struct, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_type_create_subarray
static void pycortex_post_dumpi_type_create_subarray(int thread, int ndims, const bp::list& sizes, const bp::list& subsizes, const bp::list& starts, int order, dumpi_datatype oldtype, dumpi_datatype newtype) {
	dumpi_type_create_subarray prm;


	prm.ndims = ndims;
	if(prm.ndims != bp::len(sizes)) ERROR("len(sizes) != ndims");
	prm.sizes = (int*)malloc(sizeof(int)*bp::len(sizes));
	for(int i=0; i < bp::len(sizes); i++)
		prm.sizes[i] = bp::extract<int>(sizes[i]);
	if(prm.ndims != bp::len(subsizes)) ERROR("len(subsizes) != ndims");
	prm.subsizes = (int*)malloc(sizeof(int)*bp::len(subsizes));
	for(int i=0; i < bp::len(subsizes); i++)
		prm.subsizes[i] = bp::extract<int>(subsizes[i]);
	if(prm.ndims != bp::len(starts)) ERROR("len(starts) != ndims");
	prm.starts = (int*)malloc(sizeof(int)*bp::len(starts));
	for(int i=0; i < bp::len(starts); i++)
		prm.starts[i] = bp::extract<int>(starts[i]);
	prm.order = order;
	prm.oldtype = oldtype;
	prm.newtype = newtype;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Type_create_subarray, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_type_get_extent
static void pycortex_post_dumpi_type_get_extent(int thread, dumpi_datatype datatype, int lb, int extent) {
	dumpi_type_get_extent prm;


	prm.datatype = datatype;
	prm.lb = lb;
	prm.extent = extent;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Type_get_extent, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_type_get_true_extent
static void pycortex_post_dumpi_type_get_true_extent(int thread, dumpi_datatype datatype, int lb, int extent) {
	dumpi_type_get_true_extent prm;


	prm.datatype = datatype;
	prm.lb = lb;
	prm.extent = extent;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Type_get_true_extent, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_unpack_external
static void pycortex_post_dumpi_unpack_external(int thread, const std::string& datarep, int insize, const bp::dict& position, int outcount, dumpi_datatype datatype) {
	dumpi_unpack_external prm;


	prm.datarep = (char*)malloc(sizeof(char)*(datarep.size()+1));
	strcpy(prm.datarep,datarep.c_str());
	prm.insize = insize;
	prm.position.in = bp::extract<int>(position["in"]);
	prm.position.out = bp::extract<int>(position["out"]);
	prm.outcount = outcount;
	prm.datatype = datatype;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Unpack_external, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_win_create_errhandler
static void pycortex_post_dumpi_win_create_errhandler(int thread, dumpi_errhandler errhandler) {
	dumpi_win_create_errhandler prm;


	prm.errhandler = errhandler;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Win_create_errhandler, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_win_get_errhandler
static void pycortex_post_dumpi_win_get_errhandler(int thread, dumpi_win win, dumpi_errhandler errhandler) {
	dumpi_win_get_errhandler prm;


	prm.win = win;
	prm.errhandler = errhandler;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Win_get_errhandler, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_win_set_errhandler
static void pycortex_post_dumpi_win_set_errhandler(int thread, dumpi_win win, dumpi_errhandler errhandler) {
	dumpi_win_set_errhandler prm;


	prm.win = win;
	prm.errhandler = errhandler;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Win_set_errhandler, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_file_open
static void pycortex_post_dumpi_file_open(int thread, dumpi_comm comm, const std::string& filename, int amode, dumpi_info info, dumpi_file file) {
	dumpi_file_open prm;


	prm.comm = comm;
	prm.filename = (char*)malloc(sizeof(char)*(filename.size()+1));
	strcpy(prm.filename,filename.c_str());
	prm.amode = amode;
	prm.info = info;
	prm.file = file;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_File_open, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_file_close
static void pycortex_post_dumpi_file_close(int thread, dumpi_file file) {
	dumpi_file_close prm;


	prm.file = file;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_File_close, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_file_delete
static void pycortex_post_dumpi_file_delete(int thread, const std::string& filename, dumpi_info info) {
	dumpi_file_delete prm;


	prm.filename = (char*)malloc(sizeof(char)*(filename.size()+1));
	strcpy(prm.filename,filename.c_str());
	prm.info = info;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_File_delete, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_file_set_size
static void pycortex_post_dumpi_file_set_size(int thread, dumpi_file file, int64_t size) {
	dumpi_file_set_size prm;


	prm.file = file;
	prm.size = size;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_File_set_size, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_file_preallocate
static void pycortex_post_dumpi_file_preallocate(int thread, dumpi_file file, int64_t size) {
	dumpi_file_preallocate prm;


	prm.file = file;
	prm.size = size;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_File_preallocate, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_file_get_size
static void pycortex_post_dumpi_file_get_size(int thread, dumpi_file file, int64_t size) {
	dumpi_file_get_size prm;


	prm.file = file;
	prm.size = size;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_File_get_size, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_file_get_group
static void pycortex_post_dumpi_file_get_group(int thread, dumpi_file file, dumpi_group group) {
	dumpi_file_get_group prm;


	prm.file = file;
	prm.group = group;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_File_get_group, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_file_get_amode
static void pycortex_post_dumpi_file_get_amode(int thread, dumpi_file file, int amode) {
	dumpi_file_get_amode prm;


	prm.file = file;
	prm.amode = amode;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_File_get_amode, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_file_set_info
static void pycortex_post_dumpi_file_set_info(int thread, dumpi_file file, dumpi_info info) {
	dumpi_file_set_info prm;


	prm.file = file;
	prm.info = info;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_File_set_info, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_file_get_info
static void pycortex_post_dumpi_file_get_info(int thread, dumpi_file file, dumpi_info info) {
	dumpi_file_get_info prm;


	prm.file = file;
	prm.info = info;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_File_get_info, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_file_set_view
static void pycortex_post_dumpi_file_set_view(int thread, dumpi_file file, int64_t offset, dumpi_datatype hosttype, dumpi_datatype filetype, const std::string& datarep, dumpi_info info) {
	dumpi_file_set_view prm;


	prm.file = file;
	prm.offset = offset;
	prm.hosttype = hosttype;
	prm.filetype = filetype;
	prm.datarep = (char*)malloc(sizeof(char)*(datarep.size()+1));
	strcpy(prm.datarep,datarep.c_str());
	prm.info = info;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_File_set_view, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_file_get_view
static void pycortex_post_dumpi_file_get_view(int thread, dumpi_file file, int64_t offset, dumpi_datatype hosttype, dumpi_datatype filetype, const std::string& datarep) {
	dumpi_file_get_view prm;


	prm.file = file;
	prm.offset = offset;
	prm.hosttype = hosttype;
	prm.filetype = filetype;
	prm.datarep = (char*)malloc(sizeof(char)*(datarep.size()+1));
	strcpy(prm.datarep,datarep.c_str());


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_File_get_view, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_file_read_at
static void pycortex_post_dumpi_file_read_at(int thread, dumpi_file file, int64_t offset, int count, dumpi_datatype datatype,const bp::object& status) {
	dumpi_file_read_at prm;


	prm.file = file;
	prm.offset = offset;
	prm.count = count;
	prm.datatype = datatype;
	prm.status = (dumpi_status*)malloc(sizeof(dumpi_status));
	*prm.status = bp::extract<dumpi_status>(status);


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_File_read_at, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_file_read_at_all
static void pycortex_post_dumpi_file_read_at_all(int thread, dumpi_file file, int64_t offset, int count, dumpi_datatype datatype,const bp::object& status) {
	dumpi_file_read_at_all prm;


	prm.file = file;
	prm.offset = offset;
	prm.count = count;
	prm.datatype = datatype;
	prm.status = (dumpi_status*)malloc(sizeof(dumpi_status));
	*prm.status = bp::extract<dumpi_status>(status);


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_File_read_at_all, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_file_write_at
static void pycortex_post_dumpi_file_write_at(int thread, dumpi_file file, int64_t offset, int count, dumpi_datatype datatype,const bp::object& status) {
	dumpi_file_write_at prm;


	prm.file = file;
	prm.offset = offset;
	prm.count = count;
	prm.datatype = datatype;
	prm.status = (dumpi_status*)malloc(sizeof(dumpi_status));
	*prm.status = bp::extract<dumpi_status>(status);


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_File_write_at, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_file_write_at_all
static void pycortex_post_dumpi_file_write_at_all(int thread, dumpi_file file, int64_t offset, int count, dumpi_datatype datatype,const bp::object& status) {
	dumpi_file_write_at_all prm;


	prm.file = file;
	prm.offset = offset;
	prm.count = count;
	prm.datatype = datatype;
	prm.status = (dumpi_status*)malloc(sizeof(dumpi_status));
	*prm.status = bp::extract<dumpi_status>(status);


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_File_write_at_all, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_file_iread_at
static void pycortex_post_dumpi_file_iread_at(int thread, dumpi_file file, int64_t offset, int count, dumpi_datatype datatype, dumpio_request request) {
	dumpi_file_iread_at prm;


	prm.file = file;
	prm.offset = offset;
	prm.count = count;
	prm.datatype = datatype;
	prm.request = request;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_File_iread_at, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_file_iwrite_at
static void pycortex_post_dumpi_file_iwrite_at(int thread, dumpi_file file, int64_t offset, int count, dumpi_datatype datatype, dumpio_request request) {
	dumpi_file_iwrite_at prm;


	prm.file = file;
	prm.offset = offset;
	prm.count = count;
	prm.datatype = datatype;
	prm.request = request;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_File_iwrite_at, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_file_read
static void pycortex_post_dumpi_file_read(int thread, dumpi_file file, int count, dumpi_datatype datatype,const bp::object& status) {
	dumpi_file_read prm;


	prm.file = file;
	prm.count = count;
	prm.datatype = datatype;
	prm.status = (dumpi_status*)malloc(sizeof(dumpi_status));
	*prm.status = bp::extract<dumpi_status>(status);


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_File_read, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_file_read_all
static void pycortex_post_dumpi_file_read_all(int thread, dumpi_file file, int count, dumpi_datatype datatype,const bp::object& status) {
	dumpi_file_read_all prm;


	prm.file = file;
	prm.count = count;
	prm.datatype = datatype;
	prm.status = (dumpi_status*)malloc(sizeof(dumpi_status));
	*prm.status = bp::extract<dumpi_status>(status);


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_File_read_all, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_file_write
static void pycortex_post_dumpi_file_write(int thread, dumpi_file file, int count, dumpi_datatype datatype,const bp::object& status) {
	dumpi_file_write prm;


	prm.file = file;
	prm.count = count;
	prm.datatype = datatype;
	prm.status = (dumpi_status*)malloc(sizeof(dumpi_status));
	*prm.status = bp::extract<dumpi_status>(status);


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_File_write, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_file_write_all
static void pycortex_post_dumpi_file_write_all(int thread, dumpi_file file, int count, dumpi_datatype datatype,const bp::object& status) {
	dumpi_file_write_all prm;


	prm.file = file;
	prm.count = count;
	prm.datatype = datatype;
	prm.status = (dumpi_status*)malloc(sizeof(dumpi_status));
	*prm.status = bp::extract<dumpi_status>(status);


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_File_write_all, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_file_iread
static void pycortex_post_dumpi_file_iread(int thread, dumpi_file file, int count, dumpi_datatype datatype, dumpio_request request) {
	dumpi_file_iread prm;


	prm.file = file;
	prm.count = count;
	prm.datatype = datatype;
	prm.request = request;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_File_iread, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_file_iwrite
static void pycortex_post_dumpi_file_iwrite(int thread, dumpi_file file, int count, dumpi_datatype datatype, dumpio_request request) {
	dumpi_file_iwrite prm;


	prm.file = file;
	prm.count = count;
	prm.datatype = datatype;
	prm.request = request;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_File_iwrite, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_file_seek
static void pycortex_post_dumpi_file_seek(int thread, dumpi_file file, int64_t offset, int whence) {
	dumpi_file_seek prm;


	prm.file = file;
	prm.offset = offset;
	prm.whence = whence;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_File_seek, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_file_get_position
static void pycortex_post_dumpi_file_get_position(int thread, dumpi_file file, int64_t offset) {
	dumpi_file_get_position prm;


	prm.file = file;
	prm.offset = offset;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_File_get_position, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_file_get_byte_offset
static void pycortex_post_dumpi_file_get_byte_offset(int thread, dumpi_file file, int64_t offset, int64_t bytes) {
	dumpi_file_get_byte_offset prm;


	prm.file = file;
	prm.offset = offset;
	prm.bytes = bytes;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_File_get_byte_offset, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_file_read_shared
static void pycortex_post_dumpi_file_read_shared(int thread, dumpi_file file, int count, dumpi_datatype datatype,const bp::object& status) {
	dumpi_file_read_shared prm;


	prm.file = file;
	prm.count = count;
	prm.datatype = datatype;
	prm.status = (dumpi_status*)malloc(sizeof(dumpi_status));
	*prm.status = bp::extract<dumpi_status>(status);


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_File_read_shared, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_file_write_shared
static void pycortex_post_dumpi_file_write_shared(int thread, dumpi_file file, int count, dumpi_datatype datatype,const bp::object& status) {
	dumpi_file_write_shared prm;


	prm.file = file;
	prm.count = count;
	prm.datatype = datatype;
	prm.status = (dumpi_status*)malloc(sizeof(dumpi_status));
	*prm.status = bp::extract<dumpi_status>(status);


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_File_write_shared, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_file_iread_shared
static void pycortex_post_dumpi_file_iread_shared(int thread, dumpi_file file, int count, dumpi_datatype datatype, dumpio_request request) {
	dumpi_file_iread_shared prm;


	prm.file = file;
	prm.count = count;
	prm.datatype = datatype;
	prm.request = request;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_File_iread_shared, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_file_iwrite_shared
static void pycortex_post_dumpi_file_iwrite_shared(int thread, dumpi_file file, int count, dumpi_datatype datatype, dumpio_request request) {
	dumpi_file_iwrite_shared prm;


	prm.file = file;
	prm.count = count;
	prm.datatype = datatype;
	prm.request = request;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_File_iwrite_shared, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_file_read_ordered
static void pycortex_post_dumpi_file_read_ordered(int thread, dumpi_file file, int count, dumpi_datatype datatype,const bp::object& status) {
	dumpi_file_read_ordered prm;


	prm.file = file;
	prm.count = count;
	prm.datatype = datatype;
	prm.status = (dumpi_status*)malloc(sizeof(dumpi_status));
	*prm.status = bp::extract<dumpi_status>(status);


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_File_read_ordered, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_file_write_ordered
static void pycortex_post_dumpi_file_write_ordered(int thread, dumpi_file file, int count, dumpi_datatype datatype,const bp::object& status) {
	dumpi_file_write_ordered prm;


	prm.file = file;
	prm.count = count;
	prm.datatype = datatype;
	prm.status = (dumpi_status*)malloc(sizeof(dumpi_status));
	*prm.status = bp::extract<dumpi_status>(status);


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_File_write_ordered, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_file_seek_shared
static void pycortex_post_dumpi_file_seek_shared(int thread, dumpi_file file, int64_t offset, int whence) {
	dumpi_file_seek_shared prm;


	prm.file = file;
	prm.offset = offset;
	prm.whence = whence;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_File_seek_shared, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_file_get_position_shared
static void pycortex_post_dumpi_file_get_position_shared(int thread, dumpi_file file, int64_t offset) {
	dumpi_file_get_position_shared prm;


	prm.file = file;
	prm.offset = offset;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_File_get_position_shared, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_file_read_at_all_begin
static void pycortex_post_dumpi_file_read_at_all_begin(int thread, dumpi_file file, int64_t offset, int count, dumpi_datatype datatype) {
	dumpi_file_read_at_all_begin prm;


	prm.file = file;
	prm.offset = offset;
	prm.count = count;
	prm.datatype = datatype;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_File_read_at_all_begin, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_file_read_at_all_end
static void pycortex_post_dumpi_file_read_at_all_end(int thread, dumpi_file file,const bp::object& status) {
	dumpi_file_read_at_all_end prm;


	prm.file = file;
	prm.status = (dumpi_status*)malloc(sizeof(dumpi_status));
	*prm.status = bp::extract<dumpi_status>(status);


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_File_read_at_all_end, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_file_write_at_all_begin
static void pycortex_post_dumpi_file_write_at_all_begin(int thread, dumpi_file file, int64_t offset, int count, dumpi_datatype datatype) {
	dumpi_file_write_at_all_begin prm;


	prm.file = file;
	prm.offset = offset;
	prm.count = count;
	prm.datatype = datatype;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_File_write_at_all_begin, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_file_write_at_all_end
static void pycortex_post_dumpi_file_write_at_all_end(int thread, dumpi_file file,const bp::object& status) {
	dumpi_file_write_at_all_end prm;


	prm.file = file;
	prm.status = (dumpi_status*)malloc(sizeof(dumpi_status));
	*prm.status = bp::extract<dumpi_status>(status);


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_File_write_at_all_end, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_file_read_all_begin
static void pycortex_post_dumpi_file_read_all_begin(int thread, dumpi_file file, int count, dumpi_datatype datatype) {
	dumpi_file_read_all_begin prm;


	prm.file = file;
	prm.count = count;
	prm.datatype = datatype;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_File_read_all_begin, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_file_read_all_end
static void pycortex_post_dumpi_file_read_all_end(int thread, dumpi_file file,const bp::object& status) {
	dumpi_file_read_all_end prm;


	prm.file = file;
	prm.status = (dumpi_status*)malloc(sizeof(dumpi_status));
	*prm.status = bp::extract<dumpi_status>(status);


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_File_read_all_end, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_file_write_all_begin
static void pycortex_post_dumpi_file_write_all_begin(int thread, dumpi_file file, int count, dumpi_datatype datatype) {
	dumpi_file_write_all_begin prm;


	prm.file = file;
	prm.count = count;
	prm.datatype = datatype;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_File_write_all_begin, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_file_write_all_end
static void pycortex_post_dumpi_file_write_all_end(int thread, dumpi_file file,const bp::object& status) {
	dumpi_file_write_all_end prm;


	prm.file = file;
	prm.status = (dumpi_status*)malloc(sizeof(dumpi_status));
	*prm.status = bp::extract<dumpi_status>(status);


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_File_write_all_end, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_file_read_ordered_begin
static void pycortex_post_dumpi_file_read_ordered_begin(int thread, dumpi_file file, int count, dumpi_datatype datatype) {
	dumpi_file_read_ordered_begin prm;


	prm.file = file;
	prm.count = count;
	prm.datatype = datatype;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_File_read_ordered_begin, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_file_read_ordered_end
static void pycortex_post_dumpi_file_read_ordered_end(int thread, dumpi_file file,const bp::object& status) {
	dumpi_file_read_ordered_end prm;


	prm.file = file;
	prm.status = (dumpi_status*)malloc(sizeof(dumpi_status));
	*prm.status = bp::extract<dumpi_status>(status);


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_File_read_ordered_end, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_file_write_ordered_begin
static void pycortex_post_dumpi_file_write_ordered_begin(int thread, dumpi_file file, int count, dumpi_datatype datatype) {
	dumpi_file_write_ordered_begin prm;


	prm.file = file;
	prm.count = count;
	prm.datatype = datatype;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_File_write_ordered_begin, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_file_write_ordered_end
static void pycortex_post_dumpi_file_write_ordered_end(int thread, dumpi_file file,const bp::object& status) {
	dumpi_file_write_ordered_end prm;


	prm.file = file;
	prm.status = (dumpi_status*)malloc(sizeof(dumpi_status));
	*prm.status = bp::extract<dumpi_status>(status);


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_File_write_ordered_end, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_file_get_type_extent
static void pycortex_post_dumpi_file_get_type_extent(int thread, dumpi_file file, dumpi_datatype datatype, int extent) {
	dumpi_file_get_type_extent prm;


	prm.file = file;
	prm.datatype = datatype;
	prm.extent = extent;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_File_get_type_extent, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_register_datarep
static void pycortex_post_dumpi_register_datarep(int thread, const std::string& name) {
	dumpi_register_datarep prm;


	prm.name = (char*)malloc(sizeof(char)*(name.size()+1));
	strcpy(prm.name,name.c_str());


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_Register_datarep, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_file_set_atomicity
static void pycortex_post_dumpi_file_set_atomicity(int thread, dumpi_file file, int flag) {
	dumpi_file_set_atomicity prm;


	prm.file = file;
	prm.flag = flag;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_File_set_atomicity, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_file_get_atomicity
static void pycortex_post_dumpi_file_get_atomicity(int thread, dumpi_file file, int flag) {
	dumpi_file_get_atomicity prm;


	prm.file = file;
	prm.flag = flag;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_File_get_atomicity, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpi_file_sync
static void pycortex_post_dumpi_file_sync(int thread, dumpi_file file) {
	dumpi_file_sync prm;


	prm.file = file;


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPI_File_sync, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpio_test
static void pycortex_post_dumpio_test(int thread, dumpio_request request, int flag,const bp::object& status) {
	dumpio_test prm;


	prm.request = request;
	prm.flag = flag;
	prm.status = (dumpi_status*)malloc(sizeof(dumpi_status));
	*prm.status = bp::extract<dumpi_status>(status);


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPIO_Test, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpio_wait
static void pycortex_post_dumpio_wait(int thread, dumpio_request request,const bp::object& status) {
	dumpio_wait prm;


	prm.request = request;
	prm.status = (dumpi_status*)malloc(sizeof(dumpi_status));
	*prm.status = bp::extract<dumpi_status>(status);


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPIO_Wait, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpio_testall
static void pycortex_post_dumpio_testall(int thread, int count, const bp::list& requests, int flag, const bp::list& statuses) {
	dumpio_testall prm;


	prm.count = count;
	if(prm.count != bp::len(requests)) ERROR("len(requests) != count");
	prm.requests = (dumpio_request*)malloc(sizeof(dumpio_request)*bp::len(requests));
	for(int i=0; i < bp::len(requests); i++)
		prm.requests[i] = bp::extract<dumpio_request>(requests[i]);
	prm.flag = flag;
	if(prm.count != bp::len(statuses)) ERROR("len(statuses) != count");
	prm.statuses = (dumpi_status*)malloc(sizeof(dumpi_status)*bp::len(statuses));
	for(int i=0; i < bp::len(statuses); i++)
		prm.statuses[i] = bp::extract<dumpi_status>(statuses[i]);


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPIO_Testall, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpio_waitall
static void pycortex_post_dumpio_waitall(int thread, int count, const bp::list& requests, const bp::list& statuses) {
	dumpio_waitall prm;


	prm.count = count;
	if(prm.count != bp::len(requests)) ERROR("len(requests) != count");
	prm.requests = (dumpio_request*)malloc(sizeof(dumpio_request)*bp::len(requests));
	for(int i=0; i < bp::len(requests); i++)
		prm.requests[i] = bp::extract<dumpio_request>(requests[i]);
	if(prm.count != bp::len(statuses)) ERROR("len(statuses) != count");
	prm.statuses = (dumpi_status*)malloc(sizeof(dumpi_status)*bp::len(statuses));
	for(int i=0; i < bp::len(statuses); i++)
		prm.statuses[i] = bp::extract<dumpi_status>(statuses[i]);


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPIO_Waitall, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpio_testany
static void pycortex_post_dumpio_testany(int thread, int count, const bp::list& requests, int index, int flag, const bp::list& statuses) {
	dumpio_testany prm;


	prm.count = count;
	if(prm.count != bp::len(requests)) ERROR("len(requests) != count");
	prm.requests = (dumpio_request*)malloc(sizeof(dumpio_request)*bp::len(requests));
	for(int i=0; i < bp::len(requests); i++)
		prm.requests[i] = bp::extract<dumpio_request>(requests[i]);
	prm.index = index;
	prm.flag = flag;
	if(prm.count != bp::len(statuses)) ERROR("len(statuses) != count");
	prm.statuses = (dumpi_status*)malloc(sizeof(dumpi_status)*bp::len(statuses));
	for(int i=0; i < bp::len(statuses); i++)
		prm.statuses[i] = bp::extract<dumpi_status>(statuses[i]);


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPIO_Testany, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpio_waitany
static void pycortex_post_dumpio_waitany(int thread, int count, const bp::list& requests, int index, const bp::list& statuses) {
	dumpio_waitany prm;


	prm.count = count;
	if(prm.count != bp::len(requests)) ERROR("len(requests) != count");
	prm.requests = (dumpio_request*)malloc(sizeof(dumpio_request)*bp::len(requests));
	for(int i=0; i < bp::len(requests); i++)
		prm.requests[i] = bp::extract<dumpio_request>(requests[i]);
	prm.index = index;
	if(prm.count != bp::len(statuses)) ERROR("len(statuses) != count");
	prm.statuses = (dumpi_status*)malloc(sizeof(dumpi_status)*bp::len(statuses));
	for(int i=0; i < bp::len(statuses); i++)
		prm.statuses[i] = bp::extract<dumpi_status>(statuses[i]);


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPIO_Waitany, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpio_waitsome
static void pycortex_post_dumpio_waitsome(int thread, int count, const bp::list& requests, int outcount, const bp::list& indices, const bp::list& statuses) {
	dumpio_waitsome prm;


	prm.count = count;
	if(prm.count != bp::len(requests)) ERROR("len(requests) != count");
	prm.requests = (dumpio_request*)malloc(sizeof(dumpio_request)*bp::len(requests));
	for(int i=0; i < bp::len(requests); i++)
		prm.requests[i] = bp::extract<dumpio_request>(requests[i]);
	prm.outcount = outcount;
	if(prm.outcount != bp::len(indices)) ERROR("len(indices) != outcount");
	prm.indices = (int*)malloc(sizeof(int)*bp::len(indices));
	for(int i=0; i < bp::len(indices); i++)
		prm.indices[i] = bp::extract<int>(indices[i]);
	if(prm.outcount != bp::len(statuses)) ERROR("len(statuses) != outcount");
	prm.statuses = (dumpi_status*)malloc(sizeof(dumpi_status)*bp::len(statuses));
	for(int i=0; i < bp::len(statuses); i++)
		prm.statuses[i] = bp::extract<dumpi_status>(statuses[i]);


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPIO_Waitsome, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

//  dumpio_testsome
static void pycortex_post_dumpio_testsome(int thread, int count, const bp::list& requests, int outcount, const bp::list& indices, const bp::list& statuses) {
	dumpio_testsome prm;


	prm.count = count;
	if(prm.count != bp::len(requests)) ERROR("len(requests) != count");
	prm.requests = (dumpio_request*)malloc(sizeof(dumpio_request)*bp::len(requests));
	for(int i=0; i < bp::len(requests); i++)
		prm.requests[i] = bp::extract<dumpio_request>(requests[i]);
	prm.outcount = outcount;
	if(prm.outcount != bp::len(indices)) ERROR("len(indices) != outcount");
	prm.indices = (int*)malloc(sizeof(int)*bp::len(indices));
	for(int i=0; i < bp::len(indices); i++)
		prm.indices[i] = bp::extract<int>(indices[i]);
	if(prm.outcount != bp::len(statuses)) ERROR("len(statuses) != outcount");
	prm.statuses = (dumpi_status*)malloc(sizeof(dumpi_status)*bp::len(statuses));
	for(int i=0; i < bp::len(statuses); i++)
		prm.statuses[i] = bp::extract<dumpi_status>(statuses[i]);


	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;

	cortex_post(profile, DUMPIO_Testsome, &prm, thread,
		cortex_python_current_cpu,
		cortex_python_current_wall,
		cortex_python_current_perf);
}

// Communicator manipulations

static int pycortex_get_world_size() {
	cortex_dumpi_profile* profile = (cortex_dumpi_profile*)cortex_python_current_uarg;
	int size = 0;
	cortex_comm_get_size(profile, DUMPI_COMM_WORLD, &size);
	return size;
}

static bool pycortex_is_mpi_comm_world(dumpi_comm comm) {
	return comm == DUMPI_COMM_WORLD;
}

static bool pycortex_is_mpi_comm_self(dumpi_comm comm) {
	return comm == DUMPI_COMM_SELF;
}

static bool pycortex_is_mpi_comm_null(dumpi_comm comm) {
	return comm == DUMPI_COMM_NULL;
}

static int pycortex_datatype_get_size(dumpi_datatype t) {
	return cortex_datatype_get_size((cortex_dumpi_profile*)cortex_python_current_uarg,t);
}

static int pycortex_is_basic_datatype(dumpi_datatype t) {
	return t < DUMPI_FIRST_USER_DATATYPE && t > 0;
}

BOOST_PYTHON_MODULE(cortex)
{
	bp::class_<dumpi_status>("MPI_Status")
		.def_readonly("bytes",&dumpi_status::bytes)
		.def_readonly("source",&dumpi_status::source)
		.def_readonly("tag",&dumpi_status::tag)
		.def_readonly("cancelled",&dumpi_status::cancelled)
		.def_readonly("error",&dumpi_status::error);

	bp::def("world_size", &pycortex_get_world_size);
	bp::def("is_mpi_comm_world", &pycortex_is_mpi_comm_world);
	bp::def("is_mpi_comm_null",  &pycortex_is_mpi_comm_null);
	bp::def("is_mpi_comm_self",  &pycortex_is_mpi_comm_self);
	bp::def("is_basic_datatype", &pycortex_is_basic_datatype);
	bp::def("datatype_size", &pycortex_datatype_get_size);

	bp::def("MPI_Send", &pycortex_post_dumpi_send,
		(bp::arg("thread"),
		 "count",
		 "datatype",
		 "dest",
		 "tag",
		 "comm"));
	bp::def("MPI_Recv", &pycortex_post_dumpi_recv,
		(bp::arg("thread"),
		 "count",
		 "datatype",
		 "source",
		 "tag",
		 "comm",
		 "status"));
	bp::def("MPI_Get_count", &pycortex_post_dumpi_get_count,
		(bp::arg("thread"),
		 "status",
		 "datatype",
		 "count"));
	bp::def("MPI_Bsend", &pycortex_post_dumpi_bsend,
		(bp::arg("thread"),
		 "count",
		 "datatype",
		 "dest",
		 "tag",
		 "comm"));
	bp::def("MPI_Ssend", &pycortex_post_dumpi_ssend,
		(bp::arg("thread"),
		 "count",
		 "datatype",
		 "dest",
		 "tag",
		 "comm"));
	bp::def("MPI_Rsend", &pycortex_post_dumpi_rsend,
		(bp::arg("thread"),
		 "count",
		 "datatype",
		 "dest",
		 "tag",
		 "comm"));
	bp::def("MPI_Buffer_attach", &pycortex_post_dumpi_buffer_attach,
		(bp::arg("thread"),
		 "size"));
	bp::def("MPI_Buffer_detach", &pycortex_post_dumpi_buffer_detach,
		(bp::arg("thread"),
		 "size"));
	bp::def("MPI_Isend", &pycortex_post_dumpi_isend,
		(bp::arg("thread"),
		 "count",
		 "datatype",
		 "dest",
		 "tag",
		 "comm",
		 "request"));
	bp::def("MPI_Ibsend", &pycortex_post_dumpi_ibsend,
		(bp::arg("thread"),
		 "count",
		 "datatype",
		 "dest",
		 "tag",
		 "comm",
		 "request"));
	bp::def("MPI_Issend", &pycortex_post_dumpi_issend,
		(bp::arg("thread"),
		 "count",
		 "datatype",
		 "dest",
		 "tag",
		 "comm",
		 "request"));
	bp::def("MPI_Irsend", &pycortex_post_dumpi_irsend,
		(bp::arg("thread"),
		 "count",
		 "datatype",
		 "dest",
		 "tag",
		 "comm",
		 "request"));
	bp::def("MPI_Irecv", &pycortex_post_dumpi_irecv,
		(bp::arg("thread"),
		 "count",
		 "datatype",
		 "source",
		 "tag",
		 "comm",
		 "request"));
	bp::def("MPI_Wait", &pycortex_post_dumpi_wait,
		(bp::arg("thread"),
		 "request",
		 "status"));
	bp::def("MPI_Test", &pycortex_post_dumpi_test,
		(bp::arg("thread"),
		 "request",
		 "flag",
		 "status"));
	bp::def("MPI_Request_free", &pycortex_post_dumpi_request_free,
		(bp::arg("thread"),
		 "request"));
	bp::def("MPI_Waitany", &pycortex_post_dumpi_waitany,
		(bp::arg("thread"),
		 "count",
		 "requests",
		 "index",
		 "status"));
	bp::def("MPI_Testany", &pycortex_post_dumpi_testany,
		(bp::arg("thread"),
		 "count",
		 "requests",
		 "index",
		 "flag",
		 "status"));
	bp::def("MPI_Waitall", &pycortex_post_dumpi_waitall,
		(bp::arg("thread"),
		 "count",
		 "requests",
		 "statuses"));
	bp::def("MPI_Testall", &pycortex_post_dumpi_testall,
		(bp::arg("thread"),
		 "count",
		 "requests",
		 "flag",
		 "statuses"));
	bp::def("MPI_Waitsome", &pycortex_post_dumpi_waitsome,
		(bp::arg("thread"),
		 "count",
		 "requests",
		 "outcount",
		 "indices",
		 "statuses"));
	bp::def("MPI_Testsome", &pycortex_post_dumpi_testsome,
		(bp::arg("thread"),
		 "count",
		 "requests",
		 "outcount",
		 "indices",
		 "statuses"));
	bp::def("MPI_Iprobe", &pycortex_post_dumpi_iprobe,
		(bp::arg("thread"),
		 "source",
		 "tag",
		 "comm",
		 "flag",
		 "status"));
	bp::def("MPI_Probe", &pycortex_post_dumpi_probe,
		(bp::arg("thread"),
		 "source",
		 "tag",
		 "comm",
		 "status"));
	bp::def("MPI_Cancel", &pycortex_post_dumpi_cancel,
		(bp::arg("thread"),
		 "request"));
	bp::def("MPI_Test_cancelled", &pycortex_post_dumpi_test_cancelled,
		(bp::arg("thread"),
		 "status",
		 "cancelled"));
	bp::def("MPI_Send_init", &pycortex_post_dumpi_send_init,
		(bp::arg("thread"),
		 "count",
		 "datatype",
		 "dest",
		 "tag",
		 "comm",
		 "request"));
	bp::def("MPI_Bsend_init", &pycortex_post_dumpi_bsend_init,
		(bp::arg("thread"),
		 "count",
		 "datatype",
		 "dest",
		 "tag",
		 "comm",
		 "request"));
	bp::def("MPI_Ssend_init", &pycortex_post_dumpi_ssend_init,
		(bp::arg("thread"),
		 "count",
		 "datatype",
		 "dest",
		 "tag",
		 "comm",
		 "request"));
	bp::def("MPI_Rsend_init", &pycortex_post_dumpi_rsend_init,
		(bp::arg("thread"),
		 "count",
		 "datatype",
		 "dest",
		 "tag",
		 "comm",
		 "request"));
	bp::def("MPI_Recv_init", &pycortex_post_dumpi_recv_init,
		(bp::arg("thread"),
		 "count",
		 "datatype",
		 "source",
		 "tag",
		 "comm",
		 "request"));
	bp::def("MPI_Start", &pycortex_post_dumpi_start,
		(bp::arg("thread"),
		 "request"));
	bp::def("MPI_Startall", &pycortex_post_dumpi_startall,
		(bp::arg("thread"),
		 "count",
		 "requests"));
	bp::def("MPI_Sendrecv", &pycortex_post_dumpi_sendrecv,
		(bp::arg("thread"),
		 "sendcount",
		 "sendtype",
		 "dest",
		 "sendtag",
		 "recvcount",
		 "recvtype",
		 "source",
		 "recvtag",
		 "comm",
		 "status"));
	bp::def("MPI_Sendrecv_replace", &pycortex_post_dumpi_sendrecv_replace,
		(bp::arg("thread"),
		 "count",
		 "datatype",
		 "dest",
		 "sendtag",
		 "source",
		 "recvtag",
		 "comm",
		 "status"));
	bp::def("MPI_Type_contiguous", &pycortex_post_dumpi_type_contiguous,
		(bp::arg("thread"),
		 "count",
		 "oldtype",
		 "newtype"));
	bp::def("MPI_Type_vector", &pycortex_post_dumpi_type_vector,
		(bp::arg("thread"),
		 "count",
		 "blocklength",
		 "stride",
		 "oldtype",
		 "newtype"));
	bp::def("MPI_Type_hvector", &pycortex_post_dumpi_type_hvector,
		(bp::arg("thread"),
		 "count",
		 "blocklength",
		 "stride",
		 "oldtype",
		 "newtype"));
	bp::def("MPI_Type_indexed", &pycortex_post_dumpi_type_indexed,
		(bp::arg("thread"),
		 "count",
		 "lengths",
		 "indices",
		 "oldtype",
		 "newtype"));
	bp::def("MPI_Type_hindexed", &pycortex_post_dumpi_type_hindexed,
		(bp::arg("thread"),
		 "count",
		 "lengths",
		 "indices",
		 "oldtype",
		 "newtype"));
	bp::def("MPI_Type_struct", &pycortex_post_dumpi_type_struct,
		(bp::arg("thread"),
		 "count",
		 "lengths",
		 "indices",
		 "oldtypes",
		 "newtype"));
	bp::def("MPI_Address", &pycortex_post_dumpi_address,
		(bp::arg("thread"),
		 "address"));
	bp::def("MPI_Type_extent", &pycortex_post_dumpi_type_extent,
		(bp::arg("thread"),
		 "datatype",
		 "extent"));
	bp::def("MPI_Type_size", &pycortex_post_dumpi_type_size,
		(bp::arg("thread"),
		 "datatype",
		 "size"));
	bp::def("MPI_Type_lb", &pycortex_post_dumpi_type_lb,
		(bp::arg("thread"),
		 "datatype",
		 "lb"));
	bp::def("MPI_Type_ub", &pycortex_post_dumpi_type_ub,
		(bp::arg("thread"),
		 "datatype",
		 "ub"));
	bp::def("MPI_Type_commit", &pycortex_post_dumpi_type_commit,
		(bp::arg("thread"),
		 "datatype"));
	bp::def("MPI_Type_free", &pycortex_post_dumpi_type_free,
		(bp::arg("thread"),
		 "datatype"));
	bp::def("MPI_Get_elements", &pycortex_post_dumpi_get_elements,
		(bp::arg("thread"),
		 "status",
		 "datatype",
		 "elements"));
	bp::def("MPI_Pack", &pycortex_post_dumpi_pack,
		(bp::arg("thread"),
		 "incount",
		 "datatype",
		 "outcount",
		 "position",
		 "comm"));
	bp::def("MPI_Unpack", &pycortex_post_dumpi_unpack,
		(bp::arg("thread"),
		 "incount",
		 "position",
		 "outcount",
		 "datatype",
		 "comm"));
	bp::def("MPI_Pack_size", &pycortex_post_dumpi_pack_size,
		(bp::arg("thread"),
		 "incount",
		 "datatype",
		 "comm",
		 "size"));
	bp::def("MPI_Barrier", &pycortex_post_dumpi_barrier,
		(bp::arg("thread"),
		 "comm"));
	bp::def("MPI_Bcast", &pycortex_post_dumpi_bcast,
		(bp::arg("thread"),
		 "count",
		 "datatype",
		 "root",
		 "comm"));
	bp::def("MPI_Gather", &pycortex_post_dumpi_gather,
		(bp::arg("thread"),
		 "commrank",
		 "sendcount",
		 "sendtype",
		 "recvcount",
		 "recvtype",
		 "root",
		 "comm"));
	bp::def("MPI_Gatherv", &pycortex_post_dumpi_gatherv,
		(bp::arg("thread"),
		 "commrank",
		 "commsize",
		 "sendcount",
		 "sendtype",
		 "recvcounts",
		 "displs",
		 "recvtype",
		 "root",
		 "comm"));
	bp::def("MPI_Scatter", &pycortex_post_dumpi_scatter,
		(bp::arg("thread"),
		 "commrank",
		 "sendcount",
		 "sendtype",
		 "recvcount",
		 "recvtype",
		 "root",
		 "comm"));
	bp::def("MPI_Scatterv", &pycortex_post_dumpi_scatterv,
		(bp::arg("thread"),
		 "commrank",
		 "commsize",
		 "sendcounts",
		 "displs",
		 "sendtype",
		 "recvcount",
		 "recvtype",
		 "root",
		 "comm"));
	bp::def("MPI_Allgather", &pycortex_post_dumpi_allgather,
		(bp::arg("thread"),
		 "sendcount",
		 "sendtype",
		 "recvcount",
		 "recvtype",
		 "comm"));
	bp::def("MPI_Allgatherv", &pycortex_post_dumpi_allgatherv,
		(bp::arg("thread"),
		 "commsize",
		 "sendcount",
		 "sendtype",
		 "recvcounts",
		 "displs",
		 "recvtype",
		 "comm"));
	bp::def("MPI_Alltoall", &pycortex_post_dumpi_alltoall,
		(bp::arg("thread"),
		 "sendcount",
		 "sendtype",
		 "recvcount",
		 "recvtype",
		 "comm"));
	bp::def("MPI_Alltoallv", &pycortex_post_dumpi_alltoallv,
		(bp::arg("thread"),
		 "commsize",
		 "sendcounts",
		 "senddispls",
		 "sendtype",
		 "recvcounts",
		 "recvdispls",
		 "recvtype",
		 "comm"));
	bp::def("MPI_Reduce", &pycortex_post_dumpi_reduce,
		(bp::arg("thread"),
		 "count",
		 "datatype",
		 "op",
		 "root",
		 "comm"));
	bp::def("MPI_Op_create", &pycortex_post_dumpi_op_create,
		(bp::arg("thread"),
		 "commute",
		 "op"));
	bp::def("MPI_Op_free", &pycortex_post_dumpi_op_free,
		(bp::arg("thread"),
		 "op"));
	bp::def("MPI_Allreduce", &pycortex_post_dumpi_allreduce,
		(bp::arg("thread"),
		 "count",
		 "datatype",
		 "op",
		 "comm"));
	bp::def("MPI_Reduce_scatter", &pycortex_post_dumpi_reduce_scatter,
		(bp::arg("thread"),
		 "commsize",
		 "recvcounts",
		 "datatype",
		 "op",
		 "comm"));
	bp::def("MPI_Scan", &pycortex_post_dumpi_scan,
		(bp::arg("thread"),
		 "count",
		 "datatype",
		 "op",
		 "comm"));
	bp::def("MPI_Group_size", &pycortex_post_dumpi_group_size,
		(bp::arg("thread"),
		 "group",
		 "size"));
	bp::def("MPI_Group_rank", &pycortex_post_dumpi_group_rank,
		(bp::arg("thread"),
		 "group",
		 "rank"));
	bp::def("MPI_Group_translate_ranks", &pycortex_post_dumpi_group_translate_ranks,
		(bp::arg("thread"),
		 "group1",
		 "count",
		 "ranks1",
		 "group2",
		 "ranks2"));
	bp::def("MPI_Group_compare", &pycortex_post_dumpi_group_compare,
		(bp::arg("thread"),
		 "group1",
		 "group2",
		 "result"));
	bp::def("MPI_Comm_group", &pycortex_post_dumpi_comm_group,
		(bp::arg("thread"),
		 "comm",
		 "group"));
	bp::def("MPI_Group_union", &pycortex_post_dumpi_group_union,
		(bp::arg("thread"),
		 "group1",
		 "group2",
		 "newgroup"));
	bp::def("MPI_Group_intersection", &pycortex_post_dumpi_group_intersection,
		(bp::arg("thread"),
		 "group1",
		 "group2",
		 "newgroup"));
	bp::def("MPI_Group_difference", &pycortex_post_dumpi_group_difference,
		(bp::arg("thread"),
		 "group1",
		 "group2",
		 "newgroup"));
	bp::def("MPI_Group_incl", &pycortex_post_dumpi_group_incl,
		(bp::arg("thread"),
		 "group",
		 "count",
		 "ranks",
		 "newgroup"));
	bp::def("MPI_Group_excl", &pycortex_post_dumpi_group_excl,
		(bp::arg("thread"),
		 "group",
		 "count",
		 "ranks",
		 "newgroup"));
	bp::def("MPI_Group_range_incl", &pycortex_post_dumpi_group_range_incl,
		(bp::arg("thread"),
		 "group",
		 "count",
		 "ranges",
		 "newgroup"));
	bp::def("MPI_Group_range_excl", &pycortex_post_dumpi_group_range_excl,
		(bp::arg("thread"),
		 "group",
		 "count",
		 "ranges",
		 "newgroup"));
	bp::def("MPI_Group_free", &pycortex_post_dumpi_group_free,
		(bp::arg("thread"),
		 "group"));
	bp::def("MPI_Comm_size", &pycortex_post_dumpi_comm_size,
		(bp::arg("thread"),
		 "comm",
		 "size"));
	bp::def("MPI_Comm_rank", &pycortex_post_dumpi_comm_rank,
		(bp::arg("thread"),
		 "comm",
		 "rank"));
	bp::def("MPI_Comm_compare", &pycortex_post_dumpi_comm_compare,
		(bp::arg("thread"),
		 "comm1",
		 "comm2",
		 "result"));
	bp::def("MPI_Comm_dup", &pycortex_post_dumpi_comm_dup,
		(bp::arg("thread"),
		 "oldcomm",
		 "newcomm"));
	bp::def("MPI_Comm_create", &pycortex_post_dumpi_comm_create,
		(bp::arg("thread"),
		 "oldcomm",
		 "group",
		 "newcomm"));
	bp::def("MPI_Comm_split", &pycortex_post_dumpi_comm_split,
		(bp::arg("thread"),
		 "oldcomm",
		 "color",
		 "key",
		 "newcomm"));
	bp::def("MPI_Comm_free", &pycortex_post_dumpi_comm_free,
		(bp::arg("thread"),
		 "comm"));
	bp::def("MPI_Comm_test_inter", &pycortex_post_dumpi_comm_test_inter,
		(bp::arg("thread"),
		 "comm",
		 "inter"));
	bp::def("MPI_Comm_remote_size", &pycortex_post_dumpi_comm_remote_size,
		(bp::arg("thread"),
		 "comm",
		 "size"));
	bp::def("MPI_Comm_remote_group", &pycortex_post_dumpi_comm_remote_group,
		(bp::arg("thread"),
		 "comm",
		 "group"));
	bp::def("MPI_Intercomm_create", &pycortex_post_dumpi_intercomm_create,
		(bp::arg("thread"),
		 "localcomm",
		 "localleader",
		 "remotecomm",
		 "remoteleader",
		 "tag",
		 "newcomm"));
	bp::def("MPI_Intercomm_merge", &pycortex_post_dumpi_intercomm_merge,
		(bp::arg("thread"),
		 "comm",
		 "high",
		 "newcomm"));
	bp::def("MPI_Keyval_create", &pycortex_post_dumpi_keyval_create,
		(bp::arg("thread"),
		 "key"));
	bp::def("MPI_Keyval_free", &pycortex_post_dumpi_keyval_free,
		(bp::arg("thread"),
		 "key"));
	bp::def("MPI_Attr_put", &pycortex_post_dumpi_attr_put,
		(bp::arg("thread"),
		 "comm",
		 "key"));
	bp::def("MPI_Attr_get", &pycortex_post_dumpi_attr_get,
		(bp::arg("thread"),
		 "comm",
		 "key",
		 "flag"));
	bp::def("MPI_Attr_delete", &pycortex_post_dumpi_attr_delete,
		(bp::arg("thread"),
		 "comm",
		 "key"));
	bp::def("MPI_Topo_test", &pycortex_post_dumpi_topo_test,
		(bp::arg("thread"),
		 "comm",
		 "topo"));
	bp::def("MPI_Cart_create", &pycortex_post_dumpi_cart_create,
		(bp::arg("thread"),
		 "oldcomm",
		 "ndim",
		 "dims",
		 "periods",
		 "reorder",
		 "newcomm"));
	bp::def("MPI_Dims_create", &pycortex_post_dumpi_dims_create,
		(bp::arg("thread"),
		 "nodes",
		 "ndim",
		 "dims"));
	bp::def("MPI_Graph_create", &pycortex_post_dumpi_graph_create,
		(bp::arg("thread"),
		 "numedges",
		 "oldcomm",
		 "nodes",
		 "index",
		 "edges",
		 "reorder",
		 "newcomm"));
	bp::def("MPI_Graphdims_get", &pycortex_post_dumpi_graphdims_get,
		(bp::arg("thread"),
		 "comm",
		 "nodes",
		 "edges"));
	bp::def("MPI_Graph_get", &pycortex_post_dumpi_graph_get,
		(bp::arg("thread"),
		 "totedges",
		 "totnodes",
		 "comm",
		 "maxindex",
		 "maxedges",
		 "index",
		 "edges"));
	bp::def("MPI_Cartdim_get", &pycortex_post_dumpi_cartdim_get,
		(bp::arg("thread"),
		 "comm",
		 "ndim"));
	bp::def("MPI_Cart_get", &pycortex_post_dumpi_cart_get,
		(bp::arg("thread"),
		 "ndim",
		 "comm",
		 "maxdims",
		 "dims",
		 "periods",
		 "coords"));
	bp::def("MPI_Cart_rank", &pycortex_post_dumpi_cart_rank,
		(bp::arg("thread"),
		 "ndim",
		 "comm",
		 "coords",
		 "rank"));
	bp::def("MPI_Cart_coords", &pycortex_post_dumpi_cart_coords,
		(bp::arg("thread"),
		 "ndim",
		 "comm",
		 "rank",
		 "maxdims",
		 "coords"));
	bp::def("MPI_Graph_neighbors_count", &pycortex_post_dumpi_graph_neighbors_count,
		(bp::arg("thread"),
		 "comm",
		 "rank",
		 "nneigh"));
	bp::def("MPI_Graph_neighbors", &pycortex_post_dumpi_graph_neighbors,
		(bp::arg("thread"),
		 "nneigh",
		 "comm",
		 "rank",
		 "maxneighbors",
		 "neighbors"));
	bp::def("MPI_Cart_shift", &pycortex_post_dumpi_cart_shift,
		(bp::arg("thread"),
		 "comm",
		 "direction",
		 "displ",
		 "source",
		 "dest"));
	bp::def("MPI_Cart_sub", &pycortex_post_dumpi_cart_sub,
		(bp::arg("thread"),
		 "ndim",
		 "oldcomm",
		 "remain_dims",
		 "newcomm"));
	bp::def("MPI_Cart_map", &pycortex_post_dumpi_cart_map,
		(bp::arg("thread"),
		 "comm",
		 "ndim",
		 "dims",
		 "period",
		 "newrank"));
	bp::def("MPI_Graph_map", &pycortex_post_dumpi_graph_map,
		(bp::arg("thread"),
		 "numedges",
		 "comm",
		 "nodes",
		 "index",
		 "edges",
		 "newrank"));
	bp::def("MPI_Get_processor_name", &pycortex_post_dumpi_get_processor_name,
		(bp::arg("thread"),
		 "name",
		 "resultlen"));
	bp::def("MPI_Get_version", &pycortex_post_dumpi_get_version,
		(bp::arg("thread"),
		 "version",
		 "subversion"));
	bp::def("MPI_Errhandler_create", &pycortex_post_dumpi_errhandler_create,
		(bp::arg("thread"),
		 "errhandler"));
	bp::def("MPI_Errhandler_set", &pycortex_post_dumpi_errhandler_set,
		(bp::arg("thread"),
		 "comm",
		 "errhandler"));
	bp::def("MPI_Errhandler_get", &pycortex_post_dumpi_errhandler_get,
		(bp::arg("thread"),
		 "comm",
		 "errhandler"));
	bp::def("MPI_Errhandler_free", &pycortex_post_dumpi_errhandler_free,
		(bp::arg("thread"),
		 "errhandler"));
	bp::def("MPI_Error_string", &pycortex_post_dumpi_error_string,
		(bp::arg("thread"),
		 "errorcode",
		 "errorstring",
		 "resultlen"));
	bp::def("MPI_Error_class", &pycortex_post_dumpi_error_class,
		(bp::arg("thread"),
		 "errorcode",
		 "errorclass"));
	bp::def("MPI_Wtime", &pycortex_post_dumpi_wtime,
		(bp::arg("thread"),
		 "psec"));
	bp::def("MPI_Wtick", &pycortex_post_dumpi_wtick,
		(bp::arg("thread"),
		 "psec"));
	bp::def("MPI_Init", &pycortex_post_dumpi_init,
		(bp::arg("thread"),
		 "argc",
		 "argv"));
	bp::def("MPI_Finalize", &pycortex_post_dumpi_finalize,
		(bp::arg("thread"),
		 "dummy"));
	bp::def("MPI_Initialized", &pycortex_post_dumpi_initialized,
		(bp::arg("thread"),
		 "result"));
	bp::def("MPI_Abort", &pycortex_post_dumpi_abort,
		(bp::arg("thread"),
		 "comm",
		 "errorcode"));
	bp::def("MPI_Close_port", &pycortex_post_dumpi_close_port,
		(bp::arg("thread"),
		 "portname"));
	bp::def("MPI_Comm_accept", &pycortex_post_dumpi_comm_accept,
		(bp::arg("thread"),
		 "portname",
		 "info",
		 "root",
		 "oldcomm",
		 "newcomm"));
	bp::def("MPI_Comm_connect", &pycortex_post_dumpi_comm_connect,
		(bp::arg("thread"),
		 "portname",
		 "info",
		 "root",
		 "oldcomm",
		 "newcomm"));
	bp::def("MPI_Comm_disconnect", &pycortex_post_dumpi_comm_disconnect,
		(bp::arg("thread"),
		 "comm"));
	bp::def("MPI_Comm_get_parent", &pycortex_post_dumpi_comm_get_parent,
		(bp::arg("thread"),
		 "parent"));
	bp::def("MPI_Comm_join", &pycortex_post_dumpi_comm_join,
		(bp::arg("thread"),
		 "fd",
		 "comm"));
	bp::def("MPI_Comm_spawn", &pycortex_post_dumpi_comm_spawn,
		(bp::arg("thread"),
		 "oldcommrank",
		 "command",
		 "argv",
		 "maxprocs",
		 "info",
		 "root",
		 "oldcomm",
		 "newcomm",
		 "errcodes"));
	bp::def("MPI_Comm_spawn_multiple", &pycortex_post_dumpi_comm_spawn_multiple,
		(bp::arg("thread"),
		 "totprocs",
		 "oldcommrank",
		 "count",
		 "commands",
		 "argvs",
		 "maxprocs",
		 "info",
		 "root",
		 "oldcomm",
		 "newcomm",
		 "errcodes"));
	bp::def("MPI_Lookup_name", &pycortex_post_dumpi_lookup_name,
		(bp::arg("thread"),
		 "servicename",
		 "info",
		 "portname"));
	bp::def("MPI_Open_port", &pycortex_post_dumpi_open_port,
		(bp::arg("thread"),
		 "info",
		 "portname"));
	bp::def("MPI_Publish_name", &pycortex_post_dumpi_publish_name,
		(bp::arg("thread"),
		 "servicename",
		 "info",
		 "portname"));
	bp::def("MPI_Unpublish_name", &pycortex_post_dumpi_unpublish_name,
		(bp::arg("thread"),
		 "servicename",
		 "info",
		 "portname"));
	bp::def("MPI_Accumulate", &pycortex_post_dumpi_accumulate,
		(bp::arg("thread"),
		 "origincount",
		 "origintype",
		 "targetrank",
		 "targetdisp",
		 "targetcount",
		 "targettype",
		 "op",
		 "win"));
	bp::def("MPI_Get", &pycortex_post_dumpi_get,
		(bp::arg("thread"),
		 "origincount",
		 "origintype",
		 "targetrank",
		 "targetdisp",
		 "targetcount",
		 "targettype",
		 "win"));
	bp::def("MPI_Put", &pycortex_post_dumpi_put,
		(bp::arg("thread"),
		 "origincount",
		 "origintype",
		 "targetrank",
		 "targetdisp",
		 "targetcount",
		 "targettype",
		 "win"));
	bp::def("MPI_Win_complete", &pycortex_post_dumpi_win_complete,
		(bp::arg("thread"),
		 "win"));
	bp::def("MPI_Win_create", &pycortex_post_dumpi_win_create,
		(bp::arg("thread"),
		 "size",
		 "dispunit",
		 "info",
		 "comm",
		 "win"));
	bp::def("MPI_Win_fence", &pycortex_post_dumpi_win_fence,
		(bp::arg("thread"),
		 "assertion",
		 "win"));
	bp::def("MPI_Win_free", &pycortex_post_dumpi_win_free,
		(bp::arg("thread"),
		 "win"));
	bp::def("MPI_Win_get_group", &pycortex_post_dumpi_win_get_group,
		(bp::arg("thread"),
		 "win",
		 "group"));
	bp::def("MPI_Win_lock", &pycortex_post_dumpi_win_lock,
		(bp::arg("thread"),
		 "locktype",
		 "winrank",
		 "assertion",
		 "win"));
	bp::def("MPI_Win_post", &pycortex_post_dumpi_win_post,
		(bp::arg("thread"),
		 "group",
		 "assertion",
		 "win"));
	bp::def("MPI_Win_start", &pycortex_post_dumpi_win_start,
		(bp::arg("thread"),
		 "group",
		 "assertion",
		 "win"));
	bp::def("MPI_Win_test", &pycortex_post_dumpi_win_test,
		(bp::arg("thread"),
		 "win",
		 "flag"));
	bp::def("MPI_Win_unlock", &pycortex_post_dumpi_win_unlock,
		(bp::arg("thread"),
		 "winrank",
		 "win"));
	bp::def("MPI_Win_wait", &pycortex_post_dumpi_win_wait,
		(bp::arg("thread"),
		 "win"));
	bp::def("MPI_Alltoallw", &pycortex_post_dumpi_alltoallw,
		(bp::arg("thread"),
		 "commsize",
		 "sendcounts",
		 "senddispls",
		 "sendtypes",
		 "recvcounts",
		 "recvdispls",
		 "recvtypes",
		 "comm"));
	bp::def("MPI_Exscan", &pycortex_post_dumpi_exscan,
		(bp::arg("thread"),
		 "count",
		 "datatype",
		 "op",
		 "comm"));
	bp::def("MPI_Add_error_class", &pycortex_post_dumpi_add_error_class,
		(bp::arg("thread"),
		 "errorclass"));
	bp::def("MPI_Add_error_code", &pycortex_post_dumpi_add_error_code,
		(bp::arg("thread"),
		 "errorclass",
		 "errorcode"));
	bp::def("MPI_Add_error_string", &pycortex_post_dumpi_add_error_string,
		(bp::arg("thread"),
		 "errorcode",
		 "errorstring"));
	bp::def("MPI_Comm_call_errhandler", &pycortex_post_dumpi_comm_call_errhandler,
		(bp::arg("thread"),
		 "comm",
		 "errorcode"));
	bp::def("MPI_Comm_create_keyval", &pycortex_post_dumpi_comm_create_keyval,
		(bp::arg("thread"),
		 "keyval"));
	bp::def("MPI_Comm_delete_attr", &pycortex_post_dumpi_comm_delete_attr,
		(bp::arg("thread"),
		 "comm",
		 "keyval"));
	bp::def("MPI_Comm_free_keyval", &pycortex_post_dumpi_comm_free_keyval,
		(bp::arg("thread"),
		 "keyval"));
	bp::def("MPI_Comm_get_attr", &pycortex_post_dumpi_comm_get_attr,
		(bp::arg("thread"),
		 "comm",
		 "keyval",
		 "flag"));
	bp::def("MPI_Comm_get_name", &pycortex_post_dumpi_comm_get_name,
		(bp::arg("thread"),
		 "comm",
		 "name",
		 "resultlen"));
	bp::def("MPI_Comm_set_attr", &pycortex_post_dumpi_comm_set_attr,
		(bp::arg("thread"),
		 "comm",
		 "keyval"));
	bp::def("MPI_Comm_set_name", &pycortex_post_dumpi_comm_set_name,
		(bp::arg("thread"),
		 "comm",
		 "name"));
	bp::def("MPI_File_call_errhandler", &pycortex_post_dumpi_file_call_errhandler,
		(bp::arg("thread"),
		 "file",
		 "errorcode"));
	bp::def("MPI_Grequest_complete", &pycortex_post_dumpi_grequest_complete,
		(bp::arg("thread"),
		 "request"));
	bp::def("MPI_Grequest_start", &pycortex_post_dumpi_grequest_start,
		(bp::arg("thread"),
		 "request"));
	bp::def("MPI_Init_thread", &pycortex_post_dumpi_init_thread,
		(bp::arg("thread"),
		 "argc",
		 "argv",
		 "required",
		 "provided"));
	bp::def("MPI_Is_thread_main", &pycortex_post_dumpi_is_thread_main,
		(bp::arg("thread"),
		 "flag"));
	bp::def("MPI_Query_thread", &pycortex_post_dumpi_query_thread,
		(bp::arg("thread"),
		 "supported"));
	bp::def("MPI_Status_set_cancelled", &pycortex_post_dumpi_status_set_cancelled,
		(bp::arg("thread"),
		 "status",
		 "flag"));
	bp::def("MPI_Status_set_elements", &pycortex_post_dumpi_status_set_elements,
		(bp::arg("thread"),
		 "status",
		 "datatype",
		 "count"));
	bp::def("MPI_Type_create_keyval", &pycortex_post_dumpi_type_create_keyval,
		(bp::arg("thread"),
		 "keyval"));
	bp::def("MPI_Type_delete_attr", &pycortex_post_dumpi_type_delete_attr,
		(bp::arg("thread"),
		 "datatype",
		 "keyval"));
	bp::def("MPI_Type_dup", &pycortex_post_dumpi_type_dup,
		(bp::arg("thread"),
		 "oldtype",
		 "newtype"));
	bp::def("MPI_Type_free_keyval", &pycortex_post_dumpi_type_free_keyval,
		(bp::arg("thread"),
		 "keyval"));
	bp::def("MPI_Type_get_attr", &pycortex_post_dumpi_type_get_attr,
		(bp::arg("thread"),
		 "datatype",
		 "keyval",
		 "flag"));
	bp::def("MPI_Type_get_contents", &pycortex_post_dumpi_type_get_contents,
		(bp::arg("thread"),
		 "numdatatypes",
		 "numaddresses",
		 "numintegers",
		 "datatype",
		 "maxintegers",
		 "maxaddresses",
		 "maxdatatypes",
		 "arrintegers",
		 "arraddresses",
		 "arrdatatypes"));
	bp::def("MPI_Type_get_envelope", &pycortex_post_dumpi_type_get_envelope,
		(bp::arg("thread"),
		 "datatype",
		 "numintegers",
		 "numaddresses",
		 "numdatatypes",
		 "combiner"));
	bp::def("MPI_Type_get_name", &pycortex_post_dumpi_type_get_name,
		(bp::arg("thread"),
		 "datatype",
		 "name",
		 "resultlen"));
	bp::def("MPI_Type_set_attr", &pycortex_post_dumpi_type_set_attr,
		(bp::arg("thread"),
		 "datatype",
		 "keyval"));
	bp::def("MPI_Type_set_name", &pycortex_post_dumpi_type_set_name,
		(bp::arg("thread"),
		 "datatype",
		 "name"));
	bp::def("MPI_Type_match_size", &pycortex_post_dumpi_type_match_size,
		(bp::arg("thread"),
		 "typeclass",
		 "size",
		 "datatype"));
	bp::def("MPI_Win_call_errhandler", &pycortex_post_dumpi_win_call_errhandler,
		(bp::arg("thread"),
		 "win",
		 "errorcode"));
	bp::def("MPI_Win_create_keyval", &pycortex_post_dumpi_win_create_keyval,
		(bp::arg("thread"),
		 "keyval"));
	bp::def("MPI_Win_delete_attr", &pycortex_post_dumpi_win_delete_attr,
		(bp::arg("thread"),
		 "win",
		 "keyval"));
	bp::def("MPI_Win_free_keyval", &pycortex_post_dumpi_win_free_keyval,
		(bp::arg("thread"),
		 "keyval"));
	bp::def("MPI_Win_get_attr", &pycortex_post_dumpi_win_get_attr,
		(bp::arg("thread"),
		 "win",
		 "keyval",
		 "flag"));
	bp::def("MPI_Win_get_name", &pycortex_post_dumpi_win_get_name,
		(bp::arg("thread"),
		 "win",
		 "name",
		 "resultlen"));
	bp::def("MPI_Win_set_attr", &pycortex_post_dumpi_win_set_attr,
		(bp::arg("thread"),
		 "win",
		 "keyval"));
	bp::def("MPI_Win_set_name", &pycortex_post_dumpi_win_set_name,
		(bp::arg("thread"),
		 "win",
		 "name"));
	bp::def("MPI_Alloc_mem", &pycortex_post_dumpi_alloc_mem,
		(bp::arg("thread"),
		 "size",
		 "info"));
	bp::def("MPI_Comm_create_errhandler", &pycortex_post_dumpi_comm_create_errhandler,
		(bp::arg("thread"),
		 "errhandler"));
	bp::def("MPI_Comm_get_errhandler", &pycortex_post_dumpi_comm_get_errhandler,
		(bp::arg("thread"),
		 "comm",
		 "errhandler"));
	bp::def("MPI_Comm_set_errhandler", &pycortex_post_dumpi_comm_set_errhandler,
		(bp::arg("thread"),
		 "comm",
		 "errhandler"));
	bp::def("MPI_File_create_errhandler", &pycortex_post_dumpi_file_create_errhandler,
		(bp::arg("thread"),
		 "errhandler"));
	bp::def("MPI_File_get_errhandler", &pycortex_post_dumpi_file_get_errhandler,
		(bp::arg("thread"),
		 "file",
		 "errhandler"));
	bp::def("MPI_File_set_errhandler", &pycortex_post_dumpi_file_set_errhandler,
		(bp::arg("thread"),
		 "file",
		 "errhandler"));
	bp::def("MPI_Finalized", &pycortex_post_dumpi_finalized,
		(bp::arg("thread"),
		 "flag"));
	bp::def("MPI_Free_mem", &pycortex_post_dumpi_free_mem,
		(bp::arg("thread"),
		 "dummy"));
	bp::def("MPI_Get_address", &pycortex_post_dumpi_get_address,
		(bp::arg("thread"),
		 "address"));
	bp::def("MPI_Info_create", &pycortex_post_dumpi_info_create,
		(bp::arg("thread"),
		 "info"));
	bp::def("MPI_Info_delete", &pycortex_post_dumpi_info_delete,
		(bp::arg("thread"),
		 "info",
		 "key"));
	bp::def("MPI_Info_dup", &pycortex_post_dumpi_info_dup,
		(bp::arg("thread"),
		 "oldinfo",
		 "newinfo"));
	bp::def("MPI_Info_free", &pycortex_post_dumpi_info_free,
		(bp::arg("thread"),
		 "info"));
	bp::def("MPI_Info_get", &pycortex_post_dumpi_info_get,
		(bp::arg("thread"),
		 "info",
		 "key",
		 "valuelength",
		 "value",
		 "flag"));
	bp::def("MPI_Info_get_nkeys", &pycortex_post_dumpi_info_get_nkeys,
		(bp::arg("thread"),
		 "info",
		 "nkeys"));
	bp::def("MPI_Info_get_nthkey", &pycortex_post_dumpi_info_get_nthkey,
		(bp::arg("thread"),
		 "info",
		 "n",
		 "key"));
	bp::def("MPI_Info_get_valuelen", &pycortex_post_dumpi_info_get_valuelen,
		(bp::arg("thread"),
		 "info",
		 "key",
		 "valuelen",
		 "flag"));
	bp::def("MPI_Info_set", &pycortex_post_dumpi_info_set,
		(bp::arg("thread"),
		 "info",
		 "key",
		 "value"));
	bp::def("MPI_Pack_external", &pycortex_post_dumpi_pack_external,
		(bp::arg("thread"),
		 "datarep",
		 "incount",
		 "intype",
		 "outcount",
		 "position"));
	bp::def("MPI_Pack_external_size", &pycortex_post_dumpi_pack_external_size,
		(bp::arg("thread"),
		 "datarep",
		 "incount",
		 "datatype",
		 "size"));
	bp::def("MPI_Request_get_status", &pycortex_post_dumpi_request_get_status,
		(bp::arg("thread"),
		 "request",
		 "flag",
		 "status"));
	bp::def("MPI_Type_create_darray", &pycortex_post_dumpi_type_create_darray,
		(bp::arg("thread"),
		 "size",
		 "rank",
		 "ndims",
		 "gsizes",
		 "distribs",
		 "dargs",
		 "psizes",
		 "order",
		 "oldtype",
		 "newtype"));
	bp::def("MPI_Type_create_hindexed", &pycortex_post_dumpi_type_create_hindexed,
		(bp::arg("thread"),
		 "count",
		 "blocklengths",
		 "displacements",
		 "oldtype",
		 "newtype"));
	bp::def("MPI_Type_create_hvector", &pycortex_post_dumpi_type_create_hvector,
		(bp::arg("thread"),
		 "count",
		 "blocklength",
		 "stride",
		 "oldtype",
		 "newtype"));
	bp::def("MPI_Type_create_indexed_block", &pycortex_post_dumpi_type_create_indexed_block,
		(bp::arg("thread"),
		 "count",
		 "blocklength",
		 "displacments",
		 "oldtype",
		 "newtype"));
	bp::def("MPI_Type_create_resized", &pycortex_post_dumpi_type_create_resized,
		(bp::arg("thread"),
		 "oldtype",
		 "lb",
		 "extent",
		 "newtype"));
	bp::def("MPI_Type_create_struct", &pycortex_post_dumpi_type_create_struct,
		(bp::arg("thread"),
		 "count",
		 "blocklengths",
		 "displacements",
		 "oldtypes",
		 "newtype"));
	bp::def("MPI_Type_create_subarray", &pycortex_post_dumpi_type_create_subarray,
		(bp::arg("thread"),
		 "ndims",
		 "sizes",
		 "subsizes",
		 "starts",
		 "order",
		 "oldtype",
		 "newtype"));
	bp::def("MPI_Type_get_extent", &pycortex_post_dumpi_type_get_extent,
		(bp::arg("thread"),
		 "datatype",
		 "lb",
		 "extent"));
	bp::def("MPI_Type_get_true_extent", &pycortex_post_dumpi_type_get_true_extent,
		(bp::arg("thread"),
		 "datatype",
		 "lb",
		 "extent"));
	bp::def("MPI_Unpack_external", &pycortex_post_dumpi_unpack_external,
		(bp::arg("thread"),
		 "datarep",
		 "insize",
		 "position",
		 "outcount",
		 "datatype"));
	bp::def("MPI_Win_create_errhandler", &pycortex_post_dumpi_win_create_errhandler,
		(bp::arg("thread"),
		 "errhandler"));
	bp::def("MPI_Win_get_errhandler", &pycortex_post_dumpi_win_get_errhandler,
		(bp::arg("thread"),
		 "win",
		 "errhandler"));
	bp::def("MPI_Win_set_errhandler", &pycortex_post_dumpi_win_set_errhandler,
		(bp::arg("thread"),
		 "win",
		 "errhandler"));
	bp::def("MPI_File_open", &pycortex_post_dumpi_file_open,
		(bp::arg("thread"),
		 "comm",
		 "filename",
		 "amode",
		 "info",
		 "file"));
	bp::def("MPI_File_close", &pycortex_post_dumpi_file_close,
		(bp::arg("thread"),
		 "file"));
	bp::def("MPI_File_delete", &pycortex_post_dumpi_file_delete,
		(bp::arg("thread"),
		 "filename",
		 "info"));
	bp::def("MPI_File_set_size", &pycortex_post_dumpi_file_set_size,
		(bp::arg("thread"),
		 "file",
		 "size"));
	bp::def("MPI_File_preallocate", &pycortex_post_dumpi_file_preallocate,
		(bp::arg("thread"),
		 "file",
		 "size"));
	bp::def("MPI_File_get_size", &pycortex_post_dumpi_file_get_size,
		(bp::arg("thread"),
		 "file",
		 "size"));
	bp::def("MPI_File_get_group", &pycortex_post_dumpi_file_get_group,
		(bp::arg("thread"),
		 "file",
		 "group"));
	bp::def("MPI_File_get_amode", &pycortex_post_dumpi_file_get_amode,
		(bp::arg("thread"),
		 "file",
		 "amode"));
	bp::def("MPI_File_set_info", &pycortex_post_dumpi_file_set_info,
		(bp::arg("thread"),
		 "file",
		 "info"));
	bp::def("MPI_File_get_info", &pycortex_post_dumpi_file_get_info,
		(bp::arg("thread"),
		 "file",
		 "info"));
	bp::def("MPI_File_set_view", &pycortex_post_dumpi_file_set_view,
		(bp::arg("thread"),
		 "file",
		 "offset",
		 "hosttype",
		 "filetype",
		 "datarep",
		 "info"));
	bp::def("MPI_File_get_view", &pycortex_post_dumpi_file_get_view,
		(bp::arg("thread"),
		 "file",
		 "offset",
		 "hosttype",
		 "filetype",
		 "datarep"));
	bp::def("MPI_File_read_at", &pycortex_post_dumpi_file_read_at,
		(bp::arg("thread"),
		 "file",
		 "offset",
		 "count",
		 "datatype",
		 "status"));
	bp::def("MPI_File_read_at_all", &pycortex_post_dumpi_file_read_at_all,
		(bp::arg("thread"),
		 "file",
		 "offset",
		 "count",
		 "datatype",
		 "status"));
	bp::def("MPI_File_write_at", &pycortex_post_dumpi_file_write_at,
		(bp::arg("thread"),
		 "file",
		 "offset",
		 "count",
		 "datatype",
		 "status"));
	bp::def("MPI_File_write_at_all", &pycortex_post_dumpi_file_write_at_all,
		(bp::arg("thread"),
		 "file",
		 "offset",
		 "count",
		 "datatype",
		 "status"));
	bp::def("MPI_File_iread_at", &pycortex_post_dumpi_file_iread_at,
		(bp::arg("thread"),
		 "file",
		 "offset",
		 "count",
		 "datatype",
		 "request"));
	bp::def("MPI_File_iwrite_at", &pycortex_post_dumpi_file_iwrite_at,
		(bp::arg("thread"),
		 "file",
		 "offset",
		 "count",
		 "datatype",
		 "request"));
	bp::def("MPI_File_read", &pycortex_post_dumpi_file_read,
		(bp::arg("thread"),
		 "file",
		 "count",
		 "datatype",
		 "status"));
	bp::def("MPI_File_read_all", &pycortex_post_dumpi_file_read_all,
		(bp::arg("thread"),
		 "file",
		 "count",
		 "datatype",
		 "status"));
	bp::def("MPI_File_write", &pycortex_post_dumpi_file_write,
		(bp::arg("thread"),
		 "file",
		 "count",
		 "datatype",
		 "status"));
	bp::def("MPI_File_write_all", &pycortex_post_dumpi_file_write_all,
		(bp::arg("thread"),
		 "file",
		 "count",
		 "datatype",
		 "status"));
	bp::def("MPI_File_iread", &pycortex_post_dumpi_file_iread,
		(bp::arg("thread"),
		 "file",
		 "count",
		 "datatype",
		 "request"));
	bp::def("MPI_File_iwrite", &pycortex_post_dumpi_file_iwrite,
		(bp::arg("thread"),
		 "file",
		 "count",
		 "datatype",
		 "request"));
	bp::def("MPI_File_seek", &pycortex_post_dumpi_file_seek,
		(bp::arg("thread"),
		 "file",
		 "offset",
		 "whence"));
	bp::def("MPI_File_get_position", &pycortex_post_dumpi_file_get_position,
		(bp::arg("thread"),
		 "file",
		 "offset"));
	bp::def("MPI_File_get_byte_offset", &pycortex_post_dumpi_file_get_byte_offset,
		(bp::arg("thread"),
		 "file",
		 "offset",
		 "bytes"));
	bp::def("MPI_File_read_shared", &pycortex_post_dumpi_file_read_shared,
		(bp::arg("thread"),
		 "file",
		 "count",
		 "datatype",
		 "status"));
	bp::def("MPI_File_write_shared", &pycortex_post_dumpi_file_write_shared,
		(bp::arg("thread"),
		 "file",
		 "count",
		 "datatype",
		 "status"));
	bp::def("MPI_File_iread_shared", &pycortex_post_dumpi_file_iread_shared,
		(bp::arg("thread"),
		 "file",
		 "count",
		 "datatype",
		 "request"));
	bp::def("MPI_File_iwrite_shared", &pycortex_post_dumpi_file_iwrite_shared,
		(bp::arg("thread"),
		 "file",
		 "count",
		 "datatype",
		 "request"));
	bp::def("MPI_File_read_ordered", &pycortex_post_dumpi_file_read_ordered,
		(bp::arg("thread"),
		 "file",
		 "count",
		 "datatype",
		 "status"));
	bp::def("MPI_File_write_ordered", &pycortex_post_dumpi_file_write_ordered,
		(bp::arg("thread"),
		 "file",
		 "count",
		 "datatype",
		 "status"));
	bp::def("MPI_File_seek_shared", &pycortex_post_dumpi_file_seek_shared,
		(bp::arg("thread"),
		 "file",
		 "offset",
		 "whence"));
	bp::def("MPI_File_get_position_shared", &pycortex_post_dumpi_file_get_position_shared,
		(bp::arg("thread"),
		 "file",
		 "offset"));
	bp::def("MPI_File_read_at_all_begin", &pycortex_post_dumpi_file_read_at_all_begin,
		(bp::arg("thread"),
		 "file",
		 "offset",
		 "count",
		 "datatype"));
	bp::def("MPI_File_read_at_all_end", &pycortex_post_dumpi_file_read_at_all_end,
		(bp::arg("thread"),
		 "file",
		 "status"));
	bp::def("MPI_File_write_at_all_begin", &pycortex_post_dumpi_file_write_at_all_begin,
		(bp::arg("thread"),
		 "file",
		 "offset",
		 "count",
		 "datatype"));
	bp::def("MPI_File_write_at_all_end", &pycortex_post_dumpi_file_write_at_all_end,
		(bp::arg("thread"),
		 "file",
		 "status"));
	bp::def("MPI_File_read_all_begin", &pycortex_post_dumpi_file_read_all_begin,
		(bp::arg("thread"),
		 "file",
		 "count",
		 "datatype"));
	bp::def("MPI_File_read_all_end", &pycortex_post_dumpi_file_read_all_end,
		(bp::arg("thread"),
		 "file",
		 "status"));
	bp::def("MPI_File_write_all_begin", &pycortex_post_dumpi_file_write_all_begin,
		(bp::arg("thread"),
		 "file",
		 "count",
		 "datatype"));
	bp::def("MPI_File_write_all_end", &pycortex_post_dumpi_file_write_all_end,
		(bp::arg("thread"),
		 "file",
		 "status"));
	bp::def("MPI_File_read_ordered_begin", &pycortex_post_dumpi_file_read_ordered_begin,
		(bp::arg("thread"),
		 "file",
		 "count",
		 "datatype"));
	bp::def("MPI_File_read_ordered_end", &pycortex_post_dumpi_file_read_ordered_end,
		(bp::arg("thread"),
		 "file",
		 "status"));
	bp::def("MPI_File_write_ordered_begin", &pycortex_post_dumpi_file_write_ordered_begin,
		(bp::arg("thread"),
		 "file",
		 "count",
		 "datatype"));
	bp::def("MPI_File_write_ordered_end", &pycortex_post_dumpi_file_write_ordered_end,
		(bp::arg("thread"),
		 "file",
		 "status"));
	bp::def("MPI_File_get_type_extent", &pycortex_post_dumpi_file_get_type_extent,
		(bp::arg("thread"),
		 "file",
		 "datatype",
		 "extent"));
	bp::def("MPI_Register_datarep", &pycortex_post_dumpi_register_datarep,
		(bp::arg("thread"),
		 "name"));
	bp::def("MPI_File_set_atomicity", &pycortex_post_dumpi_file_set_atomicity,
		(bp::arg("thread"),
		 "file",
		 "flag"));
	bp::def("MPI_File_get_atomicity", &pycortex_post_dumpi_file_get_atomicity,
		(bp::arg("thread"),
		 "file",
		 "flag"));
	bp::def("MPI_File_sync", &pycortex_post_dumpi_file_sync,
		(bp::arg("thread"),
		 "file"));
	bp::def("MPIO_Test", &pycortex_post_dumpio_test,
		(bp::arg("thread"),
		 "request",
		 "flag",
		 "status"));
	bp::def("MPIO_Wait", &pycortex_post_dumpio_wait,
		(bp::arg("thread"),
		 "request",
		 "status"));
	bp::def("MPIO_Testall", &pycortex_post_dumpio_testall,
		(bp::arg("thread"),
		 "count",
		 "requests",
		 "flag",
		 "statuses"));
	bp::def("MPIO_Waitall", &pycortex_post_dumpio_waitall,
		(bp::arg("thread"),
		 "count",
		 "requests",
		 "statuses"));
	bp::def("MPIO_Testany", &pycortex_post_dumpio_testany,
		(bp::arg("thread"),
		 "count",
		 "requests",
		 "index",
		 "flag",
		 "statuses"));
	bp::def("MPIO_Waitany", &pycortex_post_dumpio_waitany,
		(bp::arg("thread"),
		 "count",
		 "requests",
		 "index",
		 "statuses"));
	bp::def("MPIO_Waitsome", &pycortex_post_dumpio_waitsome,
		(bp::arg("thread"),
		 "count",
		 "requests",
		 "outcount",
		 "indices",
		 "statuses"));
	bp::def("MPIO_Testsome", &pycortex_post_dumpio_testsome,
		(bp::arg("thread"),
		 "count",
		 "requests",
		 "outcount",
		 "indices",
		 "statuses"));

}


extern "C" int cortex_python_set_module(const char* module, const char* class_name) {
	if(cortex_python_initialized) return -1;

	setenv("PYTHONPATH", ".", 1);

	Py_Initialize();
	try {
		PyImport_AppendInittab((char*)"cortex",&initcortex);
		bp::object __main__(bp::handle<>(bp::borrowed(PyImport_AddModule("__main__"))));
		bp::object __dict__ = __main__.attr("__dict__");
		cortex_python_module = bp::object(bp::handle<>(PyImport_ImportModule("cortex")));
		user_python_module = bp::import(module);
		user_python_translator 
			= user_python_module.attr(class_name)();
		
	} catch(const bp::error_already_set&)
	{
		PyErr_Print();
		exit(-1);
	}
	cortex_python_initialized = true;
	return 0;
}
