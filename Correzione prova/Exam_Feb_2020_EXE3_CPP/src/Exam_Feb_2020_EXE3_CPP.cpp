//============================================================================
// Name        : Exam_Feb_2020_EXE3_CPP.cpp
// Author      : Michele Piffari
// Version     :
// Copyright   : No copyright
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

struct A {
	A() {
		cout << "Costruttore A\n";
	}
	~A() {
		cout << "Distruttore A\n";
	}
};

struct B  {
	B() {
		cout << "Costruttore B\n";
	}
	~B() {
		cout << "Distruttore B\n";
	}
};

struct C: A, private B {
	C() {
		cout << "Costruttore C\n";
	}
	virtual ~C() {
		cout << "Distruttore C\n";
	}
};

void test() {
	C* c = new C();
	delete(c); // Variabile allocata tramite puntatore che deve essere esplicitamente distrutta

	A a; // Variabile locale automaticamente distrutta
}

int main() {
	// Il distruttore è il metodo duale del costruttore: esso serve principalmente ad eliminare gli oggetti
	// della memoria, andando quindi a liberare spazio in memoria.
	// Il distruttore viene chiamato automaticamente dal compliatore quando la variabile esce dal suo scope.
	// Questa eliminazione automatica però non avviene per i puntatori: quindi se ho un puntatore (allocato tramite la funzione
	// malloc) sarà necessario che sia invocato esplicitamenteun comando di free per evitare un memory leakage.

	// Nel caso di utilizzi di sottoclassi è sempre meglio dichiarare il distruttore virtual così che chiami tutti i distruttori
	// delle superclassi (dalla sottoclasse e poi fino alla superclasse)

	test();
}
