#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

// Function to create a new stack
Stack_t* createStack() 
{
    Stack_t* stack = (Stack_t*) malloc(sizeof(Stack_t));
    if(stack == NULL) 
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    stack->top = -1;
    return stack;
}

static int isEmpty_stack(Stack_t* stack) 
{
    return stack->top == -1;
}

static int isFull_stack(Stack_t* stack) 
{
    return stack->top == STACK_MAX_SIZE - 1;
}

void push(Stack_t* stack, int data) 
{
    if(isFull_stack(stack)) 
    {
        printf("Stack overflow\n");
        return;
    }
    stack->array[++stack->top] = data;
}

int pop(Stack_t* stack) 
{
    if(isEmpty_stack(stack)) 
    {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack->array[stack->top--];
}
