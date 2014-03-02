#include <stdio.h>
#include <stdlib.h>

#include "graph.h"

int main() {
    int n_people, n_shares;
    int i, p1, p2;

    scanf("%d", &n_people);
    scanf("%d", &n_shares);
    getchar();

    // TODO: alloc graph

    for (i = 0; i < n_shares; i++) {
        scanf("%d", &p1);
        scanf("%d", &p2);
        getchar();
        // TODO: Insert into graph
    }

    // TODO: Generate the output:
    //       1st: #(SCC)
    //       2nd: biggest size(SCC)
    //       3rd: #(?) 

    return 0;
}
