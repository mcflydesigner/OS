#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include <pthread.h>

void *func(void *var) {
	printf("Hello from thread with ID %d\n", *(int*)var);
	//pthread_exit(0);	
}

/*
	When we run the 1 version of the program, we couldn't not define the 
	order of printing threads, the order is different everytime because 
	thread scheduler decides the order of their execution.
	Main func:
	int main() {
		int n = 10;

		pthread_t thread_ids[n];
		for(int i = 0; i < n; i++) {
			pthread_create(&thread_ids[i], NULL, func, &thread_ids[i]);
			printf("Hey, I created a thread with ID: %d\n", thread_ids[i]);
		}
		
		pthread_exit(0);
		
		
		return 0;
	}
	
	When we run current version of the program(strict order), when we run
	a threat we should wait until it finishes, and only then start a new thread,
	in this case we will have ordered execution.
*/
  
int main() {
	int n = 10;

	for(int i = 0; i < n; i++) {
		pthread_t thread_id;
		
		pthread_create(&thread_id, NULL, func, &thread_id);
		pthread_join(&thread_id, NULL); //Wait for current thread to finish, then create another one
	}
	
	pthread_exit(0);
	
	
	return 0;
}
