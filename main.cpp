#include <cstdio>
#include <list>
#include <vector>
#include <stack>

#define WHITE -1

typedef std::vector< std::list<int> > graph;
typedef std::list<int>::iterator iter;

int output1 = 0, output2 = 0, output3 = 0;

void DFS_visit(graph &g, int v, int color[], std::stack<int> &stack) {
    color[v] = !WHITE;
    for (iter vIter = g[v].begin(); vIter != g[v].end(); vIter++)
        if (color[*vIter] == WHITE)
            DFS_visit(g, *vIter, color, stack);
    stack.push(v);
}

int DFS_visit2(graph &g, int u, int color[], bool &out_edge) {
    int size = 1;
    color[u] = output1;
    for (iter vIter = g[u].begin(); vIter != g[u].end(); vIter++)
        if (color[*vIter] == WHITE) 
            size += DFS_visit2(g, *vIter, color, out_edge);
        else if (color[*vIter] != output1) 
            out_edge = true;
    return size;
}

void create_transpose_graph(graph &g, graph &t) {
    for (int i = 0; i < (int) g.size(); i++)
        for (iter vIter = g[i].begin(); vIter != g[i].end(); vIter++)
            t[*vIter].push_back(i);
}

void solve(graph &g) {
    int V = g.size();
    int color[V], i;
    std::stack<int> stack;
    
    graph t(V);
    create_transpose_graph(g, t);
    
    for (i = 0; i < V; i++) color[i] = WHITE;
    for (i = 0; i < V; i++)
        if (color[i] == WHITE)
            DFS_visit(t, i, color, stack);

    for (i = 0; i < V; i++) color[i] = WHITE;
    while (stack.size() > 0) {
        int u = stack.top();
        stack.pop();
        if (color[u] == WHITE) {
            bool out_edge = false;
            int size = DFS_visit2(g, u, color, out_edge);
            if (!out_edge) output3++;
            output2 = std::max(size, output2);
            output1++;
        }
    }
}

int main() {
    int V, E, v1, v2;

    scanf("%d %d%*c", &V, &E);
    graph g(V);

    for (int i = 0; i < E; i++) {
        scanf("%d %d%*c", &v1, &v2);
        g[v1-1].push_back(v2-1);
    }
    
    solve(g);

    printf("%d\n%d\n%d\n", output1, output2, output3);

    return 0;
}
