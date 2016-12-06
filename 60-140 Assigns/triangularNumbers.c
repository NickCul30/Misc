//triangularNumbers.c
//Nicholas Culmone

#include <stdio.h>
#include <stdbool.h>

int readNum(){ //gets input
	int num = 0;

	while(num <= 0){ //loops until valid num
		printf("Enter a valid number (>0): "); //prompts user and gets input
		scanf("%d", &num);
		if(num <= 0) printf("Invalid number.\n"); //if num is invalid
	}
	return num;
}

int iterativeTriangularNumber(int n){ //using iterative approach finds tri num of n
	int tot = 0;
	for(int i=1;i<=n;i++){
		tot += i;
	}
	return tot;
}

int recursiveTriangularNumber(int n){ //using recursive approach finds tri num of n
	if(n == 1) return 1;
	return n + recursiveTriangularNumber(n-1);
}

int main(){
	int user = readNum(); //gets user num
	int a = iterativeTriangularNumber(user); //iterative tri num & prints
	printf("Iterative: Triangular number of %d is %d.\n",user, a);

	int b = recursiveTriangularNumber(user); //recursive tri num & prints
	printf("Recursive: Triangular number of %d is %d.\n",user, b);

	return 0;
}