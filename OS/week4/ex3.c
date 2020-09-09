#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <stdlib.h>
#include <string.h>

/*
	Initially we read an input string until we meet a special
	symbol " " and then execute user's command via function system()
*/

int main() 
{ 	
	printf("Welcome!\n");
	printf("Enter your command:\n>");
	
	char com[256]; //assume that the longest command is 256 symbols
	while(1) {
		//read a new command
		scanf("%s", com);
		//execute
		system(com);
		//waiting for a new command
		printf("> ");
		
		//If user's command == "exit", then terminate the program
		if(strcmp("exit", com) == 0) break;
	}
	
	printf("Bye!");
	
	return 0; 
} 

