//q1_a.c
//Nicholas Culmone
//prints 8 digits of the unsigned int 40000 left aligned in a 15 digit field

#include <stdio.h>

int main(){
	unsigned int a = 40000;
	printf("%-15.8d",a);

	return 0;
}