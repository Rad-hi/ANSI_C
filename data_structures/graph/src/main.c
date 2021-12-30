#include "graph_adj_mtx.h"

#define NUM_NODES				5

graph * my_graph;

int main(int argc, char const *argv[]){
	
	my_graph = create_graph(NUM_NODES);

	add_node_to_graph(my_graph, 0, 2);
	add_node_to_graph(my_graph, 2, 3);
	add_node_to_graph(my_graph, 1, 2);
	add_node_to_graph(my_graph, 0, 3);
	add_node_to_graph(my_graph, 1, 3);

	display_graph(my_graph);

	delete_node_from_graph(my_graph, 0, 2);
	delete_node_from_graph(my_graph, 1, 3);

	display_graph(my_graph);

	return 0;
}