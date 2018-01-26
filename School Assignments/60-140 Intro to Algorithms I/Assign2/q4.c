//q4.c
//Nicholas Culmone

#include <stdio.h>

int main(){
	int i,j,k;

	i = 3; j = 4; k = 5;
	printf("%d ", i < j || ++j < k);
	printf("%d %d %d", i, j, k);

	i = 7; j = 8; k = 9;
	printf("\n%d ", i - 7 && j++ < k);
	printf("%d %d %d", i, j, k);

	i = 7; j = 8; k = 9;
	printf("\n%d ", (i = j) || (j = k));
	printf("%d %d %d", i, j, k);

	i = 1; j = 1; k = 1;
	printf("\n%d ", ++i || ++j && ++k);
	printf("%d %d %d", i, j, k);

	return 0;
}