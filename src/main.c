#include <stdio.h>
#include <stdlib.h>

#include "graph.h"

int main() {
    int n_people, n_shares;
    int i, p1, p2, counter, biggest;
    graph_t *graph;
    list_node_t *scc_size, *list_aux;

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
 
    //graph_print(graph);
    scc_size = tarjan(graph);
    for (list_aux = scc_size, counter = 0, biggest = 0; list_aux != NULL; list_aux = list_aux->next) {
        if (list_aux->val > biggest) {
            biggest = list_aux->val;
        }
        counter++;
    }
    printf("%d\n", counter);
    printf("%d\n", biggest);
    // TODO: 3rd output: #(?)

    return 0;
}
