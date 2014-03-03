#ifndef __graph_h__
#define __graph_h__

#include "int_list.h"
#include "int_list_list.h"

typedef struct graph {
    int V, E;
    int_list_p *adj_list;
} graph_t, *graph_p;

graph_p new_graph(int vertices);
void graph_insert_edge(graph_p graph, int from, int to);
int_list_list_p tarjan(graph_p graph);
void tarjanAlgorithm(graph_p graph, int v, int_list_p stack, int_list_list_p scc_list, int *tarjan_index, int *tarjan_lowlink, int *index);

#endif
