#include "gettoken.h"

static int getch(void);
static void ungetch(int c);

/* This is the pointer containing the line */
extern char * line_ptr;
extern int tokentype;
extern char token[];
extern char name[];

/* return next token */
int gettoken(void){
	int c;
    char *p = token;
    
    while ((c = getch()) == ' ' || c == '\t');

    if(c == '('){
        if((c = getch()) == ')'){
            strcpy(token, "()");
            return tokentype = PARENS;
        }
        else if(isalpha(c)){
            for (*p++ = c; isalpha(c = getch()) || c == ' '; )
                *p++ = c;
            ungetch(c);
            *p = '\0';
            return tokentype = VARIABLE;
        }
        else{
            ungetch(c);
            return tokentype = '(';
        }
    }
    else if(c == '['){
        for (*p++ = c; (*p++ = getch()) != ']'; );
        *p = '\0';
        return tokentype = BRACKETS;
    }
    else if(isalpha(c) && !strlen(name)){ /* Alphanumeric and it's the name */
        for (*p++ = c; isalnum(c = getch()); )
            *p++ = c;
        *p = '\0';
        ungetch(c);
        return tokentype = NAME;
    }
    else if(isalpha(c) && strlen(name)){ /* Alphanumeric but it's not the name; variable */
        for (*p++ = c; isalpha(c = getch()) || c == ' '; )
                *p++ = c;
            ungetch(c);
            *p = '\0';
            return tokentype = VARIABLE;
    }
    else{
        return tokentype = c;
    }
}

void return_token(int c){
    ungetch(c);
}

/* Read the input line into the line_ptr */
void read_input(char * s){
	unsigned char i;
	for(i = 0; i < MAX_INPUT_LEN && (s[i] = getchar()) != EOF; i++);
	DEBUG("INPUT: %s\n", s);
}

/* Get the first char in the line */
static int getch(void){
	DEBUG("GET: %c\n", *line_ptr);
	return *line_ptr++;
}

/* Return the last read value to the line */
static void ungetch(int c){
	DEBUG("UNGET: %c\n", c);
	*--line_ptr = c;
}