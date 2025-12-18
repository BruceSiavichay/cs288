#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

//thread function for each thread to execute
void *hello(void *id){
	long *myid = (long *)id;
	printf("I'm thread %ld", *myid);
	return NULL;
}

int main(int argc, char *argv[]){
	long nthread = strtol(argv[1], NULL, 10) //string to long (pointer to sstart, end, and base system)
	pthread_t *thread_array = malloc(nthread * sizeof(pthread_t));
	long *thread_ids = (long *)malloc(nthread * sizeof(long));

	//create threads
	for(int i = 0; i < nthread; i++){
		thread_ids[i] = i;
		pthread_create(&thread_array[i], NULL, hello, &thread_ids[i]);
	}

	//join threads
	for(int i = 0; i < nthread; i++){
		pthread_join(thread_array[i], NULL);
	}

	//free memory
	free(thread_array);
	free(thread_ids);
}
