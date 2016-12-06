//gcd.c
//Nicholas Culmone

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int gcd(int m, int n){ //gets gcd of two nums
	if(n == 0) return m;
	else gcd(n, m%n); //recursive step
}
int main(){
	srand(time(NULL)); //fix so same random num isn't generated every time
	int num1 = rand() % 99 + 2; //generates rand nums from 2-100
	int num2 = rand() % 99 + 2;

	int d = gcd(num1, num2); //calls gcd

	printf("The GCD of %d and %d is: %d", num1, num2, d); //prints gcd

	return 0;
}