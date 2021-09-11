#include "dcl.h"

/* These are the global variables in the main file */
extern int tokentype;
extern char out[];
extern char token[];
extern char name[]; 

/* dcl: parse a declarator */
void dcl(void){
	int ns;
	for (ns = 0; gettoken() == '*'; ) /* count *'s */
		ns++;
	
	dirdcl();
	while (ns-- > 0)
		strcat(out, " pointer to");
}

/* dirdcl: parse a direct declarator */
void dirdcl(void){
	int type;
	
	if(tokentype == '(') { /* ( dcl ) */
		dcl();
		if(tokentype != ')')
			printf("error: missing )\n");
	}
	else if(tokentype == NAME) /* variable name */
		strcpy(name, token); 
	else
		printf("error: expected name or (dcl)\n");
	
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