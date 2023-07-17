#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Queue structure
typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
} Queue;

// Function to initialize the queue
void initializeQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is empty
int isQueueEmpty(Queue *q) {
    return (q->front == -1 && q->rear == -1);
}

// Function to check if the queue is full
int isQueueFull(Queue *q) {
    return (q->rear == MAX_SIZE - 1);
}

// Function to add an element to the queue
void enqueue(Queue *q, int vertex) {
    if (isQueueFull(q)) {
        printf("Queue is full. Cannot enqueue more elements.\n");
        return;
    } else if (isQueueEmpty(q)) {
        q->front = 0;
        q->rear = 0;
    } else {
        q->rear++;
    }
    q->data[q->rear] = vertex;
}

// Function to remove an element from the queue
int dequeue(Queue *q) {
    int vertex;
    if (isQueueEmpty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    } else if (q->front == q->rear) {
        vertex = q->data[q->front];
        q->front = -1;
        q->rear = -1;
    } else {
        vertex = q->data[q->front];
        q->front++;
    }
    return vertex;
}

// Function to perform breadth-first search
void breadthFirstSearch(int **graph, int numVertices, int startVertex, int endVertex) {
    Queue q;
    int visited[MAX_SIZE] = {0};
    int parent[MAX_SIZE];
    initializeQueue(&q);

    enqueue(&q, startVertex);
    visited[startVertex] = 1;
    parent[startVertex] = -1;

    while (!isQueueEmpty(&q)) {
        int currentVertex = dequeue(&q);
        printf("%d ", currentVertex);

        if (currentVertex == endVertex) {
            // Shortest path found, trace back the parent vertices
            printf("\nShortest Path: ");
            int v = currentVertex;
            while (v != -1) {
                printf("%d ", v);
                v = parent[v];
            }
            return;
        }

        // Visit all adjacent vertices
        for (int i = 0; i < numVertices; i++) {
            if (graph[currentVertex][i] == 1 && visited[i] == 0) {
                enqueue(&q, i);
                visited[i] = 1;
                parent[i] = currentVertex;
            }
        }
    }

    printf("\nNo path found between the given vertices.\n");
}

int main() {
    int numVertices, startVertex, endVertex;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &numVertices);

    // Create adjacency matrix for the graph
    int **graph = (int **)malloc(numVertices * sizeof(int *));
    for (int i = 0; i < numVertices; i++) {
        graph[i] = (int *)malloc(numVertices * sizeof(int));
    }

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &startVertex);

    printf("Enter the ending vertex: ");
    scanf("%d", &endVertex);

    printf("BFS traversal: ");
    breadthFirstSearch(graph, numVertices, startVertex, endVertex);

    // Free dynamically allocated memory
    for (int i = 0; i < numVertices; i++) {
        free(graph[i]);
    }
    free(graph);

    return 0;
}
