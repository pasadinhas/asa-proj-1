#include <stdlib.h>
#include <stdio.h>

#include "graph.h"
#include "int_list.h"
#include "int_list_list.h"

graph_p new_graph(int vertices) {
    int i;
    graph_p graph = (graph_p) malloc(sizeof(graph_t));
    graph->V = vertices;
    graph->E = 0;
    graph->adj_list = (int_list_p *) malloc(vertices * sizeof(int_list_p));
    for (i = 0; i < vertices; i++) {
        graph->adj_list[i] = new_int_list();
    }
    return graph;
}

void graph_insert_edge(graph_p graph, int from, int to) {
    int_list_insert(graph->adj_list[from-1], to-1);
    graph->E++;
}

/* source: http://en.algoritmy.net/article/44220/Tarjans-algorithm */

int_list_list_p tarjan(graph_p graph) {
    int_list_p stack = new_int_list();
    int_list_list_p scc_list = new_int_list_list();
    int *tarjan_index, *tarjan_lowlink, index = 0;
    int i;
    tarjan_index = (int *) malloc(graph->V * sizeof(int));
    tarjan_lowlink = (int *) malloc(graph->V * sizeof(int));
    for (i = 0; i < graph->V; i++) {
        tarjan_index[i] = tarjan_lowlink[i] = -1;
    }
    for (i = 0; i < graph->V; i++) {
        if (tarjan_index[i] == -1) {
            tarjanAlgorithm(graph, i, stack, scc_list, tarjan_index, tarjan_lowlink, &index);
        }
    }
    return scc_list;
}

void tarjanAlgorithm(graph_p graph, int v, int_list_p stack, int_list_list_p scc_list, int *tarjan_index, int *tarjan_lowlink, int *index) {
    int_list_node_p node;
    int_list_p scc;
    int val;
    tarjan_index[v] = tarjan_lowlink[v] = (*index);
    (*index)++;
    int_list_push(stack, v);
    
    for (node = graph->adj_list[v]->head; node != NULL; node = node->next) {
	val = node->val;
	if (tarjan_index[val] == -1) {
	    tarjanAlgorithm(graph, val, stack, scc_list, tarjan_index, tarjan_lowlink, index);
	    tarjan_lowlink[v] = (tarjan_lowlink[v] < tarjan_lowlink[val]) ? tarjan_lowlink[v] : tarjan_lowlink[val];
	} else if (int_list_search(stack, val) != NULL) {
	    tarjan_lowlink[v] = (tarjan_lowlink[v] < tarjan_index[val]) ? tarjan_lowlink[v] : tarjan_index[val];
	}
    }

    if (tarjan_lowlink[v] == tarjan_index[v]) {
        scc = new_int_list();
	do {
	    val = int_list_pop(stack);
	    int_list_insert(scc, val);
	} while(v != val);
	int_list_list_insert(scc_list, scc);
    }
}
