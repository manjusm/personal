#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "graph.h"

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
            printf("Is there an edge from vertex %d to %d : ", i+1, j+1);
            scanf("%d", &node);
            if (node)
            {
                entry_t *entry = (entry_t *) malloc(sizeof(entry_t));
                entry->connectedVertex = node;
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
        printf("Vertex %d is connected to ", i+1);
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

int main()
{
    graph_t *graph = initGraph();
    printf("\nEnter the number of vertices : ");
    scanf("%d", &graph->v);
    createGraph(graph);
    showGraph(graph);
    deleteGraph(graph);
    return 0;
}
