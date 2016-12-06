import cortex

def GenerateThings(thread):

    print "In the generator"
    if thread == 0:
       cortex.MPI_Send(thread,count=1,datatype=cortex.MPI_INT,dest=1,tag=1234,comm=cortex.MPI_COMM_WORLD)
    elif thread == 1:
       s = cortex.MPI_Status()
       s.nbytes = 4
       s.source = 0
       s.tag = 1234
       s.cancelled = False
       s.error = 0
       cortex.MPI_Recv(thread,count=1,datatype=cortex.MPI_INT,source=0,tag=1234,comm=cortex.MPI_COMM_WORLD,status=s)
