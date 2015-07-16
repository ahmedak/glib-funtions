#include <glib.h>
#include <stdio.h>
#include <stdlib.h>
#include "SparseMatrix.h"

/* Compares two elements based on their weights (relative position) */
gint compare_elements(gpointer a, gpointer b){
	gint weight1 = ((element *)a)->row*10 + ((element *)a)->col;
	gint weight2 = ((element *)b)->row*10 + ((element *)b)->col;
	return weight1 - weight2;
}

/* Creates a new sparse matrix with given number of rows and columns */
Sparsemat * sm_create_matrix(int maxRow, int maxCol){	
	Sparsemat * s = (Sparsemat*)malloc(sizeof(struct _sm));
	s->el = g_array_new(FALSE, FALSE, sizeof(element));
	s->maxRow = maxRow;
	s->maxCol = maxCol;
	s->tot = 0;
	return s;
}

/* Stores the value of element at given row, column into given variable */
gboolean sm_get_element(Sparsemat * smat, int row, int col, int * value){
	int index;
	for(index=0; index < smat->tot; index++){
		element e = g_array_index(smat->el, element, index); 
		if(e.row == row && e.col == col){
			*value = e.value;
			return TRUE;
		}
	}
	return FALSE;
}

/* Set an element at given row, column to given value */
gboolean sm_set_element(Sparsemat * smat, int row, int col, int val){
	element x;
	x.row = row;
	x.col = col;
	x.value = val;
	if(smat->maxRow >= row){
		g_array_append_val(smat->el, x);
		g_array_sort(smat->el, (GCompareFunc)compare_elements);
		smat->tot++;
		return TRUE;
	}
	else return FALSE;
}

/* Searches for, and stores a given element into given variable if found */
gboolean sm_search_element(Sparsemat * smat, int el, element * e){
	int index;
	for(index = 0; index < smat->tot; index++){
		 *e = g_array_index(smat->el, element, index);
		 if(e->value == el)
			 return TRUE;	
	}
	e->row = e->col = e->value = -1;
	return FALSE;
}

/* Prints entire sparse matrix */
void sm_print_matrix(Sparsemat * smat) {
	int i, j, index = 0 ;
	for(i =1; i <= smat->maxRow; i++){
		for(j=1; j <= smat->maxCol; j++){
			element e = g_array_index(smat->el, element, index);
			if(e.row== i && e.col == j){
				printf("%d ", e.value);
				index++;
			}
			else
				printf("0 ");
		}
		printf("\n");
	}
}

/* Adds two compatible sparse matrices */
Sparsemat * sm_add_matrix(Sparsemat * sm1, Sparsemat * sm2){
	Sparsemat  * sm3 = sm_create_matrix (0, 0);
	if(sm1->maxCol == sm2->maxCol && sm1->maxRow == sm2->maxRow){
		sm3->maxRow = sm1->maxRow;
		sm3->maxCol = sm1->maxCol;
		element e1, e2, e3;
		int ptr1 = 0, ptr2 = 0, weight1, weight2;
		while(ptr1 < sm1->tot && ptr2 < sm2->tot){
			e1 = g_array_index(sm1->el, element, ptr1);
			e2 = g_array_index(sm2->el, element, ptr2);
			weight1 = e1.row*10 + e1.col;
			weight2 = e2.row*10 + e2.col;
			if(weight1 < weight2){
				e3 = e1;
				ptr1++;
			}
			else if(weight1 == weight2){
				e3.row = e1.row;
				e3.col = e1.col;
				e3.value = e1.value + e2.value;
				ptr1++;
				ptr2++;
			}
			else{
				e3 = e2;
				ptr2++;
			}
			sm_set_element(sm3, e3.row, e3.col, e3.value);
		}
		while(ptr1 < sm1->tot){
			e3 = g_array_index(sm1->el, element, ptr1);
			sm_set_element(sm3, e3.row, e3.col, e3.value);
			ptr1++;
		}
		while(ptr2 < sm2->tot){
			e3 = g_array_index(sm2->el, element, ptr2);
			sm_set_element(sm3, e3.row, e3.col, e3.value);
			ptr2++;
		}
		return sm3;
	}
	else return sm3;
}

/* Computes transpose of sparse matrix */
Sparsemat * sm_transpose(Sparsemat * smat){
	Sparsemat * sm1 = sm_create_matrix(smat->maxCol, smat->maxRow);
	sm1->tot= smat->tot;
	int index, temp;
	for(index=0; index < smat->tot; index++){
		element  e = g_array_index(smat->el, element, index);
		sm_set_element( sm1, e.col, e.row, e.value);
	}
	return sm1;
}

/* Computes trace of a sparse matrix */
gboolean sm_trace_matrix(Sparsemat * smat, int * sum){
	*sum = 0;
	if(smat->maxRow != smat->maxCol)
		return FALSE;
	else{
		int index;
		for(index=0; index < smat->tot; index++){
			element e = g_array_index(smat->el, element, index);
			if(e.row == e.col)
				*sum += e.value;
		}
		return TRUE;
	}
}

/* Scales the matrix by scale_factor */
Sparsemat * sm_scale_matrix(Sparsemat * smat, int scale_factor){
	Sparsemat * sm1 = smat;
	int index;
	for(index = 0; index < sm1->tot; index++){
		element * e = &g_array_index(sm1->el, element, index);
		e->value = scale_factor*(e->value);
	}
	return sm1;
}
