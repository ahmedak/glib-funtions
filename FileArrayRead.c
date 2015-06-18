#include <glib.h>
#include<glib/gstdio.h>

gint int_comparator(gconstpointer item1, gconstpointer item2) {
 	return *(int*)item1-*(int*)item2;
}

void print_array(GArray * a) {
	int i;
	for(i=0; i<(a->len); i++)
		g_printf("%d  ",g_array_index(a, int, i));
	g_printf("\n");
}

void find_element(int x,GArray* a){
	int i;
	for(i=0;i<a->len;i++)
		if(g_array_index(a,int,i)==x){
			g_printf("\nElement found at position %d\n",i);
			return;
		}
	printf("\nElement not found in the array\n");
}

int main(int argc, char ** argv) {
        gchar * fcontents = NULL;
        gsize * len = NULL;
        const gchar * filename = argv[1];
        gboolean bl=g_file_get_contents(filename, &fcontents, len, NULL);
        if(bl==TRUE) {
                GArray * array = g_array_new(FALSE, FALSE, sizeof(int));
                gchar **p = g_strsplit(fcontents,"\n",0);
                int i,x;
		for(i=0; p[i]!=NULL; i++){
			if(g_ascii_strcasecmp(p[i], "")){
				int r = g_strtod(p[i], NULL);
				g_array_append_val(array, r);
			}
		}
		g_array_sort(array, (GCompareFunc)int_comparator);
		g_printf("\nEnter the number to searched for:  ");
		scanf("%d",&x);
		find_element(x,array);
		g_printf("\nSorted Array: \n");
		print_array(array);
                g_printf("\nMaximum element: %d\n", g_array_index(array, int, (array->len)-1));
                g_printf("\nNumber of Elements in Array: %d \n", array->len);
        }
        else g_printf("Reading Data Failed\n");
        return 0;
}

