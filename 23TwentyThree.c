//Depth-First-Search(DFS).
#include <stdio.h>
#define MAX 10
int visited[MAX] = {0};
void dfs(int adj[MAX][MAX], int n, int vertex) {
    visited[vertex] = 1;
    printf("%d ", vertex);
    for (int i = 0; i < n; i++) {
        if (adj[vertex][i] == 1 && !visited[i]) {
            dfs(adj, n, i);
        }
    }
}
int main() {
    int n = 5; 
    int adj[MAX][MAX] = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 1},
        {1, 0, 0, 0, 1},
        {0, 1, 0, 0, 0},
        {0, 1, 1, 0, 0}
    };
    int startVertex = 0;
    printf("DFS Traversal: ");
    dfs(adj, n, startVertex);
    printf("\n");
    return 0;
}