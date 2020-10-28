#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>

//A constant, since the size of task's string
#define STRING_SIZE 5

/* 
	Task 2.
	Done by Vladislav Lamzenkov, BS1905.
*/

int main()
{	
	char stringToBeWrriten[STRING_SIZE] = "Hello";
	
	//Set parameters for the output stream
	//_IOLBF = Line buffering
	//BUFSIZe = Size of the buffer by default
	setvbuf(stdout, NULL, _IOLBF, BUFSIZ);
	
	int i;
	for(i = 0; i < STRING_SIZE; i++) {
		printf("%c", stringToBeWrriten[i]);
		sleep(1);
	}
		
	return 0;
}
