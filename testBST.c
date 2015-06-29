#include <stdio.h>
#include "BalancedBst.h"
#include <glib.h>

int main (int argc, char ** argv) {
	Bst * tree = balanced_bst_new();
	
	if(balanced_bst_insert_file(tree, argv[1]))
		printf("\nInserted from file");
	else printf("\n Error reading from file");
	
	printf("\n\nInorder traversal: ");
	balanced_bst_inorder(tree);

	if(balanced_bst_delete(tree, 4))
		printf("\n\nDeleted 4");

	printf("\nInorder after deleting: ");
	balanced_bst_inorder(tree);

	printf("\n\nPostorder traversal: ");
	balanced_bst_postorder(tree);
	
	printf("\n\nPreorder traversal: ");
	balanced_bst_preorder(tree);
	printf("\n");

	if(balanced_bst_search(tree, 4))
		printf("\nSearching for 4: Found\n");
	else
		printf("\nSearching for 4: Not Found\n");

	if(balanced_bst_insert(tree, 99))
		printf("\n99 Inserted\n");
	else
		printf("\n99 already present\n");
	
	printf("\nInorder traversal now: ");
	balanced_bst_inorder(tree);
	printf("\n");

	return 0;
}
