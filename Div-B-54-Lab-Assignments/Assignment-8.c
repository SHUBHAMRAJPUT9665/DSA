#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    int numVertices;
    struct Node* adjList[MAX_VERTICES];
};

struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    for (int i = 0; i < vertices; i++) {
        graph->adjList[i] = NULL;
    }

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

void DFS(struct Graph* graph, int startVertex, int visited[]) {
    visited[startVertex] = 1;
    printf("%d ", startVertex);

    struct Node* temp = graph->adjList[startVertex];

    while (temp != NULL) {
        int adjVertex = temp->vertex;
        if (!visited[adjVertex]) {
            DFS(graph, adjVertex, visited);
        }
        temp = temp->next;
    }
}

void BFS(struct Graph* graph, int startVertex, int visited[]) {
    int queue[MAX_VERTICES];
    int front = -1, rear = -1;

    visited[startVertex] = 1;
    queue[++rear] = startVertex;

    while (front != rear) {
        int currentVertex = queue[++front];
        printf("%d ", currentVertex);

        struct Node* temp = graph->adjList[currentVertex];

        while (temp != NULL) {
            int adjVertex = temp->vertex;
            if (!visited[adjVertex]) {
                visited[adjVertex] = 1;
                queue[++rear] = adjVertex;
            }
            temp = temp->next;
        }
    }
}

int main() {
    struct Graph* graph = NULL;
    int choice, vertices, edges, src, dest;

    do {
        printf("\nMenu:\n");
        printf("1. Create Graph\n");
        printf("2. Perform DFS\n");
        printf("3. Perform BFS\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of vertices: ");
                scanf("%d", &vertices);
                graph = createGraph(vertices);

                printf("Enter the number of edges: ");
                scanf("%d", &edges);

                for (int i = 0; i < edges; i++) {
                    printf("Enter edge (source destination): ");
                    scanf("%d %d", &src, &dest);
                    addEdge(graph, src, dest);
                }
                break;

            case 2:
                if (graph == NULL) {
                    printf("Graph not created. Create a graph first.\n");
                } else {
                    int visited[MAX_VERTICES] = {0};
                    printf("Depth First Search (DFS): ");
                    DFS(graph, 0, visited);
                    printf("\n");
                }
                break;

            case 3:
                if (graph == NULL) {
                    printf("Graph not created. Create a graph first.\n");
                } else {
                    int visited[MAX_VERTICES] = {0};
                    printf("Breadth First Search (BFS): ");
                    BFS(graph, 0, visited);
                    printf("\n");
                }
                break;

            case 4:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 4);

    return 0;
}




/*
Enter your choice: 1

Enter the number of vertices: 4
Enter the number of edges: 5
Enter edge (source destination): 0 1
Enter edge (source destination): 0 2
Enter edge (source destination): 1 2
Enter edge (source destination): 1 3
Enter edge (source destination): 2 3
*/