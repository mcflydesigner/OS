#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
	int temp = *a; 
	*a = *b;
	*b = temp;
}

int main() {
    int a, b;
    printf("Enter a: ");
	scanf("%d", &a);
	printf("Enter b: ");
	scanf("%d", &b);
	
	swap(&a, &b);
	
	printf("Value of a: %d \n", a);
	printf("Value of b: %d", b);

    return 0;
}

