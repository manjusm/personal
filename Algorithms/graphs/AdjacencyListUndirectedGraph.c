/* Adjacency list represenatation of an undirected graph */

#include <stdio.h>
#include <stdlib.h>

typedef struct listNode_t {
    int weight;
    int index;
    struct listNode_t *next;
} listNode;

typedef listNode* listPtr;

typedef struct graph_t {
    listPtr* dpHead;
    int count;
} graph;

typedef graph* graphPtr;


void graphInit(graphPtr pgraph, int nodeCount)
{
    listPtr* dpHead = (listPtr*) malloc(nodeCount * sizeof(listPtr));

    for (int i = 0; i <= nodeCount; i++){
        dpHead[i] = NULL;
    }
    pgraph->dpHead = dpHead;
    pgraph->count = nodeCount;

    return;
}


int graphInsert(graphPtr gPtr, int src, int dest, int weight)
{
    listPtr temp = (listPtr)malloc(sizeof(listNode));
    temp->weight = weight;
    temp->index = dest;

    temp->next = gPtr->dpHead[src];
    gPtr->dpHead[src] = temp;

    return 1;
}

void undirectedGraphInsert(graphPtr gPtr, int src, int dest, int weight)
{
    graphInsert(gPtr, src, dest, weight);
    graphInsert(gPtr, dest, src, weight);
    return;
}

void printGraph(graphPtr gPtr)
{
    int count = gPtr->count, index;
    for (index = 0; index < count; index++){
        listPtr head = gPtr->dpHead[index];
        printf("Adjacency list of index %d are [ ", index);
        while(head){
            printf("%d ", head->index);
            head = head->next;
        }
        printf("]\n");
    }
    return;
}

int main()
{
    int nodeCount = 4;
    graph G;

    graphInit(&G, nodeCount);
    undirectedGraphInsert(&G, 0, 1, 1);
    undirectedGraphInsert(&G, 0, 2, 1);
    undirectedGraphInsert(&G, 0, 3, 1);
    undirectedGraphInsert(&G, 1, 3, 1);
    undirectedGraphInsert(&G, 2, 3, 1);
   
    printGraph(&G);

    return 0;
}
