#include <stdio.h>
#include "SparseMatrix.h"

int main(int argc, char ** argv) {
	Sparsemat * s = createMatrix (10, 10);
	Sparsemat * s1 = createMatrix (10, 10);

	int row =2, col = 3, value = 3;
	if(setElement(s, row, col, value))
		printf("\nElement of matrix 1 at %d,%d set to %d", row, col, value); 
	row = 1; col = 1; value = 1;
	if(setElement(s, row, col, value))
		printf("\nElement of matrix 1 at %d,%d set to %d", row, col, value);
	
	printf("\nMatrix 1 is: \n");
	printMatrix(s);	

	row = 2; col = 3; value = 5;
	if(setElement(s1, row, col, value))
		printf("\nElement of matrix 2 at %d,%d set to %d", row, col, value);
	row = 1; col = 1; value = 1;
        if(setElement(s1, row, col, value))
                printf("\nElement of matrix 2 at %d,%d set to %d", row, col, value);
	printf("\nMatrix 2: \n");
	printMatrix(s1);

	Sparsemat * s2 = createMatrix(10, 10);
	s2 = addMatrix(s, s1);
	printf("\nMatrix1 + Matrix2: \n");
	printMatrix(s2);
	
	/* Searching for an element */
	element e;
	if(searchElement(s2, 8, &e))
			printf("\nElement found at %d, %d\n", e.row, e.col);
	else	printf("\nElement not found\n");
	

	Sparsemat * s3 = createMatrix (10,5);
	setElement(s3, 2, 3, 1);
	setElement(s3, 4, 4, 2);
	printf("\nMatrix 3: \n");
	printMatrix(s3);

	/* Transpose of matrix */
	s = transpose(s);
	printf("\nTranspose of Matrix 1 is: \n");
	printMatrix(s);

	Sparsemat * tr = transpose(s3);
	printf("\nTranspose of matrix 3 is: \n");
	printMatrix(tr);
	
	/* Trace of a square matrix */
	int trace;
	if(traceMatrix(s1, &trace))
		printf("\nThe trace of matrix 2 is: %d\n", trace);
	else
		printf("\nTrace does not exist for matrix\n");
	
	/* Trace: if Matrix is not square matrix */
	
	if(traceMatrix(s3, &trace))
                printf("\nThe trace of matrix 3 is: %d\n", trace);
	else
		printf("\nTrace does not exist for matrix3\n");
		
	/* Get element at row, col */
	int val;
	if(getElement(s3, 2, 3, &val))
		printf("\n Element at 2,3 of matrix 3 is: %d", val);
	else
		printf("Element does not exist\n");

	/* Scale matrix */
	Sparsemat * scaled_matrix = scaleMatrix(s3, 5);
	printf("\nScaled matrix: \n");
	printMatrix(scaled_matrix);

	return 0;
}
