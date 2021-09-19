#include "preprocessor.h"

extern struct directives_list * hashtab[];

static struct directives_list * lookup(char * s);
static unsigned hash(char *s);
static char * get_word(char * line, int * idx);

/* -------------------------------------------------------------------- */

/* install: put (name, defn) in hashtab */
struct directives_list *install(char *name, char *defn){
	struct directives_list *np;
	unsigned hashval;

	if ((np = lookup(name)) == NULL) { /* not found */
		np = (struct directives_list *) malloc(sizeof(*np));
		if (np == NULL || (np->name = strdup(name)) == NULL)
			return NULL;
		hashval = hash(name);
		np->next = hashtab[hashval];
		hashtab[hashval] = np;
	}
	else /* already there */
		free(np->defn); /*free previous defn */
	
	if ((np->defn = strdup(defn)) == NULL)
		return NULL;
	return np;
}

/* -------------------------------------------------------------------- */


void uninstall(char * name){
	/* Not implemented yet */
	printf("UNINSTALLING: %s\n", name);
}

/* -------------------------------------------------------------------- */

/* Change the defined macro in line if needed */
void process(char * line){

	char * word;
	int idx = 0;
	struct directives_list * np;

	/* This would be built incrementally with the line words/substitutions */
	char * temp = (char *)malloc(MAX_LINE_LEN);

	/* Keep searching for words as long as we haven't gone through the whole line */
	while(idx < strlen(line)){

		word = get_word(line, &idx);

		/* Add the words (processed/or not) in the edited line */
		if((np = lookup(word)) != NULL){
			strcat(temp, np->defn);
			strcat(temp, " ");
		}
		else{
			strcat(temp, word);
			strcat(temp, " ");
		}

		free(word);
	}

	strcpy(line, temp); /* Copy the temporary buffer into the actual line buffer */
	
	free(temp);
}

/* -------------------------------------------------------------------- */

/* Get one word at a time from a line, starting from a set index */
static char * get_word(char * line, int * idx){
	int c;
	char * word = (char *)malloc(MAX_WORD_LEN);
	char * origin = word; /* This points to the beginning of the word */

	while(isspace(line[(*idx)++]));
	(*idx)--; /* Skip spaces, but not too far */

	/* Get any actual words (alphanumerical) */
	while(isalnum((c = line[(*idx)++])) || c == '_') *word++ = c;

	/* If we encounter a symbol, we return it as it is for printing */
	if(strlen(origin) == 0) *word++ = c;

	*word = '\0'; /* Turn the read word into a string */

	return origin;
}		

/* -------------------------------------------------------------------- */

/* hash: form hash value for string s */
static unsigned hash(char *s){

	unsigned hashval;
	for (hashval = 0; *s != '\0'; s++)
	hashval = *s + 31 * hashval; 
	
	return hashval % HASHSIZE;
}

/* -------------------------------------------------------------------- */

/* lookup: look for s in hashtab */
static struct directives_list * lookup(char * s){
	struct directives_list * np;
	
	for (np = hashtab[hash(s)]; np != NULL; np = np->next)
		if (strcmp(s, np->name) == 0)
			return np; /* found */
	return NULL; /* not found */
}