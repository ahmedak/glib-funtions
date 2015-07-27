#include <stdio.h>
#include <limits.h>
#include "graph.h"

int main(int argc, char ** argv) {
	if(argc == 2){ 
		Graph * g = graph_new(4, 4, 2);
		Path * d;
		Mst * m;
		int i, src;
		if(graph_file_insert(g, argv[1])){
			printf("Graph loaded from file\n");
			m = graph_mst_kruskal(g);
			printf("\nMST calulated using Kruskal's algorithm: \n");
			for(i =0; i < m->e; i++)
				printf("%d --%d-- %d\n",  m->edge[i].src, m->edge[i].weight, m->edge[i].dest);
			printf("\n");
			src = 2;
			d = graph_dijkstra(g, src);	
			printf("\nShortest distance from: %d to\n", src);
			for(i =0; i < (g->V); i++)
				if(d->distance[i] != INT_MAX && d->distance[i] != INT_MIN)
					printf("%d: %d\n", i, d->distance[i]);
		}
		else
			printf("Specified parameters of graph do not match that from given file\n");
	}
	else printf("Usage : ./example <filename.txt>\n");
	return 0;
}
