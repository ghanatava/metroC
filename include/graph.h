
struct Node {
    int dest;
    int weight;
    struct Node* next;
};

struct AdjList {
    struct Node *head;
};

struct Graph {
    int V;
    struct AdjList* array;
};

struct Graph* createGraph();
struct Node* createNode(int dest, int weight);
void addEdge(struct Graph* graph, int src, int dest, int weight);
void printGraph(struct Graph* graph);
void dijkstra(struct Graph* graph, int src, int dest);
int minDistance(int dist[], int sptSet[]);
void printShortestPath(int parent[], int j);
void map();
void dijkstra_caller(int source,int destination);

