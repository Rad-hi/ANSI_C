/*
    PAGE: 79
    ---
    Ex: Write a recursive version of the function reverse(s), 
    	which reverses the string s in place.
 */

#include <stdio.h>
#include <string.h>

#define MAX_INPUT_LEN			255

/* Inputs fills a buffer from stdin */
void input(char * s);

/* Reverses a string, given the beginning and the end indexes */
void reverse(char * s, unsigned char start, unsigned char end);

int main(){

	char s[MAX_INPUT_LEN];
	
	input(s); /* Get input string */

	printf("INPUT: %s\n", s);

	reverse(s, 0, strlen(s) - 1); /* Reverse it */

	printf("REVERSED: %s\n", s);

	return 0;
}

void input(char * s){
	int c;
	for(unsigned i = 0; (c = getchar()) != EOF && i < MAX_INPUT_LEN; i++)
		s[i] = c;
}

void reverse(char * s, unsigned char start, unsigned char end){
	char temp;
	if(start < end){
		temp = s[start], s[start] = s[end], s[end] = temp;
		
		/* Reverse two chars at a time, then advance to the middle from both sides */
		reverse(s, ++start, --end); 
	}
}