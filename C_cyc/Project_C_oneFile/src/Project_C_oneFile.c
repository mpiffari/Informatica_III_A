/*
 ============================================================================
 Name        : Project_C_cyc.c
 Author      : Michele Piffari
 Version     :
 Copyright   : No copyright
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#define SENDER 0
#define RECEIVER 1
#define PLACE 2

#define MAX_NAMES_LENGTH 30
#define MAX_PLACES_LENGTH 30

#define MAX_LINE_LENGTH 95
#define MAX_POSTCARDS_IN_FILE 50

#define FILE_NAME "C:\\Users\\miche\\OneDrive\\Desktop\\I anno Magistrale\\Informatica III - Modulo di programmazione\\WS_INFO_III_A\\Project_C_oneFile\\src\\PostcardsSimplified.txt"
#define BY_SENDER 1
#define BY_REC	  2
#define BY_PLACE  3
#define EXIT 	  -1

void outofmemory() {
	printf("[ERROR] - Out of memory error!\n");
	exit(EXIT_FAILURE);
}

typedef struct postcard {
	char* sender_name;
	char* receiver_name;
	char* place;
} postcard;

/* Destructively converts the given zero-terminated string to lowercase */
void str2lower(char* str) {
	while (*str) {
		if (*str >= 65 && *str <= 90) { // a-z
			*str += 32;
		}
		str++;
	}
}

/*Divides the given string into tokens, delimited in the original string
* by the given delimiter character.
* Returns an array of tokens (as a parameter) and the number of such
* substrings (as the return value). Delimiters are not part of the tokens;
* tokens may also be empty strings.
* If delimiter is '\0', the whole string is one single token.
*/
unsigned int tokenize(const char* str, char delimiter, char*** tokens) {
	const char* s = str;
	// Counts occurrences of the tokens (= delimiters + 1)
	int tokenCount = 1;
	while (*s) {
		if (*s == delimiter)
			tokenCount++;
		s++;
	}

	// Allocate space for tokens array
	char** t = calloc(tokenCount, sizeof(char*));
	if (!t)
		outofmemory();

	s = str;
	const char* p = str;
	tokenCount = 0;

	// Scan the string, storing the start (p) and end (s) of
	// every token, and copying the token into the array
	while (1) {
		while (*s != delimiter && *s != '\0' && *s != '\n') {
			s++;
		}

		// s points to the delimiter right after the current token
		int len = s - p;
		t[tokenCount] = malloc((len + 1) * sizeof(char));
		if (!t[tokenCount])
			outofmemory();

		strncpy(t[tokenCount], p, len);
		t[tokenCount][len] = '\0'; // Add null char at the end of tokenCount-esimo token
		tokenCount++;

		// when the end of the string has been reached, end the loop
		if (*s == '\0' || *s == '\n')
			break;

		// otherwise, skip the delimiter
		s++;
		p = s; // now p points to the next token's first char
	}

	*tokens = t; // return the tokens array through the parameter
	return tokenCount;
}

/*
 * Make postcard.
 * If number of informations it's not enough, return NULL postcard
 */
postcard* make_postcard(char* line) {
	postcard* pc = (postcard*) malloc(sizeof(postcard));
	pc->sender_name = (char*) malloc(sizeof(char) * (MAX_NAMES_LENGTH + 1));
	pc->receiver_name = (char*) malloc(sizeof(char) * (MAX_NAMES_LENGTH + 1));
	pc->place = (char*) malloc(sizeof(char) * (MAX_NAMES_LENGTH + 1));

	char** tokens = (char**) calloc(strlen(line) + 1, sizeof(char*));
	int numberOfToken = tokenize(line, '|', &tokens);

	if(numberOfToken == 3) {
		for (int i = 0; i < numberOfToken; i++) {
			str2lower(tokens[i]);
			switch (i) {
			case SENDER:
				strcpy(pc->sender_name, tokens[i]);
				break;
			case RECEIVER:
				strcpy(pc->receiver_name, tokens[i]);
				break;
			case PLACE:
				strcpy(pc->place, tokens[i]);
				break;
			default:
				break;
			}
		}

		for (int i = 0; i < numberOfToken; i++) {
			free(tokens[i]);
		}
		free(tokens);
		return pc;
	} else {
		return NULL;
	}
}

void printPostcard (postcard* p) {
	printf("	----------------\n");
	printf("	from: %s\n", p->sender_name);
	printf("	to: %s\n", p->receiver_name);
	printf("	place: %s\n", p->place);
	printf("	----------------\n");
}


/* Read the file and create a list of postcard object, only if it's present
 * all the needed informations.
 * Returns the number of postcards (as a parameter) and the reference of such
 * postcard (as the return value).
 */
postcard* readFile(int** num_of_postcard) {
	postcard* postcards = (postcard*) malloc(sizeof(postcard) * MAX_POSTCARDS_IN_FILE);
	FILE* stream;
	// Opening stream file for reading
	stream = fopen(FILE_NAME, "r");
	if(stream == NULL) {
		printf("Error opening file %s\n", FILE_NAME);
		return NULL;
	}

	char* line = (char*) malloc(sizeof(char) * (MAX_LINE_LENGTH + 1));
	int* index = (int*) calloc(1, sizeof(int)); // From 1 to (MAX_POSTCARDS_IN_FILE - 1)

	while(fgets(line, (MAX_LINE_LENGTH + 1), stream) != NULL) {
		postcard* pc = make_postcard(line);
		printPostcard(pc);
		if(pc != NULL) {
			*(postcards + *index) = *pc;
			*index = *index + 1;
		} else {
			printf("__ERROR ON POSTCARD ___\n");
		}
	}

	*(num_of_postcard) = index;
	fclose(stream);
	free(line);
	return postcards;
}

/*
 * Search postcards and return them.
 * If number of informations it's not enough, return NULL postcard
 */
postcard* findBy(postcard* postcards, char* str_src, int** nop, int findBy) {
	postcard* res = (postcard*) malloc(sizeof(postcard) * (*(*nop)));
	int* nop_searched = calloc(1, sizeof(int));

	int temp = *(*nop);
	for(int i = 0; i < temp; i++) {
		if(findBy == BY_SENDER &&
				strcmp((postcards+i)->sender_name, str_src) == 0) {

			*(res + *nop_searched) = *(postcards + i);
			*nop_searched = *nop_searched + 1;
		} else if(findBy == BY_REC &&
				strcmp((postcards+i)->receiver_name, str_src) == 0) {

			*(res + *nop_searched) = *(postcards + i);
			*nop_searched = *nop_searched + 1;
		} else if(findBy == BY_PLACE &&
				strcmp((postcards+i)->place, str_src) == 0) {

			*(res + *nop_searched) = *(postcards + i);
			*nop_searched = *nop_searched + 1;
		}
	}

	*nop = nop_searched;
	return res;
}

int main( int argc, char *argv[] ){
	// Console reading
	char *command = (char*) malloc(sizeof(char) * MAX_LINE_LENGTH);
	char *param = (char*) malloc(sizeof(char) * MAX_LINE_LENGTH);
	int* nop = 0; // Number of postcard
	postcard* postcards = (postcard*) malloc(sizeof(postcard) * MAX_POSTCARDS_IN_FILE);
	postcards = readFile(&nop);
	printf("Number of postcards = %i\n", *nop);

	postcard* res = (postcard*) malloc(sizeof(postcard) * MAX_POSTCARDS_IN_FILE);
	printf("FIND POSTCARD BY: \n- SENDER [1]\n- RECEIVER [2]\n- PLACE [3]"
			"\n- EXIT [-1]\n");
	while (atoi(command) != EXIT) {

		gets(command);
		if(atoi(command) == BY_SENDER) {
			printf("BY SENDER --> ");
			gets(param);
			int** nop_searched = &nop;
			str2lower(param);
			res = findBy(postcards, param, nop_searched, BY_SENDER);
			printf("Postcard search: \n");
			if(*(*nop_searched) == 0) {
				printf("----> No postcard match <----\n");
				printf("FIND POSTCARD BY: \n- SENDER [1]\n- RECEIVER [2]\n- PLACE [3]\n- EXIT [-1]\n");
			} else {
				for(int i = 0; i < *(*nop_searched); i++) {
					printPostcard((res + i));
				}
				printf("FIND POSTCARD BY: \n- SENDER [1]\n- RECEIVER [2]\n- PLACE [3]\n- EXIT [-1]\n");
			}
		} else if(atoi(command) == BY_REC) {
			printf("BY REC --> ");
			gets(param);
			int** nop_searched = &nop;
			str2lower(param);
			res = findBy(postcards, param, nop_searched, BY_REC);
			printf("Postcard search: \n");
			if(*(*nop_searched) == 0) {
				printf("----> No postcard match <----\n");
				printf("FIND POSTCARD BY: \n- SENDER [1]\n- RECEIVER [2]\n- PLACE [3]\n- EXIT [-1]\n");
			} else {
				for(int i = 0; i < *(*nop_searched); i++) {
					printPostcard((res + i));
				}
				printf("FIND POSTCARD BY: \n- SENDER [1]\n- RECEIVER [2]\n- PLACE [3]\n- EXIT [-1]\n");
			}
		} else if(atoi(command) == BY_PLACE) {
			printf("BY PLACE --> ");
			gets(param);
			int** nop_searched = &nop;
			str2lower(param);
			res = findBy(postcards, param, nop_searched, BY_PLACE);
			printf("Postcard search: \n");
			if(*(*nop_searched) == 0)  {
				printf("----> No postcard match <----\n");
				printf("FIND POSTCARD BY: \n- SENDER [1]\n- RECEIVER [2]\n- PLACE [3]\n- EXIT [-1]\n");
			} else {
				for(int i = 0; i < *(*nop_searched); i++) {
					printPostcard((res + i));
				}
				printf("FIND POSTCARD BY: \n- SENDER [1]\n- RECEIVER [2]\n- PLACE [3]\n- EXIT [-1]\n");
			}
		} else if(atoi(command) == EXIT) {
			printf("EXIT");
		}
	}


	free(command);
	return EXIT_SUCCESS;
}
