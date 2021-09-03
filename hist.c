/*	
	PAGE: 25
	---
	Ex: Write a program to print a histogram of the lengths of words in its input. 
		It is easy to draw the histogram with the bars horizontal; 
		a vertical orientation is more challenging 
	---
	Created the vertical histogram
	---
	How to run:
		1- Create a file containing whatever you want (I'm passing this file as input)
		3- Compile: 	$ gcc hist.c -o hist.out
		2- Run : 	    $ cat hist.c | ./hist.out
 */

#include <stdio.h>

#define IN_WORD				1
#define OUT_OF_WORD			0
#define MAX_WORD_LENGTH 	1023

/* Function that returns the maximum value in a table */
unsigned int get_max(unsigned int * tab, unsigned int len);

int main(){

	unsigned int word_lengths[MAX_WORD_LENGTH]; /* Max word length is 1023 */
	unsigned int word_length = 0; /* Counts current word's length */
	unsigned int max_word_length = 0; /* Holds max words' length */

	unsigned int max_value = 0; /* The maximum value in the table */

	unsigned int state; /* Keeps track of whether we're in a word or not */
	int c;

	/* Initialize the table with zero values */
	for(unsigned int i = MAX_WORD_LENGTH - 1; i != 0; i--){
		word_lengths[i] = 0;
	}

	/* Read the input */
	while ((c = getchar()) != EOF) {

		if (c == ' ' || c == '\n' || c == '\t'){
			state = OUT_OF_WORD;
			word_lengths[word_length]++; /* Count the appearance of an additional word with this length */
			
			if(word_length > max_word_length) max_word_length = word_length; 
			word_length = 0;
		}
		else{
			state = IN_WORD;
			word_length++;
		}
	}

	max_value = get_max(word_lengths, sizeof(word_lengths)/sizeof(word_lengths[0]));

	/* 
		We have max_value + 1 lines to draw, and max_word_length columns 
	*/
	for(unsigned int j = max_value + 1; j != 0; j--){ /* For each line */
		for(unsigned int i = 1; i <= max_word_length; i++){	/* For each column */
			if(word_lengths[i] >= j) printf("|");
			else printf(" ");
		}
		printf("\n");
	}	

	return 0;
}

/* Function to return the max value in a table */
unsigned int get_max(unsigned int * tab, unsigned int len){
	
	unsigned int max_val = 0;

	for(unsigned int i = len - 1; i != 0; i--){
		
		if(tab[i] > max_val) max_val = tab[i];
	}
	return max_val;
}