/* push operation */
#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

/* Stack using lists */
typedef struct node_s
{
        float value;
            struct node_s *next;
}sll_t;

sll_t *stack = NULL;

void push(int value){

    if (NULL == stack){
        stack = (sll_t *)malloc(sizeof(sll_t));
        if (NULL == stack){
            exit(0);
        }
        stack->value = value;
        stack->next = NULL;
        return;
    }

    sll_t *temp = (sll_t *)malloc(sizeof(sll_t));
    temp->value = value;
    temp->next = stack;
    stack = temp;

    return;
}

int pop(void){
    if (NULL == stack){
        printf("stack is empty \n");
        return;
    }
    int tos = stack->value;
    sll_t *temp = stack;
    stack = stack->next;
    free(temp);
    return tos;
}
