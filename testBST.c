#include <stdio.h>
#include "BalancedBst.h"
#include <glib.h>

/* Print the array */
void print_array(GArray * a) {
	int i;
	for(i=0; i<(a->len); i++)
		g_printf("%d  ",g_array_index(a, int, i));
	g_printf("\n");
}


int main (int argc, char ** argv) {
	GArray * traversal = g_array_new(FALSE, FALSE, sizeof(int));
	Bst * tree = balanced_bst_new();

	if(balanced_bst_insert_file(tree, argv[1]))
		printf("\nInserted from file");
	else printf("\n Error reading from file");
	
	printf("\n\nInorder traversal: ");
	traversal = balanced_bst_inorder(tree, traversal);
	print_array(traversal);

	if(balanced_bst_delete(tree, 4))
		printf("\n\nDeleted 4");

	printf("\nInorder after deleting: ");
	traversal = balanced_bst_inorder(tree, traversal);
	print_array(traversal);

	printf("\n\nPostorder traversal: ");
	traversal = balanced_bst_postorder(tree, traversal);
	print_array(traversal);
	
	printf("\n\nPreorder traversal: ");
	traversal = balanced_bst_preorder(tree, traversal);
	print_array(traversal);
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
	traversal = balanced_bst_inorder(tree, traversal);
	print_array(traversal);
	printf("\n");

	return 0;
}
