#ifndef _graph_h
#define _graph_h

#include <stdbool.h>

/********************************************
 * Structure to represent a weighted edge in graph
 *
 ********************************************/
typedef struct _Edge{
	int src, dest, weight;
}Edge;
 
/********************************************
 * Structure to represent a minimum spanning
 * tree

 ********************************************/
typedef struct _mst{
<<<<<<< Updated upstream
	int e;
	Edge * edge;
=======
	int e;		//no of edges in mst
	Edge * edge;	// edge array
>>>>>>> Stashed changes
}Mst;

/********************************************
 * Structure to represent various paths from a
 * source vertex to other vertices in a graph
 *
 ********************************************/
typedef struct _path{
<<<<<<< Updated upstream
	int v;
	int * distance;
=======
	int v;		//source vertex
	int * distance;	//distance to all vertices in graph
>>>>>>> Stashed changes
}Path;

/********************************************
 * Structure to represent a connected, weighted 
 * graph
 *
 *********************************************/
typedef struct _Graph{
	// V: Number of vertices
	// E: Number of edges
	// d: 0 if undirected, 1 if directed
	int V, E, d;
	int ** am;	//adjacency matrix
	Edge * edge;	
}Graph;
 
/*******************************************
 * Structure to represent a subset for union-find
 * and store parent & rank of the node
 *******************************************/
typedef struct _subset{
    	int parent;
    	int rank;
}subset;
 
/*********************************************
 * Function: minDistance
 *
 * Find the vertex with minimum distance value, 
 * from the set of vertices not yet included 
 * in shortest path tree
 **********************************************/
int graph_min_distance(int dist[], bool visited[], int v);

/*********************************************
 * Funtion: graph_dijkstra
 * 
 * Function that implements Dijkstra's single source 
 * shortest path algorithm for a graph represented 
 * using adjacency matrix representation
 **********************************************/
Path * graph_dijkstra(Graph * g, int src);

/*******************************************
 * Function: graph_new
 * 
 * Creates a graph with V vertices, E edges
 * and allocates space for edge list & adjacency
 * matrix
 *******************************************/
Graph * graph_new(int V, int E, int d);

/********************************************
 * Function: graph_file_insert
 * 
 * Insert data from file(adjacency matrix representation)
 * to graph
 ********************************************/
int graph_file_insert(Graph * graph, const char * filename);

/*******************************************
 * Function: graph_find
 * 
 * Function to find set of an element i
 * (uses path compression technique)
 *******************************************/
int graph_find(subset s[], int i);
 
/*******************************************
 * Function: graph_union
 * 
 * Function that does union of two sets of x and y
 * (uses union by rank)
 *******************************************/
void graph_union(subset  s[], int x, int y);

/******************************************
 * Function: edge_comparator
 *
 * Compare two edges according to their weights.
 * Used in qsort() for sorting an array of edges.
 *******************************************/
int edge_comparator(const void* a, const void* b);

/******************************************
 * Function: graph_mst_kruskal
 *  
 * Function to construct MST using Kruskal's algorithm
 *******************************************/
Mst * graph_mst_kruskal(Graph * graph);

#endif
