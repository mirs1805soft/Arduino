#include <stdio.h>
#include <pthread.h>
#include "request.h"
//#include "uss.h"
//#include "stay.h"
#include "run_base.h"

#define go 5
#define vel 10

extern int stop;

void run_base(){
	request_set_runmode(STR,vel,go);
/*	if(stop == 1){
		stay();
	}else{
	}
*/
}
