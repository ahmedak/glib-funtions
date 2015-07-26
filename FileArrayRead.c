#include <glib.h>
#include<glib/gstdio.h>

/* Utility function to compare two integers. Used by g_array_sort */
gint int_comparator(gconstpointer item1, gconstpointer item2) {
 	return *(int*)item1-*(int*)item2;
}

/* Print the array */
void print_array(GArray * a) {
	int i;
	for(i=0; i<(a->len); i++)
		g_printf("%d  ",g_array_index(a, int, i));
	g_printf("\n");
}

/* Function to search for element */
int find_element(int x, GArray* a, int* pos){
	int i;
	for(i=0;i<a->len;i++)
		if(g_array_index(a,int,i)==x){
			*pos = i;
			return 1;
		}
	return 0;
}


int main(int argc, char ** argv) {
        gchar * fcontents = NULL;
        gsize * len = NULL;
        const gchar * filename = argv[1];
        gboolean bl=g_file_get_contents(filename, &fcontents, len, NULL);
        if(bl==TRUE) {
                // Create new GArray
		GArray * array = g_array_new(FALSE, FALSE, sizeof(int));
                gchar **p = g_strsplit(fcontents,"\n",0);
                int i,x;
		for(i=0; p[i]!=NULL; i++){
			if(g_ascii_strcasecmp(p[i], "")){
				int r = g_strtod(p[i], NULL);
				g_array_append_val(array, r);
			}
		}

		// Sort array
		g_array_sort(array, (GCompareFunc)int_comparator);
		g_printf("\nEnter the number to searched for:  ");
		scanf("%d",&x);
		
		// Search for element
		int position = -1;
		if(find_element(x, array, &position))
			g_printf("\nElement found at position %d\n", position);
		else
			g_printf("\nElement not found\n");
		
		g_printf("\nSorted Array: \n");
		print_array(array);
                g_printf("\nMaximum element: %d\n", g_array_index(array, int, (array->len)-1));
                g_printf("\nNumber of Elements in Array: %d \n", array->len);
        }
        else g_printf("Reading Data Failed\n");
        return 0;
}

