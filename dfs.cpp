#include <stdio.h>
#define MAX 100

int visited[MAX];

void DFS(int graph[MAX][MAX], int n, int start) {
    visited[start] = 1;
    printf("%d ", start);

    for (int i = 0; i < n; i++) {
        if (graph[start][i] == 1 && !visited[i]) {
            DFS(graph, n, i);
        }
    }
}

int main() {
    int n, start;
    int graph[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix of the directed graph:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Input starting node
    printf("Enter starting node (0 to %d): ", n - 1);
    scanf("%d", &start);

    // Initialize visited array
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    printf("Nodes reachable from node %d are: ", start);
    DFS(graph, n, start); // Perform DFS traversal

    printf("\n");
    return 0;
}
