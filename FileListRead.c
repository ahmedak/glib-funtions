#include <glib.h> 
#include<glib/gstdio.h>

/* Function returns 1 if first item is greater , -1 if less 
   and 0 if equal to the second item respectively */
gint int_comparator(gconstpointer item1, gconstpointer item2) {
	gint item1d = g_strtod(item1,NULL);
	gint item2d = g_strtod(item2,NULL);
	if(item1d>item2d)
		return 1;
	else if(item1d==item2d)
		return 0;
	else return -1;
}

int main(int argc, char ** argv) {
	gchar * fcontents = NULL;
	gsize * len = NULL;
	const gchar * filename = argv[1];
	
	// reads the contents of file into the string fcontents
	gboolean bl=g_file_get_contents(filename, &fcontents, len, NULL);
	if(bl==TRUE) {
		
		GSList * list, * iterator = NULL;
		
		// Splits the array in fcontents to integers
		gchar **p = g_strsplit(fcontents,"\n",0);
		int i;
		for ( i=0;p[i]!=NULL; i++){
			if(g_ascii_strcasecmp(p[i],""))
				// Appends all on empty integers to the list
				list = g_slist_append(list, p[i]);
		}
		printf("\n\nBefore Sorting\n");
		for(iterator = list; iterator; iterator= iterator->next)
			g_printf("--> %s", (char*)iterator->data);

		// List is sorted using the comparator function 
		list = g_slist_sort(list, (GCompareFunc)int_comparator);		//sort
		printf("\n\nAfter sorting: \n");
		
		for(iterator = list; iterator; iterator= iterator->next)
	       	        g_printf("--> %s", (char*)iterator->data);
		
		g_printf("\n\nMinimum element: %s\n", (char*)list->data);
		g_printf("Number of Elements in the List: %d \n\n", (int)g_slist_length(list));
	}
	else g_printf("Reading Data Failed\n");
	return 0;
}
	
