/*	
	PAGE: 34
	---
	Ex: Write a program detab that replaces tabs in the input with the proper number
		of blanks to space to the next tab stop. Assume a fixed set of tab stops, 
		say every n columns. Should n be a variable or a symbolic parameter? 
 */

#include <stdio.h>

#define TAB_STOP			3 /* Number of columns to reach a tab stop */


int main(){
	
	unsigned int num_spaces = 0;

	int c, detab = 1;

	/* Read the input */
	while ((c = getchar()) != EOF) {

		if (c != '\n'){ // Inside a line
			if(detab){
				if(c == ' ')num_spaces++;
				else{
					detab = 0;

					unsigned int n_spaces = num_spaces - (num_spaces % TAB_STOP) + TAB_STOP; 
					for(n_spaces; n_spaces != 0; n_spaces--)putchar(' ');
					putchar(c);
				}
			}
			else putchar(c);
		}
		else{ // End of line
			num_spaces = 0;
			detab = 1;
			putchar(c);
		}
	}

	putchar('\n');

	return 0;
}