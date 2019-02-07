#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include "arduino.h"

extern int thread_run0_1(void *t);
extern void thread_measure(void *t);
//extern void thread_touch(void *t);

int main(void){

	if(arduino_open() != 0) return -1;

	int s;
	pthread_t tid_run, tid_uss, tid_io;

	s = pthread_create(&tid_run, NULL, thread_run0_1, NULL);
	if(s != 0){
		printf("create error!\n");
		return -1;
	}
	
	s = pthread_create(&tid_uss, NULL, thread_measure, NULL);
	if(s != 0){
		printf("create error!\n");
		return -1;
	}

/*	s = pthread_create(&tid_io, NULL, thread_touch, NULL);
	if(s != 0){
		printf("create error!\n");
		return -1;
	}
*/	
	pthread_join(tid_run, NULL);
	//pthread_join(tid_uss, NULL);
//	pthread_join(tid_io, NULL);

	return 0;
}
