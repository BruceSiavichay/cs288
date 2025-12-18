#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#define ITERATIONS 5000000
#define MAX_THREADS 2

//semaphore: a synchronization tool for locking and unlocking threads
//Declare a global variable of unsigned type
//semaphore can be manipulated by two functions
//wait() => decreases the semaphore (locking the thread)
//post() => increases the semephore (unlocking the thread)

//problem with semaphore is any thread can essentially decrrement, making it harder to manage
//use mutex whenever possible
//with mutex, only a locked thread can unlock 

//declare the semaphore
//sem_t mysem;

//declare the mutex (part of pthread library)
pthread_mutex_t mymutex;

int cnt = 0;

void *worker(){
	for(int i = 0; i < ITERATIONS; i++){
		//lock the thread
		//sem_wait(&mysem);
		pthread_mutex_lock(&mymutex);
		cnt++;
		pthread_mutex_unlock(&mymutex);
		//sem_post(&mysem);
	}
}

int main(){
	pthread_t pthread_array[MAX_THREADS];

	//initialize the semaphore
	//sem_init(sem_t *mysem, int pshare, int value);
	//pshare => share the semaphore between threads and processes (0 to share between threads, 1 to share between processes
	//value initialized value of the semaphore usually set to 1
	//sem_init(&mysem, 0, 1);
	
	//initialize mutex
	pthread_mutex_init(&mymutex, NULL);

	for(int i = 0; i<MAX_THREADS; i++){
		pthread_create(&pthread_array[i], NULL, worker, NULL);
	}

	for(int i = 0; i < MAX_THREADS; i++){
		pthread_join(pthread_array[i], NULL);
	}

	//free the semaphore
	//sem_destroy(&mysem);

	//free mutex
	pthread_mutex_destroy(&mymutex);

	printf("%d", cnt);
}
