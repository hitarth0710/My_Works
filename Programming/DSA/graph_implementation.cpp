#include<iostream>

// Function to add an edge between nodes
void add_edge(int** adj_matrix, int u, int v) {
    adj_matrix[u][v] = 1;
    adj_matrix[v][u] = 1;
}

// Function to print the adjacency matrix
void print_matrix(int** adj_matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << adj_matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int n;  // Number of nodes
    std::cout << "Enter the number of nodes: ";
    std::cin >> n;

    // Create adjacency matrix
    int** adj_matrix = new int*[n];
    for(int i = 0; i < n; i++) {
        adj_matrix[i] = new int[n];
        for(int j = 0; j < n; j++) {
            adj_matrix[i][j] = 0;
        }
    }

    int edges;  // Number of edges
    std::cout << "Enter the number of edges: ";
    std::cin >> edges;

    for(int i = 0; i < edges; i++) {
        int u, v;
        std::cout << "Enter the nodes for edge " << i+1 << ": ";
        std::cin >> u >> v;
        add_edge(adj_matrix, u, v);
    }

    print_matrix(adj_matrix, n);

    // Delete adjacency matrix
    for(int i = 0; i < n; i++) {
        delete [] adj_matrix[i];
    }
    delete [] adj_matrix;

    return 0;
}
