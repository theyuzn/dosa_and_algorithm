#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"
#include "binary_tree.h"
#include "queue.h"
#include "heap.h"
#include "stack.h"


static inline void add_element1(Node_t **list)
{
    insertAtEnd(list, 1);
    insertAtEnd(list, 3);
    insertAtEnd(list, 5);
    insertAtEnd(list, 8);
    insertSorted(list, 2);
    insertSorted(list, 9);
    insertSorted(list, 3);
    insertSorted(list, 7);
    insertAtBeginning(list, 3);
    insertAtBeginning(list, 6);
    insertAtBeginning(list, 5);
    insertAtBeginning(list, 9);
}

static inline void print_divider(void)
{
    printf("\n---------------------------------------------------------\n");
    printf("---------------------------------------------------------\n");
    printf("---------------------------------------------------------\n");
}

static inline void add_element2(Node_t **list)
{
    insertAtEnd(list, 1);
    insertAtEnd(list, 3);
    insertSorted(list, 8);
    insertSorted(list, 7);
    insertAtBeginning(list, 4);
    insertAtBeginning(list, 2);
}

/*
void heartDraw()
{
    int i, j, n = 6; // Adjust n to change the size of the heart 
 
    for (i = n / 2; i <= n; i += 2) { 
        for (j = 1; j < n - i; j += 2) { 
            printf(" "); 
        } 
 
        for (j = 1; j <= i; j++) { 
            printf("*"); 
        } 
 
        for (j = 1; j <= n - i; j++) { 
            printf(" "); 
        } 
 
        for (j = 1; j <= i; j++) { 
            printf("*"); 
        } 
 
        printf("\n"); 
    } 
 
    for (i = n; i >= 1; i--) { 
        for (j = i; j < n; j++) { 
            printf(" "); 
        } 
 
        for (j = 1; j <= (i * 2) - 1; j++) { 
            printf("*"); 
        } 
 
        printf("\n"); 
    } 
 } 
*/

int main() {
    /*
     * -----------------------------------------------
     * Linked List
     * -----------------------------------------------
     */
    print_divider();
    printf("[ Linked List ]\n\n");
    Node_t *list1 = NULL;
    Node_t *list2 = NULL;

    add_element1(&list1);
    add_element2(&list2);

    printf("List 1: ");
    printLinkedList(list1);
    printf("List 2: ");
    printLinkedList(list2);

    Node_t *mergedList = mergeSortedLists(list1, list2);
    printf("Merged List: ");
    printLinkedList(mergedList);

    // Reverse the merged list
    Node_t *reversedList = reverseLinkedList(mergedList);
    printf("Reversed List: ");
    printLinkedList(reversedList);

    // Search for a node with data 3 in the reversed list
    Node_t *searchResult = search(reversedList, 3);
    if (searchResult != NULL) {
        printf("Node with data 3 found in the reversed list\n");
    } else {
        printf("Node with data 3 not found in the reversed list\n");
    }


    // Delete a node with data 5 from the reversed list
    deleteNode(&reversedList, 5);
    printf("Reversed List after deleting node with data 5: ");
    printLinkedList(reversedList);

    freeLinkedList(reversedList);


    /*
     * -----------------------------------------------
     * Binary Tree
     * -----------------------------------------------
     */
    print_divider();
    printf("[ Binary Tree ]\n\n");
    int arr[] = {5, 3, 7, 1, 4, 6, 8, 10, 14, 12, 20, 18, 16, 100, 50};
    TreeNode_t *root = arrayToBTree(arr, sizeof(arr) / sizeof(arr[0]));

    // Print the inorder traversal of the binary search tree
    printf("Inorder traversal of the BST: ");
    inorderTraversal(root);
    printf("\n");

    //////////////////////////////////////////////////////////
    // Search
    /////////////////////////////////////////////////////////
    int searchKey = 60;
    TreeNode_t *searchResultBT = searchBT(root, searchKey);
    if (searchResultBT != NULL) {
        printf("Node with data %d found in the BST\n", searchKey);
    } else {
        printf("Node with data %d not found in the BST\n", searchKey);
    }

    searchKey = 30;
    searchResultBT = searchBT(root, searchKey);
    if (searchResultBT != NULL) {
        printf("Node with data %d found in the BST\n", searchKey);
    } else {
        printf("Node with data %d not found in the BST\n", searchKey);
    }

    searchKey = 12;
    searchResultBT = searchBT(root, searchKey);
    if (searchResultBT != NULL) {
        printf("Node with data %d found in the BST\n", searchKey);
    } else {
        printf("Node with data %d not found in the BST\n", searchKey);
    }

    searchKey = 100;
    searchResultBT = searchBT(root, searchKey);
    if (searchResultBT != NULL) {
        printf("Node with data %d found in the BST\n", searchKey);
    } else {
        printf("Node with data %d not found in the BST\n", searchKey);
    }

    //////////////////////////////////////////////////////////
    // Delete
    /////////////////////////////////////////////////////////    
    int deleteKey = 30;
    root = deleteBTNode(root, deleteKey);
    printf("Inorder traversal after deleting node with data %d: ", deleteKey);
    inorderTraversal(root);
    printf("\n");

    deleteKey = 12;
    root = deleteBTNode(root, deleteKey);
    printf("Inorder traversal after deleting node with data %d: ", deleteKey);
    inorderTraversal(root);
    printf("\n");

    deleteKey = 1;
    root = deleteBTNode(root, deleteKey);
    printf("Inorder traversal after deleting node with data %d: ", deleteKey);
    inorderTraversal(root);
    printf("\n");

    deleteKey = 3;
    root = deleteBTNode(root, deleteKey);
    printf("Inorder traversal after deleting node with data %d: ", deleteKey);
    inorderTraversal(root);
    printf("\n");

    // Free memory allocated for the binary search tree
    freeBTree(root);


    /*
     * -----------------------------------------------
     * (Priority) Queue / Heap / Stack / 
     * -----------------------------------------------
     */
    print_divider();
    printf("[ Queue ]\n\n");
    Queue_t* q = createQueue();
    enqueue_q(q, 10);
    enqueue_q(q, 20);
    enqueue_q(q, 30);
    printf("Dequeued element: %d\n", dequeue_q(q));
    printf("Dequeued element: %d\n", dequeue_q(q));
    printf("Dequeued element: %d\n", dequeue_q(q));
    free(q);

    print_divider();
    printf("[ Priority Queue ]\n\n");
    PriorityQueue_t* pq = createPriorityQueue();
    enqueue_pq(pq, 10, 2);
    enqueue_pq(pq, 20, 1);
    enqueue_pq(pq, 30, 3);
    printf("Dequeued element: %d\n", dequeue_pq(pq));
    printf("Dequeued element: %d\n", dequeue_pq(pq));
    printf("Dequeued element: %d\n", dequeue_pq(pq));
    free(pq);


    print_divider();
    printf("[ Heap ]\n\n");
    // arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    buildHeap(arr, n);
    printf("Max heap: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    print_divider();
    printf("[ Stack ]\n\n");
    Stack_t* stack = createStack();
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    printf("Popped element: %d\n", pop(stack));
    printf("Popped element: %d\n", pop(stack));
    printf("Popped element: %d\n", pop(stack));
    free(stack);


    /*
     * -----------------------------------------------
     * Love
     * -----------------------------------------------
     */
    /*
    print_divider();
    printf("[ Gloria ]\n\n");
    heartDraw();
    */
    return 0;
}
