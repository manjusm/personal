#include <stdio.h>
#include "graph.h"
#include <stdlib.h>
#include <string.h>

graph_t *initGraph()
{
    graph_t *graph = (graph_t *)malloc(sizeof(graph_t));
    if (graph)
    {
        graph->v = 0;
        graph->e = 0;
        graph->adjMatrix = NULL;
    }
    else
    {
        printf("Malloc failed.\n");
        exit(0);
    }
    return graph;
}

void createGraph(graph_t *graph)
{
    int size = (graph->v * graph->v);
    graph->adjMatrix = (int *)malloc(size * sizeof(int));
    memset(graph->adjMatrix, 0, size);
    int *ptr = graph->adjMatrix;

    for (int i = 0; i < graph->v; i++)
    {
        for (int j = 0; j < graph->v; j++)
        {
            printf("Is there an edge from node %d to %d :  ", i, j);
            scanf("%d", (ptr + (graph->v * i) + j));
        }
    }
    printf("\n");

    return;
}

void showGraph(graph_t *graph)
{
    int *ptr = graph->adjMatrix;

    for (int i = 0; i < graph->v; i++)
    {
        for (int j = 0; j < graph->v; j++)
        {
            printf("%d\t", *(ptr + (graph->v * i) + j));
        }
        printf("\n");
    }

    printf("\n");
    return;
}

void deleteGraph(graph_t *graph)
{
    if (graph)
    {
        if (graph->adjMatrix)
        {
            free(graph->adjMatrix);
            graph->adjMatrix = NULL;
        }
        free(graph);
        graph = NULL;
    }
    return;
}

int main()
{
    graph_t *graph = initGraph();
    printf("\n Enter number of Vertices: ");
    scanf("%d", &graph->v);
    createGraph(graph);
    showGraph(graph);
    deleteGraph(graph);
}
