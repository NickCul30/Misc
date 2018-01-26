// client.c
// Nicholas Culmone

#include <fcntl.h> 
#include <stdio.h>
#include <stdlib.h>
#include <signal.h> 
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
	int fd1, fd2, num;
	pid_t pid;
	char ch, ch2;
	char blanks[55]="                                                  | ";
	int writeblanks = 1;

	while (1) {
		fd1 = open("/tmp/fifo1", O_WRONLY);
		fd2 = open("/tmp/fifo2", O_RDONLY);
		printf("\nConnected.");
		printf("\nmy messages (client)                                received messages (server) \n");
		printf("-------------------------------------------------------------------------------\n");
		if ( (pid = fork()) == -1 ) {
			perror("fork");
			exit(1);
		}
		if ( pid == 0 ) {
			while (1) {
				while ((num = read(fd2, &ch2, 1)) == 1 ) {
					printf("%c", ch2);

					if ( writeblanks == 1 ){
						write(1, blanks, sizeof(blanks)); 
						writeblanks = 0;
					}
					write(1, &ch2, 1);
					if (ch2 == '\n'){
						writeblanks = 1;
					}
				}
				printf("%c %d\n", ch2, num);
				break;
			}
		}
		else{
			while ((ch = getchar()) != -1){
				write(fd1, &ch, 1); 
			}
			printf("%d\n", ch);
		}

		close(fd1);
		close(fd2);
		kill(pid, SIGTERM);
	}
}