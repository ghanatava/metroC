#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 5 // Number of vertices in the graph

// Structure to represent a node in the adjacency list
struct Node {
    int dest;
    int weight;
    struct Node* next;
    struct Node* prev;
};

// Structure to represent the adjacency list
struct AdjList {
    struct Node *head;
};

// Structure to represent the graph
struct Graph {
    struct AdjList* array;
};

// Function to create a new node
struct Node* createNode(int dest, int weight) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to create a graph with V vertices
struct Graph* createGraph() {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));

    // Create an array of adjacency lists. Each array element represents a vertex.
    graph->array = (struct AdjList*)malloc(V * sizeof(struct AdjList));

    // Initialize each adjacency list as empty by making the head as NULL
    for (int i = 0; i < V; ++i)
        graph->array[i].head = NULL;

    return graph;
}

// Function to add an edge to a weighted graph
void addEdge(struct Graph* graph, int src, int dest, int weight) {
    // Add an edge from src to dest with the given weight
    struct Node* newNode = createNode(dest, weight);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
}

// Function to find the vertex with the minimum distance value, from the set of vertices not yet included in the shortest path tree
int minDistance(int dist[], int sptSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (sptSet[v] == 0 && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// Function to print the shortest path from source to destination using Dijkstra's algorithm
void printShortestPath(int parent[], int j) {
    if (parent[j] == -1)
        return;

    printShortestPath(parent, parent[j]);
    printf("%d -> ", j);
}

// Function to find shortest path from source to all other vertices using Dijkstra's algorithm
void dijkstra(struct Graph* graph, int src, int dest) {
    int dist[V];
    int sptSet[V];
    int parent[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = 0;
        parent[i] = -1;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = 1;

        struct Node* temp = graph->array[u].head;
        while (temp != NULL) {
            int v = temp->dest;
            int weight = temp->weight;
            if (!sptSet[v] && dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                parent[v] = u;
            }
            temp = temp->next;
        }
    }

    printf("Shortest path from node %d to node %d: ", src, dest);
    printf("%d -> ", src);
    printShortestPath(parent, dest);
    printf("\nShortest distance: %d\n", dist[dest]);
}

void printGraph(struct Graph* graph) {
    for (int v = 0; v < V; ++v) {
        struct Node* temp = graph->array[v].head;
        printf("Adjacency list of vertex %d\n", v);
        printf("head");
        while (temp) {
            printf(" -> %d(%d)", temp->dest, temp->weight);
            temp = temp->next;
        }
        printf("\n");
    }
}

void map() {
    // Create a graph
    struct Graph* graph = createGraph();

    // Add edges with weights
    addEdge(graph, 0, 1, 2);
    addEdge(graph, 0, 4, 5);
    addEdge(graph, 1, 2, 4);
    addEdge(graph, 1, 3, 1);
    addEdge(graph, 1, 4, 3);
    addEdge(graph, 2, 3, 7);
    addEdge(graph, 3, 4, 6);

    // int source = 0; // Source node
    // int destination = 2; // Destination node

    printGraph(graph);

}

void dijkstra_caller(int source,int destination){
       // Create a graph
    struct Graph* graph = createGraph();

    // Add edges with weights
    addEdge(graph, 0, 1, 2);
    addEdge(graph, 0, 4, 5);
    addEdge(graph, 1, 2, 4);
    addEdge(graph, 1, 3, 1);
    addEdge(graph, 1, 4, 3);
    addEdge(graph, 2, 3, 7);
    addEdge(graph, 3, 4, 6);


    dijkstra(graph,source,destination);

}
