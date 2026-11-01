//Breadth-First-Search (BFS).
#include <stdio.h>
#define MAX 10
int queue[MAX];
int front = -1, rear = -1;
void enqueue(int vertex) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = vertex;
}
int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}
int isEmpty() {
    return (front == -1 || front > rear);
}
void bfs(int adj[MAX][MAX], int n, int start) {
    int visited[MAX] = {0};
    enqueue(start);
    visited[start] = 1;
    printf("BFS Traversal: ");
    while (!isEmpty()) {
        int curr = dequeue();
        printf("%d ", curr);
        for (int i = 0; i < n; i++) {
            if (adj[curr][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
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
    bfs(adj, n, startVertex);
    return 0;
}