// Lab7b.c
// Nicholas Culmone
// Make an array to store structs called myWord, which hold a string and its length.
// Then, print the array, sort it, and print again.

// LIBRARY PACKAGES INCLUDED BELOW
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// STRUCT DEFINITIONS FOLLOW
struct myWord{
	char Word[21];
	int Length;
};

// FUNCTION PROTOTYPE STATEMENTS FOLLOW
void BubbleSort(struct myWord words[20], int s);		// Bubble sort implemented for myWord

// MAIN PROGREAM FOLLOWS
int main(){
	// Variable init
	struct myWord words[20];
	char myString[] = "the cat in the hat jumped over the lazy fox main";
	char *tmp = strtok(myString, " ");
	int i=0;

	// Copies the words from myString to words
	while(tmp != NULL){
		strcpy(words[i].Word, tmp);
		words[i].Length = strlen(tmp);
		tmp = strtok(NULL, " ");
		i++;
	}

	// Prints words
	for(int j=0; j<i; j++){
		printf("%s\t%d\n",words[j].Word, words[j].Length);
	}

	BubbleSort(words, i);
	printf("\n");

	// Prints words
	for(int j=0; j<i; j++){
		printf("%s\t%d\n",words[j].Word, words[j].Length);
	}

	return 0;
}

// FUNCTION DEFINITIONS FOLLOW

/*	Sorts an array of myWords using the bubble sort method.
	Input: struct myWord words[20], int s (amount of non-null entries in words)
*/
void BubbleSort(struct myWord words[20], int s){
	bool sorting = true;
	while(sorting){
		sorting = false;
		for(int i=0;i<s-1;i++){
			if(strcmp(words[i].Word, words[i+1].Word) > 0){
				sorting = true;
				struct myWord tmp = words[i];
				words[i] = words[i+1];
				words[i+1] = tmp;
			}
		}
	}
}