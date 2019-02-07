#include <stdio.h>
#include <unistd.h>
#include <wiringPiI2C.h>
#include "uss.h"

// 測定の時間間隔[ms]
static const int t_uss = 50;

// 測定範囲の下限・上限[cm]
static const int uss_min =  16;
static const int uss_max = 600;

// センサからMIRS中心までの距離[cm]
static const int dist_center = 10;

static int fd_l, fd_r;  
//
static int fd_f, fd_b;

int uss_open_l(){
	fd_l = wiringPiI2CSetup(0x70);
	
	// ソフトウェアリビジョンの確認
	if(wiringPiI2CReadReg8(fd_l, 0x00) == 0x06){
		printf("USS_L opened\n");
		return 0;
	}else{
		printf("failed to open USS_L\n");
		return -1;
	}
}

int uss_open_r(){
	fd_r = wiringPiI2CSetup(0x71);
	
	// ソフトウェアリビジョンの確認
	if(wiringPiI2CReadReg8(fd_r, 0x00) == 0x06){
		printf("USS_R opened\n");
		return 0;
	}else{
		printf("failed to open USS_R\n");
		return -1;
	}
}

//
int uss_open_f(){
	fd_f = wiringPiI2CSetup(0x72);
	
	// ソフトウェアリビジョンの確認
	if(wiringPiI2CReadReg8(fd_f, 0x00) == 0x06){
		printf("USS_F opened\n");
		return 0;
	}else{
		printf("failed to open USS_F\n");
		return -1;
	}
}

int uss_open_b(){
	fd_b = wiringPiI2CSetup(0x73);
	
	// ソフトウェアリビジョンの確認
	if(wiringPiI2CReadReg8(fd_r, 0x00) == 0x06){
		printf("USS_B opened\n");
		return 0;
	}else{
		printf("failed to open USS_B\n");
		return -1;
	}
}

long uss_get_l(){
	unsigned char lowbyte, highbyte;
	long val;
	
	wiringPiI2CWriteReg8(fd_l, 0x00, 0x51);
	usleep(t_uss * 1000);
	
	lowbyte  = wiringPiI2CReadReg8(fd_l, 0x03);
	highbyte = wiringPiI2CReadReg8(fd_l, 0x02);
	val = lowbyte + highbyte * 256;
	
	if(val < uss_min || val > uss_max){
		return -1;
	}else{
		return val + dist_center;
	}
}

long uss_get_r(){
	unsigned char lowbyte, highbyte;
	long val;
	
	wiringPiI2CWriteReg8(fd_r, 0x00, 0x51);
	usleep(t_uss * 1000);
	
	lowbyte  = wiringPiI2CReadReg8(fd_r, 0x03);
	highbyte = wiringPiI2CReadReg8(fd_r, 0x02);
	val = lowbyte + highbyte * 256;
	
	if(val < uss_min || val > uss_max){
		return -1;
	}else{
		return val + dist_center;
	}
}

//
long uss_get_f(){
	unsigned char lowbyte, highbyte;
	long val;
	
	wiringPiI2CWriteReg8(fd_f, 0x00, 0x51);
	usleep(t_uss * 1000);
	
	lowbyte  = wiringPiI2CReadReg8(fd_f, 0x03);
	highbyte = wiringPiI2CReadReg8(fd_f, 0x02);
	val = lowbyte + highbyte * 256;
	
	if(val < uss_min || val > uss_max){
		return -1;
	}else{
		return val + dist_center;
	}
}

long uss_get_b(){
	unsigned char lowbyte, highbyte;
	long val;
	
	wiringPiI2CWriteReg8(fd_b, 0x00, 0x51);
	usleep(t_uss * 1000);
	
	lowbyte  = wiringPiI2CReadReg8(fd_b, 0x03);
	highbyte = wiringPiI2CReadReg8(fd_b, 0x02);
	val = lowbyte + highbyte * 256;
	
	if(val < uss_min || val > uss_max){
		return -1;
	}else{
		return val + dist_center;
	}
}
