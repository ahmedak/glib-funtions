#include <stdio.h>
#include "Bst.h"

int main (int argc, char ** argv) {
	Bst * tree = bst_new();
	if(argc != 2){
		printf("Usage: ./example <filename.txt>\n");
		return 0;
	}
	if(bst_insert_file(tree, argv[1]))
		printf("\nInserted from file");
	else printf("\n Error reading from file");
	
	printf("\n\nInorder traversal: ");
	bst_inorder(tree);

	if(bst_delete(tree, 3))
		printf("\n\nDeleted 3");

	if(bst_delete(tree, 1))
		printf("\n\nDeleted 1");
	
	if(bst_delete(tree, 2))
		printf("\n\nDeleted 2");


	printf("\nInorder after deleting: ");
	bst_inorder(tree);

	printf("\n\nPostorder traversal: ");
	bst_postorder(tree);
	
	printf("\n\nPreorder traversal: ");
	bst_preorder(tree);
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
	bst_inorder(tree);
	printf("\n");

	return 0;
}
