/*	
	PAGE: 44
	---
	Ex: Write a function htoi(s), which converts a string of hexadecimal digits
		(including an optional 0x or 0X) into its equivalent integer value. 
		The allowable digits are 0 through 9, a through f, and A through F. 
	---
	The linker didn't fin the reference to pow() despite of me including math.h
	Solution --> $ gcc hex_to_int.c -o hex_to_int.out -lm
 */

#include <stdio.h>
#include <ctype.h>
#include <math.h> 

#define MAX_STR_LEN			11 /* Figured a maximum of 4 bytes and the optional "0x" would suffice 
							      (and a '\0' at the end).
							    */

/* This function takes in a char array of hex values, and its length, 
   and returns the conversion from HEX to DEC 
 */
static unsigned int htoi(const unsigned char *str, unsigned char len);

int main(){
	
	unsigned char buf[MAX_STR_LEN];
	unsigned char len;
	int c;

	for(unsigned char i = 0; i < MAX_STR_LEN && (c = getchar()) != EOF && c != '\n'; i++){
		buf[i] = c;
		len = i;
	}

	//printf("%s\n", buf);

	unsigned int result = htoi(buf, len);
	printf("%d\n", result);
	
	return 0;
}


static unsigned int htoi(const unsigned char *str, unsigned char len){
	unsigned int res = 0;
	unsigned char start;


	/* Whether there's the 0x OR 0X at the beginning */
	if(str[0] == '0' && (str[1] == 'x' || str[1] == 'X'))start = 2;
	else start = 0;

	/* Go from the far righ to the far left, where res = res + str[i] * 16^(len - i - 1) */
	for(char i = len - 1; i >= start; i--){
		
		unsigned char c = str[i]; 		
		if(isdigit(c))res += pow(16L, (long)(len - i - 1)) * (c - '0');
		else res += pow(16, len - i - 1) * (tolower(c) - 'a' + 10);
	}

	return res;
}