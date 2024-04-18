#include <stdio.h>
#include <stdlib.h>
#include "def.h"
#include "dfs.h"
#include "bfs.h"


Node_t* createNode(int v, int w) 
{
    Node_t* new_node = (Node_t*) malloc(sizeof(Node_t));
    new_node->vertex = v;
    new_node->weight = w;
    new_node->visited = false;
    new_node->next   = NULL;
    return new_node;
}


Graph_t* createGraph(int vertices) 
{
    Graph_t *graph       = (Graph_t*) malloc(sizeof(Graph_t));
    graph->adj_lists      = (Node_t**) malloc(vertices * sizeof(Node_t*));
    graph->num_vertices  = vertices;
    return graph;
}


void addEdge(Graph_t* graph, int src, int dest, int weight, bool directed) 
{
    Node_t* new_node = createNode(dest, weight);
    new_node->next = graph->adj_lists[src];
    graph->adj_lists[src] = new_node;

    if(!directed)
    {
        new_node = createNode(src, weight);
        new_node->next = graph->adj_lists[dest];
        graph->adj_lists[dest] = new_node;
    }
}

void printGraph(Graph_t* graph) 
{
    for(int v = 0; v < graph->num_vertices; v++) 
    {
        Node_t* temp = graph->adj_lists[v];

        printf("\nvertex %d :=== head", v);

        while (temp) 
        {
            printf("->(%d: w %d)", temp->vertex, temp->weight);
            temp = temp->next;
        }
        printf("->null");
    }
}

void clear_visited(Graph_t* graph)
{
    for(int v = 0; v < graph->num_vertices; v++) 
    {
        Node_t* temp = graph->adj_lists[v];
        while (temp) 
        {
            temp->visited = false;
            temp = temp->next;
        }
    }
}

int main() {
    int vertices = 10;
    Graph_t* graph = createGraph(vertices);

    addEdge(graph, 0, 1, 10,    DIRECTED);
    addEdge(graph, 0, 4, 8,     DIRECTED);
    addEdge(graph, 1, 2, 3,     DIRECTED);
    addEdge(graph, 1, 3, 100,   DIRECTED);
    addEdge(graph, 1, 4, 2,     DIRECTED);
    addEdge(graph, 2, 3, 7,     DIRECTED);
    addEdge(graph, 3, 4, 6,     DIRECTED);
    addEdge(graph, 7, 1, 10,    DIRECTED);
    addEdge(graph, 8, 4, 8,     DIRECTED);
    addEdge(graph, 9, 2, 3,     DIRECTED);
    addEdge(graph, 2, 3, 100,   DIRECTED);
    addEdge(graph, 5, 4, 2,     DIRECTED);
    addEdge(graph, 6, 3, 7,     DIRECTED);
    addEdge(graph, 7, 4, 6,     DIRECTED);
    // addEdge(graph, 0, 4, 6,     DIRECTED);
    // addEdge(graph, 1, 4, 6,     DIRECTED);
    // addEdge(graph, 2, 4, 6,     DIRECTED);
    // addEdge(graph, 3, 4, 6,     DIRECTED);
    // addEdge(graph, 4, 4, 6,     DIRECTED);
    // addEdge(graph, 5, 4, 6,     DIRECTED);
    // addEdge(graph, 6, 4, 6,     DIRECTED);
    // addEdge(graph, 7, 4, 6,     DIRECTED);
    // addEdge(graph, 8, 4, 6,     DIRECTED);
    // addEdge(graph, 9, 4, 6,     DIRECTED);


    printGraph(graph);
    printf("\n");

    int src = 0, des = 0;
    bool result = false;
    while(src != -1)
    {
        scanf("%d %d", &src, &des);

        result = BFS(graph, src, des);
        clear_visited(graph);
        printf("BFS ==> Vertex %d --> %d (%c)\n", src, des, result? 'O': 'X');

        result = DFS(graph, src, des);
        clear_visited(graph);
        printf("DFS ==> Vertex %d --> %d (%c)\n", src, des, result? 'O': 'X');
    }

    return 0;
}
