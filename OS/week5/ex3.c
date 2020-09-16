#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

/* Implimentation of producer-consumer problem */

//Initially, we set up the parameteres of our system

int global_count = 0; //Current position in the buffer
int global_capacity = 5; //The size of the buffer
int global_data[5]; //Storing data here 

//Consuming data from the buffer
void* consumer(void *arg)
{
	while(1)
	{
		while(global_count <= 0) {
			//Busy waiting
		}
		
		if(global_count <= 0)
		{
			//if we are here, something went wrong(race condition occured);
			printf("Error: buffer is empty.");
			return -1;
		}

		//take the data from the buffer
		global_data[global_count] = rand() % 10 + 1; //store a number
		global_count -= 1;
	}
}

//Produce data for the consumer
void* producer(void *arg)
{
	while(1)
	{
		while(global_count >= global_capacity) {
			//Busy waiting
		}
		
		if(global_count >= global_capacity)
		{
			//if we are here, something went wrong(race condition occured);
			printf("Error: buffer is full.");
			return -1;
		}
		//new data, store it in the buffer
		global_data[global_count] = rand() % 10 + 1; //store a number
		global_count += 1;
	}
}




int main()
{
	pthread_t t_prod, t_cons;
	//Create threads for consumer and producer
	pthread_create(&t_cons, NULL, consumer, NULL);
	pthread_create(&t_prod, NULL, producer, NULL);
	
	//Not to terminate the program wait all threads to finish	
	pthread_join(t_prod, NULL);
	pthread_join(t_cons, NULL);
	
	pthread_exit(0);
	
	return 0;
}
