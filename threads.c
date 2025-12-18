#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

//thread function (each worker thread will execute this function)
void *computation(void *id){
	long *myid = (long *)id;
	int sum = 0;
	for(int i = 0; i < 1000000000; i++){
		sum += *myid;
	}
}

int main(){
	//to create worker thread
	//pthread create(pthread_t *thread, pthread_atts_t *attrs, void *thread func, void* thread func_parameters);
	//1. thread => pointer to the thread (address of the worker thread)
	//2. attrs => attributes to the thread
	//3. thread_func => function that each thread will be executing
	//4. thread_func_parameters => the arguments to the thread function
	
	//creating worker thread
	pthread_t thread1;
	pthread_t thread2;

	long value1=1, value2=2

	pthread_create(&thread1, NULL, computation, (void *)&value1);
	pthread_create(&thread2, NULL, computation, (void *)&value2);

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	//pthread programs must be compiled with the -pthread flag (gcc -pthread prog.c)
}
