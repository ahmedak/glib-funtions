#include <stdio.h>
#include <glib.h>
#include "Bst.h"

/* Print the array */
void print_array(GArray * a) {
	int i;
	for(i=0; i<(a->len); i++)
		printf("%d  ", g_array_index(a, int, i));
	printf("\n");
}


int main (int argc, char ** argv) {
	Bst * tree = bst_new();
	GArray * traversal = g_array_new(FALSE, FALSE, sizeof(int));
	if(argc != 2){
		printf("Usage: ./example <filename.txt>\n");
		return 0;
	}
	if(bst_insert_file(tree, argv[1]))
		printf("\nInserted from file");
	else {
		printf("\n Error reading from file");
		return 1;
	}
	printf("\n\nInorder traversal: ");
	traversal = bst_inorder(tree, traversal);
	print_array(traversal);

	if(bst_delete(tree, 3))
		printf("\n\nDeleted 3");

	if(bst_delete(tree, 1))
		printf("\n\nDeleted 1");
	
	if(bst_delete(tree, 2))
		printf("\n\nDeleted 2");


	printf("\nInorder after deleting: ");
	traversal = bst_inorder(tree, traversal);
	print_array(traversal);

	printf("\n\nPostorder traversal: ");
	traversal = bst_postorder(tree, traversal);
	print_array(traversal);

	printf("\n\nPreorder traversal: ");
	traversal = bst_preorder(tree, traversal);
	print_array(traversal);
	printf("\n");

	if(bst_search(tree, 3))
		printf("\nSearching for 3: Found\n");
	else
		printf("\nSearching for 3: Not Found\n");

	if(bst_insert(tree, 99))
		printf("\n99 Inserted\n");
	else
		printf("\n99 already present\n");
	
	printf("\nInorder traversal now: ");
	traversal = bst_inorder(tree, traversal);
	print_array(traversal);
	printf("\n");

	return 0;
}
