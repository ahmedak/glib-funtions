#include <stdio.h>
#include <stdlib.h>
#include "Bst.h"

/*Creates new bst */
Bst * bst_new() {
	Bst * b = malloc(sizeof(struct _node));
	b->data = NULL;
	b->parent = NULL;
	b->leftChild = NULL;
	b->rightChild = NULL;
	return b;
}

/* Reads contents from file and inserts into bst */
int bst_insert_file(Bst * tree, const char * filename){
	FILE * fin = fopen(filename, "r");
	if(!fin)
		return 0;
	int el = 1;	
	while(!feof(fin)){
		fscanf(fin, "%d", &el);
		// Insert into the bst
		bst_insert(tree, el);
	}
	return 1;
}

/* Manually insert an element into the bst */
int bst_insert(Bst * tree, int element){
	//If the bst is empty	
	if(tree->data == NULL){
		tree->data = malloc(sizeof(int));
		*tree->data = element;
      		return 1;
	}	
    	else if(!bst_search(tree, element)){
		Bst * child = bst_new();
		child->data = malloc(sizeof(int));
		*child->data = element;
		Bst * x = tree;
		Bst * y ;
		while(x != NULL){
			y = x; 
			if(*x->data < element )
				x = x->rightChild;
			else  x = x->leftChild;
		}
		if(*y->data > element){
			y->leftChild = child;
			child->parent = y;
		}
		else {
			y->rightChild = child;
			child->parent = y;
		}
		return 1;
    	} 
	else return 0;
}

/* Search for an element in bst */
int bst_search(Bst * tree, int element){
	Bst * x = tree; 
	while(x != NULL && x->data != NULL){
		if( *x->data == element)
			return 1;
		else if(*x->data < element )
			x = x->rightChild;
		else  x = x->leftChild;
	}
	return 0;
}

/* Returns the minimum of a subtree */
Bst * bst_minimum(Bst * node){
	Bst * x = node;
	while(x->leftChild)
		x = x->leftChild;
	return x;
}

/* Returns the successor of a node */
Bst * bst_successor(Bst * x){
	if(x->rightChild)
		return bst_minimum(x->rightChild);
	else{
		Bst * y = x->parent;
		while(y && x == y->rightChild){
			x = y;
			y = y->parent;
		}
	return y;
	}
}

/* Deletes a node from the bst */
int bst_delete(Bst * root, int element){
	if(root == NULL)
		return 0;
	Bst * x = root; 	
	while(x){
		if( *x->data == element)
			break;
		else if(*x->data < element )
			x = x->rightChild;
		else  x = x->leftChild;
	}
	if(x){
		Bst * y, * z, *py;
		if(x->rightChild == NULL || x->leftChild == NULL)
			y = x;
		else y = bst_successor(x);
		if(y->leftChild)
			z = y->leftChild;
		else
			z = y->rightChild;
		if(z)
			z->parent = y->parent;
		py = y->parent;
		if(py){
			if(y == py->rightChild)
				py->rightChild = z;
			else py->leftChild = z;
		}
		else if(z != NULL)
			*root = *z;
		else *root = *bst_new(); 
		if(y != x)
		x->data = y->data;
		return 1;
	}
	return 0;
}

/* Prints inorder traversal */
void bst_inorder(Bst * x) {
	if(!x)
		return;
	bst_inorder(x->leftChild);
	if(x->data)
		printf("%d  ", *x->data);
	else	printf("(null)");
	bst_inorder(x->rightChild);
}

/* Prints postorder traversal */
void bst_postorder(Bst * x) {
	if(!x)
		return;
	bst_postorder(x->leftChild);
	bst_postorder(x->rightChild);
	if(x->data)
		printf("%d  ", *x->data);
	else	printf("(null)");
}

/* Prints preorder traversal */
void bst_preorder(Bst * x) {
	if(!x)
		return;
	if(x->data)
		printf("%d  ", *x->data);
	else	printf("(null)");
	bst_preorder(x->leftChild);
	bst_preorder(x->rightChild);
}
