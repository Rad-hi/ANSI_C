#include "input.h"

static char is_space(int c);

/* -------------------------------------------------------------------- */

/* Read the input line into the lines container, return the number of lines read */
unsigned int read_input(char * lines[]){
	size_t size;
    char * line;
    unsigned int lineno = 0;

    /* allocate memory for a line, add a ref to it in the tab of pointers, then fill it */
    do{
        line = (char *)malloc(MAXLINE * sizeof(char));
        *(lines + lineno) = line;    
    }while(getline(&lines[lineno++], &size, stdin) > 0);

    return lineno;
}

/* -------------------------------------------------------------------- */

/* Free the allocated memory */
void free_input(char * lines[], unsigned int how_many){
	/* Free allocated memory */
    for(unsigned i = 0; i < how_many; i++)
        free(lines[i]);
}

/* -------------------------------------------------------------------- */

/* Detect '#' symbols and returns the preprocessor directive ID, and fills the name/change values */
unsigned char get_directive(char * s, char * name, char * val){

	char * temp = (char *)malloc(MAX_DIRECTIVE_LEN*sizeof(char));
	char * origin = temp;
	char res = NORMAL_LINE;

	/* First char is a newline --> empty line */
	if(*s == '\n') return EMPTY_LINE;

	/* Ignore spaces and tabs */
	while(is_space(*s++));
	s--;

	/* Identify the preprocessor dir, and get its value */
	if(*s++ == '#'){ /* It's a preprocessor directive */
		
		/* If the preprocessor name doesn't start with a letter, it's a faulty declaration */
		if(!isalpha(*s)) return ERR_DIR;

		/*  GET DIRECTIVE  */
		
		/* copy the directive into the temporary buffer */
		while(!is_space((*temp++ = *s++)));
		*--temp = '\0';

		/* Ignore spaces and tabs */
		while(is_space(*s++));
		s--;

		/*  GET NAME  */

		/* copy the directive into the name buffer */
		while(!is_space((*name++ = *s++)));
		*--name = '\0';

		/* Ignore spaces and tabs */
		while(is_space(*s++));
		s--;

		/* Process the macro appropriately */
		if(strcmp(origin, "define") == 0){

			/* Read the value to substitute the defined name */
			while((*val++ = *s++) != '\n');
			*--val = '\0';

			res = DEFINE_DIR;
		} 
		else if(strcmp(origin, "undef") == 0){
			val = '\0';
			res = UNDEFINE_DIR;
		} 
		else res = UNKNOWN_DIR;
	}

	free(origin);
	return res;
}

/* -------------------------------------------------------------------- */

static char is_space(int c){
	return (c == ' ' || c == '\t');
}