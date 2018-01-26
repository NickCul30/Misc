//Lab5b.c
//Nicholas Culmone
//A program that generates an array of randomized integers from 0-100
//then sorts it using bubble sort (while using pointer notation)

// LIBRARY PACKAGES INCLUDED BELOW
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

// DEFINE SECTION BELOW
#define SIZE 20

// FUNCTION PROTOTYPE STATEMENTS FOLLOW
void FillArray(int *array, int size);		// Fills the array with sudo-random numbers with the range of 0-100
void PrintArray(int *array, int size);		// Prints the array given the array and its size
void Swap(int *x, int *y);					// Swaps the values pointed to by two given pointers x,y
void BubbleSort(int *array, int size);		// Sorts an array using bubble sort while using pointer notation


// MAIN PROGREAM FOLLOWS
int main(){
	srand(time(NULL));

	// Testing the functions
	int NumList[SIZE];
	FillArray(NumList,SIZE);
	PrintArray(NumList,SIZE);
	BubbleSort(NumList,SIZE);
	PrintArray(NumList,SIZE);

	return 0;
}

// FUNCTION DEFINITIONS FOLLOW

/* 	Fills an array with sudo-random numbers ranging from 0-100 given the
	address to the first value of the array and its size
	Input: int *array, int size
*/
void FillArray(int *array, int size){
	for(int i=0;i<size;i++){
		*(array + i) = rand() % 101;
	}
}

/* 	Prints the array given the address to its first value and the size
	Input: int *array, int size
*/
void PrintArray(int *array, int size){
	for(int i=0;i<size;i++){
		printf("%d ", *array);
		array++;
	}
	printf("\n");
}

/* 	Sorts an array of integers in descending order using pointer notation
	and bubble sort
	Input: int *array, int size
*/
void BubbleSort(int *array, int size){
	bool sorting = true;
	int *start = array;

	while(sorting){
		sorting = false;
		for(array = start; array < start+size; array++){
			if(*array < *(array+1)){
				Swap(array,array+1);
				sorting = true;
			}
		}
	}
}

/* 	Swaps the values pointed to by two pointers
	Input: int *x, int *y
*/
void Swap(int *x, int *y){
	int tmp = *x;
	*x = *y;
	*y = tmp;
}