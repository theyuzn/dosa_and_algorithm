#include <stdlib.h>
#include <stdio.h>
#include "binary_tree.h"

TreeNode_t* createBTNode(int data) 
{
    TreeNode_t *newNode = (TreeNode_t*) malloc(sizeof(TreeNode_t));
    if (newNode == NULL) 
        exit(1);

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

TreeNode_t* insertBT(TreeNode_t *root, int data) 
{
    if(root == NULL) return createBTNode(data);

    if(data < root->data)       root->left = insertBT(root->left, data);
    else if(data > root->data)  root->right = insertBT(root->right, data);
    #if 0 // (optional handle the duplicate node)
    else root->left = insertBT(root->left, data);
    #endif
    return root;
}

TreeNode_t* arrayToBTree(int *arr, int size) 
{
    TreeNode_t *root = NULL;
    for (int i = 0; i < size; i++) 
        root = insertBT(root, arr[i]);

    return root;
}

TreeNode_t* searchBT(TreeNode_t *root, int data) 
{
    if (root == NULL || root->data == data)
        return root;
    
    if (data < root->data)  
        return searchBT(root->left, data);
    else            
        return searchBT(root->right, data);
}

TreeNode_t* minValueBTNode(TreeNode_t *node) 
{
    if(!node) return node;

    TreeNode_t *current = node;

    while (current->left != NULL) 
        current = current->left;
    
    return current;
}

TreeNode_t* deleteBTNode(TreeNode_t *root, int data) 
{
    if (!root) return root; 
    
    if (data < root->data) 
        root->left = deleteBTNode(root->left, data);

    else if (data > root->data) 
        root->right = deleteBTNode(root->right, data);

    else // data == root->data
    {
        if(!root->left) 
        {
            TreeNode_t* temp = root->right;
            free(root);
            return temp;
        } 
        else if(!root->right) 
        {
            TreeNode_t* temp = root->left;
            free(root);
            return temp;
        }

        TreeNode_t *temp = minValueBTNode(root->right);
        root->data = temp->data;
        root->right = deleteBTNode(root->right, temp->data);
    }
    return root;
}

void inorderTraversal(TreeNode_t *root) 
{
    if(!root) return;
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

void preOrderTraversal(TreeNode_t *root) 
{
    if (!root) return;
    printf("%d ", root->data);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void postOrderTraversal(TreeNode_t *root) 
{
    if (!root) return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    printf("%d ", root->data);
}

void freeBTree(TreeNode_t *root) 
{
    if(!root) return;
    freeBTree(root->left);
    freeBTree(root->right);
    free(root);
}
