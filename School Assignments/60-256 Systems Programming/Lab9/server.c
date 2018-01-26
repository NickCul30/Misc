// server.c
// Nicholas Culmone

#include <fcntl.h> 
#include <stdio.h>
#include <stdlib.h>
#include <signal.h> 
#include <unistd.h>
#include <sys/stat.h>

void handler(int sig); //lets server stop the client nanoseconds before the server process ends

int main(int argc, char *argv[]) {

	int fd1, fd2;
	pid_t pid;
	char ch, ch2;
	char blanks[55] = "                                                    | ";
	signal(SIGINT, handler);
	int writeblanks = 1;

	unlink("/tmp/fifo1");
	unlink("/tmp/fifo2");

	if (mkfifo("/tmp/fifo1", 0777) || mkfifo("/tmp/fifo2", 0777)) {
		perror("fifo");
		exit(1); 
	}
	while (1) {
		printf("\nWaiting for connection...\n");
		fd1 = open("/tmp/fifo1", O_RDONLY);
		fd2 = open("/tmp/fifo2", O_WRONLY);

		printf("\nmy messages (server)                                received messages (client) \n");
		printf("-------------------------------------------------------------------------------\n");
		if ( (pid = fork()) == -1 ) {
			perror("fork");
			exit(1);
		}

		if ( pid == 0 ) {
			while (1) {
				while ( ( ch2 = getchar()) != -1){
					write(fd2, &ch2, 1); 
				}
				break;	
			}
		}
		else{
			while (read(fd1, &ch, 1) == 1 ) { 
				if ( writeblanks == 1 ){
					write(1, blanks, sizeof(blanks)); 
					writeblanks = 0;
				}
				write(1, &ch, 1);
				if (ch == '\n'){
					writeblanks = 1;
				}
			}
		}

		close(fd1);
		close(fd2);
		printf("\nClient left.\n\n\n");
		kill(pid, SIGTERM);
	}
}

void handler(int sig) {
	int fd2 = open("/tmp/fifo2", O_WRONLY);
	close(fd2);
	unlink("/tmp/fifo1");
	unlink("/tmp/fifo2");
	exit(0);
}