// Assignment1.c
// Nicholas Culmone
// Writes n! in terms of powers of prime numbers. Takes in integer inputs
// until the input is 0, and prints out their factorials in terms of primes.

//Include Section
#include <stdio.h>
#include <stdbool.h>

//Function prototypes
int findPrimeCount(int n, int p);		//Finds how many times p can be multiplied into n!
int findNextPrime(int n);	       		//Finds the next prime number greater than n
bool isPrime(int n);			       	//Checks if n is prime, returns true or false accordingly

//MAIN PROGRAM FOLLOWS
int main(){
	bool first = true;

	while(1){
		// Variable setting
		int n = 0, i = 2, count = 0;
		scanf ("%d", &n); // Gets input from file

		if(n == 0) return 0;	// When program reaches the end of the file

		if(first) first = false;	// A flag for the first line
		else printf("\n\n");

		printf("%3d! =  ", n); 	//right aligns n in a 3 digit field
		while(i <= n){ 			//iterates through every prime number between 2 and n
			if(i != 2) printf("*");
			int times = findPrimeCount(n, i);
			printf("(%d^%d)", i, times);
			i = findNextPrime(i);
			count ++;
			if(count == 9){		// When it reaches the end of the line
				printf("\n%7s", " ");
				count = 0;
			}
		}
	}

	return 0;
}

//FUNCTION DEFINITIONS FOLLOW

/*	Finds the amount of times a prime num (p) can be evenly divided into n!
	Input: int n, int p
	Output: returns amt of times p is evenly divided into n!
*/

int findPrimeCount(int n, int p){
	int count = 0;
	int i;

	for(i=2;i<=n;i++){
		int tmp = i;
		while(tmp % p == 0){
			count ++;
			tmp /= p;
		}
	}

	return count;
}

/*	Finds the next prime number after n
	Input: prime int n
	Output: returns next prime number after n
*/

int findNextPrime(int n){
	n++;
	if(isPrime(n)) return n;
	else return findNextPrime(n);
}

/*	Checks if a number is prime
	Input: int n
	Output: bool denoting if n is prime or not
*/

bool isPrime(int n){
	int i;
	for(i=2;i<=n/2;i++){
		if(n % i == 0) return false;
	}
	return true;
}
