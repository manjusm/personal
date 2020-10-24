#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "graph.h"

const int EMPTY=-1;
const int NOT_EMPTY=0;

/* Stack data structure operations. */

int isEmpty( node_t *head )
{
    if (NULL == head)
    {
        return EMPTY;
    }
    return NOT_EMPTY;
}

int pop(node_t **head)
{
    /* make call to pop() after checking whether stack is empty. */
    node_t *temp = *head;
    int ret = temp->data;
    (*head) = (*head)->next;
    free(temp);

    return ret;
}

void push(node_t **head, int vertex)
{
    node_t *node = (node_t *) malloc (sizeof(node_t));
    node->data = vertex;
    node->next = NULL;

    if(*head)
    {
        node->next = *head;
        *head = node;
    }
    else
    {
        *head = node;
    }
    return;
}

node_t *createStack( int vertex )
{
    node_t *stack = (node_t *) malloc (sizeof(node_t));
    if(stack)
    {
        stack->data = vertex;
        stack->next = NULL;
    }
    return stack;
}

/* Queue Data structure members */
/* isEmpty() can be used from stack. */

void enqueue(node_t **head, int vertex)
{
    node_t *node = (node_t *)malloc(sizeof(node_t));
    node->data = vertex;
    node->next = NULL;

    if (!(*head))
    {
        (*head) = node;
    }
    else
    {
        node_t *temp = (*head);
        node_t *prev;
        while(temp)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = node;
    }

    return;
}

int dequeue(node_t **head)
{
    int ret = (*head)->data;
    node_t *temp =  (*head);
    (*head) = (*head)->next;
    free(temp);

    return ret;
}

node_t *createQueue(int vertex)
{
    node_t *queue = (node_t *) malloc (sizeof(node_t));
    if(queue)
    {
        queue->data = vertex;
        queue->next = NULL;
    }
    return queue;
}

graph_t *initGraph()
{
    graph_t *graph = (graph_t *) malloc(sizeof(graph_t));
    if (graph)
    {
        graph->v = 0;
        graph->entryItem = NULL;
    } else
    {
        printf("malloc failed\n");
        exit(0);
    }
    return graph;
}

void createGraph(graph_t *graph)
{
    graph->entryItem = (entry_t **) malloc(sizeof(entry_t) * graph->v);
    memset(graph->entryItem, 0, sizeof(entry_t) * graph->v);
    int node = 0;

    for (int i = 0; i < graph->v; i++)
    {
        for (int j = 0; j < graph->v; j++)
        {
            printf("Is there an edge from vertex %d to %d : ", i, j);
            scanf("%d", &node);
            if (node)
            {
                entry_t *entry = (entry_t *) malloc(sizeof(entry_t));
                entry->connectedVertex = (j);
                entry->next = NULL;

                if(!graph->entryItem[i])
                {
                    graph->entryItem[i] = entry;
                }
                else
                {
                    entry_t *temp = graph->entryItem[i];
                    while(temp->next)
                    {
                        temp = temp->next;
                    }
                    temp->next = entry;
                }
            }
        }
    }
}

void showGraph(graph_t *graph)
{
    for (int i = 0; i < graph->v; i++)
    {
        printf("Vertex %d is connected to ", i);
        if (graph->entryItem[i])
        {
            entry_t *temp = graph->entryItem[i];
            while(temp)
            {
                printf("%d\t", temp->connectedVertex);
                temp = temp->next;
            }
        }
        printf("\n");
    }
    printf("\n");
}

void deleteGraph(graph_t *graph)
{
    if (!graph)
    {
        return;
    }
    for (int i = 0; i < graph->v; i++)
    {
        if (graph->entryItem[i])
        {
            entry_t *temp = graph->entryItem[i];
            entry_t *next;
            while(temp)
            {
                next = temp->next;
                free(temp);
                temp = NULL;
                temp = next;
            }
        }
    }
    free(graph->entryItem);
    graph->entryItem = NULL;
    free(graph);
    graph = NULL;

    return;
}

void DFS( graph_t *graph, int startingNode)
{
    /* uses stack */
    printf("Depth First Search - Using stack: ");
    int visited[graph->v];
    int vertex;
    for (int i = 0; i < graph->v; i++)
    {
        visited[i] = 0;
    }
    int toBeVistedVisited[graph->v];
    for (int i = 0; i < graph->v; i++)
    {
        toBeVistedVisited[i] = 0;
    }

    node_t *stack = createStack(startingNode);
    while(!isEmpty(stack))
    {
        vertex = pop(&stack);
        visited[vertex] = 1;
        printf("%d\t", vertex);
        entry_t *entry = graph->entryItem[vertex];
        while(entry)
        {
            if (!visited[entry->connectedVertex] && !toBeVistedVisited[entry->connectedVertex])
            {
                push(&stack, entry->connectedVertex);
                toBeVistedVisited[entry->connectedVertex] = 1;
            }
            entry = entry->next;
        }
    }
    printf("\n");
    return;
}

void BFS( graph_t *graph, int startingNode)
{
    /* Uses Queue */
    printf("Breadth First Search - Using queue: ");
    int visited[graph->v];
    int vertex;

    for (int i = 0; i < graph->v; i++)
    {
        visited[i] = 0;

    }
    int toBeVistedVisited[graph->v];
    for (int i = 0; i < graph->v; i++)
    {
        toBeVistedVisited[i] = 0;
    }
    node_t *queue = createQueue(startingNode);
    while(!isEmpty(queue))
    {
        vertex = dequeue(&queue);
        visited[vertex] = 1;
        printf("%d\t", vertex);
        entry_t *entry = graph->entryItem[vertex];
        while(entry)
        {
            if (!visited[entry->connectedVertex] && !toBeVistedVisited[entry->connectedVertex])
            {
                enqueue(&queue, entry->connectedVertex);
                toBeVistedVisited[entry->connectedVertex] = 1;
            }
            entry = entry->next;
        }
    }
    printf("\n");
    return;
}

int main()
{
    graph_t *graph = initGraph();
    printf("\nEnter the number of vertices : ");
    scanf("%d", &graph->v);
    createGraph(graph);
    showGraph(graph);
    DFS(graph, 0);
    BFS(graph, 0);
    deleteGraph(graph);
    return 0;
}
