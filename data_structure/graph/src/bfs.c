#include <stdlib.h>
#include <stdbool.h>
#include "bfs.h"
#include <stdio.h>

bool BFS(Graph_t *graph, int src, int des) 
{
    if(!graph->adj_lists[src]) return false;

    int queue[graph->num_vertices];
    int front = -1, rear = -1;

    graph->adj_lists[src]->visited = true;
    queue[++rear] = src;        // enqueue

    while(front < rear) 
    {
        src = queue[++front];   //dequeue
        Node_t *temp = graph->adj_lists[src];

        while(temp) 
        {
            int adj_vertex = temp->vertex;

            if(adj_vertex == des) return true;
            else if(!graph->adj_lists[adj_vertex]) ;
            else if(!graph->adj_lists[adj_vertex]->visited) 
            {
                graph->adj_lists[adj_vertex]->visited = true;
                queue[++rear] = adj_vertex; // enqueue
            }
            temp = temp->next;
        }
    }
    return false;
}