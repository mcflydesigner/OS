#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>
#include <sys/stat.h>

/* 
	Task 4.
	Done by Vladislav Lamzenkov, BS1905.
*/

int main() {
	//Open the source file
	int sourceFile = open("ex1.txt", O_RDONLY);
	if (sourceFile == -1) {
		printf("Sorry, couldn't open the source file");
		return -1;
	}
	
	//Get the size of the source file
	struct stat fstat;
	stat("ex1.txt", &fstat);
	int fileSize = fstat.st_size;
	
	//Create mapping for the source file
	char *sourceMap = mmap(NULL, fileSize, PROT_READ, MAP_PRIVATE, sourceFile, 0);
	if(sourceMap == MAP_FAILED) {
		printf("Sorry, couldn't map to the source file");
		return -1;
	}
	
	//Work with destionation file
	int destinationFile = open("ex1.memcpy.txt", O_RDWR);
	if (destinationFile == -1) {
		printf("Sorry, couldn't open the destination file");
		return -1;
	}
	
	//We should short or extend the size of the destination file
	//based on the size of the source file to transfer the data
	ftruncate(destinationFile, fileSize);
	if(ftruncate == -1) {
		printf("Sorry, couldn't change the size of the destination file");
		return -1;
	}
	
	//Create mapping for the destination file
	char *destinationMap = mmap(NULL, fileSize, PROT_READ | PROT_WRITE, MAP_SHARED, destinationFile, 0);
	if(destinationMap == MAP_FAILED) {
		printf("Sorry, couldn't map to the destination file");
		return -1;
	}
	
	//Copy from the source to the destination map
	memcpy(destinationMap, sourceMap, fileSize);
	
	//Write changed data from the map to the disk
	msync(destinationMap, fileSize, MS_SYNC);
	
	printf("The data was successfully copied from the source to the destination!"); 
	
	//Remove mappings 
	munmap(sourceMap, fileSize);
	munmap(destinationMap, fileSize);
	
	//Close the files
	close(sourceFile);
	close(destinationFile);
	
	return 0;
}
