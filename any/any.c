/*	
	PAGE: 46
	---
	Ex: Write the function any(s1,s2), which returns the first location in a string s1
		 where any character from the string s2 occurs, or -1 if s1 contains no 
		 characters from s2. (The standard library function strpbrk does the same job
		 but returns a pointer to the location.)
 */

#include <stdio.h>


#define MAX_STR_LEN				1024
#define NUM_OF_CHARS				255

/* This table would hold NUM_OF_CHARS flags for the apperance of chars
   in s1 while reading the chars one by one, and this way, none of the 
   strings needs to be stored, and no more than one run is required.
   O(len(s1) + len(s2))
   ---
   Now for the assignment, this would still be used, but to only go
   through s2 once (to set the flags), and then go through s1 to
   check the flags (similarities) -> O(2 * (len(s1) + len(s2)))
   instead of going through s2 for each char of s1 (O(len(s1) * len(s2)))
 */
char char_apperances[NUM_OF_CHARS];

/* Input strings containers */
char s1 [MAX_STR_LEN];
char s2 [MAX_STR_LEN];

static int any(const char* s1, const char* s2); 

int main(){
	
	unsigned char num_str = 2; 
	int c;

	/* We could do better for the parsing of the two strings */
	unsigned int i = 0;
	unsigned int j = 0;

	/* Read until there's a '\n' indicating an end of string, or an EOF, 
		or either strings is longer than the MAX_STR_LEN allowed
	 */
	while((c = getchar()) != EOF 
			&& (num_str -= (c == '\n')) 
			&& i < MAX_STR_LEN - 1 
			&& j < MAX_STR_LEN - 1){
		
		if(num_str == 2)s1[i++] = c;
		else if(num_str == 1 && c != '\n')s2[j++] = c;
	}
	/* Turn the char arrays into strings */
	s1[i] = s2[j] ='\0';

	/* Get the output */
	int verdict = any(s1, s2);
	printf("%s, %d\n", verdict >= 0 ? "SIMILARITY" : "NO SIMILARITY", verdict);

	return 0;
}


static int any(const char* s1, const char* s2){
	int res = -1;

	/* Clear the flags */
	for(unsigned char i = 0; i < NUM_OF_CHARS; i++)char_apperances[i] = 0;

	/* Set the flags for the chars of s2 */
	for(unsigned short i = 0; i < MAX_STR_LEN && s2[i] != '\0'; i++){
		char_apperances[s2[i]]++;
	}

	/* Test for the similarities between s1 and s2 */
	for(unsigned short i = 0; i < MAX_STR_LEN && s1[i] != '\0'; i++){
		if(char_apperances[s1[i]]){
			res = i;
			break;
		}
	}

	return res;
}