#include<iostream>
using namespace std;

struct node{
    int data;
    struct node* next;
};

struct graph{
    int vertex;
    struct node** adjlist;
};

struct node* createNode(int data){

    struct node* ptr = new node;
    ptr->data = data;
    ptr->next = NULL;
    return ptr;   
}

struct graph* createGraph(int vertex){

    struct graph* ptr = new graph;
    ptr->vertex = vertex;
    ptr->adjlist = new node*[vertex];
    for(int i=0;i<vertex;i++)
    {
        ptr->adjlist[i] = NULL;
    }
    return ptr;
}

void addEdge(struct graph* Graph, int src, int dest) {
    struct node* newNode = createNode(dest);
    newNode->next = Graph->adjlist[src];
    Graph->adjlist[src] = newNode;

    // Since it's an undirected graph, add an edge from dest to src also
    newNode = createNode(src);
    newNode->next = Graph->adjlist[dest];
    Graph->adjlist[dest] = newNode;
}

void printGraph(struct graph* Graph) {
    for (int v = 0; v < Graph->vertex; ++v) {
        struct node* temp = Graph->adjlist[v];
        cout << "\n Adjacency list of vertex " << v << "\n head ";
        while (temp) {
            cout << "-> " << temp->data;
            temp = temp->next;
        }
        cout << endl;
    }
}

int main() {
    int vertices = 5;
    struct graph* Graph = createGraph(vertices);
    addEdge(Graph, 0, 1);
    addEdge(Graph, 0, 4);
    addEdge(Graph, 1, 2);
    addEdge(Graph, 1, 3);
    addEdge(Graph, 1, 4);
    addEdge(Graph, 2, 3);
    addEdge(Graph, 3, 4);

    printGraph(Graph);

    return 0;
}