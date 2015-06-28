#ifndef _sparse_matrix
#define _sparse_matrix
#include <glib.h>

typedef struct _element {
	int row;
	int col;
	int value;
}element;

typedef struct _sm {
	//element * el;
	GArray * el;
	int maxRow;
	int maxCol;
	int tot;
}Sparsemat;

Sparsemat * createMatrix(int maxRow, int maxCol);

gboolean getElement(Sparsemat * smat, int row, int col, int * value);

gboolean setElement(Sparsemat * smat, int row, int col, int el);

//gboolean setIndex(Sparsemat * smat, int index, int row, int col, int el);

gboolean searchElement(Sparsemat * smat, int el, element * e);

void printMatrix(Sparsemat * smat);

Sparsemat * addMatrix(Sparsemat * sm1, Sparsemat * sm2);

Sparsemat * transpose(Sparsemat * smat);

gboolean traceMatrix(Sparsemat * smat, int * sum);

Sparsemat * scaleMatrix(Sparsemat * smat, int scale_factor);
#endif
