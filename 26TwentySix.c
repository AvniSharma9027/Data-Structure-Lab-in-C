// Program 26: Minimum Spanning Tree - Kruskal's Algorithm
#include <stdio.h>
#define INF 9999
#define V 5
int parent[V];
int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}
void unionSet(int i, int j) {
    int rootA = find(i);
    int rootB = find(j);
    parent[rootA] = rootB;
}
int main() {
    int cost[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };
    for (int i = 0; i < V; i++) {
        parent[i] = i;
        for (int j = 0; j < V; j++) {
            if (cost[i][j] == 0)
                cost[i][j] = INF; 
        }
    }
    int edge_count = 0;
    int mincost = 0;
    printf("Edge : Weight\n");
    while (edge_count < V - 1) {
        int min = INF, a = -1, b = -1;
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }
        int u = find(a);
        int v = find(b);
        if (u != v) {
            printf("%d - %d : %d\n", a, b, min);
            mincost += min;
            unionSet(u, v);
            edge_count++;
        }
        cost[a][b] = cost[b][a] = INF;
    }
    printf("Total Cost of MST: %d\n", mincost);
    return 0;
}