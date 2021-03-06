#include "gauss.h"
#include "backsubst.h"
#include "mat_io.h"
#include "testy_3_4.h"
#include "testy_1_2.h" 
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char ** argv) {
	int res;

	test1(argv[1], argv[2]); 
    test2(argv[1]);

	test4();

	Matrix * A = readFromFile(argv[1]);
	Matrix * b = readFromFile(argv[2]);
	Matrix * x;

	if (A == NULL) return -1;
	if (b == NULL) return -2;
	printToScreen(A);
	printToScreen(b);

	res = eliminate(A,b);
	x = createMatrix(b->r, 1);
	if (x != NULL) {
		res = backsubst(x,A,b);

		printToScreen(x);
	  freeMatrix(x);
	} else {
					fprintf(stderr,"Błąd! Nie mogłem utworzyć wektora wynikowego x.\n");
	}

	test3(A, argv[1]);

	freeMatrix(A);
	freeMatrix(b);

	return 0;
}
