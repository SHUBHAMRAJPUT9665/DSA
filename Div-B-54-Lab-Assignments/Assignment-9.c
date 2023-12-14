/*
Write a program to represent a graph of any city using adjacency
matrix /adjacency list. Nodes should represent the various areas in the
city and links should represent the distance between them. Find the
shortest path of your college from your home using Dijkstra's
algorithm
*/

#include <stdio.h>
#include <limits.h>

#define MAX_AREAS 10

int minDistance(int distance[], int shortestPathSet[], int numAreas) {
    int min = INT_MAX, minIndex;

    for (int v = 0; v < numAreas; v++) {
        if (shortestPathSet[v] == 0 && distance[v] <= min) {
            min = distance[v];
            minIndex = v;
        }
    }

    return minIndex;
}

void printPath(int parent[], int j) {
    if (parent[j] == -1) {
        return;
    }

    printPath(parent, parent[j]);
    printf(" -> %d", j);
}

void printSolution(int distance[], int parent[], int numAreas, int source, int destination) {
    printf("Shortest Path from %d to %d: %d\n", source, destination, distance[destination]);
    printf("Path: %d", source);
    printPath(parent, destination);
    printf("\n");
}

void dijkstra(int graph[MAX_AREAS][MAX_AREAS], int numAreas, int source, int destination) {
    int distance[MAX_AREAS];
    int shortestPathSet[MAX_AREAS];
    int parent[MAX_AREAS];

    for (int i = 0; i < numAreas; i++) {
        distance[i] = INT_MAX;
        shortestPathSet[i] = 0;
        parent[i] = -1;
    }

    distance[source] = 0;

    for (int count = 0; count < numAreas - 1; count++) {
        int u = minDistance(distance, shortestPathSet, numAreas);
        shortestPathSet[u] = 1;

        for (int v = 0; v < numAreas; v++) {
            if (!shortestPathSet[v] && graph[u][v] && distance[u] != INT_MAX &&
                distance[u] + graph[u][v] < distance[v]) {
                distance[v] = distance[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    printSolution(distance, parent, numAreas, source, destination);
}

int main() {
    int numAreas;
    printf("Enter the number of areas in the city: ");
    scanf("%d", &numAreas);

    int graph[MAX_AREAS][MAX_AREAS];

    printf("Enter the adjacency matrix (enter 0 for areas not directly connected):\n");
    for (int i = 0; i < numAreas; i++) {
        for (int j = 0; j < numAreas; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int source, destination, choice;

    do {
        printf("\nMenu:\n");
        printf("1. Find Shortest Path\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the source area: ");
                scanf("%d", &source);
                printf("Enter the destination area: ");
                scanf("%d", &destination);
                dijkstra(graph, numAreas, source, destination);
                break;

            case 2:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 2);

    return 0;
}


// Output
/*
Enter the number of areas in the city: 5
Enter the adjacency matrix (enter 0 for areas not directly connected):
0 2 4 1 0
2 0 0 3 0
4 0 0 1 5
1 3 1 0 0
0 0 5 0 0

Menu:
1. Find Shortest Path
2. Exit
Enter your choice: 1
Enter the source area: 1
Enter the destination area: 4
Shortest Path from 1 to 4: 4
Path: 1 -> 3 -> 2 -> 4

Menu:
1. Find Shortest Path
2. Exit
Enter your choice: 2
Exiting program.

*/