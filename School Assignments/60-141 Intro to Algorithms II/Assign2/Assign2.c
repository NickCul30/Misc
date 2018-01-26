// Assign2.c
// Nicholas Culmone
// Solves a maze (or shows that there's no exit) by using the method
// of hugging the right wall. Does this recursively with the use of multiple
// functions.

// Directions:
// UP - 0
// RIGHT - 1
// DOWN - 2
// LEFT - 3

//LIBRARY PACKAGES INCLUDED BELOW
#include <stdio.h>
#include <stdlib.h>

// FUNCTION PROTOTYPE STATEMENTS FOLLOW
int findStart(char col[12][1]);															// Finds the r-coord of the start position given the first column
int validMove(char maze[12][12], int r, int c, int dir);								// Checks if a move is valid
void printMaze(char maze[12][12]);														// Prints the current state of the maze
void mazeTraversal(char maze[12][12], int r, int c, int dir, int startR, int startC);	// Traverses through the maze hugging the right wall
int coordsAreEdge(char maze[12][12], int c, int r);										// Checks if the current spot is an edge of the maze

//MAIN PROGRAM FOLLOWS
int main(){

	// Maze decliration (is overwritten by input redirection if done so)
	char maze[12][12] = {{'1','1','1','1','1','1','1','1','1','1','1','1'},
						{'1','0','0','0','1','0','0','0','0','0','0','1'},
						{'0','0','1','0','1','0','1','1','1','1','0','1'},
						{'1','1','1','0','1','0','0','0','0','1','0','1'},
						{'1','0','0','0','0','1','1','1','0','1','0','0'},
						{'1','1','1','1','0','1','0','1','0','1','0','1'},
						{'1','0','0','1','0','1','0','1','0','1','0','1'},
						{'1','1','0','1','0','1','0','1','0','1','0','1'},
						{'1','0','0','0','0','0','0','0','0','1','0','1'},
						{'1','1','1','1','1','1','0','1','1','1','0','1'},
						{'1','0','0','0','0','0','0','1','0','0','0','1'},
						{'1','1','1','1','1','1','1','1','1','1','1','1'}};

	char firstCol[12][1] = {"\0"}; 		// First column of values
	int r, c=0, dir = 1;				// Variable setting

	// Gets user/input redirection input
	int i;
	for(i=0;i<12;i++){
		// Comment the line below if not using input redirection
		scanf(" %c%c%c%c%c%c%c%c%c%c%c%c", &maze[i][0], &maze[i][1], &maze[i][2], &maze[i][3], &maze[i][4], &maze[i][5], &maze[i][6], &maze[i][7], &maze[i][8], &maze[i][9], &maze[i][10], &maze[i][11]);
		firstCol[i][0] = maze[i][0];
	}

	// gets the row coordinate of the start point
	r = findStart(firstCol);
	int startR = r, startC = c;

	// calls the recursive function mazeTraversal
	mazeTraversal(maze, r, c, dir, startR, startC);
	return 0;
}

//FUNCTION DEFINITIONS FOLLOW

/*	Finds the starting position given the first column of values
	Input: char col[12][1]
	Output: the r-coord of the starting position, given by the
		first 0 found in the input
*/

int findStart(char col[12][1]){
	int i;
	for(i=0;i<12;i++){
		if(col[i][0] == '0') return i;
	}
	return -1;
}

/*	Prints the maze to the output window.
	Input: char maze[12][12]
	Output: prints the values of the maze to the output window
*/

void printMaze(char maze[12][12]){
	int i,j;
	for(i=0;i<12;i++){
		for(j=0;j<12;j++){
			printf("%c", maze[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	//printf("Press any key to see next move");
	//getchar();
}


/*	Given coordinates and a direction that will be moved, checks
	if the move is valid.
	Input: char maze[12][12], int r, int c, int dir
	Output: a 0 denoting that the move is invalid, a 1 if valid
*/

int validMove(char maze[12][12], int r, int c, int dir){

	// Changes position based on direction
	switch(dir){
		case 0: r--; break;
		case 1: c++; break;
		case 2: r++; break;
		case 3: c--; break;
	}

	// case when move is invalid
	if(r >= 12 || r < 0 || c >= 12 || c < 0 || maze[r][c] == '1') return 0;
	return 1; // returns 1 otherwise (move is valid)
}

/*	Given coordinates, checks if it is an edge (exit) of the maze
	Input: char maze[12][12], int r, int c
	Output: a 0 denoting that it's not an edge, a 1 if so
*/

int coordsAreEdge(char maze[12][12], int r, int c){
	if(r == 11 || r == 0 || c == 11 || c == 0) return 1;
	return 0;
}

/*	Recursive function that goes through the maze and checks to see
	if there's an exit or not. Uses the method of hugging the right wall.
	Input: char maze[12][12], int r, int c, int dir, int startR, int startC
*/

void mazeTraversal(char maze[12][12], int r, int c, int dir, int startR, int startC){
	dir = (dir+1) % 4; 		// Checks spot to the right first

	// foundMove is a flag denoting whether a valid move was found
	int foundMove = validMove(maze,r,c,dir);

	while(foundMove == 0){
		dir = (dir-1) % 4;		// Rotates counterclockwise looking for valid moves
		if(dir==-1) dir = 3;
		foundMove = validMove(maze,r,c,dir);
	}

	maze[r][c] = 'X';		// Puts an 'X' in the position that was moved to

	// Changes position based on direction
	switch(dir){
		case 0: r--; break;
		case 1: c++; break;
		case 2: r++; break;
		case 3: c--; break;
	}

	// Line below was commented when making the script file
	printMaze(maze);

	// When an exit/entrance was found
	if(coordsAreEdge(maze,r,c) == 1){
		maze[r][c] = 'X';
		if(startR == r && startC == c) printf("\nThe maze has no exit");	// Case when the entance was found
		else printMaze(maze);												// Case when the exit was found
		return;
	}

	// When not an edge, call the function again
	mazeTraversal(maze,r,c,dir,startR,startC);
}