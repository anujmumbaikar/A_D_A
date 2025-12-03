#include <stdio.h>
#define MAX 100

int visited[MAX];
int queue[MAX];
int front = -1, rear = -1;

void enqueue(int x) {
    if (rear == -1) {
        front = rear = 0;
    } else {
        rear++;
    }
    queue[rear] = x;
}

int dequeue() {
    int x = queue[front];
    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
    return x;
}

int isEmpty() {
    return (front == -1);
}

void BFS(int graph[MAX][MAX], int n, int start) {
    enqueue(start);
    visited[start] = 1;

    while (!isEmpty()) {
        int node = dequeue();
        printf("%d ", node);

        for (int i = 0; i < n; i++) {
            if (graph[node][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
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

    printf("Enter starting node (0 to %d): ", n - 1);
    scanf("%d", &start);

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    printf("Nodes reachable from node %d (BFS): ", start);
    BFS(graph, n, start);

    printf("\n");
    return 0;
}
