#include <glib.h>
#include <stdio.h>
#include<stdlib.h>

#include "BalancedBst.h"

gint int_comparator(gconstpointer item1, gconstpointer item2) {
 	return *(int*)item1 - *(int*)item2;
}

gboolean traverse_func(gpointer key, gpointer value, gpointer data){
	printf("  %d", *(int *)value);
	return FALSE;
}

Bst * balanced_bst_new (){
	Bst * b = g_tree_new((GCompareFunc)int_comparator);
	return b;
}

gboolean balanced_bst_insert_file(Bst * tree, const char * filename){
        gchar * fcontents = NULL;
        gsize * len = NULL;
        gboolean bl=g_file_get_contents(filename, &fcontents, len, NULL);
        if(bl==TRUE) {
                gchar **p = g_strsplit(fcontents,"\n",0);
                int i;
		for(i=0; p[i]!=NULL; i++){
			if(g_ascii_strcasecmp(p[i], "")){
				int r = g_strtod(p[i], NULL);
				balanced_bst_insert(tree, r);
			}
		}
		return TRUE;
	}
	else return FALSE;
}

gboolean balanced_bst_insert(Bst * tree, int element){
	int * k  =(int *)malloc(sizeof(int));
	*k = element;
	if(!(g_tree_lookup(tree, (gpointer)k))){
		g_tree_insert(tree, (gpointer)k, (gpointer)k);
		return TRUE;
	}
	else return FALSE;
}

gboolean balanced_bst_search(Bst * tree, int element){
	int * k = (int *)malloc(sizeof(int));
	* k  = element;
	if(g_tree_lookup(tree, (gpointer)k))
		return TRUE;
	else return FALSE;
}

gboolean balanced_bst_delete(Bst * tree, int element){
	int * k = &element;
	return g_tree_remove(tree, k);
}

void balanced_bst_inorder(Bst * tree) {
	g_tree_traverse(tree, (GTraverseFunc)traverse_func, G_IN_ORDER, NULL);
}

void balanced_bst_postorder(Bst * tree) {
	g_tree_traverse(tree, (GTraverseFunc)traverse_func, G_POST_ORDER, NULL);
}

void balanced_bst_preorder(Bst * tree) {
	g_tree_traverse(tree, (GTraverseFunc)traverse_func, G_PRE_ORDER, NULL);
}
