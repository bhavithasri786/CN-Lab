#include <stdio.h>

struct RoutingTable {
    unsigned distance[20];
    unsigned nextHop[20];
} rt[10];

int main() {
    int costMatrix[20][20];
    int numNodes;
    int i, j, k;
    int updated;

    printf("\nEnter the number of nodes (routers): ");
    scanf("%d", &numNodes);

    printf("\nEnter the cost matrix:\n");
    for (i = 0; i < numNodes; i++) {
        for (j = 0; j < numNodes; j++) {
            scanf("%d", &costMatrix[i][j]);

            if (i == j) {
                costMatrix[i][j] = 0;
            }

            rt[i].distance[j] = costMatrix[i][j];
            rt[i].nextHop[j] = j;
        }
    }

    do {
        updated = 0;

        for (i = 0; i < numNodes; i++) {
            for (j = 0; j < numNodes; j++) {
                for (k = 0; k < numNodes; k++) {
                    if (rt[i].distance[j] > costMatrix[i][k] + rt[k].distance[j]) {
                        rt[i].distance[j] = costMatrix[i][k] + rt[k].distance[j];
                        rt[i].nextHop[j] = k;
                        updated = 1;
                    }
                }
            }
        }
    } while (updated);

    for (i = 0; i < numNodes; i++) {
        printf("\nRouting Table for Router %d:\n", i + 1);
        printf("Destination\tNext Hop\tDistance\n");
        for (j = 0; j < numNodes; j++) {
            printf("     %d\t\t   %d\t\t   %d\n", j + 1, rt[i].nextHop[j] + 1, rt[i].distance[j]);
        }
    }

    printf("\n");
    return 0;
}