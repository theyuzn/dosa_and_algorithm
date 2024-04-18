#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

/* 
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 * Structure Definition
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 */
typedef struct Node {
    int data;
    struct Node* next;
}Node_t;


/* 
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 * APIs
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 */

Node_t* createNode          (int data);
void    insertAtBeginning   (Node_t **head, int data); // Use double pointer
void    insertAtEnd         (Node_t **head, int data); // Use double pointer
void    insertSorted        (Node_t **head, int data); // Use double pointer
void    deleteNode          (Node_t **head, int data); // Use double pointer
Node_t* search              (Node_t *head, int data);
Node_t* mergeSortedLists    (Node_t *list1, Node_t *list2);
Node_t* reverseLinkedList   (Node_t *head);
void    printLinkedList     (Node_t *head);
void    freeLinkedList      (Node_t *head);



#endif // __LINKED_LIST_H__