#ifndef __CONFIGS_H__
	#define __CONFIGS_H__
	
	#define MAXTOKEN 100
	#define MAX_INPUT_LEN           128
	#define MAX_OUTPUT_LEN          1024
	

//	#define DEBUG_EN /* --- To enable debug printing, uncomment this line --- */

	#ifdef DEBUG_EN /* Debug printing enabled */
		#include <stdio.h>
		#define DEBUG(STR, VAR)     printf(STR, VAR);
	#else
		#define DEBUG(STR, VAR)		/* Nothing */
	#endif

	enum {NAME, PARENS, BRACKETS};

#endif // __CONFIGS_H__