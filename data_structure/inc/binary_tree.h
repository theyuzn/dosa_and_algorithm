#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

/* 
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 * Structure Definition
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 */
typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
}TreeNode_t;


/* 
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 * APIs
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 */
TreeNode_t* createBTNode    (int data);
TreeNode_t* insertBT        (TreeNode_t *root, int data);
TreeNode_t* searchBT        (TreeNode_t *root, int data);
TreeNode_t* minValueBTNode  (TreeNode_t *node);
TreeNode_t* deleteBTNode    (TreeNode_t *root, int data);
TreeNode_t* arrayToBTree    (int *arr, int size);

void inorderTraversal   (TreeNode_t *root);
void preOrderTraversal  (TreeNode_t *root);
void postOrderTraversal (TreeNode_t *root);
void freeBTree          (TreeNode_t *root);



#endif // __BINARY_TREE_H__