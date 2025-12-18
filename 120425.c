#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[]){
  int rank, size;

  // step 1: start the MPI Environment
  MPI_Init(&argc, &argv);

  // step 2: get the rank/id for each process
  // Each process can be identified by its rank
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  // MPI_COMM_WORLD => MPI_COMMUNICATION_WORLD => refers to the group of processes running the program.

  // step 3: get the total number of processes
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  // print each rank
  printf("I'm rank/process %d of total %d \n", rank, size);

  // step 4: Close the MPI Environment
  MPI_Finalize();
}
