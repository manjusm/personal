#include <stdio.h>
#include <stdlib.h>

#include "dll.h"


void printDll(node_t *dll)
{
    while(dll){
        printf("%d\n", dll->data);
        dll = dll->next;
    }
    return;
}

void addNode(node_t **dll, int data)
{
    node_t *temp = (node_t *)malloc(sizeof(node_t));
    temp->data = data;
    temp->prev = NULL;
    temp->next = NULL;

    if (*dll == NULL) {
        *dll = temp;
        return;
    }

    temp->next = *dll;
    (*dll)->prev = temp;
    *dll = temp;

    return;
}

int main()
{
    node_t *dll = NULL;
    addNode(&dll, 10);
    addNode(&dll, 20);
    addNode(&dll, 30);
    printDll(dll);
    return;
}
