#include <stdio.h>
#define INF 9999
#define MAX 10

void dijkstra(int graph[MAX][MAX], int n, int src) {
    int cost[MAX][MAX], dist[MAX], pred[MAX], visited[MAX];
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            cost[i][j] = (graph[i][j] == 0 && i != j) ? INF : graph[i][j];

    for (i = 0; i < n; i++) {
        dist[i] = cost[src][i];
        pred[i] = src;
        visited[i] = 0;
    }
    dist[src] = 0;
    visited[src] = 1;

    for (int count = 1; count < n; count++) {
        int minDist = INF, next = -1;

        for (i = 0; i < n; i++) {
            if (!visited[i] && dist[i] < minDist) {
                minDist = dist[i];
                next = i;
            }
        }

        if (next == -1) break;   
        visited[next] = 1;

        for (i = 0; i < n; i++) {
            if (!visited[i] && minDist + cost[next][i] < dist[i]) {
                dist[i] = minDist + cost[next][i];
                pred[i] = next;
            }
        }
    }

    for (i = 0; i < n; i++) {
        if (i == src) continue;

        if (dist[i] >= INF) {
            printf("\nNode %d is unreachable from node %d\n", i, src);
            continue;
        }

        printf("\nDistance from node %d to node %d = %d", src, i, dist[i]);
        printf("\nPath: %d", i);
        for (j = i; j != src; ) {
            j = pred[j];
            printf(" <- %d", j);
        }
        printf("\n");
    }
}

int main() {
    int graph[MAX][MAX], n, src;

    printf("Enter the number of vertices (1 to %d): ", MAX);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) {
        printf("Invalid number of vertices.\n");
        return 1;
    }

    printf("\nEnter the adjacency matrix (0 = no edge):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("\nEnter the starting node (0 to %d): ", n - 1);
    if (scanf("%d", &src) != 1 || src < 0 || src >= n) {
        printf("Invalid starting node.\n");
        return 1;
    }

    dijkstra(graph, n, src);
    return 0;
}
