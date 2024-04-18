#ifndef __QUEUE_H__
#define __QUEUE_H__


#define QUEUE_MAX_SIZE 100

typedef struct PQ_Node 
{
    int data;
    int priority;
}PQ_Node_t;

typedef struct PriorityQueue 
{
    PQ_Node_t array[QUEUE_MAX_SIZE];
    int size;
}PriorityQueue_t;

typedef struct Queue 
{
    int array[QUEUE_MAX_SIZE];
    int front;
    int rear;
}Queue_t;


#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


PriorityQueue_t* createPriorityQueue();
void enqueue_pq(PriorityQueue_t* pq, int data, int priority);
int dequeue_pq(PriorityQueue_t* pq);

Queue_t* createQueue();
void enqueue_q(Queue_t* q, int data);
int dequeue_q(Queue_t* q);

#endif // __QUEUE_H__