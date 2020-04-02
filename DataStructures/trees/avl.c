#include <stdio.h>
#include <stdlib.h>

typedef struct node_s
{
    int             data;
    struct node_s   *left;
    struct node_s   *right;
    int             height; /* To get the balance of the subtree */
} avl_t;

int max(int a, int b)
{
   return  a > b ? a : b;
}

avl_t *newNode(int data)
{
    avl_t *newNode = (avl_t *)malloc(sizeof(avl_t));
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->data = data;
    newNode->height = 0;

    return (newNode);
}

int getBalance(avl_t *ptr)
{
    if (NULL == ptr) {
        return 0;
    }
    return (height(ptr->left) - height(ptr->right));
}

void leftRotate(avl_t **ptr)
{
    return;
}

void rightRotate(avl_t **ptr)
{
    return;
}

int height(avl_t *ptr)
{
    if (NULL == ptr){
        return 0;
    return ptr->height;
}

void insert(avl_t **ptr, int data)
{
    if (NULL == *ptr) {
        *ptr = newNode(data);
        return;
    }

    if (data > (*ptr)->data) {
        insert(&((*ptr)->right), data);
    } else if (data < (*ptr)->data) {
        insert(&((*ptr)->left), data);
    } else {
        printf("Duplicate keys are not allowed in AVL\n");
    }
    /* Update the height of this ancestor node */
    (*ptr)->height = 1 + max(height((*ptr)->left),
                             height((*ptr)->right));

    /* Check the balance factor of this node to check
     * whether this node has become unbalanced */
    int balance = getBalance(*ptr);

    /* If this node is unbalanced, there are 4
     * possible cases */

    /* Balance factor > 1 : left heavy */
    if (balance > 1) {
        /* left left case */
        if ((*ptr)->data > data) {
            rightRotate(**ptr);
            return;
        } else {
            /*left right case */
            leftRotate(**ptr);
            rightRotate(**ptr);
            return;
        }
    }

    /* Balance factor < -1 : right heavy */
    if (balance < -1) {
        /* right right case */
        if ((*ptr)->data < data) {
            leftRotate(**ptr);
            return;
        } else {
            /*right left case */
            rightRotate(**ptr);
            leftRotate(**ptr);
            return;
        }
    }
    return;
}

int height(avl_t *ptr)
{
    if (!ptr){
        return -1;
    }
    if (!ptr->left && !ptr->right) {
        return 0;
    }
    int lh = height(ptr->left);
    int rh = height(ptr->right);

    ptr->height = (1 + ((lh > rh) ? lh : rh));
    return (ptr->height);
}

void printInOrder(avl_t *root)
{
    if (root == NULL) {
        return;
    }
    printInOrder(root->left);
    printf("%d(%d)\t", root->data, root->height);
    printInOrder(root->right);
    return;
}

int main()
{
    avl_t *root = NULL;
    int tHeight = 0;

    insert(&root, 20);
    insert(&root, 30);
    insert(&root, 10);
    insert(&root, 13);
    insert(&root, 7);
    insert(&root, 25);
    insert(&root, 12);
    insert(&root, 4);
    insert(&root, 11);
    insert(&root, 35);
    insert(&root, 50);
    insert(&root, 2);
    //tHeight = height(root);
    printf("Height of the tree : %d\n", tHeight);
    printf("Print tree in InOrder:\n");
    printInOrder(root);
    printf("\n");
    return;
}
