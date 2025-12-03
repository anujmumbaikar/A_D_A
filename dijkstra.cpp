#include <stdio.h>
#include <limits.h>

#define V 5 // Number of vertices in the graph

int main() {

    int graph[V][V] = {
        {0, 10, 0, 5, 0},
        {10, 0, 1, 2, 0},
        {0, 1, 0, 9, 4},
        {5, 2, 9, 0, 2},
        {0, 0, 4, 2, 0}
    };

    int dist[V];      // shortest distances from source
    int visited[V];   // visited set
    int source = 0;   // starting node

    // Step 1: Initialize
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[source] = 0; // source to itself = 0

    // Step 2: Dijkstra core logic
    for (int count = 0; count < V - 1; count++) {

        // Find node with minimum distance
        int min = INT_MAX, u = -1;
        for (int i = 0; i < V; i++) {
            if (!visited[i] && dist[i] < min) {
                min = dist[i];
                u = i;
            }
        }

        visited[u] = 1; // mark u as visited

        // Relax edges of u
        for (int v = 0; v < V; v++) {
            if (graph[u][v] != 0 &&        // edge exists
                !visited[v] &&             // v not processed
                dist[u] != INT_MAX &&      // u must be reachable
                dist[u] + graph[u][v] < dist[v]) {

                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Step 3: Print the result
    printf("Shortest distances from source %d:\n", source);
    for (int i = 0; i < V; i++) {
        printf("To %d = %d\n", i, dist[i]);
    }

    return 0;
}
