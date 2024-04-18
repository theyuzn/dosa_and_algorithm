#ifndef __DEF_H__
#define __DEF_H__

/*
 * The struct definition here
 */

/* 
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 * include function
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 */
#include <stdbool.h>


/* 
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 * Define
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 */
#define DIRECTED    true
#define UNDIRECTED  false


/* 
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 * Structure definition
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 */
typedef struct Node 
{
    int vertex;
    bool visited;
    int weight;
    struct Node* next;
} Node_t;


typedef struct Graph 
{
    int num_vertices;
    Node_t **adj_lists;
} Graph_t;

#endif // __DEF_H__