/*
 ============================================================================
 Name        : Exam_Feb_2020_EXE4_Opachi.c
 Author      : Michele Piffari
 Version     :
 Copyright   : No copyright
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include "CoppiaInteri.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {

	coppia_interi_ref c1 = make(5, 10);
	coppia_interi_ref c2 = make(6, 3);
	//coppia_interi_ref c3 = make(8, 1);
	//coppia_interi_ref c4 = make(98, 1);

	printf(toString(c1));
	printf(toString(somma(c1, c2)));

	puts("No greetings"); /* prints No greetings */
	return EXIT_SUCCESS;
}
