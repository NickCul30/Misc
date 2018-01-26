// writer2.c
// Nicholas Culmone
// A program that writes two lines to the file list2.txt using
// System Call IO

// INCLUDE SECTION
#include <unistd.h>
#include <fcntl.h>

// MAIN PROGRAM FOLLOWS
int main(){
	char l1[40] = "GM\t101\tBuick\t2010\nFord\t102\tLincoln\t2005";

	int fd;

	fd = open("list2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0777);
	write(fd, l1, 39);
	close(fd);

	return 0;
}