#include <stdio.h>

/* 
	Excercise 5.
	Made by Vladislav Lamzenkov.
*/



int main(){
	//Initially, allocate memory for a pointer to a char pointer
	char **s = malloc(sizeof(char*));
	
	char foo[] = "Hello World";
	*s = foo;
	
	//S is not a sequence of symbols, s is an address of memory cell, so we do not see anything 
	//while printing("%s") for memory address.
	
	//To fix it and see the string "Hello wolrd" instead of the following string should be
	//printf("s is %s\n", *s); 
	printf("s is %s\n", s); 
	s[0] = foo;
	printf("s[0] is %s\n", s[0]);
	
	return 0;
}
