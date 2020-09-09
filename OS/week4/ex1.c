#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 

/*
	If we run this program 10 times, in our output we will see
	20 hello's: 10's hello from children and 10's hello from parents.
	
	The output will contain the PID which is provided by function call
	fork(), and we will have 2 proccesses: a parent process and a child process,
	then if-statement will differentiate 2 different processes and print the line
	which depends PID's value.
	
	PID value is 0 for any child process. PID value > 0 determines parents' process,
	and PID value < 0 returns an error(a new process was not created by some reason).
	
	Thank you.
*/

int main() 
{ 	
	pid_t pid = fork(); 
	int n = 10; //by the task this value equals to 10

	if (pid == 0) {
		printf("Hello from child[%d - %d]\n", pid, n);
	} else if(pid > 0) {
		printf("Hello from parent[%d - %d]\n", pid, n);
	} else {
		printf("Uknown error occured");
	}
	
	return 0; 
} 

