#ifndef _sparse_matrix
#define _sparse_matrix
#include <glib.h>

/********************************************
 * Structure to represent a connected, weighted 
 * graph
 *
 *********************************************/
typedef struct _element {
	int row;
	int col;
	int value;
}element;

/********************************************
 * Structure to represent a connected, weighted 
 * graph
 *
 *********************************************/
typedef struct _sm {
	GArray * el;
	int maxRow;
	int maxCol;
	int tot;
}Sparsemat;

/*******************************************
 * Function: sm_create_matrix
 *  
 * Creates a new sparse matrix with given number
 * of rows and columns
 *******************************************/
Sparsemat * sm_create_matrix(int maxRow, int maxCol);

/*******************************************
 * Function: sm_get_element
 * 
 * Get value of the element at given row and column.
 * Returns FALSE if element not present in matrix.
 *******************************************/
gboolean sm_get_element(Sparsemat * smat, int row, int col, int * value);

/*******************************************
 * Function: sm_set_element
 * 
 * Sets the element at given row and column to the
 * given value.
 *******************************************/
gboolean sm_set_element(Sparsemat * smat, int row, int col, int el);

/*******************************************
 * Function: sm_search_element
 * 
 * Searches for an element and stores the result
 * given element. Returns TRUE if element found, 
 * FALSE otherwise.
 *******************************************/
gboolean sm_search_element(Sparsemat * smat, int el, element * e);

/*******************************************
 * Function: sm_print_matrix
 * 
 * Prints the entire sparse matrix.
 *******************************************/
void sm_print_matrix(Sparsemat * smat);

/*******************************************
 * Function: sm_add_matrix
 * 
 * Adds two compatible sparse matrices and returns
 * the resultant matrix.
 *******************************************/
Sparsemat * sm_add_matrix(Sparsemat * sm1, Sparsemat * sm2);

/*******************************************
 * Function: sm_transpose
 * 
 * Returns the transpose of the given sparse matrix.
 *******************************************/
Sparsemat * sm_transpose(Sparsemat * smat);

/*******************************************
 * Function: sm_trace_matrix
 * 
 * Stores the trace of the sparse matrix in the given
 * variable. Returns FALSE if sparse matrix is not a 
 * square matrix.
 *******************************************/
gboolean sm_trace_matrix(Sparsemat * smat, int * sum);

/*******************************************
 * Function: sm_scale_matrix
 * 
 * Returns a matrix scaled to the given scale factor.
 *******************************************/
Sparsemat * sm_scale_matrix(Sparsemat * smat, int scale_factor);
#endif
