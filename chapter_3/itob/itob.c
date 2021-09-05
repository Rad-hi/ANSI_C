/*
	PAGE: 59
	---
	Ex: Write the function itob(n,s,b) that converts the integer n 
	into a base b character representation in the string s. 
	In particular, itob(n,s,16) formats s as a hexadecimal integer in s. 
 */

#include <stdio.h>
#include <string.h>

#define BITS_IN_BYTE			8

/*  The lengthiest representation is the binary one, so the max outuput length is of its repr
	---
	sizeof(int) * BITS_IN_BYTE : gives us the number of bits in total (in n)
	2 : is for the "0b" to be padded at the beginning
	1 : is for the sign char
	1 : is for the null char ('\0')
 */
#define MAX_OUTPUT_LEN			(sizeof(int) * BITS_IN_BYTE + 2 + 1 + 1)

/* Bases to change to */
enum{BASE_2 = 2, BASE_8 = 8, BASE_10 = 10, BASE_16 = 16};

/* Turn intered to string in any base {2, 8, 10, 16} */
void itob(int n, char * str, char base);
void reverse(char* s);

int main(){

	int n;
	unsigned base = BASE_2;
	char str[MAX_OUTPUT_LEN];

	printf("Enter the number to be converted\n");
	scanf("%d", &n);

	printf("Enter the base you want to convert to {2, 8, 10, 16}\n");
	scanf("%u", &base);

	itob(n, str, base);

	printf("Output: %s\n", str);
	return 0;
}

void itob(int n, char * str, char base){
	unsigned char str_idx = 0;
	int c, sign, carrier_msk;

	switch(base){
		case BASE_2:
		
			str[str_idx++] = '0';
			str[str_idx++] = 'b';
			/* int is 4 bytes -> left-shift 31, 30, 29 .. and test if that bit is set or not */
			for(char i = sizeof(n) * BITS_IN_BYTE - 1; i >= 0; i--){
				if(((carrier_msk = (1 << i)) <= n)) /* Create the bitmask for the current bit */
					str[str_idx++] = (n & carrier_msk) ? '1' : '0'; /* If the bit is set, write 1 else 0 */
			}
			str[str_idx] = '\0';
		
		break;

		case BASE_8:
			do { /* generate digits in reverse order */
				str[str_idx++] = n % 8 + '0'; /* get next digit */
			} while ((n /= 8) > 0); /* delete it */
		
			str[str_idx] = '\0';
			str[str_idx++] = 'o';
			str[str_idx++] = '0';
			reverse(str);
		break;

		case BASE_10: /* This is the example's code PAGE: 59 */

			if ((sign = n) < 0) /* record sign */
				n = -n; /* make n positive */
			do { /* generate digits in reverse order */
				str[str_idx++] = n % 10 + '0'; /* get next digit */
			} while ((n /= 10) > 0); /* delete it */
			if (sign < 0)
				str[str_idx++] = '-';
			str[str_idx] = '\0';
			reverse(str);
		
		break;

		case BASE_16:

			do { /* generate digits in reverse order */
				char rest = n % 16;
				str[str_idx++] = rest < 10 ? rest + '0' : rest - 10 + 'A'; /* get next digit */
			} while ((n /= 16) > 0); /* delete it */

			str[str_idx] = '\0';
			str[str_idx++] = 'x';
			str[str_idx++] = '0';
			reverse(str);

		break;

		default: 
		break;
	}
}

void reverse(char * s){
	char c;

	/*  Two counters, one from the end, and one from the beginning,
		and they meet in the middle, swapping chars
	 */
	for(unsigned int i = 0, j = strlen(s) - 1; i < j; i++, j--)
		c = s[i], s[i] = s[j], s[j] = c;	
}