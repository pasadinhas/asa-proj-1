#include <stdlib.h>

#include "graph.h"
#include "linked_list.h"

graph_t *new_graph(int vertices) {
    graph_t *graph = (graph_t *) malloc(1 * sizeof(graph_t));
    graph->V = vertices;
    graph->E = 0;
    graph->adj_list = (list_node_t **) malloc(vertices * sizeof(list_node_t *));
    return graph;
}

void graph_insert_edge(graph_t *graph, int from, int to) {
    graph->adj_list[from-1] = list_insert_beggin(graph->adj_list[from-1], to-1);
    graph->E++;
}
#include <stdio.h>
void graph_print(graph_t *graph) {
    int i;
    list_node_t *list;
    printf("This graph has %d vertices and %d edges.\n", graph->V, graph->E);
    printf("The connections are:\n");
    for (i=0; i<graph->V; i++) {
        list = graph->adj_list[i];
        while(list != NULL) {
            printf("  %d -> %d\n", i, list->val);
            list = list->next;
        }
    }
}

list_node_t *tarjan(graph_t *graph) {
    list_node_t *stack = NULL;
    list_node_t *scc = NULL;
    int *tarjan_index, *tarjan_lowlink, index = 0;
    int i;
    tarjan_index = (int *) malloc(graph->V * sizeof(int));
    tarjan_lowlink = (int *) malloc(graph->V * sizeof(int));
    for (i = 0; i < graph->V; i++) {
        tarjan_index[i] = tarjan_lowlink[i] = -1;
    }
    for (i = 0; i < graph->V; i++) {
        if (tarjan_index[i] == -1) {
            tarjanAlgorithm(graph, i, &stack, &scc, tarjan_index, tarjan_lowlink, &index);
        }
    }
    return scc;
}

/* source: http://en.algoritmy.net/article/44220/Tarjans-algorithm */

void tarjanAlgorithm(graph_t *graph, int v, list_node_t **stack, list_node_t **scc, int *tarjan_index, int *tarjan_lowlink, int *index) {
    list_node_t *node;
    int val, counter = 0;
    tarjan_index[v] = tarjan_lowlink[v] = (*index);
    (*index)++;
    (*stack) = list_insert_beggin((*stack), v);
    
    for (node = graph->adj_list[v]; node != NULL; node = node->next) {
	val = node->val;
	if (tarjan_index[val] == -1) {
	    tarjanAlgorithm(graph, val, stack, scc, tarjan_index, tarjan_lowlink, index);
	    tarjan_lowlink[v] = (tarjan_lowlink[v] < tarjan_lowlink[val]) ? tarjan_lowlink[v] : tarjan_lowlink[val];
	} else if (list_search((*stack), val) != NULL) {
	    tarjan_lowlink[v] = (tarjan_lowlink[v] < tarjan_index[val]) ? tarjan_lowlink[v] : tarjan_index[val];
	}
    }
    
    if (tarjan_lowlink[v] == tarjan_index[v]) {
	do {
	    (*stack) = list_pop_beggin((*stack), &val);
	    counter++;
	} while(v != val);
	(*scc) = list_insert_beggin((*scc), counter);
    }
}
