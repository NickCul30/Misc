// Title: Lab2.c
// Author: Nicholas Culmone
// Last Modified: January 24th 2017
// Objective: Write functions to compute Summation (n), Factorial (n), Fibonacci (n),
// GCD (x,y) and Power (a,b), returns an error message if the input is out of range.
// All of these functions are done recursively.

//LIBRARY PACKAGES INCLUDED BELOW
#include <stdio.h>

// FUNCTION PROTOTYPE STATEMENTS FOLLOW
long int Summation(int n);			// Returns the summation from 1 to n
long int Factorial(int n);			// Returns n!
long int Fibonacci(int n);			// Returns the nth fibonacci number
long int gcd(int x, int y);			// Returns the greatest common denominator of x & y
long int Power(int a, int b);		// Returns a^b

// MAIN PROGRAM FOLLOWS
int main(){
	while(1){

		// Variable setting
		int a, b, s = 1;
		long int ans;

		// Prompts and gets user input
		printf("Select a Function:\n1. Exit\n6. Summation (int n)\n7. Factorial (int n)\n8. Fibonacci (int n)\n9. gcd (int x, int y)\n10. Power (int a, int b)\n\n");
		scanf("%d", &s);

		switch(s){ // Selects which function to run based on user input
			case 1: return 0; // Exit case

			case 6: // Summation
				printf("Enter n: ");
				scanf("%d", &a); // Prompts

				if(a < 1) ans = -1;
				else ans = Summation(a);
				break;

			case 7: // Factorial
				printf("Enter n: ");
				scanf("%d", &a);  // Prompts

				if(a < 0) ans = -1; // Error Handling
				else ans = Factorial(a);
				break;

			case 8: // Fibonacci
				printf("Enter n: ");
				scanf("%d", &a);  // Prompts

				if(a < 0) ans = -1; // Error Handling
				else ans = Fibonacci(a);
				break;

			case 9: // GCD
				printf("Enter x and y (space seperated): ");
				scanf("%d %d", &a, &b);  // Prompts

				if(a < 0 || b < 0) ans = -1; // Error Handling
				else ans = gcd(a,b); 
				break;

			case 10: // Power
				printf("Enter a and b (space seperated): ");
				scanf("%d %d", &a, &b);  // Prompts

				if(a < 1 || b < 0) ans = -1; // Error Handling
				else ans = Power(a,b);
				break;

			default: ans = -1; break; // Default when incorrect input
		}

		// Prints final ans or incorrect input
		if(ans == -1) printf("Incorrect Input.\n\n");
		else printf("%ld\n\n", ans);
	}
}

// FUNCTION DEFINITIONS FOLLOW

/* 	Calculates summation from 1 to n
	Input: int n
	Output: returns the summation from 1 to n (int)
*/

long int Summation(int n){
	if(n == 0) return 0;		// Base case when n = 0
	return Summation(n-1) + n;	// Recurses when n > 0
}

/*	Objective: calculates n!
	Input: int n
	Output: an int value = n!
*/

long int Factorial(int n){
	if(n == 0) return 1;		// Base case when n = 1
	return Factorial(n-1) * n;	// Recurses when n > 1
}

/*	Objective: calculates the nth fib number
	Input: n
	Output: int, nth fib number
*/

long int Fibonacci(int n){
	if(n == 0) return 0;		// Base case when n = 0
	else if(n == 1) return 1;	// Base case when n = 1
	else return Fibonacci(n-1) + Fibonacci(n-2);	// Recurses when n > 1
}

/*	Objective: calculates greatest common denominator of x,y
	Input: int x, int y
	Output: The GCD of x and y
*/

long int gcd(int x, int y){
	if(y == 0) return x;		// Base case when a common denominator is found
	else return gcd(y, x % y);	// Recurses when not base case
}

/*	Objective: calculates a^b
	Input: int a, int b
	Output: an int value = a^b
*/

long int Power(int a, int b){
	if(b == 0) return 1;		// Base case when b = 0
	return Power(a, b-1) * a;	// Recurses when b > 0
}