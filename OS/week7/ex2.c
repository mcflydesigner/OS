#include <stdio.h>
#include <stdlib.h>

<<<<<<< HEAD
int main() {
		
=======
/* 
	Excercise 2.
	Made by Vladislav Lamzenkov.
*/

int main() {
	int n;
	
	//Input data
	printf("Enter the length of the array: ");
	scanf("%d", &n);
	
	//Allocate memory for array
	int *arr = malloc(n * sizeof(int));
	
	//Print the array
	int i;
	for(i = 0; i < n; i++) {
		*(arr + i) = i;
		printf("arr[%d] = %d\n", i, *(arr+i));
	}
	
	//Release the memory
	free(arr);
>>>>>>> 3cde8f7bec48f9d87e8813ac1453ae9147825434
	
	return 0;
}
