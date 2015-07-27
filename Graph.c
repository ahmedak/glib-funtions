#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include "graph.h"

/*********************************************
 * Function: minDistance
 *
 * Find the vertex with minimum distance value, 
 * from the set of vertices not yet included 
 * in shortest path tree
 **********************************************/
int graph_min_distance(int dist[], bool visited[], int v){
	// Initialize min value
	int min = INT_MAX, min_index, i;

	for (i = 0; i< v; i++)
	if (visited[i] == false && dist[i] <= min)
		min = dist[i], min_index = i;
	return min_index;
}
 
/*********************************************
 * Funtion: graph_dijkstra
 * 
 * Function that implements Dijkstra's single source 
 * shortest path algorithm for a graph represented 
 * using adjacency matrix representation
 **********************************************/
Path * graph_dijkstra(Graph * g, int src){
	Path * dj = malloc(sizeof(struct _path));
	dj->distance = malloc((g->V)*sizeof(int));
	int v = g->V;
	dj-> v = v;
	int ** graph = g->am;	
	int dist[v];
	bool visited[v];
	int count, i;

	// Initialize all distances as INFINITE and visited[] as false
	for (i = 0; i < v; i++)
 	       dist[i] = INT_MAX, visited[i] = false;
     	dist[src] = 0;

     	// Find shortest path for all vertices
     	for (count = 0; count < v-1; count++){
    		int u = graph_min_distance(dist, visited, v);
		visited[u] = true;
		for (i = 0; i < v; i++)
			if (!visited[i] && graph[u][i] && dist[u]+graph[u][i] < dist[i])
            			dist[i] = dist[u] + graph[u][i];
     	}
	dj->distance = dist;
	return dj;
}



/*******************************************
 * Function: graph_new
 * 
 * Creates a graph with V vertices, E edges
 * and allocates space for edge list & adjacency
 * matrix
 *******************************************/
Graph * graph_new(int V, int E, int d){
    	Graph * graph = (Graph*) malloc( sizeof(struct _Graph) );
	graph->V = V;
	graph->E = E;
	graph->d = d;
	graph->am = (int**)malloc(sizeof(int)*V*V);
 	graph->edge = (Edge*) malloc( graph->E * sizeof( struct _Edge ) );
 	return graph;
}

/********************************************
 * Function: graph_file_insert
 * 
 * Insert data from file(adjacency matrix representation)
 * to graph
 ********************************************/
int graph_file_insert(Graph * graph, const char * filename){
	char c;
	int v = 0, d = 0, e = 0, i, j;
	FILE * fp = fopen(filename, "r");
	if(fp) {
		while(!feof(fp)){
			c = fgetc(fp);
			if(c == '\n')
				v++;	
		}

		fseek(fp, 0 ,SEEK_SET);
		int ** g = malloc(v*sizeof(int*));
		for(i = 0; i < v; i++)
			g[i] = malloc(v*sizeof(int));
		for(i = 0; i < v; i++)
			for(j = 0; j < v; j++)
				fscanf(fp, "%d", &g[i][j]);
		
		for(i = 0; i < v; i++)
			for(j = 0; j < v; j++){
				if(g[i][j] != g[j][i])
				d = 1;
				if(g[i][j])
					e++;
			}
		if(!d)
			e = e/2;
		
		//If given graph parameters do not match the ones from the file
		if(graph->V != v || graph->E != e || graph->d != d)
			return 0;
		
		graph->am = g;
		e = -1;
		for(i = 0; i < v; i++)
			for(j = 0; j < v; j++)
				if(g[i][j])
					if((!d && j >= i) || d){
						e++;
						graph->edge[e].src = i;
						graph->edge[e].dest = j;
						graph->edge[e].weight = g[i][j];
					}
	
		return 1;
	}
	return 0;
}

/*******************************************
 * Function: graph_find
 * 
 * Function to find set of an element i
 * (uses path compression technique)
 *******************************************/
int graph_find(subset s[], int i){

    	// find root and make root as parent of i (path compression)
    	if (s[i].parent != i)
        	s[i].parent = graph_find(s, s[i].parent);
 
    	return s[i].parent;
}
 
/*******************************************
 * Function: graph_union
 * 
 * Function that does union of two sets of x and y
 * (uses union by rank)
 *******************************************/
void graph_union(subset  s[], int x, int y){
    	int xroot = graph_find(s, x);
    	int yroot = graph_find(s, y);

	// (Union by Rank)
    	if (s[xroot].rank < s[yroot].rank)
        	s[xroot].parent = yroot;
    	else 
		s[yroot].parent = xroot;
	if (s[xroot].rank == s[yroot].rank)
        	s[xroot].rank++;
}
 
/******************************************
 * Function: edge_comparator
 *
 * Compare two edges according to their weights.
 * Used in qsort() for sorting an array of edges.
 *******************************************/
int edge_comparator(const void* a, const void* b){
	Edge * a1 = (Edge*)a;
	Edge * b1 = (Edge*)b;
	return a1->weight > b1->weight;
}
 

/******************************************
 * Function: graph_mst_kruskal
 * 
 * Function to construct MST using Kruskal's algorithm
 *******************************************/
Mst * graph_mst_kruskal(Graph * graph){
    	Mst * m = malloc(sizeof(struct _mst));
	int V = graph->V;
    	Edge result[V];  // The resultant MST
    	int e = 0;
    	int i = 0;
 
	//Sort all the edges in non-decreasing order of their weight
    	qsort(graph->edge, graph->E, sizeof(graph->edge[0]), edge_comparator);
    	subset * s = (subset *) malloc(V * sizeof(struct _subset) );
 
    	// Create V subsets with single elements
    	for (i = 0; i < V; i++){
        	s[i].parent = i;
        	s[i].rank = 0;
    	}
    	i = 0;
    	while (e < V - 1){
		// Union by rank
        	Edge next_edge = graph->edge[i++];
        	int x = graph_find(s, next_edge.src);
        	int y = graph_find(s, next_edge.dest);
	
        	if (x != y){
            		result[e++] = next_edge;
            		graph_union(s, x, y);
        	}
	} 
	m->e = e;
	m->edge = result;	
	return m;
}
