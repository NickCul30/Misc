// consumer.c
// Nicholas Culmone
// The consumer program: takes the number from the file
// storage, removes 3 from it, and writes the new number
// back into the file
// Both producer and consumer assume the initial number
// in storage is greater than or equal to 5

// INCLUDE SECTION
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

// MAIN PROGRAM FOLLOWS
int main(){
	char num[2], newNum[2], buf[100];

	// reads the number
	int fd = open("storage", O_RDWR);
	read(fd, num, 2);

	int n = atoi(num);
	n -= 3;

	// writes it back into the file
	sprintf(newNum, "%d", n);
	lseek(fd, 0, SEEK_SET);
	write(fd, newNum, 2);

	// prompts
	sprintf(buf, "from consumer: current total is %d\n", n);
	write(STDOUT_FILENO, buf, strlen(buf));
	close(fd);

	// Executes producer
	execl("./producer", "producer", (char*)0);

	return 0;
}