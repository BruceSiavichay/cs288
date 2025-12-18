#include <stdio.h>
#include <mpi.h>
#define N 100
#define FROM_MASTER 1
#define FROM_WORKER 2

int main(int argc, char *argv[]){
	//send the message
	//MPI Send(void *buff, int count, MPI_DATATYPE datatype, int destination, int tag, MPI_COMM_WORLD comm);
	//1. buff => address of the buffer of the data to be sent
	//2. count => number of elements to be sent
	//3. datatype => type of data being sent
	//4. destination => rank of the process to which the data is being sent to.
	//5. tag => user-defined number for pairing send and recv functions
	//6. comm => communicator world (group of processes)
	
	//receive the message
	//MPI_Recv(void *buff, int count, MPI_DATATYPE datatype, int source, int tag, MPI_COMM_WORLD comm, MPI_STATUS status);
	//1. buff => address where the data will be stored.
	//4. source => rank of the process where the data is coming from
	//7. status => status information by receive function
	int numtasks, taskid, numworkers, rows;
	doublie A[N][N], B[N][N], C[N][N];
	MPI_Init(&argc, &argv);
	MPI_Status status;

	MPI_Comm_rank(MPI_COMM_WORLD, &taskid);

	MPI_Comm_size(MPI_COMM_WORLD, &numtasks);

	numworkers = numtasks - 1;
	rows = N / numworkers;

	if(taskid == 0){
		//preparae data => initialize the matrix
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				A[i][j] = i+j;
				B[i][j] = i*j;
			}
		}

		//send the matrix data to worker processes
		for(int dest = 1; dest <=numworkers; dest++){
			MPI_Send(&A[(dest - 1) * rows][0], rows*N, MPI_DOUBLE, dest, FROM_MASTER, MPI_COMM_WORLD);
			MPI_Send(&B, N*N, MPI_DOUBLE, dest, FROM_MASTER, MPI_COMM_WORLD);
		}	

		//receive the result matrix data
		for(int source = 1; source <= numworkers; source++){
			MPI_Recv(&C[(source-1) * rows][0], rows*N, MPI_DOUBLE, source, FROM_WORKER, MPI_COMM_WORLD, status);
		}

		//print the result
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				printf("%6.2f \n", &C[i][j]);
			}
		}
	}

	if(taskid > 0){
		//receive the matrix data for both A and B
		MPI_Recv(&A, rows*N, MPI_DOUBLE, 0, FROM_MASTER, MPI_COMM_WORLD, status);
		MPI_Recv(&B, N*N, MPI_DOUBLE, 0, FROM_MASTER, MPI_COMM_WORLD, status);

		//perform matrix multiplication
		for(int i = 0; i < rows; i++){
			for(int j = 0; j < N; i++){
				for(int  k = 0; k < N; k++){
					C[i][k] += A[i][j] * B[j][k];
				}
			}
		}

		//send the result back to the root process
		MPI_Send(&C, rows*N, MPI_DOUBLE, 0, FROM_WORKER, MPI_COMM_WORLD);
	}


	MPI_Finalize();
}
