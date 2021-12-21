#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#include "testy_3_4.h"

/*uzupełnia minor odpowiednimi elementami z A*/
void fill_minor(Matrix * A, int a, int b, Matrix * mat){
    int c = 0;
    int d = 0;
    for(int i = 0; i < A->r; i++){
        for(int j = 0; j < A->c; j++){
            if(i != a && j != b){
                mat->data[c][d] = A->data[i][j];
                if(d < mat->c - 1){
                    d++;
                }else{
                    d = 0;
                    c++;
                }
            }
        }
    }
}

/*liczy wyznacznik macierzy wykorzystując rozwinięcie Laplace'a*/
double laplace(Matrix * A){
    int rows = A->r - 1;
    int columns = A->c - 1;
    double det = 0;
    Matrix * minor;

    while(rows > 2 && columns > 2){
        for(int i = 0; i < A->r; i++){
            minor = createMatrix(rows, columns);
            fill_minor(A, i, 0, minor);
            det += A->data[i][0] * pow(-1, i) * laplace(minor);
        }
        rows--;
        columns--;
    }
    for(int i = 0; i < A->r; i++){
        minor = createMatrix(rows, columns);
        fill_minor(A, i, 0, minor);
        det += A->data[i][0] * pow(-1, i) * (minor->data[0][0]*minor->data[1][1] - minor->data[0][1]*minor->data[1][0]);
    }
    return det;
}

/*sprawdzenie poprawności działania programu dla macierzy osobliwej 
(takiej której rząd jest mniejszy od rozmiaru wektora x)*/
int test3(Matrix * mat, char * FileName){

    Matrix * A = readFromFile("A_osobliwa2x2.txt");
    Matrix * B = readFromFile("A_osobliwa3x3.txt");
    Matrix * C = readFromFile("A_nieosobliwa.txt");

    if(laplace(mat) == 0.0){
        printf("Test 3 - Czy macierz osobliwa w pliku %s?: TAK, ERROR!\n", FileName);
    }else{
        printf("Test 3 - Czy macierz osobliwa w pliku %s?: NIE, OK.\n", FileName);
    }

    if(laplace(A) == 0.0){
        printf("Test 3 - Czy macierz osobliwa w pliku %s?: TAK, ERROR!\n", "A_osobliwa2x2.txt");
    }else{
        printf("Test 3 - Czy macierz osobliwa w pliku %s?: NIE, OK.\n", "A_osobliwa2x2.txt");
    }

    if(laplace(B) == 0.0){
        printf("Test 3 - Czy macierz osobliwa w pliku %s?: TAK, ERROR!\n", "A_osobliwa3x3.txt");
    }else{
        printf("Test 3 - Czy macierz osobliwa w pliku %s?: NIE, OK.\n", "A_osobliwa3x3.txt");
    }

    if(laplace(C) == 0.0){
        printf("Test 3 - Czy macierz osobliwa w pliku %s?: TAK, ERROR!\n", "A_nieosobliwa.txt");
    }else{
        printf("Test 3 - Czy macierz osobliwa w pliku %s?: NIE, OK.\n", "A_nieosobliwa.txt");
    }

    return 0;
}

/*sprawdzenie prawidłowej reakcji programu dla danych o niewłaściwym formacie (część kodu fukcji w pliku mat_io.c)*/
int test4(){

    Matrix * A = readFromFile("A_zly_format.txt");
	Matrix * b = readFromFile("b_zly_format.txt");

    return 0;    
}