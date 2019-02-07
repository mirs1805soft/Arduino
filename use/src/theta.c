#include <stdio.h>
#include <math.h>
#include "theta.h"

double to_deg(double a){
	return a * 180.0 /(atan(1.0) * 4.0);
}

double pi(void){
	return atan(1.0) * 4.0;
}

int theta(int y, int x){
	double a = (double) y / x;
	double a_rad,a_deg;
	a_rad = atan(a);
	a_deg = to_deg(a_rad);
	int deg = round(a_deg);

	return deg;
}
