#include <stdio.h>
#include <unistd.h>
#include <wiringPiI2C.h>
#include <pthread.h>
//#include "uss.h"

// 測定の時間間隔[ms]
static const int t_uss = 100;		//50

// 測定範囲の下限・上限[cm]
static const int uss_min =  16;
static const int uss_max = 600;

// センサからMIRS中心までの距離[cm]
static const int dist_center1 = 16;   //mae,ushiro,naname
static const int dist_center2 = 18;   //yoko

static int fd_1, fd_2, fd_3, fd_4, fd_5, fd_6;

int uss_open_1(){
	fd_1 = wiringPiI2CSetup(0x70);
	
	// ソフトウェアリビジョンの確認
	if(wiringPiI2CReadReg8(fd_1, 0x00) == 0x06){
		printf("USS_1 opened\n");
		return 0;
	}else{
		printf("failed to open USS_1\n");
		return -1;
	}
}

int uss_open_2(){
	fd_2 = wiringPiI2CSetup(0x71);
	
	// ソフトウェアリビジョンの確認
	if(wiringPiI2CReadReg8(fd_2, 0x00) == 0x06){
		printf("USS_2 opened\n");
		return 0;
	}else{
		printf("failed to open USS_2\n");
		return -1;
	}
}

int uss_open_3(){
	fd_3 = wiringPiI2CSetup(0x72);
	
	// ソフトウェアリビジョンの確認
	if(wiringPiI2CReadReg8(fd_3, 0x00) == 0x06){
		printf("USS_3 opened\n");
		return 0;
	}else{
		printf("failed to open USS_3\n");
		return -1;
	}
}

int uss_open_4(){
	fd_4 = wiringPiI2CSetup(0x73);
	
	// ソフトウェアリビジョンの確認
	if(wiringPiI2CReadReg8(fd_4, 0x00) == 0x06){
		printf("USS_4 opened\n");
		return 0;
	}else{
		printf("failed to open USS_4\n");
		return -1;
	}
}

int uss_open_5(){
	fd_5 = wiringPiI2CSetup(0x74);
	
	// ソフトウェアリビジョンの確認
	if(wiringPiI2CReadReg8(fd_5, 0x00) == 0x06){
		printf("USS_5 opened\n");
		return 0;
	}else{
		printf("failed to open USS_5\n");
		return -1;
	}
}

int uss_open_6(){
	fd_6 = wiringPiI2CSetup(0x75);
	
	// ソフトウェアリビジョンの確認
	if(wiringPiI2CReadReg8(fd_6, 0x00) == 0x06){
		printf("USS_6 opened\n");
		return 0;
	}else{
		printf("failed to open USS_6\n");
		return -1;
	}
}

long uss_get_1(){
	unsigned char lowbyte, highbyte;
	long val;
	
	wiringPiI2CWriteReg8(fd_1, 0x00, 0x51);
	usleep(t_uss * 1000);
	
	lowbyte  = wiringPiI2CReadReg8(fd_1, 0x03);
	highbyte = wiringPiI2CReadReg8(fd_1, 0x02);
	val = lowbyte + highbyte * 256;
	
	if(val < uss_min || val > uss_max){
		return -1;
	}else{
		return val + dist_center1;
	}
}

long uss_get_2(){
	unsigned char lowbyte, highbyte;
	long val;
	
	wiringPiI2CWriteReg8(fd_2, 0x00, 0x51);
	usleep(t_uss * 1000);
	
	lowbyte  = wiringPiI2CReadReg8(fd_2, 0x03);
	highbyte = wiringPiI2CReadReg8(fd_2, 0x02);
	val = lowbyte + highbyte * 256;
	
	if(val < uss_min || val > uss_max){
		return -1;
	}else{
		return val + dist_center1;
	}
}

long uss_get_3(){
	unsigned char lowbyte, highbyte;
	long val;
	
	wiringPiI2CWriteReg8(fd_3, 0x00, 0x51);
	usleep(t_uss * 1000);
	
	lowbyte  = wiringPiI2CReadReg8(fd_3, 0x03);
	highbyte = wiringPiI2CReadReg8(fd_3, 0x02);
	val = lowbyte + highbyte * 256;
	
	if(val < uss_min || val > uss_max){
		return -1;
	}else{
		return val + dist_center2;
	}
}

long uss_get_4(){
	unsigned char lowbyte, highbyte;
	long val;
	
	wiringPiI2CWriteReg8(fd_4, 0x00, 0x51);
	usleep(t_uss * 1000);
	
	lowbyte  = wiringPiI2CReadReg8(fd_4, 0x03);
	highbyte = wiringPiI2CReadReg8(fd_4, 0x02);
	val = lowbyte + highbyte * 256;
	
	if(val < uss_min || val > uss_max){
		return -1;
	}else{
		return val + dist_center1;
	}
}

long uss_get_5(){
	unsigned char lowbyte, highbyte;
	long val;
	
	wiringPiI2CWriteReg8(fd_5, 0x00, 0x51);
	usleep(t_uss * 1000);
	
	lowbyte  = wiringPiI2CReadReg8(fd_5, 0x03);
	highbyte = wiringPiI2CReadReg8(fd_5, 0x02);
	val = lowbyte + highbyte * 256;
	
	if(val < uss_min || val > uss_max){
		return -1;
	}else{
		return val + dist_center2;
	}
}

long uss_get_6(){
	unsigned char lowbyte, highbyte;
	long val;
	
	wiringPiI2CWriteReg8(fd_6, 0x00, 0x51);
	usleep(t_uss * 1000);
	
	lowbyte  = wiringPiI2CReadReg8(fd_6, 0x03);
	highbyte = wiringPiI2CReadReg8(fd_6, 0x02);
	val = lowbyte + highbyte * 256;
	
	if(val < uss_min || val > uss_max){
		return -1;
	}else{
		return val + dist_center1;
	}
}

int stop;     //It's called by run.c

void thread_main(void *t){

	int hit = 50;
	stop = 0;

	if(uss_open_1() != 0) return -1;
	if(uss_open_2() != 0) return -1;
	if(uss_open_3() != 0) return -1;
	if(uss_open_4() != 0) return -1;
//	if(uss_open_5() != 0) return -1;
//	if(uss_open_6() != 0) return -1;

	while(1){
		long a = uss_get_1();
		long b = uss_get_2();
		long c = uss_get_3();
		long d = uss_get_4();
//		long e = uss_get_5();	
//		long f = uss_get_6();
	
		if(/*a < hit || b < hit ||*/ c < hit /*|| d < hit || e < hit || f < hit*/){
			stop = 1;
		}else{
			stop = 0;
		}

		sleep(1);	//100*1000
		if(stop == 1){
			printf("1\n");
		}
		if(stop == 0){
			printf("0\n");
		}

		usleep(100*1000);
		printf("uss = ");
		printf("%6ld\n",c);

//		usleep(100*1000);

	}
	return 0;
}

