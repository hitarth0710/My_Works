#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Graph {
    int numVertices;
    Node** adjLists;
    int* visited;
} Graph;

Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*)calloc(1, sizeof(Graph));
    graph->numVertices = numVertices;
    graph->adjLists = (Node**)calloc(numVertices, sizeof(Node*));
    graph->visited = (int*)calloc(numVertices, sizeof(int));
    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = dest;
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}

void dfs(Graph* graph, int vertex) {
    if (graph->visited[vertex]) return;

    graph->visited[vertex] = 1;
    printf("%d ", vertex);

    for (Node* temp = graph->adjLists[vertex]; temp; temp = temp->next)
        dfs(graph, temp->data);
}

int main() {
    int numVertices, src;
    printf("Enter number of vertices: ");
    scanf("%d", &numVertices);

    Graph* graph = createGraph(numVertices);

    printf("Enter source vertex: ");
    scanf("%d", &src);

    int edges, srcVertex, destVertex;
    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        printf("Enter edge source and destination: ");
        scanf("%d %d", &srcVertex, &destVertex);
        addEdge(graph, srcVertex, destVertex);
    }

    printf("DFS traversal: ");
    dfs(graph, src);
    printf("\n");

    return 0;
}
