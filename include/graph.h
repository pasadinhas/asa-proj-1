#ifndef __graph_h__
#define __graph_h__

#include "linked_list.h"

typedef struct graph {
    int V, E;
    list_node_t **adj_list;
} graph_t;

graph_t *new_graph(int vertices);
void graph_insert_edge(graph_t *graph, int from, int to);
void graph_print(graph_t *graph);
list_node_t *tarjan(graph_t *graph);
void tarjanAlgorithm(graph_t *graph, int v, list_node_t **stack, list_node_t **scc, int *tarjan_index, int *tarjan_lowlink, int *index);

#endif
