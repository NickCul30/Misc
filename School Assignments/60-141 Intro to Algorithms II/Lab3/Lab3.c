// Lab3.c
// Nicholas Culmone
// Last Modified: Feb. 7th 2017
// Objective: Create a 2D Array and write the functions:
// PopulateRandom2D: to fill the array with random numbers
// from 1-M*N (non-repeating)
// LinearSearch2D: find whether a value is contained in the array
// LeftShift2D: shift the array to the left by one spot
// PrintArray2D: print the 2D array

// LIBRARY PACKAGES INCLUDED BELOW
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>

// DEFINE SECTION BELOW
#define M 5
#define N 6

// FUNCTION PROTOTYPE STATEMENTS FOLLOW
void PopulateRandom2D(int A2D[M][N]);			// Populates the array with sudo-random numbers
bool LinearSearch2D(int A2D[M][N], int n);		// Searches through the array to see if n is found in A2D
void PrintArray2D(int A2D[M][N]);				// Prints A2D
void LeftShift2D(int A2D[M][N]);				// Shifts the values in A2D to the left by one spot


// MAIN PROGREAM FOLLOWS
int main(){

	srand(time(NULL)); //done in order to make sudo-random numbers not repeat
	int A2D [M][N] = {0}; //declares the 2D array, and fills it with zeroes to start

	while(1){
		int s = 0, n = 0; // user entered variables

		printf("\nSelect a Function:\n0. Exit\n1. PopulateRandom2D\n2. LinearSearch2D\n3. LeftShift2D\n4. PrintArray2D\n\n");
		scanf("%d", &s); //gets user input

		switch(s){ //runs a function based on the user input
			case 0: return 0; //exits program
			case 1: //PopulateRandom2D
				PopulateRandom2D(A2D);
				break;
			case 2: //LinearSearch2D
				printf("Enter n: ");
				scanf("%d", &n); // Prompts
				printf(LinearSearch2D(A2D, n) ? "true\n" : "false\n");
				break;
			case 3: //LeftShift2D
				LeftShift2D(A2D);
				break;
			case 4: //PrintArray2D
				PrintArray2D(A2D);
				break;
			default: printf("Incorrect Input."); break; //incorrect input
		}
		
	}
}

// FUNCTION DEFINITIONS FOLLOW

/* 	Populates a 2D array with non-repeating sudo-random numbers from 1 to M*N
	Input: 2D Array A2D
*/

void PopulateRandom2D(int A2D[M][N]){
	int nums[M*N];
	for(int i=0;i<M*N;i++){
		nums[i] = i+1;
	}

	int end = M*N;

	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			int r = rand() % end;
			A2D[i][j] = nums[r];
			end --;
			nums[r] = nums[end];
			nums[end] = 0;
		}
	}
}

/* 	Does a linear search through the 2D array A2D, and tries to find n, if found returns true
	otherwise, returns false
	Input: 2D Array A2D, the value to be searched for, n
	Output: true or false depending if the value is found
*/

bool LinearSearch2D(int A2D[M][N], int n){
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			if(A2D[i][j] == n) return true;
		}
	}
	return false;
}

/* 	Shifts every value in A2D to the left by one spot in the array, puts the leftmost
	column in A2D to the furthest right
	Input: 2D Array A2D
*/

void LeftShift2D(int A2D[M][N]){

	for(int i=0;i<M;i++){
		int first = A2D[i][0];
		for(int j=0;j<N-1;j++){
			A2D[i][j] = A2D[i][j+1];
		}
		A2D[i][N-1] = first;
	}
}

/* 	Prints the 2D Array A2D
	Input: 2D Array A2D
	Output: prints the values in A2D line and space seperated
*/

void PrintArray2D(int A2D[M][N]){
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			printf("%2d ", A2D[i][j]);
		}
		printf("\n");
	}
}