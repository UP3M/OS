#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#define N 10

typedef struct{
pthread_t thread_id;
char* text;
int thread_num;
} thread_info;

void* job(void* args){
	thread_info* t = (thread_info*)args;
	unsigned long x = pthread_self();
	printf("Hello from thread with id %lu \n", t->thread_id);
	return NULL;
}

int main(){
	pthread_t thread_id;
	thread_info th_info[N-1];
	for(int i=0; i<N; i++){
		pthread_create(&thread_id, NULL, &job, &th_info[i]);
		th_info[i].thread_id = thread_id;
		th_info[i].thread_num = i;
		sprintf(&th_info[i].text,"Create thread %d with id %lu", i, thread_id);
		printf("%s\n", &th_info[i].text);
		pthread_join(thread_id, NULL);
		printf("Terminating of thread %d with id %lu \n", i, thread_id);
	 }
	pthread_t x = pthread_self();// unsigned long
	printf("Hello from main thread %lu \n", x);
	exit(EXIT_SUCCESS);
}
  