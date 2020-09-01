#include <stdio.h>
#include <stdlib.h>

//arguments: pointer to array and the size of the given array
//sort in increasing order
void bubble_sort(int arr[], int size) {
	int i, j;
	for(i = 0; i < size; i++) {
		for(j = 0; j < size - 1; j++) {
			if(arr[j] > arr[j + 1]) {
				//swap elements
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

#include <stdio.h>
int main(){
 int a[8] = {-1, -2, 5, 4, 3, 2, 3, 0};
 
 //determine the size of the given array
 int size = sizeof(a) / sizeof(a[0]);
 int i;
 
 printf("Before sort:");
 for(i = 0; i < size; i++) {
 	printf("%d ", a[i]);
 }
 
 bubble_sort(a, size);
 
 printf("\nAfter sort:");
 for(i = 0; i < size; i++) {
 	printf("%d ", a[i]);
 }
 
 getchar();
 return 0;
}
