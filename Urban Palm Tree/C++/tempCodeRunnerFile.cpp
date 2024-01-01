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
  Graph* graph = (Graph*)malloc(sizeof(Graph));
  graph->numVertices = numVertices;
  graph->adjLists = (Node**)malloc(numVertices * sizeof(Node*));
  graph->visited = (int*)malloc(numVertices * sizeof(int));

  for (int i = 0; i < numVertices; i++) {
    graph->adjLists[i] = NULL;
    graph->visited[i] = 0;
  }
  return graph;
}

void addEdge(Graph* graph, int src, int dest) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = dest;
  newNode->next = graph->adjLists[src];
  graph->adjLists[src] = newNode;
}

void bfs(Graph* graph, int vertex) {
  int queue[100];
  int front = 0, rear = 0;

  graph->visited[vertex] = 1;
  queue[rear++] = vertex;

  while (front != rear) {
    vertex = queue[front++];
    printf("%d ", vertex);

    Node* temp = graph->adjLists[vertex];
    while (temp) {
      if (!graph->visited[temp->data]) {
        graph->visited[temp->data] = 1;
        queue[rear++] = temp->data;
      }
      temp = temp->next;
    }
  }
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

  printf("BFS traversal: ");
  bfs(graph, src);

  printf("\n");

  return 0;
}