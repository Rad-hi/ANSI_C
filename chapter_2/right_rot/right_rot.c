/*
	PAGE: 47
	---
	Ex: Write a function rightrot(x,n) that returns the value 
	of the integer x rotated to the right by n positions. 
 */

#include <stdio.h>

unsigned int right_rot(unsigned int x, unsigned int n);

int main(){
	
	unsigned int x, n, res;

	printf("INSERT :: X (to be rotated, in HEX and you can ommit the \"0x\" )\n");
	scanf("%x", &x);

	printf("INSERT :: n (n° bits of rotation)\n");
	scanf("%u", &n);

	res = right_rot(x, n);

	/* Visualize the number as a binary value */
	for(unsigned short i = sizeof(res)*8 ; i != 0; i--)
		printf("%c", (res & (1 << i)) ? '1' : '0');
	printf("\n");

	return 0;
}

/* Rotate x to the right by n places */
unsigned int right_rot(unsigned int x, unsigned int n){
	
	unsigned int carrier = 0;

	n = n % (sizeof(x) * 8); // Since rotation is a periodic act, don't rotate 
							 // more than the number of bits in the input (fold the rotation)

	carrier = ~(~0 << n) & x; // Capture the last n bits to the right (to be shifted to oblivian)
	
	/*  Since we have the bits that'd be lost forever due to shifting in the carrier variable,
		we shift x, then we OR it with the recovered bits shifted to the mostleft
	 */
	x = (x >> n) | (carrier << (sizeof(carrier) * 8 - n));

	return x;
}