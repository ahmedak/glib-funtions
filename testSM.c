#include <stdio.h>
#include "SparseMatrix.h"

int main(int argc, char ** argv) {
	/* Create two matrices and set some elements */
	Sparsemat * s = sm_create_matrix (10, 10);
	Sparsemat * s1 = sm_create_matrix (10, 10);

	int row =2, col = 3, value = 3;
	if(sm_set_element(s, row, col, value))
		printf("\nElement of matrix 1 at %d,%d set to %d", row, col, value); 
	row = 1; col = 1; value = 1;
	if(sm_set_element(s, row, col, value))
		printf("\nElement of matrix 1 at %d,%d set to %d", row, col, value);
	
	printf("\nMatrix 1 is: \n");
	sm_print_matrix(s);	

	row = 2; col = 3; value = 5;
	if(sm_set_element(s1, row, col, value))
		printf("\nElement of matrix 2 at %d,%d set to %d", row, col, value);
	row = 1; col = 1; value = 1;
        if(sm_set_element(s1, row, col, value))
                printf("\nElement of matrix 2 at %d,%d set to %d", row, col, value);
	printf("\nMatrix 2: \n");
	sm_print_matrix(s1);

	/* Addition of two Sparse Matrices */
	Sparsemat * s2 = sm_create_matrix(10, 10);
	s2 = sm_add_matrix(s, s1);
	printf("\nMatrix1 + Matrix2: \n");
	sm_print_matrix(s2);
	
	/* Searching for an element */
	element e;
	if(sm_search_element(s2, 8, &e))
			printf("\nElement found at %d, %d\n", e.row, e.col);
	else	printf("\nElement not found\n");
	

	Sparsemat * s3 = sm_create_matrix (10,5);
	sm_set_element(s3, 2, 3, 1);
	sm_set_element(s3, 4, 4, 2);
	printf("\nMatrix 3: \n");
	sm_print_matrix(s3);

	/* Transpose of matrix */
	s = sm_transpose(s);
	printf("\nTranspose of Matrix 1 is: \n");
	sm_print_matrix(s);

	Sparsemat * tr = sm_transpose(s3);
	printf("\nTranspose of matrix 3 is: \n");
	sm_print_matrix(tr);

	/* Trace of a square matrix */
	int trace;
	if(sm_trace_matrix(s1, &trace))
		printf("\nThe trace of matrix 2 is: %d\n", trace);
	else
		printf("\nTrace does not exist for matrix\n");
	
	/* Trace: if Matrix is not square matrix */
	
	if(sm_trace_matrix(s3, &trace))
                printf("\nThe trace of matrix 3 is: %d\n", trace);
	else
		printf("\nTrace does not exist for matrix3\n");
		
	/* Get element at row, col */
	int val;
	if(sm_get_element(s3, 2, 3, &val))
		printf("\nElement at 2,3 of matrix 3 is: %d", val);
	else
		printf("Element does not exist\n");

	/* Scale matrix */
	Sparsemat * scaled_matrix = sm_scale_matrix(s3, 5);
	printf("\nScaled matrix: \n");
	sm_print_matrix(scaled_matrix);

	return 0;
}
