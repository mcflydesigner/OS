#include <stdio.h>
#include <stdlib.h>

/*
	Excercise 2.
	Made by Vladislav Lamzenkov.
	
	Please, take a look in "ex2.txt" file to see 
	the output of 'vmstat' command.
	
	So, in my case the amound of virtual memory used is 
	equal to 0(spwd == 0 during the execution time). 
	As you can observe swap in(si) == 0 and swap out(so) == 0 
	during the exectuion of the program. It means that there was no
	swapped memory. Moreover, it is ideal case since si == so == 0.
	
	
	
	Excercise 3 part:
	Analyzing the table which was provided by "top -d 1" command we see:
	As time was growing, every second parameters VIRT and RES were growing 
	since program requires more memory every second(using realloc funct). 
	In addition, parameter "TIME+" was proving too since it indicates 
	the amount of working time since the moment when the process started.
	
	
	
*/


int main() {
	int *ptr = NULL;
	
	const int one_mb = 1024 * 1024;
	int i;
	size_t size_of_memory = 0;
	for(i = 0; i < 10; i++) {
		//Increase the required size of mem by 10 MB
		size_of_memory += 10 * one_mb;
		//Realloc
		ptr = realloc(ptr, size_of_memory);
		//Full mem with 0
		memset(ptr, 0, size_of_memory);
		printf("Now I am using %d bytes of memory\n", (size_of_memory / one_mb));
		sleep(1);	
	}
	
	free(ptr);
	printf("I finished. The memory is free now!");
	return 0;
}
