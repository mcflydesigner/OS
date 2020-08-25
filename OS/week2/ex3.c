#include <stdio.h>
#include <stdlib.h>

//height n
//width 2n-1
void printTree(int n) {
	int i, j;
	for(i = 0; i < n; i++) {
		for(j = i + 1; j < n; j++) {
			printf(" ");
		}
    	for(j = 0; j <= 2*i; j++) {
    		printf("*");
		}
    	printf("\n");
	}
}

int main() {
    int n;
    printf("Enter n: ");
	scanf("%d", &n);
	printTree(n);

    return 0;
}

