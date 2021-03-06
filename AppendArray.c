#include <glib.h>
#include <glib/gstdio.h>

/* Prints the 2-D array */
void array_print_2d(GArray * a, int row, int col) {
	int i,j,r,index;
	for(i=0; i<row; i++){
		for(j=0; j<col; j++) {
			// stored as Row major 
			index = i*col + j;
			r = g_array_index (a, int, index);
			g_printf("%d\t",r);
		}	
	g_printf("\n");	
	}
}

/* Returns the trace of the 2-D array */ 
int array_trace_2d(GArray * a, int len) {
	int i,sum = 0;
	for(i=0; i<len; i++)
		sum += g_array_index(a, int, i*len + i);
	return sum;
}

int main(int argc, char ** argv) {
        gchar * fcontents = NULL;
        gsize * len = NULL;
        const gchar * filename = "test2.txt";
        
	// Reads the contents of the file into string fcontents
	gboolean bl = g_file_get_contents(filename, &fcontents, len, NULL);
        if(bl==TRUE) {
                GArray * array = g_array_new(FALSE, FALSE, sizeof(int));
		gchar **p = g_strsplit(fcontents,"\n",0);
                int i, row, col, el;
		//Finding no.of rows and columns
		for(row = 0; p[row]!= NULL; row++);		
		col=--row;
		
		for(i=0; p[i]!=NULL; i++){
                	if(g_ascii_strcasecmp(p[i], "")){
                        	// Splits each line to corresponding elements
				gchar **q = g_strsplit(p[i], " ", 0);
			  	for(int j=0,k=0; q[j]!=NULL; j++) {
					if(g_ascii_strcasecmp(q[j], "")){
						el = (int)g_strtod(q[j], NULL);
						// Append to the row major array 
						g_array_append_val (array, el);						
					}	
				}
			}
                }
		array_print_2d(array, row, col);
		int trace = array_trace_2d(array, row);
		g_printf("\nTrace of %dx%d array: %d", row, row, trace);
	
		g_printf("\nEnter elements of new row: ");
		for(i=0; i<row; i++) {
			scanf("%d", &el);
			g_array_append_val(array, el);
		}
		row++;

		g_printf("\nNew array: \n");
		array_print_2d(array, row, col);
	}
	return 0;
}
