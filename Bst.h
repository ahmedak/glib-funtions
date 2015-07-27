#ifndef _bst_h
#define _bst_h

/**************************************
 * The tree data structure
 *
 ***************************************/
typedef struct _node{
    int * data;
    struct _node * parent;
    struct _node * leftChild;
    struct _node * rightChild;
}Bst;

/***************************************
 * Function: bst_new
 *
 * Creates a new bst and returns
 * a pointer to it
 ****************************************/
Bst * bst_new();

/***************************************
 * Function: bst_insert_file
 *
 * Inserts elements from a file to the tree
 ***************************************/
int bst_insert_file(Bst * tree, const char * in_file); 

/***************************************
 * Function: bst_insert
 *
 * Inserts an element into the tree
 ****************************************/
int bst_insert(Bst * tree, int element);

/***************************************
 * Function: bst_search
 *
 * Searches for an element in the tree
 ****************************************/
int bst_search(Bst * tree, int element);

/***************************************
 * Function: bst_delete
 * 
 * Deletes the element 
 ****************************************/
int bst_delete(Bst * tree, int element);

/***************************************
 * Function: bst_inorder
 *
 * Stores the inorder traversal of the 
 * tree to an array
 ****************************************/
GArray * bst_inorder(Bst * tree, GArray * traversal);

/***************************************
 * Function: bst_preoder
 *
 * Stores the preorder traversal of the 
 * tree to an array
 ****************************************/
GArray *  bst_preorder(Bst * tree, GArray * traversal);

/***************************************
 * Function: bst_postorder
 *
 * Stores the postorder traversal of the 
 * tree to an array
 ****************************************/
GArray * bst_postorder(Bst * tree, GArray * traversal);

#endif
