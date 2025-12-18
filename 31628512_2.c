#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#define MAX 1000

int main(int argc, char *argv[]){
	int myid, numprocs;

	//prevents garbage vals
	int local_counts[MAX] = {0};
	int counts[MAX] = {0};
	int count = 0;
	char filename[100];

	MPI_Init(&argc, &argv);
	MPI_Status status;

	MPI_Comm_rank(MPI_COMM_WORLD, &myid);
	MPI_Comm_size(MPI_COMM_WORLD, &numprocs);

	int numworkers = numprocs - 1;
	int *buffer = NULL;
	
	if(myid == 0){
		printf("Enter filename: ");
		scanf("%s", filename);

		FILE *stream1;
        	stream1 = fopen(filename, "rb");

        	if(stream1 == NULL){
                	perror("fopen");
        	}

        	//gets number of ints for space
        	int num;
        	while(fread(&num, sizeof(int), 1, stream1)){
                	count++;
        	}

        	buffer = malloc(count * sizeof(int));

        	//resets to beginning of file
        	fseek(stream1, 0, SEEK_SET);
        	for(int i = 0; i < count; i++){
                	fread(&buffer[i], sizeof(int), 1, stream1);
        	}

		fclose(stream1);
	}

	//right now, only process 0 knows the total count. this tells it to everyone
	MPI_Bcast(&count, 1, MPI_INT, 0, MPI_COMM_WORLD);

	int chunk = count / numprocs;
	int local_buffer[chunk];
	//distributes the elements of buffer equally between processes automatically, including process 0
	MPI_Scatter(buffer, chunk, MPI_INT, local_buffer, chunk, MPI_INT, 0, MPI_COMM_WORLD);

	for(int i = 0; i < chunk; i++){
		local_counts[local_buffer[i]] = local_counts[local_buffer[i]] + 1;
	}

	//basically reduce is called in every process, adds up all the local counts, stores it in counts but only for rank 0 because of the penultimate parameter.
	MPI_Reduce(local_counts, counts, MAX, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

	if(myid == 0){
		FILE *stream2;
		stream2 = fopen(filename, "wb");

		for(int i = 0; i < MAX; i++){
			if(counts[i] != 0){
				for(int j = 0; j < counts[i]; j++){
					fwrite(&i, sizeof(int), 1, stream2);
				}
			}
		}

		fclose(stream2);
		free(buffer);
	}

	MPI_Finalize();
}
