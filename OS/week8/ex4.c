#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>

/*
	Excercise 4.
	Made by Vladislav Lamzenkov.
*/


int main() {
	int *ptr = NULL;
	
	struct rusage using;
	
	const int one_mb = 1024 * 1024;
	int i;
	size_t size_of_memory = 0;
	for(i = 0; i < 10; i++) {
		printf("\n");
		printf("Step %d\n", (i + 1));
		//Increase the required size of mem by 10 MB
		size_of_memory += 10 * one_mb;
		//Realloc
		ptr = realloc(ptr, size_of_memory);
		//Full mem with 0
		memset(ptr, 0, size_of_memory);
		//Get info
		getrusage(RUSAGE_SELF, &using);
		
		printf("Total amount of memory that belongs to the process = %ld\n", using.ru_maxrss);
		printf("Soft page faults = %ld\n", using.ru_minflt);
		printf("Hard page faults = %ld\n", using.ru_majflt);
		
		//Following parameters do not work on Linux OS
		/*
		printf("Shared memory size = %ld\n", using.ru_ixrss);
		printf("Heap memory size = %ld\n", using.ru_idrss);
		printf("Stack memory size = %ld\n", using.ru_isrss);
		*/

		printf("\n");
		
		sleep(1);	
	}
	
	free(ptr);
	printf("I finished. The memory is free now!");
	return 0;
}
