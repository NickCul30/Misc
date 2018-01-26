//primeFactor.c
//Nicholas Culmone

#include <stdio.h>
#include <stdbool.h>


int readNum(){ //reads number entered by user, loops until they enter a valid number
	int num = 0;
	while(num <= 1){
		printf("Enter a valid number (>1): "); //prompts user & gets inputs
		scanf("%d", &num);
		if(num <= 1) printf("Invalid number.\n"); //chcks if invalid number, prompts user
	}

	return num;
}

int isPrime(int n){ //checks if a number is prime

	//loops up to half the number, as there can be no prime factors of a number bigger than half of a number
	for(int i=2;i<=n/2;i++){
		if(n % i == 0) return false; //if there is a prime factor returns false
	}
	return true;
}

int findPrimeCount(int n, int f){ //returns how many times a prime is in a number
	int count = 0;

	while(n % f == 0){ //loops while they divide evenly
		n /= f;
		count ++;
	}

	return count;
}

int main(){
	int user = readNum(); //user input
	int pCount = 0; //how many times a number is in the user's num
	printf("%d = 1 ", user);
	
	for(int i=2;i<=user;i++){ //loops through all numbers up to the user's number
		if(isPrime(i)){ //checks if the number is prime first
			pCount = findPrimeCount(user,i);
			if(pCount != 0) printf("x (%d^%d) ", i, pCount); //if a prime is a multiple of user's num
		}
	}

	return 0;
}