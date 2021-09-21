#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>
#define N 100


char s[N];
int bConsumerSleeping, bProducerSleeping;
int position;
int i =0;
void* Produce(void* args){
	clock_t begin = clock();
	while(1){
		if (bProducerSleeping){
			continue;
			}
		if(position == N-1){
			bConsumerSleeping = 0;
			bProducerSleeping = 1;
			}
		s[position] = rand();
		position++;
		if (position == N){
			clock_t end = clock();
			printf("Time of execution:%f\n", ((double)(end - begin)));
			printf("Producer Sleep and Customer Wakeup\n");
		}else
		printf("Produce # %d\n",position);
		}
	}

void* Consume(void* args){
	while(1){
		if (bConsumerSleeping){
			continue;
			}
		if(position == 1){
			bConsumerSleeping = 1;
			bProducerSleeping = 0;
			}
		s[position] = 0;
		position--;
		if (position == 0){
			printf("Customer Sleep and Producer Wakeup\n");
		}else
		printf("Consume # %d\n", position);
		}
	}

int main(){
	
	bConsumerSleeping=1;
	pthread_t tProducer, tConsumer;
	pthread_create(&tProducer, NULL, &Produce, NULL);
	pthread_create(&tConsumer, NULL, &Consume, NULL);
	pthread_join(tProducer, 0);
	pthread_join(tConsumer, 0);
	}
  