#include <stdio.h>
#include <stdlib.h>

#include "graph.h"

int main() {
    int n_people, n_shares;
    int i, p1, p2, disj, biggest, flag;
    graph_p graph;
    int_list_list_p scc_list;
    int_list_list_node_p scc_list_node;
    int_list_p scc;
    int_list_node_p scc_el, edge;

    scanf("%d", &n_people);
    scanf("%d", &n_shares);
    getchar();

    graph = new_graph(n_people);

    for (i = 0; i < n_shares; i++) {
        scanf("%d", &p1);
        scanf("%d", &p2);
        getchar();
        graph_insert_edge(graph, p1, p2);
    }
    
    scc_list = tarjan(graph);
    
    for (scc_list_node = scc_list->head, biggest = 0, disj = 0; scc_list_node != NULL; scc_list_node = scc_list_node->next) {
        if (scc_list_node->list->size > biggest) {
            biggest = scc_list_node->list->size;
        }
        for (scc = scc_list_node->list, scc_el = scc->head, flag = 1; scc_el != NULL; scc_el = scc_el->next) {
            for (edge = graph->adj_list[scc_el->val]->head; edge != NULL; edge = edge->next) {
                if (int_list_search(scc, edge->val) == NULL) {
                    flag = -1;
                    break;
                }
            }
            if (flag == -1) {
                break;
            }
        }
        if (flag != -1) {
            disj++;
        }
        
    }
    printf("%d\n", scc_list->size);
    printf("%d\n", biggest);
    printf("%d\n", disj);

    return 0;
}
