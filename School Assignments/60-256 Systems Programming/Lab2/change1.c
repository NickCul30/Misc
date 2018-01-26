// change1.c
// Nicholas Culmone
// Changes the string 101 to an integer 101 in the list1.txt file

// INCLUDE SECTION
#include <unistd.h>
#include <fcntl.h>

// MAIN PROGRAM FOLLOWS
int main(void){
    int num = 101;

    int fd = open("list1.txt", O_WRONLY, 0777);
    write(fd, &num, 3);

    close(fd);

    return 0;
}