/*  
	PAGE 22:
	---
	PROVIDED EXAMPLE
	---
	How to run this code:
		1- Create a file containing whatever you want
		3- Compile this code: 	$ gcc hello.c -o hello.out
		2- Run this code: 	    $ cat thing | ./hello.out
 */

#include <stdio.h>
#define IN 1  /* inside a word */
#define OUT 0 /* outside a word */
int main(){

	int c, nl, nw, nc, state;
	state = OUT;
	nl = nw = nc = 0;
	while ((c = getchar()) != EOF) {
		++nc;
		if (c == '\n') ++nl;
		
		if (c == ' ' || c == '\n' || c == '\t') state = OUT;
		else if (state == OUT){
			state = IN;
			++nw;
		}
	}
	printf("%d %d %d\n", nl, nw, nc);
}