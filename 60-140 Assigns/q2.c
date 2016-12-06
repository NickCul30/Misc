//q2.c
//Nicholas Culmone

#include <stdio.h>

int main(){
	int i,j,k;

	i = 5;
	j = 3;
	printf("%d %d", i / j, i % j);

	i = 2;
	j = 3;
	printf("\n%d", (i + 10) % j);

	i = 7;
	j = 8;
	k = 9;
	printf("\n%d", (i + 10) % k / j);

	i = 1;
	j = 2;
	k = 3;
	printf("\n%d", (i + 5) % (j + 2) / k);


	return 0;
}