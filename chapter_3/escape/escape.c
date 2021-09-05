/*
	PAGE: 56
	---
	Ex: Write a function escape(s,t) that converts characters like newline 
		and tab into visible escape sequences like \n and \t as it copies 
		the string t to s. Use a switch. Write a function for the other 
		direction as well, converting escape sequences into the real characters. 
 */

#include <stdio.h>

#define MAX_LEN_INPUT				1023

/*  Assuming that the input string might be all special characters,
	The second would be double the size, since '\n' would be written
	as '\' + 'n' -> sizeof(s2) 2x sizeof(s1)
 */
#define MAX_LEN_OUTPUT				(2 * MAX_LEN_INPUT + 1)

/* The escape function and its "reverse" */
void escape(const char*original, char* modified);
void unescape(const char*escaped, char* unescaped);

int main(){
	
	char s1[MAX_LEN_INPUT], s2[MAX_LEN_OUTPUT], s3[MAX_LEN_INPUT];	
	int c;

	unsigned i = 0;
	for(i; (c = getchar()) != EOF && i < MAX_LEN_INPUT ; i++)
		s1[i] = c;

	/* Escape s1 into s2 */
	escape(s1, s2);

	printf("\nORIGINAL: \n\n%s \n", s1);
	printf("\nESCAPED: \n\n%s \n", s2);

	/* Unescape s2 into s3 */
	unescape(s2, s3);
	printf("\nUNESCAPED: \n\n%s\n", s3);

	return 0;
}

/* Turn any \t, \n or \b escape chars "visible" buy actually writing them */
void escape(const char*original, char* modified){

	/* i counts for the original, j counts for the modified */
	unsigned i = 0, j = 0;
	int c;
	while((c = original[i]) != '\0'){
		switch(c){
			case '\t':
				modified[j] = '\\';
				modified[++j] = 't';
			break;

			case '\n':
				modified[j] = '\\';
				modified[++j] = 'n';
			break;

			case '\b':
				modified[j] = '\\';
				modified[++j] = 'b';
			break;

			default: /* Any other char */
				modified[j] = c;
			break;
		}
		i++; /* i must only be modified in one place (here) 
				since no chars must be skipped 
			  */

		j++; /* j is modified in multiple places since some 
				pairs of chars must be replaced with a single one 
			  */
	}

}

/* Reverse the escaped strings */
void unescape(const char*escaped, char* unescaped){

	/* i counts for the escaped, j counts for the unescaped */
	unsigned i = 0, j = 0;
	int c;
	while((c = escaped[i]) != '\0'){
		switch(c){
			case '\\': /* We found a special char */
				switch(escaped[++i]){
					case 't':
						unescaped[j] = '\t';
					break;

					case 'n':
						unescaped[j] = '\n';
					break;

					case 'b':
						unescaped[j] = '\b';
					break;

					default: break;
				}
			break;

			default: /* Any other char */
				unescaped[j] = c;
			break;
		}
		i++; /* i is modified in multiple places since some 
				pairs of chars must be replaced with a single one 
			  */

		j++; /* j must only be modified in one place (here) 
				since no locations must be skipped 
			  */
	}

}