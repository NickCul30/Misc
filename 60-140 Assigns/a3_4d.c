//a3_4d.c
//Nicholas Culmone

#include <stdio.h>
#include <math.h>

int main(){
	float x = 10;

	while(x >= 1.001){
		printf("%f ", x);
		x = sqrt(x);
	}

	return 0;
}