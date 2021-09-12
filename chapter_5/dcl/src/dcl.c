#include "dcl.h"

/* These are the global variables in the main file */
extern int tokentype;
extern char out[];
extern char token[];
extern char name[]; 

extern char parameters[];

#define MAX_PARAM_LEN	50
#define MAX_PARAM_NUM	6
static char params[MAX_PARAM_NUM][MAX_PARAM_LEN];
static unsigned char idx = 0; 

/* dcl: parse a declarator */
void dcl(void){

	DEBUG("DCL, tokentype: %c\n", (char)tokentype);
	
	int ns = 0, c;
	for (; (c = gettoken()) == '*'; ) // count *'s 
			ns++;

	dirdcl();
	
	/* If we found a variable name, we keep on looking for them; dcl will recurcively call itself */
	if(tokentype == VARIABLE){ 

		char buf[MAX_PARAM_LEN];
		sprintf(buf, "%s, ", token); /* Add the ',' and the spacing to the param name */

		/* Count '*'s */
		do{
			ns += (c = gettoken()) == '*';
		}while(c == '*');

		/* Read too far, return what you read */
		return_token(c);
		
		/* Add as many pointers to variables as needed */
		while(ns--)strcat(params[idx], "pointer to ");
		
		/* Fill the varibale names */
		strcat(params[idx++], buf);

		DEBUG("BUF: %s\n", buf); /* Debugging */

		dcl(); /* Find the next parameter name */
	}

	while(ns-- > 0)strcat(out, " pointer to");	
}

/* dirdcl: parse a direct declarator */
void dirdcl(void){
	
	DEBUG("DIR_DCL, tokentype: %c\n", (char)tokentype);

	int type;
	
	if(tokentype == '('){
		dcl();
		if(tokentype != ')')
			printf("error: missing )\n");
	}
	else if(tokentype == NAME){ /* Found a variable name */
		
		DEBUG("DIR_DCL :: NAME %s\n", "");
		strcpy(name, token);
	}
	else if(tokentype == ')'){ /* End of declaration after variables (or no variables) */

		strcat(out, " function returning");

		DEBUG("END %d\n", idx);
		strcat(parameters, idx > 1 ? " with parameters: " : " with parameter: ");
		for(unsigned char i = 0; i < idx; i ++){
			strcat(parameters, params[i]);
		}
		parameters[strlen(parameters) - 2] = '\0'; /* Remove the last ',' */
	}
	else if(tokentype == ','){
		; /* If we find a ',' inside a multiple params function declaration we ignore it */
	}
	else{
		printf("error: expected name or (dcl)\n");
	}

	while((type = gettoken()) == PARENS || type == BRACKETS){
		if(type == PARENS)
			strcat(out, " function returning");
		else{
			strcat(out, " array");
			strcat(out, token);
			strcat(out, " of");
		}
	}
}