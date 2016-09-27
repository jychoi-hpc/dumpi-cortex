DUMPI-CoRtEx is a library that reads DUMPI traces and enables the conversion of
MPI collective communication events into their equivalent sequence of point to
point events, in particular as implemented in MPICH.


DUMPI-CoRtEx currently supports the following collectives.
* MPI_Allgather
* MPI_Allgatherv
* MPI_Allreduce
* MPI_Alltoallv
* MPI_Barrier
* MPI_Bcast
* MPI_Reduce

If you want other algorithms to be implemented, please either submit a ticket on
the issue tracker. You can also fork the project, implement the algorithm 
yourself, and submit a pull request.