#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


PriorityQueue_t* createPriorityQueue() 
{
    PriorityQueue_t* pq = (PriorityQueue_t*) malloc(sizeof(PriorityQueue_t));
    if (!pq)
        exit(1);

    pq->size = 0;
    return pq;
}

static int isEmpty_pq(PriorityQueue_t* pq) 
{
    return pq->size == 0;
}

static int isFull_pq(PriorityQueue_t* pq) 
{
    return pq->size == QUEUE_MAX_SIZE;
}

void enqueue_pq(PriorityQueue_t* pq, int data, int priority) 
{
    if (isFull_pq(pq)) 
    {
        printf("Priority queue is full\n");
        return;
    }

    int i = pq->size;
    while(i > 0 && pq->array[i - 1].priority > priority) 
    {
        pq->array[i] = pq->array[i - 1];
        i--;
    }

    pq->array[i].data = data;
    pq->array[i].priority = priority;
    pq->size++;
}


int dequeue_pq(PriorityQueue_t* pq) 
{
    if(isEmpty_pq(pq)) 
    {
        printf("Priority queue is empty\n");
        exit(1);
    }

    int data = pq->array[0].data;
    for (int i = 1; i < pq->size; i++) 
    {
        pq->array[i - 1] = pq->array[i];
    }
    pq->size--;
    return data;
}


// Function to create a new queue
Queue_t* createQueue() 
{
    Queue_t* q = (Queue_t*) malloc(sizeof(Queue_t));
    if (q == NULL) 
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    q->front = -1;
    q->rear = -1;
    return q;
}

static int isEmpty_q(Queue_t* q) 
{
    return q->front == -1;
}

static int isFull_q(Queue_t* q) 
{
    return (q->rear + 1) % QUEUE_MAX_SIZE == q->front;
}

void enqueue_q(Queue_t* q, int data) 
{
    if (isFull_q(q)) {
        printf("Queue is full\n");
        return;
    }

    if (isEmpty_q(q)) 
    {
        q->front = 0;
        q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % QUEUE_MAX_SIZE;
    }
    q->array[q->rear] = data;
}

int dequeue_q(Queue_t* q) 
{
    if (isEmpty_q(q)) 
    {
        printf("Queue is empty\n");
        exit(1);
    }

    int data = q->array[q->front];
    if (q->front == q->rear) 
    {
        q->front = -1;
        q->rear = -1;
    } 
    else 
    {
        q->front = (q->front + 1) % QUEUE_MAX_SIZE;
    }
    return data;
}
