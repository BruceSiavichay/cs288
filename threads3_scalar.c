#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// global variables => share across all threads
long *array, length, s, nthreads;

//thread function
void *scalar(void *id){
	long *myid = (long *)id;

	//calculate the subset for each thread to compute
	long chunk = length/nthreads;

	//calculate the start index for each thread to compute
	long start = *myid * chunk;

	//calculate the end index for each thread
	long end = start + chunk;

	//if this is the last thread compute for all remaining elements
	if(myId == numthreads - 1){
		end = length;
	}

	//perform the scalar multiplication
	for(int i = start; i < end; i++){
		array[i] = array[i] * s;
	}

	return NULL;
}

int main(int argc, char *argv[]){
	pthread_t *thread_array;
	long *thread_ids;

	//parse the command like args
	nthreads = strtol(argv[1], NULL, 10);
	length = strtol(argv[2], NULL, 10);
	s = strtol(argv[3], NULL, 10);

	//allocte memory for thread array and ids
	thread_array = malloc(nthreads * sizeof(pthread_t));
	thread_ids = (long *)malloc(nthreads * sizeof(long));
	array = (long *)malloc(length * sizeof(long));

	for(int i = 0; i < nthreads; i++){
		array[i] = i;
	}

	//create the threads
	for(int i = 0; i < nthreads; i++){
		thread_ids[i] = i;
		pthread_create(&thread_array[i], NULL, scalar, &thread_ids);
	}

	//join
	for(int i = 0; i < nthreads; i++){
		pthread_join(thread_array[i], NULL);
	}

	//display the output
	for(int i = 0; i < length; i++){
		print("%4ld", array[i]);
	}

	//free up space
	free(threade_array);
	free(thread_ids);
	free(array);
}
