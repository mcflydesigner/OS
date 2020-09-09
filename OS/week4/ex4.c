#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <stdlib.h>
#include <string.h>

/*
	Initially we read an input string until we meet a special
	symbol "\n" and then execute user's command via function system()
	and use fork() to create a new process. We execute user's commands
	only in child process(background);
*/

int main() 
{ 	
	printf("Welcome!\n");
	printf("Enter your command:\n>");
	
	char com[256]; //assume that the longest command is 256 symbols
	while(1) {
	
		//read a new command
		gets(com);
		
		pid_t pid = fork();
		
		//If user's command == "exit", then terminate the program
		if(strcmp("exit", com) == 0) {
			printf("Bye!");
			break;
		}
		
		if(pid == 0) {
			//Execute the command in the background
			//child process
			system(com);
			break;
		} else if (pid > 0) {
			//print info in the parent process
			//wait for a new command
			printf("> ");
		} else {
			//Notify user about that an problem
			//is occured
			printf("Uknown problem was occured. The command was not executed");
			
			//wait for a new command
			printf("> ");
		}
	
	}
	
	return 0; 
} 

