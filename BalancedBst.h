#ifndef _balanced_bst
#define _balanced_bst


#include <glib.h>

/**************************************
 The tree data structure:
 uses inbuilt GTree.
 
***************************************/
typedef GTree Bst;

/***************************************
 Function: balanced_bst_new
 Input	: none
 Output	: pointer to a newly created 
 	  balanced binary search tree

 Creates a new balanced bst and returns
 a pointer to it
****************************************/
Bst * balanced_bst_new();


/***************************************
 Function: balanced_bst_insert_file
 Input	: tree, file pointer
 Output	: TRUE if elements inserted from file
 	  FALSE otherwise
 
 Inserts elements from a file to the tree
 ***************************************/
gboolean balanced_bst_insert_file(Bst * tree, const char * in_file); 

/***************************************
 Function: balanced_bst_insert
 Input	: tree, element to be inserted
 Output	: TRUE if element is inserted
 	  FALSE if element already present

 Inserts an element into the tree
****************************************/
gboolean balanced_bst_insert(Bst * tree, int element);

/***************************************
 Function: balanced_bst_search
 Input	: tree, element to be searched
 Output	: TRUE if element is present
 	  FALSE otherwise

 Searches for an element in the tree
****************************************/
gboolean balanced_bst_search(Bst * tree, int element);

/***************************************
 Function: balanced_bst_delete
 Input	: tree, element to be deleted
 Output	: TRUE if element is deleted,
 	  FALSE otherwise

 Deletes the element and balances the 
 tree
****************************************/
gboolean balanced_bst_delete(Bst * tree, int element);

/***************************************
 Function: balanced_bst_inorder
 Input	: tree
 Output	: none 

 Prints the inorder traversal of the 
 tree
****************************************/
void balanced_bst_inorder(Bst * tree);

/***************************************
 Function: balanced_bst_preoder
 Input	: tree
 Output	: none

 Prints the preorder traversal of the 
 tree
****************************************/
void balanced_bst_preorder(Bst * tree);

/***************************************
 Function: balanced_bst_postorder
 Input	: tree
 Output	: none
 
 Prints the postorder traversal of the 
 tree
****************************************/
void balanced_bst_postorder(Bst * tree);

#endif
