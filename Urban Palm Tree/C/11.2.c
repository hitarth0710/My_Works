#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
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

void bfs(Graph* graph, int vertex) {
    int queue[100], front = 0, rear = 0;
    graph->visited[vertex] = 1;
    queue[rear++] = vertex;

    while (front != rear) {
        vertex = queue[front++];
        printf("%d ", vertex);

        for (Node* temp = graph->adjLists[vertex]; temp; temp = temp->next)
            if (!graph->visited[temp->data])
                graph->visited[temp->data] = 1, queue[rear++] = temp->data;
    }
}

int main() {
    int numVertices, src;
    printf("Enter number of vertices: ");
    scanf("%d", &numVertices);

    Graph* graph = createGraph(numVertices);

    printf("Enter source vertex: ");
    scanf("%d", &src);

    for (int i = 0, edges, srcVertex, destVertex; i < (printf("Enter number of edges: ") && scanf("%d", &edges));)
        for (; i < edges && (printf("Enter edge source and destination: ") && scanf("%d %d", &srcVertex, &destVertex));)
            addEdge(graph, srcVertex, destVertex), ++i;

    printf("BFS traversal: ");
    bfs(graph, src);
    printf("\n");

    return 0;
}
