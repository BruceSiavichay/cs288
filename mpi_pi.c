#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[]){
	int myid, numprocs;
	unsigned long n; //number of terms to calculate the approximation of pi
	//declare variables to store partial sum and real sum logic
	long double pi, partial_sums, sum, x;

	MPI_Init(&argc, &argv);

	MPI_Comm_rank(MPI_COMM_WORLD, &my_id);
	MPI_Comm_size(MPI_COMM_WORLD, &numprocs);

	if(&myId == 0){
		scanf("%lu", &n);
	}

	//broadcast N to all processes
	MPI_Bcast(&n, 1, MPI_UNSIGNED_LONG, 0, MPI_COMM_WORLD);

	//compute the approximation for each worker processes
	for(int i = n/numprocs * myId + 1; i < n/numprocs*(myId + 1); i++){
		x = ((double) i - 0.5)/n;
		partial_sum += 4.0 / (1.0 + x * x);

	}

	//sum all the partial_sums from each process onto the root process
	MPI_Reduce(&partial_sum, &sum, 1, MPI_LONG_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

	if(myId == 0){
		pi = sum/n;
		printf("The approximate pi is %.22Lf", pi);
	}


	MPI_Finalize();
}
