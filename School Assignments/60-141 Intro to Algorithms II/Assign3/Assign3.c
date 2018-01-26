// Assign3.c
// Nicholas Culmone
// Analyzes text given through stdin, prints out the number of times each letter
// is found, the frequency of the lengths of words and the number of occurances of
// each word.

// LIBRARY PACKAGES INCLUDED BELOW
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

// FUNCTION PROTOTYPE STATEMENTS FOLLOW
void letterAnalysis(char lines[10][81], int l);					// Prints the amount of occurances per each letter
int wordLengthAnalysis(char lines[10][81], int l);				// Prints the amount of occurances per each word length
void wordAnalysis(char lines[10][81], int l, int tokens);		// Prints the amount of occurances per each unique word

// MAIN PROGREAM FOLLOWS
int main(){
	// Variable Init
	int l, i;
	char tmp[3];
	char lines[10][81], lines2[10][81];

	// Input
	scanf("%[^\n]%*c", tmp);
	l = atoi(tmp);

	for(i=0;i<l;i++){
		scanf("%[^\n]%*c", lines[i]);
		strcpy(lines2[i], lines[i]);
	}

	// Calling functions
	letterAnalysis(lines2, l);
	int tokens = wordLengthAnalysis(lines2, l);
	wordAnalysis(lines, l, tokens);

	return 0;
}

// FUNCTION DEFINITIONS FOLLOW

/* 	Iterates through every word in lines, splitting them into tokens using
	strtok, then either adds the word into a new spot in words, or if that
	word has slready been used, then it will add one instance to freq[spot of word].
	Then will print out all the occurances of each word.
	Input: char lines[10][81], int l, int tokens
*/
void wordAnalysis(char lines[10][81], int l, int tokens){
	// Variable init
	char *words[tokens];
	int freq[tokens];
	memset(freq, 0, sizeof(freq));
	memset(words, '\0', sizeof(freq));
	int i, j, unique = 0, maxWid = 0;
	bool flag;

	// Iterating though every line
	for(i=0;i<l;i++){
		char *tmp = strtok(lines[i]," ");
		while(tmp != NULL){

			flag = false;
			for(j=0; freq[j] != 0; j++){

				// When the word is a duplicate
				if(strcmp(tmp,words[j]) == 0){
					freq[j] ++;
					flag = true;
				}
			}

			// When a unique word is found
			if(flag == false){
				words[unique] = tmp;
				freq[unique] = 1;
				unique ++;
				if(strlen(tmp) > maxWid) maxWid = strlen(tmp);
			}

			tmp = strtok(NULL, " ");
		}
	}

	// Prints the frequences of each word
	printf("\n");
	for(i=0;freq[i] != 0;i++){
		int space = maxWid - strlen(words[i]) + 2;
		printf("\"%s\"%*c\tappeared %d time%c\n", words[i], space, ' ', freq[i], freq[i] > 1 ? 's':'\0');
	}
	return;
}

/* 	Goes through every word in each line and applies strtok to
	them, then gets the length of the word and adds one to
	freq[length-1]. Then, all of the lengths' frequencies are printed-
	Input: char lines[10][81], int l
	Output: the number of valid words found in the inputted lines
*/
int wordLengthAnalysis(char lines[10][81], int l){
	int freq[20] = {0};
	int i, tokens;

	// Iteratese though each line
	for(i=0;i<l;i++){
		char *tmp = strtok(lines[i]," ");
		while(tmp != NULL){
			if(strlen(tmp) > 0){
				freq[strlen(tmp) - 1] ++;
				tokens ++;
			}
			tmp = strtok(NULL, " ");
		}
	}

	printf("\n");
	for(i=0;i<20;i++){
		if(freq[i] != 0) printf("%d\tword%c of length %d\n", freq[i], freq[i]>1?'s':'\0', i+1);
	}

	return tokens;
}

/* 	Counts the amount of times each letter in found in the given strings,
	then prints a table with a variable width field of the frequencies.
	Input: char lines[10][81], int l
*/
void letterAnalysis(char lines[10][81], int l){
	int freq[26] = {0};
	int i,j;

	// Iterates though every line, and adds to freq, depecding on which letter it is
	for(i=0;i<l;i++){
		for(j=0;lines[i][j] != '\0';j++){
			lines[i][j] = tolower(lines[i][j]);
			if(isalpha(lines[i][j])) freq[lines[i][j] - 'a'] ++;
		}
	}

	// Getting the variable width for the num of each char
	int max = 0;
	for(i=0;i<26;i++) if(freq[i] > max) max = freq[i];
	int width = floor (log10 (abs (max))) + 1;

	// Prints the totals, right aligned in a variable width field
	printf("\nTotal letter counts:\n");
	for(i=0;i<26;i++){
		printf("%c: %*d\n", 'a'+i, width, freq[i]);
	}
}