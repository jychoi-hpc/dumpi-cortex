import cortex

class MyTranslator():

    def MPI_Bcast(self, thread, **args):

       dtype = args['datatype']
       root  = args['root']
       comm  = args['comm']
       count = args['count']

       print "MPI_Bcast called in Python, root = ", root

       if not (cortex.MPI_COMM_WORLD == comm):
         print "Communicator is not MPI_COMM_WORLD, not translating"
         return

       if thread != root :
         s = cortex.MPI_Status()
         cortex.MPI_Recv(thread,count=count,datatype=dtype,source=root,tag=1234,comm=comm,status=s)
       else :
         size = cortex.comm_world_size()
         for i in range(size):
           if i != thread:
             cortex.MPI_Send(thread,count=count,datatype=dtype,dest=i,tag=1234,comm=comm)
