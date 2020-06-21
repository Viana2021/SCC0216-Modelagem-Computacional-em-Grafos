#ifndef _GRAPH_
#define _GRAPH_

typedef struct graph_elem GRAPH_ELEM;
typedef struct graph GRAPH;

//Function to create a graph
GRAPH *graph_create(int);
//Function to insert an edge in the graph list
int graph_edge_insert(GRAPH *, int, int);
//Function to remove an edge in the graph list
int graph_edge_remove(GRAPH *, int, int);
//Function to print the graph list
int graph_print_list(GRAPH *);
//Function to delete the graph and all memory allocated by it
int graph_delete(GRAPH *);

//TODO
int *graph_topological_order(GRAPH *);
//TODO
GRAPH *graph_transpose(GRAPH *);
//TODO
int graph_steps_count(GRAPH *, int *);

#endif
