//weekend.c
//Nicholas Culmone

#include <stdio.h>
#include <stdbool.h>

int main(){
	int n = 00E2;
	bool weekend[] = {true,false,false,false,false,false,true}; //regular init
	bool weekend2[7] = {[0] = true, [6] = true}; //designated initializer

	printf("%d\n", n);
	printf("%d,%d,%d", weekend[0], weekend[6], weekend[3]);
	printf("\n%d,%d,%d", weekend2[0], weekend2[6], weekend2[3]);

	return 0;
}