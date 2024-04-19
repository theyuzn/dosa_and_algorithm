#include <stdlib.h>
#include "dfs.h"

#if 0

#include <stdbool.h>
// Recursive helper function for DFS
bool DFSHelper(struct Graph* graph, int src, int dest, int visited[]) {
    // Mark the current vertex as visited
    visited[src] = 1;

    // If the current vertex is the destination, return true
    if (src == dest)
        return true;

    // Recur for all the vertices adjacent to the current vertex
    struct Node* temp = graph->adj_lists[src];
    while (temp) {
        int adjVertex = temp->vertex;
        if (!visited[adjVertex] && DFSHelper(graph, adjVertex, dest, visited))
            return true;
        temp = temp->next;
    }

    // If destination vertex is not reached through any adjacent vertices, return false
    return false;
}

// Function to perform Depth First Search (DFS)
bool DFS(struct Graph* graph, int src, int dest) {
    // Create an array to keep track of visited vertices
    int visited[graph->num_vertices];
    for (int i = 0; i < graph->num_vertices; i++)
        visited[i] = 0;

    // Call the recursive helper function
    return DFSHelper(graph, src, dest, visited);
}


#else
// DFS traversal of the vertices reachable from v
bool DFS(Graph_t *graph, int src, int des) 
{
    bool ret = false;

    Node_t *current_node = graph->adj_lists[src];

    while(current_node) 
    {
        int adj_vertex = current_node->vertex;

        if(adj_vertex == des) return true;

        if (!current_node->visited)
        {
            current_node->visited = true;
            ret = DFS(graph, adj_vertex, des);
        }
        
        current_node = current_node->next;
    }

    return ret;
}

#endif