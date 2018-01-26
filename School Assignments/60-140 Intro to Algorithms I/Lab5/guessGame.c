//guessGame.c
//Nicholas Culmone

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	srand(time(NULL)); //fix so same random num isn't generated every time

	//goal - the random number to be guessed, userGuess - the user's guess
	int goal = rand() % 50 + 1, userGuess;

	for(int i=0;i<10;i++){ //loops 10 times, will break if guessed correctly
		printf("\nEnter your guess (between 1 & 50): "); //prompts user
		scanf("%d", &userGuess); //gets user input

		if(goal > userGuess){ //checks if guess is too low
			printf("Too low...");
		}
		else if(goal < userGuess){ //checks if guess is too high
			printf("Too high...");
		}
		else{ //when guess is correct, breaks out of loop
			break;
		}
	}

	if(userGuess == goal){ //happens right after the loop is broken, checks if the user's guess was correct
		printf("Correct, the number was %d", goal);
	}
	else{ //when the user has guessed wrong 10 times
		printf("\nSorry, the number was %d", goal);
	}
	
}