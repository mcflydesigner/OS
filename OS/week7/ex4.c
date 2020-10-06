#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>

/* 
	Excercise 4.
	Made by Vladislav Lamzenkov.
*/

//Function to determine the max element between 2 arguments
//It returns max elem 
size_t max(size_t a, size_t b) {
	return (a > b) ? a : b;
}

//Function to determine the min element between 2 arguments
//It returns min elem 
size_t min(size_t a, size_t b) {
	return (a > b) ? b : a;
}

void* my_realloc(void *ptr, size_t _NewSize) {
	//If pointer is 0, do the allocation of memory
	if(ptr == NULL) {
		return malloc(_NewSize);
	}
	
	//If size is 0, then just free the mem
	if(_NewSize == 0) {
		free(ptr);
		
		return NULL;
	}
	
	//Please, notice:
	//For windows machine I use _msize function to get the size of the allocated memory.
	//If you want to complite this program for MacOS use malloc_size
	//If you want to complite this program for Linux use malloc_usable_size
	size_t old_size = _msize(ptr);
	
	//Allocate memory for resulting pointer
	void *new_ptr = malloc(_NewSize);
	
	//Determine the min size between old size and new size
	size_t min_size = min(old_size, _NewSize);
	
	//Copy _NewSize bytes from ptr to new_ptr
	//We use this function to copy elements from old array
	//to a new one ONLY if it needs
	
	//Please, notice, that according to the task: 
	//Newly allocated memory will be uninitialized
	memcpy(new_ptr, ptr, min_size);
	
	//Release memory of the old pointer
	free(ptr);
	
	return new_ptr;
}

int main(){
	//Test case ONLY
	
	//Allows you to generate random number
	srand(time(NULL));

	// Allows user to specify the original array size, stored in variable n1.
	printf("Enter original array size:");
	int n1 = 0;
	scanf("%d", &n1);

	//Create a new array of n1 ints
	int* a1 = malloc(n1 * sizeof(int));
	int i;
	for(i = 0; i < n1; i++){
		*(a1 + i) = 100;
		
		//Print each element out (to make sure things look right)
		printf("%d ", *(a1 + i));
	}

	//User specifies the new array size, stored in variable n2.
	printf("\nEnter new array size: ");
	int n2 = 0;
	scanf("%d", &n2);

	//Dynamically change the array to size n2
	a1 = my_realloc(a1, (n2*sizeof(int)));

	//Please, notice, here we use uninitialized variables
//	if(n2 > n1) {
//		for(i = n1; i < n2; i++) {
//			*(a1 + i) = 0;
//		}	
//	}
	
	//To check that we use uninitialized variables
	int max_length = max(n1, n2);

	for(i = 0; i < max_length; i++){
		//Print each element out (to make sure things look right)
		printf("%d ", *(a1 + i));
	}
	
	printf("\n");
	
	//Release the memory
	free(a1);
	
	return 0;
}
