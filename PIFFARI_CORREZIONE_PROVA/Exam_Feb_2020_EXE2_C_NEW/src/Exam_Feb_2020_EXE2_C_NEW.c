/*
 ============================================================================
 Name        : Exam_Feb_2020_C.c
 Author      : Michele Piffari
 Version     :
 Copyright   : No copyright
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int* serieNumeriPari(int N) {
	int* res = (int*) malloc(sizeof(int) * ((N / 2) + 1));
	int j = 0;

	for(int i = 1; i <= N; i ++) {
		if(i % 2 == 0) {
			*(res+j) = i;
			j++;
		}
	}

	*(res+j) = 1;
	return res;
}


int* serieNumeriPariRicorsiva_wrapped(int N, int end, int contatoreNumeriPari) {
	if(N == (end + 1)) {
		int* i = (int*) calloc(1, sizeof(int));
		*i = 1;
		return i;
	} else {
		if(N % 2 == 0) {
			int* res = (int*) malloc((contatoreNumeriPari + 1) * sizeof(int));
			*res = N;
			int* temp = serieNumeriPariRicorsiva_wrapped(N + 1, end, contatoreNumeriPari - 1);

			// =================================== DEBUG =================================
			char* r = (char*) malloc(contatoreNumeriPari * sizeof(char));
			sprintf(r, "");
			for(int i = 0; i < contatoreNumeriPari; i++) {
				sprintf(r, "%s %i", r, *(temp+i));
			}
			printf("Res size %i\n", (contatoreNumeriPari + 1));
			printf("N: %i||Memory copying to res [%i] value of %s for a size of %i\n", N, *res, r, contatoreNumeriPari);
			// ============================================================================

			memcpy(res+1, temp, sizeof(int) * contatoreNumeriPari);
			free(temp);
			return res;
		} else {
			return serieNumeriPariRicorsiva_wrapped(N + 1, end, contatoreNumeriPari);
		}
	}
}

int* serieNumeriPariRicorsiva(int N) {
	return serieNumeriPariRicorsiva_wrapped(2, N, N/2);
}

int* serieNumeriPariRicorsivaTail_wrapped(int N, int end,  int* res, int index) {
	if(N == (end + 1)) {
		*(res + index) = 1;
		return res;
	} else {
		if(N % 2 == 0) {
			*(res + index) = N;
			return serieNumeriPariRicorsivaTail_wrapped(N + 1, end, res, index+1);
		} else {
			return serieNumeriPariRicorsivaTail_wrapped(N + 1, end, res, index);
		}
	}
}

int* serieNumeriPariRicorsivaTail(int N) {
	int* res = (int*) malloc(sizeof(int) * ((N/2)+1));
	return serieNumeriPariRicorsivaTail_wrapped(2, N, res, 0);
}

int main(void) {

	//int* res = serieNumeriPari(5); // OK
	//int* res = serieNumeriPariRicorsiva(6);

	int* res = serieNumeriPariRicorsivaTail(5); // OK
	int* n = res;
	printf("Final result --> ");
	while(*n != 1) {
		printf("%d, ", *n);
		n++;
	}

	printf("%d", *n);
	printf("\n");
	return EXIT_SUCCESS;
}
