#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 

/*
	If number_of_iterations = 3, then we will get 8 processess. 
	If number_of_iterations = 5, then we will get 32 processess.
	
	Formula: number of processess = 2^n where n = number of times when 
	function fork() was called
	
	Explanation of the output:
	Every time when we call function fork() it starts a new process and 
	the new process starts to execute the same program from the line
	when it was called. So, in our loop on each iteration initally fork() does
	and then each process is sleeping for 5 seconds. 
	
	Thank you.
*/

int main() 
{ 	
	int number_of_iterations = 3; //or 5
	
	for(int i = 0; i < number_of_iterations; i++) {
		pid_t pid = fork(); 

		if (pid == 0) {
			printf("Hello from child[%d]\n", pid);
		} else if(pid > 0) {
			printf("Hello from parent[%d]\n", pid);
		} else {
			printf("Uknown error occured");
		}
	
		sleep(5);
	}
	
	return 0; 
} 

