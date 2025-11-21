#include <stdio.h> 
#include <stdlib.h> 
 
#define MAX_VERTICES 100 
 
// Structure to represent a node in the adjacency list 
struct Node { 
    int vertex; 
    struct Node* next; 
}; 
 
// Structure to represent the graph 
struct Graph { 
    struct Node* adjList[MAX_VERTICES]; 
    int visited[MAX_VERTICES]; 
}; 
 
// Function to create a new node 
struct Node* createNode(int v) { 
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
    newNode->vertex = v; 
    newNode->next = NULL; 
    return newNode; 
} 
 
// Function to create a graph 
struct Graph* createGraph() { 
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph)); 
    for (int i = 0; i < MAX_VERTICES; i++) { 
        graph->adjList[i] = NULL; 
        graph->visited[i] = 0; 
    } 
    return graph; 
} 
 
// Function to add an edge between src and dest 
void addEdge(struct Graph* graph, int src, int dest) { 
    // Add edge from src to dest 
    struct Node* newNode = createNode(dest); 
    newNode->next = graph->adjList[src]; 
    graph->adjList[src] = newNode; 
 
    // Since the graph is undirected, add edge from dest to src as well 
    newNode = createNode(src); 
    newNode->next = graph->adjList[dest]; 
    graph->adjList[dest] = newNode; 
} 
 
// Depth First Search (DFS) function 
void DFS(struct Graph* graph, int vertex) { 
    // Mark the current vertex as visited 
 graph->visited[vertex] = 1; 
    printf("%d ", vertex); 
 
    // Recursively traverse all the adjacent vertices 
    struct Node* temp = graph->adjList[vertex]; 
    while (temp != NULL) { 
        int adjVertex = temp->vertex; 
        if (graph->visited[adjVertex] == 0) { 
            DFS(graph, adjVertex); 
        } 
        temp = temp->next; 
    } 
} 
 
int main() { 
    int numVertices, numEdges; 
 
    // Input the number of vertices 
    printf("Enter the number of vertices: "); 
    scanf("%d", &numVertices); 
 
    struct Graph* graph = createGraph(); 
 
    // Input the number of edges 
    printf("Enter the number of edges: "); 
    scanf("%d", &numEdges); 
 
    // Input the edges 
    printf("Enter the edges (source destination):\n"); 
    for (int i = 0; i < numEdges; ++i) { 
        int src, dest; 
        scanf("%d %d", &src, &dest); 
        addEdge(graph, src, dest); 
    } 
 
    int startVertex; 
    // Input the starting vertex for DFS 
    printf("Enter the starting vertex for DFS: "); 
    scanf("%d", &startVertex); 
 
    // Perform DFS traversal 
    printf("Depth First Traversal starting from vertex %d: ", startVertex); 
    DFS(graph, startVertex); 
    printf("\n"); 
 
    return 0; 
}
