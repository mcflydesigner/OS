#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Enter you string:");
    char inputSymbol = ' ', *input;
    input = (char*)malloc(sizeof(char));

    int i = 0;

    while(inputSymbol != '\n') {
        inputSymbol = getchar();
        realloc(input, sizeof(char));
        input[i++] = inputSymbol;
    }
    
    input[i] = '\0';

    int k;
	
    for(i = 0; input[i] != '\0'; i++);
    {
    	k = i-1;
    }
    
    int j;
    printf("The reversed string is:");
    
    for(j = 0; j <= i-1; j++)
    {
        printf("%c", input[k]);
        k--;
    }
	
    return 0;
}

