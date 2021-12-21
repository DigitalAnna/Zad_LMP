#ifndef _TESTY_3_4_H
#define _TESTY_3_4_H

#include "mat_io.h"

/*uzupełnia minor odpowiednimi elementami z A*/
void fill_minor(Matrix * A, int a, int b, Matrix * mat);

/*liczy wyznacznik macierzy wykorzystując rozwinięcie Laplace'a*/
double laplace(Matrix * A);

/*sprawdzenie poprawności działania programu dla macierzy osobliwej 
(takiej której rząd jest mniejszy od rozmiaru wektora x)*/
int test3(Matrix * mat, char * FileName);

/*sprawdzenie prawidłowej reakcji programu dla danych o niewłaściwym formacie*/
int test4();

#endif