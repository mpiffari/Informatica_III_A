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
	int* res = (int*) malloc(sizeof(int) * N);
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


int* serieNumeriPariRicorsiva(int N) {
	if(N == 1) {
		int* i = (int*) calloc(N, sizeof(int));
		*i = 1;
		return i;
	} else {
		if(N % 2 == 0) {
			int* res = (int*) calloc(((N/2)+1), sizeof(int));
			*res = N;
			int* a = serieNumeriPariRicorsiva(N - 1);
			memcpy(res+1, a, sizeof(int) * (((N-1)/2)+1));
			return res;
		} else {
			return serieNumeriPariRicorsiva(N - 1);
		}
	}
}

int* foo(int n,int cont){
	if(cont*2 >= n){
		int* temp = (int*) calloc(n,sizeof(int));
		temp[0] = 1;
		return temp;
	} else {
		int* temp = (int*) calloc(n,sizeof(int));
		int* ris = foo(n,cont+1);
		*temp = cont*2;
		printf("contatore: %i, ris: %i,%i\n",cont,*(ris+1),*(ris+2));
		memcpy(temp+1,ris,sizeof(int)*(n-1));
		printf("contatore: %i, temp: %i,%i\n",cont,*(temp+1),*(temp+2));
		free(ris);

		return temp;
	}
}

int* numeripari(int n){
	return foo(n,1);
}


int* serieNumeriPariRicorsivaTail(int N, int* res, int index) {
	if(N == 1) {
		*(res + index) = 1;
		return res;
	} else {
		if(N % 2 == 0) {
			*(res + index) = N;
			return serieNumeriPariRicorsivaTail(N - 1, res, index+1);
		} else {
			return serieNumeriPariRicorsivaTail(N - 1, res, index);
		}
	}
}

int* serieNumeriPariR_Tail(int N) {
	int* res = (int*) malloc(sizeof(int) * ((N/2)+1));
	return serieNumeriPariRicorsivaTail(N, res, 0);
}

int main(void) {

	//int* res = serieNumeriPari(5); // OK
	//int* res = numeripari(6); // Cale
	int* res = serieNumeriPariRicorsiva(5);
	//int* res = serieNumeriPariR_Tail(5); // OK
	int* n = res;
	while(*n != 1) {
		printf("%d, ", *n);
		n++;
	}

	printf("%d, ", *n);
	printf("\n");
	puts("No greetings"); /* prints No greetings */
	return EXIT_SUCCESS;
}
