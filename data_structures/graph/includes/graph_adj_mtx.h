#ifndef __GRAPH_ADJ_MTX_H__
#define __GRAPH_ADJ_MTX_H__

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

/* Make an opaque data type */
typedef struct graph_t graph;

graph * create_graph(unsigned int num_nodes);

bool add_node_to_graph(graph* my_graph, unsigned int from, unsigned int to);
bool delete_node_from_graph(graph* my_graph, unsigned int from, unsigned int to);

void display_graph(graph* my_graph);

void free_graph(graph* my_graph);

#endif // __GRAPH_ADJ_MTX_H__