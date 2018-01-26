// MergeImage.c
// Nicholas Culmone
// A program that takes in two PPM P6 images and merges them by making a new file
// which places the second one in the top-right corner of the first one.

// INCLUDE SECTION
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

// FUNCTION DEFINITIONS FOLLOW
int readHeader(int fd, char type[2], char wid[5], char hei[5]);

// MAIN PROGRAM FOLLOWS
int main(int argC, char *argV[]){
	if(argC != 4) return 1;

	// Loading the images
	int img1 = open(argV[1], O_RDONLY, 0777);
	int img2 = open(argV[2], O_RDONLY, 0777);

	char wid1[5], hei1[5], wid2[5], hei2[5], t1[2], t2[2];
	int w1, h1, w2, h2;

	// Stores the header and gets the length of the header
	int l1 = readHeader(img1, t1, wid1, hei1);
	readHeader(img2, t2, wid2, hei2);

	// Changes the string values of the header into ints
	w1 = atoi(wid1);
	h1 = atoi(hei1);
	w2 = atoi(wid2);
	h2 = atoi(hei2);

	// Reports an error if the images are of a wrong type or size
	if(strncmp(t1,"P6",2) != 0 || strncmp(t2,"P6",2) != 0 || w2 > w1 || h2 > h1){
		char buf[] = "Incorrect input.\n";
		write(STDOUT_FILENO, buf, strlen(buf));
		return 0;
	}

	int newImg = open(argV[3], O_WRONLY | O_CREAT | O_TRUNC, 0777);

	// Reads and prints the header of the larger image to the new image
	char tmp[l1];
	lseek(img1, 0 , SEEK_SET);
	read(img1, tmp, l1);
	write(newImg, tmp ,l1);

	// Reads and prints the larger image to the new image
	for(int i=0;i<h1;i++){
		char buf[w1 * 3];
		read(img1, buf, w1 * 3);
		write(newImg, buf, w1 * 3);
	}

	lseek(newImg, l1, SEEK_SET);

	// Reads and prints the second image to the top-right corner of the new image
	for(int i=0;i<h2;i++){
		lseek(newImg, (w1 * 3) - (w2 * 3), SEEK_CUR);
		char buf[w2 * 3];
		read(img2, buf, w2 * 3);
		write(newImg, buf, w2 * 3);
	}

	close(img1);
	close(img2);
	close(newImg);

	return 0;
}

/*	Reads the header of P6 image, saves and returns the valuable information,
	This function assumes that the inputted image is at max 99999 x 99999
	Input: int fd, char type[3], char wid[5], char hei[5]
	Output: int length of the header in bytes
*/
int readHeader(int fd, char type[2], char wid[5], char hei[5]){
	
	int count = 7;
	read(fd, type, 2);
	lseek(fd, 1, SEEK_CUR);

	for(int i=0;i<5;i++){
		count ++;
		read(fd, wid + i, 1);
		if(*(wid + i) == ' '){
			*(wid + i) = '\0';
			break;
		}
	}

	for(int i=0;i<5;i++){
		count ++;
		read(fd, hei + i, 1);
		if(*(hei + i) == '\n'){
			*(hei + i) = '\0';
			break;
		}
	}

	lseek(fd, 4, SEEK_CUR);

	return count;
}
