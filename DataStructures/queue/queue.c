#include <stdio.h>
#include <stdlib.h>


typedef struct node_s
{
    int data;
    struct node_s *next;
}node_t;

void printQueue(node_t *front)
{
    while (front)
    {
        printf("%d\t", front->data);
        front = front->next;
    }
    printf("\n");
    return;
}

void enqueue(node_t **front, node_t **rear, int data)
{
    node_t *temp = (node_t *)malloc(sizeof(node_t));
    temp->data = data;
    temp->next = NULL;

    if (*front == NULL && *rear == NULL)
    {
        *front = *rear = temp;
        return;
    }

    (*rear)->next = temp;
    *rear = temp;

    return;
}

void dequeue(node_t **front, node_t **rear, int *value)
{
    struct node_t *temp = (*front);
    if (NULL == temp) return;
    if (*front == *rear){
        *value = (*front)->data;
        *front = *rear = NULL;    
    } else {
        *value = (*front)->data;
        (*front) = (*front)->next;
    }
    free(temp);
    return;
}

int main()
{
    node_t *front = NULL;
    node_t *rear = NULL;

    int value;
   
    enqueue(&front, &rear, 10);
    enqueue(&front, &rear, 20);
    enqueue(&front, &rear, 30);
    enqueue(&front, &rear, 40);
    enqueue(&front, &rear, 50);
    printQueue(front);
    dequeue(&front, &rear, &value);
    printf("Deque : %d\n", value);
    dequeue(&front, &rear, &value);
    printf("Deque : %d\n", value);
    dequeue(&front, &rear, &value);
    printf("Deque : %d\n", value);
    printQueue(front);
    return;
}
