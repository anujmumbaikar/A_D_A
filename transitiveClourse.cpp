#include <stdio.h>
#define MAX 10

// Warshall's Algorithm to compute transitive closure
void warshall(int n, int graph[MAX][MAX]) {
    int i, j, k;

    for (k = 0; k < n; k++) {    
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {

                // If i → k and k → j, then i → j is reachable
                graph[i][j] = graph[i][j] || (graph[i][k] && graph[k][j]);

            }
        }
    }
}

int main() {
    int n, i, j;
    int graph[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix of the graph:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Compute transitive closure
    warshall(n, graph);

    printf("\nTransitive Closure (Reachability Matrix):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
    return 0;
}
