// change2.c
// Nicholas Culmone
// Changes the string 101 to integer 101 in the file list2.txt by seeking to
// the part in the document using lseek

// INCLUDE SECTION
#include <unistd.h>
#include <fcntl.h>

// MAIN PROGRAM FOLLOWS
int main(){
	int num = 101;

	int fd = open("list2.txt", O_WRONLY, 0777);
	lseek(fd,3,SEEK_SET);
	write(fd, &num, 3);

	close(fd);

	return 0;
}