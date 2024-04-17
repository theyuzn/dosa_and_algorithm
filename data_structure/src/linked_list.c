#include <stdlib.h>
#include <stdio.h>

#include "linked_list.h"


Node_t* createNode(int data) 
{
    Node_t *newNode = (Node_t*) malloc(sizeof(Node_t));

    if (!newNode) exit(1);

    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(Node_t **head, int data) 
{
    Node_t *newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(Node_t **head, int data) 
{
    Node_t *newNode = createNode(data);

    if(!*head)
    {
        *head = newNode;
        return;
    }

    Node_t *temp = *head;
    while(temp->next) 
        temp = temp->next;

    temp->next = newNode;
}

void insertSorted(Node_t **head, int data)
{
    Node_t *new_node = createNode(data);

    if(!*head || data < (*head)->data)
    {
        new_node->next = *head;
        *head = new_node;
        return;
    }

    Node_t *current = *head;
    Node_t *next = current->next;
    while(next && next->data < data)
    {
        current = next;
        next = next->next;
    }

    new_node->next = next;
    current->next = new_node; 
}

Node_t* search(Node_t *head, int data) 
{
    Node_t* current = head;
    while(current) 
    {
        if (current->data == data) {
            return current;     // Return the node if found
        }
        current = current->next;
    }
    return NULL; // Return NULL if node not found
}

void deleteNode(Node_t **head, int data) 
{
    Node_t *current     = *head;
    Node_t *prev        = NULL;

    
    if (current != NULL && current->data == data) 
    {
        *head = current->next;
        free(current);
        return;
    }

    while(current && current->data != data) 
    {
        prev = current;
        current = current->next;
    }


    if (current) 
    {
        prev->next = current->next;
        free(current);
    }
}


Node_t* mergeSortedLists(Node_t *list1, Node_t *list2) {
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;

    Node_t *mergedList = NULL;
    if (list1->data <= list2->data) 
    {
        mergedList = list1;
        mergedList->next = mergeSortedLists(list1->next, list2);
    } 
    else 
    {
        mergedList = list2;
        mergedList->next = mergeSortedLists(list1, list2->next);
    }
    return mergedList;
}


Node_t* reverseLinkedList(Node_t *head) {
    Node_t *prev    = NULL;
    Node_t *current = head;
    Node_t *next    = NULL;

    while(current) 
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}


void printLinkedList(Node_t *head) 
{
    Node_t *current = head;
    if(current)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    while(current) 
    {
        printf("--> %d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to free the memory allocated for the linked list
void freeLinkedList(Node_t *head) 
{
    Node_t *temp;
    while (head != NULL) 
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}
