/*
	PAGE: 58
	---
	Ex: Write a function expand(s1,s2) that expands shorthand notations 
		like a-z in the string s1 into the equivalent complete list 
		abc...xyz in s2. Allow for letters of either case and digits, 
		and be prepared to handle cases like a-b-c and a-z0-9 and -a-z. 
		Arrange that a leading or trailing - is taken literally. 
	---
	The imlemented solution handles all corner cases, and it even 
	counts in the negative ranges (like for z-a and 9-0) .. 
	ofc 10-20 will be considred as a range from 0-2 with 1 and 0 as paddings
 */

#include <stdio.h>
#include <ctype.h>

#define FALSE						0
#define TRUE						1

/* Two states of the state machine, either we parse, or we expand a range */
enum{NORMAL = 0, RANGE};

#define MAX_INPUT_LEN				30

/*  We have to account for when the whole string is ranges, 
	in which case, things will get out of control and the 
	output string will get out of control (length of it)
 */
#define MAX_OUTPUT_LEN				(MAX_INPUT_LEN * 100)

/* Given an assortment of ranges, it expands them in an outupt string */
void expand(const char* original, char* expanded, unsigned len);

int main(){
	
	/* Input and output strings */
	char s1[MAX_INPUT_LEN], s2[MAX_OUTPUT_LEN];
	int c;

	/* Parse the input string */
	unsigned i = 0;
	for(i; (c = getchar()) != EOF && i < MAX_INPUT_LEN; i++)
		s1[i] = c;


	expand(s1, s2, i);

	printf("\nORIGINAL: \n\n%s\n", s1);
	printf("\nEXPANDED: \n\n%s\n", s2);

	return 0;
}


void expand(const char* original, char* expanded, unsigned len){
	/* i counts for the original, j counts for the expanded */
	unsigned i = 0, j = 0;
	
	/* Holds the current, previous, and upcoming char */
	char next, previous;
	int c;

	unsigned char state = NORMAL;
	unsigned char potential_range = FALSE;

	/* Beware, i doesn't go to the end of the string */
	while((c = original[i]) != EOF && (i < len - 1) && c != '\0'){

		switch(state){
			case NORMAL:
				if(c == '-' && i > 0){ /* We have a potential range */
					previous = original[i-1];
					next = original[i+1];
					if(isalnum(previous) && isalnum(next)) /* We have a valid range */
						state = RANGE;
					else
						expanded[j++] = c;
				}
				else{
					expanded[j++] = c;
				}
			break;

			case RANGE:
				/* Expand the range that we have */
				for(j; previous != next; j++){
					expanded[j] = previous > next ? --previous : ++previous;
				}
				state = NORMAL;
			break;
		}
		++i; /* Parse the next char */
	}
}