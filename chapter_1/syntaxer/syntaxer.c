/*	
	PAGE: 34
	---
	Ex: Write a program to check a C program for rudimentary syntax errors 
		like unmatched parentheses, brackets and braces. Don't forget about 
		quotes, both single and double, escape sequences, and comments. 
		(This program is hard if you do it in full generality.) 
 */

#include <stdio.h>

/* Made a true and false constants for readability */
#define TRUE						1
#define FALSE						0	

/* States of the state machine */
#define NORMAL						1
#define IN_MULTI_COMMENT			2
#define IN_SINGLE_COMMENT			3
#define IN_STRING					4
#define WRITING_CHAR				5

int main(){
	
	/* The read char (we need a signed interget since the EOF(end of file) constant == -1) */
	int c; 

	/* State variable for the state machine */
	static int state = NORMAL;
	
	/* FLAGS */
	unsigned short half_closing_comment = FALSE; /* Multiline comments close in two steps : /*
													(since we're reading one char at a time). 
													Hence the need for this "one step back memory"
												  */
	
	unsigned short half_opening_comment = FALSE; /* Single line comments open in two steps : //
													so we need a way to know whether we started opening or not
												  */

	unsigned short closing_non_opened_comment = FALSE; /* Closing a multiline comment happens in two steps,
														  and this flag is used to check if a non-opened comment 
														  is being closed. 
														*/

	unsigned short special_char = FALSE; // When using \ before a single/double quote, we musn't 
										 // let that affect the parity of number of quotes

	
	/* Counters */
	int parentheses = 0;
	int brackets = 0;
	int braces = 0;
	int quotes = 0;
	int single_quotes = 0;
	unsigned int line_counter = 0;

	/* Errors counter */
	unsigned int err_parentheses = 0;
	unsigned int err_brackets = 0;
	unsigned int err_braces = 0;
	unsigned short err_comment = 0;

	/* Read the input */
	while((c = getchar()) != EOF){

		if(c == '\n'){
			line_counter++;
			continue; // No interest in processing newlines
		}

		/* Reset the flags if the current char (next char) isn't of interest */
		if(half_opening_comment && c != '/' && c != '*')half_opening_comment = FALSE;
		if(half_closing_comment && c != '/' && c != '*')half_closing_comment = FALSE;
		if(closing_non_opened_comment && c != '/')closing_non_opened_comment = FALSE;

		/* Start the state machine */
		switch(state){
			case NORMAL:
				switch(c){
					case '/':
						/* Detected a closing of a non-opened multiline comment */
						if(closing_non_opened_comment){
							closing_non_opened_comment = FALSE;
							err_comment++;
						}

						/* Might be the start of a comment */
						if(!half_opening_comment)half_opening_comment = TRUE;
						else{
							state = IN_SINGLE_COMMENT;
							half_opening_comment = FALSE;
						}

						break;
					
					case '*':
						
						/* Detected start of a multiline comment */
						if(half_opening_comment){ 
							state = IN_MULTI_COMMENT;
							half_opening_comment = FALSE;
						}

						/* Might be an attempt to close a non-opened comment --> check for a / next */
						if(!closing_non_opened_comment)closing_non_opened_comment = TRUE;

						break;
					
					case '(': 
						parentheses++; 
					break;

					case ')': 
						if(parentheses <= 0)err_parentheses++; // No leading open paretheses
						parentheses--;
					break;
					
					case '[': 
						brackets++; 
					break;
					
					case ']': 
						if(brackets <= 0)err_brackets++; // No leading open brackets
						brackets--;
					break;
					
					case '{': 
						braces++; 
					break;

					case '}': 
						if(braces <= 0)err_braces++; // No leading open braces
						braces--;
					break;

					case '\\':
						special_char = TRUE; 
					break;

					case '\"':
						if(!special_char){
							quotes++;
							state = IN_STRING;
						} 
					break; 

					case '\'':
						if(!special_char){
							single_quotes++; 
							state = WRITING_CHAR;
						}
					break;

					default: break;
				}

			break; // END _ NORMAL state

			case IN_MULTI_COMMENT:
				//putchar(c); // Print the found multi-line-comments
				switch(c){
					case '*': 
						/* Might be closing the comment */
						if(!half_closing_comment)half_closing_comment = TRUE;
					break;

					case '/':
						if(half_closing_comment){ /* Comment closed */
							state = NORMAL;
							half_closing_comment = FALSE;
						}
					break; 

					default: break;
				}
			break; // END _ IN_MULTI_COMMENT

			case IN_SINGLE_COMMENT:
				//putchar(c); // Print the found single-line-comments 
				if(c == '\n')state = NORMAL;
			break; // END _ IN_SINGLE_COMMENT

			case IN_STRING:
				if(c == '\"'){
					quotes++;
					state = NORMAL;
				}
			break; // END _ IN_STRING

			case WRITING_CHAR:
				if(special_char){
					special_char = FALSE;
					break;
				}
				if(c == '\\'){
					special_char = TRUE;
				}
				else if(c == '\''){
					single_quotes++;
					state = NORMAL;
				}
			break; // END _ WRITING_CHAR
		}

	} // END _ Reading while-loop; if here -> reached the end of file

	// printf("COUNTS --> (): %d, []: %d, {}: %d\n", parentheses, brackets, braces);
	// printf("ERRORS --> (): %d, []: %d, {}: %d\n", err_parentheses, err_brackets, err_braces);
	
	/* Quotes checking */
	if(quotes % 2)printf("FAULTY QUOTES\n");
	if(single_quotes % 2)printf("FAULTY SINGLE QUOTES\n");

	/* Check for error flags here */
	if(err_braces || err_brackets || err_parentheses || err_comment){
		if(err_parentheses)printf("UNBALANCED PARENTHESES\n");
		if(err_brackets)printf("UNBALANCED BRACKETS\n");
		if(err_braces)printf("UNBALANCED BRACES\n");
		if(err_comment)printf("MULTILINE COMMENT IS BEING CLOSED BUT NOT OPENED\n");
		
		printf("STATS --> (): %d,"
						" []: %d,"
						" {}: %d,"
						" /**/: %d,"
						" n°\": %d,"
						" n°\': %d \n", 
						err_parentheses, 
						err_brackets, 
						err_braces, 
						err_comment,
						quotes,
						single_quotes);
	}
	else if(!(quotes % 2) && !(single_quotes % 2)) printf("ALL GOOD\n");
	printf("Lines: %d\n", line_counter + 1);

	return 0;
}