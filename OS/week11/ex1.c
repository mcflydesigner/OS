#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>

//A constant, since the size of "This is a nice day" 18 bytes
#define STRING_SIZE 18

/* 
	Task 1.
	Done by Vladislav Lamzenkov, BS1905.
*/

int main()
{	
	//Open the file in read and write mode
	int file = open("ex1.txt", O_RDWR);
	if(file == -1) {
		printf("Sorry, but I couldn't open the file");
		return -1;
	}
	
	//Reposite the file offset
	lseek(file, STRING_SIZE, SEEK_SET);
	
	//Write last byte to the file
	if(write(file, "", 1) == -1) {
		printf("Sorry, couldn't write last byte to the file");
		return -1;
	}
	
	//Memory Mapped File
	char *mapping = mmap(0, STRING_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, file, 0);
	
	if(mapping == MAP_FAILED) {
		printf("Sorry, couldn't map to the file");
		return -1;
	}
	
	//String which is going to be written in the file
	char contentToWrite[STRING_SIZE+1] = "This is a nice day";
	//Copy from the string above to the mapped file
	memcpy(mapping, contentToWrite, STRING_SIZE);
	
	//Write our string which we put before to the disk
	msync(mapping, STRING_SIZE, MS_SYNC);
	
	//After this, remove the mapping
	munmap(mapping, STRING_SIZE);
	close(file);
	printf("Done writing!");
		
	return 0;
}
