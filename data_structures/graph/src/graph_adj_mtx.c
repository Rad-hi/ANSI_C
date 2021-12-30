#include "graph_adj_mtx.h"

typedef struct graph_t{
	unsigned int num_nodes;
	bool ** nodes;
}graph;

graph * create_graph(unsigned int num_nodes){
	graph* my_graph = (graph*)malloc(sizeof(graph));

	if(my_graph == NULL) return NULL;

	my_graph->num_nodes = num_nodes;
	my_graph->nodes = (bool**)calloc(sizeof(bool*), num_nodes);
	
	if(my_graph->nodes == NULL){
		free(my_graph);
		return NULL;
	}

	for(unsigned int i = 0; i < num_nodes; i++){
		my_graph->nodes[i] = (bool*)calloc(sizeof(bool), num_nodes);
		if(my_graph->nodes[i] == NULL){
			free_graph(my_graph);
		}
	}

	return my_graph;
}

bool add_node_to_graph(graph* my_graph, unsigned int from, unsigned int to){
	if(my_graph == NULL || 
	   from < 0 || from >= my_graph->num_nodes ||
	   to < 0 || to >= my_graph->num_nodes ||
	   my_graph->nodes[from][to]){
		return false; /* Maybe returning a custom error message for each case would be better */
	}
	
	my_graph->nodes[from][to] = true;
	return true;
}

bool delete_node_from_graph(graph* my_graph, unsigned int from, unsigned int to){
	if(my_graph == NULL || 
	   from < 0 || from >= my_graph->num_nodes ||
	   to < 0 || to >= my_graph->num_nodes ||
	   my_graph->nodes[from][to] == false){
		return false; /* Maybe returning a custom error message for each case would be better */
	}

	my_graph->nodes[from][to] = false;
	return true;
}

void display_graph(graph* my_graph){
	printf("_|");
	for(unsigned int i = 0; i < my_graph->num_nodes; i++)
		printf("%d|", i);
	printf("\n");
	for(unsigned int from = 0; from < my_graph->num_nodes; from++){
		printf("%d|", from);
		for(unsigned int to = 0; to < my_graph->num_nodes; to++){
			printf("%s|", my_graph->nodes[from][to] ? "#" : ".");
		}
		printf("\n");
	}

	printf("\n");
}

void free_graph(graph* my_graph){
	if(my_graph == NULL) return;

	for(unsigned int i = 0; i < my_graph->num_nodes; i++){
		if(my_graph->nodes[i] != NULL)
			free(my_graph->nodes[i]);
	}
	free(my_graph->nodes);
	free(my_graph);
}