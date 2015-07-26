#ifndef _balanced_bst
#define _balanced_bst

#include <glib.h>

/**************************************
 * The tree data structure:
 * uses inbuilt GTree.
 ***************************************/
typedef GTree Bst;

/***************************************
 * Function: balanced_bst_new
 *
 * Creates a new balanced bst and returns
 * a pointer to it
 ****************************************/
Bst * balanced_bst_new();


/***************************************
 * Function: balanced_bst_insert_file
 *
 * Inserts elements from a file to the tree
 ***************************************/
gboolean balanced_bst_insert_file(Bst * tree, const char * in_file); 

/***************************************
 * Function: balanced_bst_insert
 *
 * Inserts an element into the tree and
 * balances the tree
 ****************************************/
gboolean balanced_bst_insert(Bst * tree, int element);

/***************************************
 * Function: balanced_bst_search
 *
 * Searches for an element in the tree
 ****************************************/
gboolean balanced_bst_search(Bst * tree, int element);

/***************************************
 * Function: balanced_bst_delete
 *
 * Deletes the element and balances the 
 * tree
 ****************************************/
gboolean balanced_bst_delete(Bst * tree, int element);

/***************************************
 * Function: balanced_bst_inorder
 *
 * Stores the inorder traversal of the 
 * tree in an array
 ****************************************/
GArray * balanced_bst_inorder(Bst * tree, GArray * traversal);

/***************************************
 * Function: balanced_bst_preoder
 *
 * Stores the preorder traversal of the 
 * tree in an array
 ****************************************/
GArray * balanced_bst_preorder(Bst * tree, GArray * traversal);

/***************************************
 * Function: balanced_bst_postorder
 *
 * Stores the postorder traversal of the 
 * tree in an array
 ****************************************/
GArray * balanced_bst_postorder(Bst * tree, GArray * traversal);

#endif
