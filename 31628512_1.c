#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

long nthreads, length;
long double *partial_sums;
//pthread_mutex_t mutex;

void *pi_computation(void *id){
	long *myid = (long *)id;
	long chunk = length/nthreads;
	long start = *myid * chunk;
	long end = start + chunk;
	long double partial_sum = 0.0;
	long double x;

	if(*myid == nthreads - 1){
		end = length;
	}

	//computation is done here in worker thread
	for(int i = start; i <end; i++){
		x = ((double) i - 0.5)/length;
		partial_sum += 4.0 / (1.0 + x * x);
	}

	//puts result in partial_sums to be added in main thread later
	partial_sums[*myid] = partial_sum;

	return NULL;
}

int main(int argc, char *argv[]){
	pthread_t *thread_array;
	long *thread_ids;
	long double sum = 0.0;
	long double pi;

	nthreads = strtol(argv[1], NULL, 10);
	length = strtol(argv[2], NULL, 10);

	thread_array = malloc(nthreads * sizeof(pthread_t));
	thread_ids = (long *)malloc(nthreads * sizeof(long));
	partial_sums = malloc(nthreads * sizeof(long double));

	for(int i = 0; i < nthreads; i++){
		thread_ids[i] = i;
		pthread_create(&thread_array[i], NULL, pi_computation, &thread_ids[i]);
	}

	for(int i = 0; i < nthreads; i++){
		pthread_join(thread_array[i], NULL);
	}

	for(int i = 0; i < nthreads; i++){
		sum += partial_sums[i];
	}
	
	pi = sum/length;
	printf("The approximation of pi is %.22Lf", pi);

	free(thread_array);
	free(thread_ids);
	free(partial_sums);

	return 0;
}
