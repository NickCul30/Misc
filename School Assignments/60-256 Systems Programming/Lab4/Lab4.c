// Lab4.c
// Nicholas Culmone

// INCLUDE SECTION
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

// FUNCTION PROTOTYPES FOLLOW
int fact(int n);

// MAIN PROGRAM FOLLOWS
int main(int arg_c, char* arg_v[]) {
	int status;

	if(arg_c != 2) return -1; 	// Error handling for case when incorrect # or args supplied

	int n = atoi(arg_v[1]);		// Converts to int, then checks if in range
	if(n < 1 || n > 10) {
		printf("Not within the range of 1-10\n");
		return -1;
	}

	int s = strlen(arg_v[1]);

	// Writes to the new file
	int n_file = open("data.dat", O_WRONLY | O_CREAT | O_TRUNC, 0777);
	write(n_file, arg_v[1], s);
	close(n_file);

	// forks, then the child process evaluates the factorial
	if(fork() == 0) {
		int fd = open("data.dat", O_RDONLY);
		int num;
		char* num_c = malloc(s);
		read(fd, num_c, s);
		num = atoi(num_c);

		printf("%d\n", fact(num));
	}

	wait(&status); // Makes sure parent finishes after the child
	return 0;
}

// FUNCTION DEFINITIONS FOLLOW
int fact(int n) {
	int a = 1;

	for(int i=1;i<=n;i++){
		a *= i;
	}

	return a;
}
