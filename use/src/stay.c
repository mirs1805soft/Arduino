#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include "uss.h"
#include "stay.h"

//extern int stop;

void stay(){
	while(1){
		sleep (3);
		if(stop == 0){
			break;
		}else{
		    //   printf("1");	
		}
	}
}	
