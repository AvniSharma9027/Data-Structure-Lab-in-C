//Minimum Spanning Tree -Prim's Algorithm.
#include <stdio.h>
#define INF 9999
#define V 5
int main() {
    int selected[V] = {0};
    int no_of_edges = 0;
    int total_cost = 0;
    int G[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };
    selected[0] = 1;
    printf("Edge : Weight\n");
    while (no_of_edges < V - 1) {
        int min = INF;
        int x = 0, y = 0;
        for (int i = 0; i < V; i++) {
            if (selected[i]) {
                for (int j = 0; j < V; j++) {
                    if (!selected[j] && G[i][j]) {
                        if (min > G[i][j]) {
                            min = G[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        printf("%d - %d : %d\n", x, y, G[x][y]);
        total_cost += G[x][y];
        selected[y] = 1;
        no_of_edges++;
    }
    printf("Total Cost of MST: %d\n", total_cost);
    return 0;
}