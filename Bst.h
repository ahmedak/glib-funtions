#ifndef _bst_h
#define _bst_h

/**************************************
 The tree data structure
 
***************************************/
typedef struct _node{
    int * data;
    struct _node * parent;
    struct _node * leftChild;
    struct _node * rightChild;
}Bst;

/***************************************
 Function: bst_new
 Input	: none
 Output	: pointer to a newly created 
 	  balanced binary search tree

 Creates a new balanced bst and returns
 a pointer to it
****************************************/
Bst * bst_new();


/***************************************
 Function: bst_insert_file
 Input	: tree, file pointer
 Output	: 1 if elements inserted from file
 	  0 otherwise
 
 Inserts elements from a file to the tree
 ***************************************/
int bst_insert_file(Bst * tree, const char * in_file); 

/***************************************
 Function: bst_insert
 Input	: tree, element to be inserted
 Output	: 1 if element is inserted
 	  0 if element already present

 Inserts an element into the tree
****************************************/
int bst_insert(Bst * tree, int element);

/***************************************
 Function: bst_search
 Input	: tree, element to be searched
 Output	: 1 if element is present
 	  0 otherwise

 Searches for an element in the tree
****************************************/
int bst_search(Bst * tree, int element);

/***************************************
 Function: bst_delete
 Input	: tree, element to be deleted
 Output	: 1 if element is deleted,
 	  0 otherwise

 Deletes the element and balances the 
 tree
****************************************/
int bst_delete(Bst * tree, int element);

/***************************************
 Function: bst_inorder
 Input	: tree
 Output	: none 

 Prints the inorder traversal of the 
 tree
****************************************/
void bst_inorder(Bst * tree);

/***************************************
 Function: bst_preoder
 Input	: tree
 Output	: none

 Prints the preorder traversal of the 
 tree
****************************************/
void bst_preorder(Bst * tree);

/***************************************
 Function: bst_postorder
 Input	: tree
 Output	: none
 
 Prints the postorder traversal of the 
 tree
****************************************/
void bst_postorder(Bst * tree);

#endif
