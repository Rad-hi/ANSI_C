/*	
	PAGE: 22
	---
	Ex: Write a program to copy its input to its output, replacing 
		each string of one or more blanks by a single blank
 */

#include <stdio.h>

int main(){

	int c, found = 0;
	
	while ((c = getchar()) != EOF) {

		if (c == ' ' && found) continue;
		else if (c == ' ' && !found) found = 1;
		else if (c != ' ' &&  found) found = 0;

		printf("%c", c);
	}
	printf("\n");
}