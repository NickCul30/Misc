// Title: Lab1.c
// Author: Nicholas Culmone
// Last Modified: January 17th 2017
// Objective: Write functions to compute Summation (n), Factorial (n), Fibonacci (n),
// GCD (x,y) and Power (a,b), and returns an error message if the input is out of range.

//Include section
#include <stdio.h>

// Function Prototypes 
int Summation(int n);		// 
long int Factorial(int n);
int Fibonacci(int n);
int gcd(int x, int y);
int Power(int a, int b);

// MAIN PROGREAM FOLLOWS
int main(){ // test inputs
	while(1){
		int a, b, s = 0; //variable setting
		long int ans;
		//gets user input
		printf("Select a Function:\n0. Exit\n1. Summation (int n)\n2. Factorial (int n)\n3. Fibonacci (int n)\n4. gcd (int x, int y)\n5. Power (int a, int b)\n\n");
		scanf("%d", &s); //gets user input

		switch(s){ //runs a function based on the user input
			case 0: return 0; //exits program
			case 1: //summation
				printf("Enter n: ");
				scanf("%d", &a); //prompts
				ans = Summation(a);
				break;
			case 2: //factorial
				printf("Enter n: ");
				scanf("%d", &a);  //prompts
				ans = Factorial(a);
				break;
			case 3: //fibonacci
				printf("Enter n: ");
				scanf("%d", &a);  //prompts
				ans = Fibonacci(a);
				break;
			case 4: //gcd
				printf("Enter x and y (space seperated): ");
				scanf("%d %d", &a, &b);  //prompts
				ans = gcd(a,b); 
				break;
			case 5: //power
				printf("Enter a and b (space seperated): ");
				scanf("%d %d", &a, &b);  //prompts
				ans = Power(a,b);
				break;
			default: ans = -1; break; //incorrect input
		}
		if(ans == -1) printf("Incorrect Input.\n\n");
		else printf("%ld\n\n", ans); //prints final ans or incorrect input
	}
}

// FUNCTION DEFINITIONS FOLLOW

/* 	Calculates summation from 1 to n
	Input: int n
	Output: returns the summation from 1 to n (int)
*/
int Summation(int n){
	if(n < 1) return -1; //returns error message if n < 1

	int k = 0; //counter
	for(int i=1;i<=n;i++){ // iterates through 1 to n
		k += i; // adds i to k
	}
	return k;
}

/*	Objective: calculates n!
	Input: int n
	Output: an int value = n!
*/

long int Factorial(int n){
	if(n < 0) return -1; //returns error message when n < 0

	long int k = 1; //counter
	for(int i=1;i<=n;i++){ //iterates through 1 to n
		k *= i; // multiplies k by i
	}
	return k;
}

/*	Objective: calculates the nth fib number
	Input: n
	Output: int, nth fib number
*/

int Fibonacci(int n){
	if(n < 0) return -1; //returns error message when n < 0

	int t0 = 0, t1 = 1, k = 0; //counter vars
	for(int i=0;i<n;i++){ //iterates through 0 to n-1
		k = t0 + t1; //adds last 2 terms to k
		int tmp = t1; //sets t2 = k and t1 to t2
		t1 = k;
		t0 = tmp;
	}
	return k;
}

/*	Objective: calculates greatest common denominator of x,y
	Input: int x, int y
	Output: an int = GCD
*/

int gcd(int x,int y){
	if(x < 0 || y < 0) return -1; //error message when x or y < 0

	while(1){
		if(y == 0) return x; //when we find a gcd
		int tmp = y; //sets x = y and y = x % y
		y = x % y;
		x = tmp;
	}
}

/*	Objective: calculates a^b
	Input: int a, int b
	Output: an int value = a^b
*/

int Power(int a, int b){
	if(a < 1 || b < 0) return -1; //error message when x < 1 or b < 0

	int k = 1; //counter
	for(int i=0;i<b;i++){ //loops b times
		k *= a; //mults k by a
	}
	return k;
}