#include <stdio.h>

#include "testy_1_2.h"
#include "mat_io.h"
int test1(char *p1, char *p2)
{
    Matrix * A1 = readFromFile("test1_A1");
	Matrix * b1 = readFromFile("test1_b1");
    Matrix * A2 = readFromFile("test1_A2"); //5x5
	Matrix * b2 = readFromFile("test1_b2");
    Matrix * A3 = readFromFile(p1);
    Matrix * b3 = readFromFile(p2);

    // A1 b1
    if( A1->r != A1->c ) {
        printf("Test 1 - nieprawidłowe dane %dx%d: ERROR!\n", A1->r, A1->c);
        return -1;
    }

    if( b1->r != A1->r ) {
        printf("Test 1 - nieprawidłowe dane %dx%d: ERROR!\n", b1->r, b1->c);
        return -1;
    }

    if( b1->c != 1) {
        printf("Test 1 - nieprawidłowe dane %dx%d: ERROR!\n", b1->r, b1->c);
        return -1;
    }   

    printf("Test 1 - poprawne dane %dx%d %dx%d: OK.\n", A1->r, A1->c, b1->r, b1->c);

    // A2 b2
    if( A2->r != A2->c ) {
        printf("Test 1 - nieprawidłowe dane %dx%d: ERROR!\n", A2->r, A2->c);
        return -1;
    }

    if( b2->r != A2->r ) {
        printf("Test 1 - nieprawidłowe dane %dx%d: ERROR!\n", b2->r, b2->c);
        return -1;
    }

    if( b2->c != 1) {
        printf("Test 1 - nieprawidłowe dane %dx%d: ERROR!\n", b2->r, b2->c);
        return -1;
    }   

    printf("Test 1 - poprawne dane %dx%d %dx%d: OK.\n", A2->r, A2->c, b2->r, b2->c);
    
    // A3 b3
    if( A3->r != A3->c ) {
        printf("Test 1 - nieprawidłowe dane %dx%d: ERROR!\n", A3->r, A3->c);
        return -1;
    }

    if( b3->r != A3->r ) {
        printf("Test 1 - nieprawidłowe dane %dx%d: ERROR!\n", b3->r, b3->c);
        return -1;
    }

    if( b3->c != 1) {
        printf("Test 1 - nieprawidłowe dane %dx%d: ERROR!\n", b3->r, b3->c);
        return -1;
    }   

    printf("Test 1 - poprawne dane %dx%d %dx%d: OK.\n", A3->r, A3->c, b3->r, b3->c);
    return 0; 
}

int test2(char *p1)
{
    
    Matrix * A = readFromFile("test2_A");
    Matrix * A2 = readFromFile(p1);

    // A2
    if( A2->data[0][0] == 0) {
        printf("Test 2 - nieprawidłowe dane %dx%d: ERROR!\n", A2->r, A2->c);
        return -1;
    }

    printf("Test 2 - poprawne dane %dx%d: OK.\n", A2->r, A2->c);
    
    // A
    if( A->data[0][0] == 0) {
        printf("Test 2 - nieprawidłowe dane %dx%d: ERROR!\n", A->r, A->c);
        return -1;
    }

    printf("Test 2 - poprawne dane %dx%d: OK.\n", A->r, A->c);
    
    return 0;

}