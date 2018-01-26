//test.c
//Nicholas Culmone

#include <stdio.h>

int f(int a, int b){
	return a + b;
}
int main(){
	int i;
	double x;

	i = f(5.43,12.4);
	x = f(83.654,12.4);
	f(83,24);
	printf("%d,%f", i , x);

	//printf("%d", i);
	return 0;
}