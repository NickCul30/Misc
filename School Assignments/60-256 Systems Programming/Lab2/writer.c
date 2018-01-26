// writer.c
// Nicholas Culmone
// A program that writes two lines to the file list1.txt using
// System Call IO

// INCLUDE SECTION
#include <fcntl.h>
#include <unistd.h>

// MAIN PROGRAM FOLLOWS
int main(){
	char l1[44] = "101   GM\tBuick\t2010\n102   Ford\tLincoln\t2005";

	int fd;

	fd = open("list1.txt", O_WRONLY | O_CREAT | O_TRUNC, 0777);
	write(fd, l1, 43);
	close(fd);

	return 0;
}