#include<stdio.h>
#include <stdlib.h>

typedef struct node_s
{
    int data;
    struct node_s *left;
    struct node_s *right;
} node_t;

int findHeight(node_t *ptr);

void isBST(node_t *rootptr)
{

    return;
}

node_t * newNode(int data)
{
    node_t *newNode = (node_t *)malloc(sizeof(node_t));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

void insert(node_t **rootPtr, int data)
{
    if (*rootPtr == NULL){
        *rootPtr = newNode(data);
        return;
    } else {
        if (data <= (*rootPtr)->data){
            insert(&((*rootPtr)->left), data);
        } else {
            insert(&((*rootPtr)->right), data);
        }
    }
    return;
}

void preorder(node_t *ptr)
{
    if (NULL == ptr) {
        return;
    }
    printf("%d\t", ptr->data);
    preorder(ptr->left);
    preorder(ptr->right);
    return;
}
void postorder(node_t *ptr)
{
    if (NULL == ptr) {
        return;
    }
    postorder(ptr->left);
    postorder(ptr->right);
    printf("%d\t", ptr->data);
    return;
}
void inorder(node_t *ptr)
{
    if (NULL == ptr) {
        return;
    }
    inorder(ptr->left);
    printf("%d\t", ptr->data);
    inorder(ptr->right);
    return;
}

void printGivenLevel(node_t *ptr, int level)
{
    if (level == 1)
    {
        printf("%d\t", ptr->data);
        return;
    }
    else
    {
        printGivenLevel(ptr->left, level-1);
        printGivenLevel(ptr->right, level-1);
    }
    return;
}

void printLevelOrder(node_t *ptr)
{
    int height = findHeight(ptr);
    int i;

    printf("Level order : ");
    for (i = 1; i <= height; i++)
    {
        printGivenLevel(ptr, i);
    }
    printf("\n");
    return;
}
int findmax(node_t *ptr)
{
    if (NULL == ptr){
        printf("Tree is empty\n");
        return -1;
    }
    if (NULL == ptr->right){
        return ptr->data;
    }
    findmax(ptr->right);
}

int findmin(node_t *ptr)
{
    if (NULL == ptr){
        printf("Tree is empty\n");
        return -1;
    }
    if (NULL == ptr->left){
        return ptr->data;
    }
    findmin(ptr->left);
}

int findHeight(node_t *ptr)
{
    if (NULL == ptr){
        return 0;
    }
    int lheight = findHeight(ptr->left);
    int rheight = findHeight(ptr->right);

    return ( (lheight > rheight)? (lheight+1):(rheight+1));
}

void deleteTree(node_t *ptr)
{
    if (!ptr)
    {
        return;
    }
    deleteTree(ptr->left);
    deleteTree(ptr->right);
    free(ptr);
    return;
}

int main ()
{
    node_t *rootPtr = NULL;
    int min, max, height;

    /* Insert data into tree */
    insert(&rootPtr, 15);
    insert(&rootPtr, 10);
    insert(&rootPtr, 20);
    insert(&rootPtr, 8);
    insert(&rootPtr, 12);
    insert(&rootPtr, 17);
    insert(&rootPtr, 25);
    printf("inorder : \n");
    inorder(rootPtr);
    printf("\n");
    printf("preorder : \n");
    preorder(rootPtr);
    printf("\n");
    printf("postorder : \n");
    postorder(rootPtr);
    printf("\n");
    min = findmin(rootPtr);
    printf("min : %d\n", min);
    max = findmax(rootPtr);
    printf("max : %d\n", max);
    height = findHeight(rootPtr);
    printf("height : %d\n", height);
    printLevelOrder(rootPtr);
    deleteTree(rootPtr);
    rootPtr = NULL;
    return 0;
}
