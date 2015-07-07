#include <stdio.h>
#include "graph.h"

int main(int argc, char ** argv) {
	if(argc == 2){ 
		Graph * g = graph_file_insert(argv[1]);
		graph_mst_kruskal(g);
		printf("\n");	
		graph_dijkstra(g, 2);	
	}
	else printf("Usage : ./example <filename.txt>\n");
	return 0;
}
