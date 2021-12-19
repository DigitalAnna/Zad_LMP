#include "gauss.h"

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){
   
    int l, d, w, i;
	double  *t1, *t2;
	double a;

	for( l = 0; l < (mat->c) - 1; l++ ) {
		d = l;
		for( w = l+1; w < mat->r; w++ ) 
			if( mat->data[w][l] > mat->data[d][l] )
				d = w; 

		if( d != l ) {
			t1 = mat->data[l];
      		mat->data[l] = mat->data[d];
			mat->data[d] = t1;

			t2 = b->data[l];
      		b->data[l] = b->data[d];
	    	b->data[d] = t2;
		}

		for( w= l+1; w < mat->r; w++ ) {
			if( mat->data[l][l]!=0) {
				a = (mat->data[w][l]) / (mat->data[l][l]);  
			for( i= l; i < mat->c; i++ )
				mat->data[w][i] -= a * mat->data[l][i];
			b->data[w][0] -= a * (b->data[l][0]);
			}
			else 
				return 1;
		}
	}
	return 0;
}

