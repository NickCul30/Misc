// Title: Lab4.c
// Author: Nicholas Culmone
// Last Modified: February 14th 2017
//

// LIBRARY PACKAGES INCLUDED BELOW
#include <stdio.h>

// FUNCTION PROTOTYPE STATEMENTS FOLLOW
int *Largest(int *Array, int size);		// Returns the pointer to the largest value in an array
void Swap(int *x, int *y);				// Swaps the values pointed to by two given pointers a,b

// MAIN PROGRAM FOLLOWS
int main(){
	// Testing largest
	int array[10] = {12,4,5,3,5,7,4,2,4,13};
	int size = 10;
	int *big = Largest(array,size);
	printf("%d\n", *big);

	// Testing swap
	int a=4,b=2;
	printf("%d %d\n", a,b);
	Swap(&a,&b);
	printf("%d %d\n", a,b);

	return 0;
}

// FUNCTION DEFINITIONS FOLLOW

/* 	Given the pointer to the first spot in an array, and the size, returns
	the pointer to the largest value in the array.
	Input: int *array, int size
	Output: int pointer to the largest value in array
*/
int *Largest(int *array, int size){
	int *high = array, val;
	for(int i=1;i<size;i++){
		val = *(array + i);
		if(val > *high){
			high = array + i;
		}
	}
	return high;
}

/* 	Swaps the values pointed to by two pointers
	Input: int *x, int *y
*/
void Swap(int *x, int *y){
	int tmp = *x;
	*x = *y;
	*y = tmp;
}