#include <stdio.h>
#define MAX 10

int adjacencyMatrix[MAX + 1][MAX + 1];  
int numNodes;

void displayAdjacentNodes(int rootNode) {
    int found = 0;

    printf("\nAdjacent nodes of node %d:\n", rootNode);

    for (int i = 1; i <= numNodes; i++) {
                if (adjacencyMatrix[rootNode][i] == 1 || adjacencyMatrix[i][rootNode] == 1) {
            printf("%d\t", i);
            found = 1;
        }
    }

    if (!found)
        printf("None");
    printf("\n");
}

int main() {
    int rootNode;

    printf("Enter number of nodes (1 to %d): ", MAX);
    if (scanf("%d", &numNodes) != 1 || numNodes < 1 || numNodes > MAX) {
        printf("Invalid number of nodes.\n");
        return 1;
    }

    printf("Enter adjacency matrix (%d x %d, use 1 for edge, 0 for no edge):\n",
           numNodes, numNodes);
    for (int i = 1; i <= numNodes; i++) {
        for (int j = 1; j <= numNodes; j++) {
            if (scanf("%d", &adjacencyMatrix[i][j]) != 1 ||
                (adjacencyMatrix[i][j] != 0 && adjacencyMatrix[i][j] != 1)) {
                printf("Invalid entry. Use only 0 or 1.\n");
                return 1;
            }
        }
    }

    printf("Enter root node (1 to %d): ", numNodes);
    if (scanf("%d", &rootNode) != 1 || rootNode < 1 || rootNode > numNodes) {
        printf("Invalid root node.\n");
        return 1;
    }

    displayAdjacentNodes(rootNode);
    return 0;
}