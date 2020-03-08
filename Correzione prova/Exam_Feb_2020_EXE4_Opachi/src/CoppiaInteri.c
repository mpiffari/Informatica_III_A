#include "CoppiaInteri.h"
#include "stdio.h"
#include "stdlib.h"

struct CoppiaInteri {
	int A;
	int B;
};

coppia_interi_ref make(int A, int B) {
	coppia_interi_ref c = (coppia_interi_ref) malloc(sizeof(struct CoppiaInteri));
	c->A = A;
	c->B = B;
	return c;
}

coppia_interi_ref somma(coppia_interi_ref c1, coppia_interi_ref c2) {

	// Smart way to make sum
	return make((c1->A + c2->A) , (c1->B + c2->B));

	/*coppia_interi_ref c = (coppia_interi_ref) malloc(sizeof(struct CoppiaInteri));
	c->A = c1->A + c2->A;
	c->B = c1->B + c2->B;
	return c;*/
}

char* toString(coppia_interi_ref c) {
	// Limito le coppie ad avere al massimo 5 cifre per numero
	// Avrò quindi bisogno di 13 caratteri:
	//		- 10 per le cifre
	//		- 2 per le parentesi quadre
	//		- 2 per \n e per il carattere terminatore

	char* res = (char*) malloc(sizeof(char) * ((5 * 2) + 4));
	sprintf(res, "[%i,%i]\n", c->A, c->B);
	return res;
}

void delete(coppia_interi_ref* c) {
	(*c)->A = 0;
	(*c)->B = 0;
	free(*c);
	*c = NULL;
}
