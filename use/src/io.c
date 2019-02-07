#include <stdio.h>
#include <wiringPi.h>
#include <pthread.h>
#include "io.h"
#include "request.h"
#include "arduino.h"

// ピン配置
//static const int pin_sw_f  = 25;
//static const int pin_sw_l  = 21;
//static const int pin_sw_r  = 27;
static const int pin_sw_f  = 18;
static const int pin_sw_l  = 25;
static const int pin_sw_r  = 26;

int io_open(){
	// GPIOデバイスのオープン
	if(wiringPiSetupGpio() != 0){
		printf("failed to open GPIO\n");
		return -1;
	}else{
		// ピン設定
		pinMode(pin_sw_f, INPUT);
		pinMode(pin_sw_l, INPUT);
		pinMode(pin_sw_r, INPUT);
		pullUpDnControl(pin_sw_f, PUD_UP);
		pullUpDnControl(pin_sw_l, PUD_UP);
		pullUpDnControl(pin_sw_r, PUD_UP);
		
		printf("GPIO opened\n");
		return 0;
	}
}

void io_get_sw(int *sw_f){ 	//, int *sw_l, int *sw_r){

	*sw_f = digitalRead(pin_sw_f);
//	*sw_l = digitalRead(pin_sw_l);
//	*sw_r = digitalRead(pin_sw_r);

}

void thread_touch(void *t){

	int sw_f;
	int s = 0;
	if(io_open() != 0) return -1;
	while(s == 1){
		io_get_sw(&sw_f);

//		if(sw_f == 0){
//			printf("io\n");
//			s = 1;
//		}
	}
	request_set_runmode(STP,0,0);
}
