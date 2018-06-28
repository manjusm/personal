#include <stdio.h>
#include <stdlib.h>

#include "sll.h"

void printsll(node_t *sll)
{
    if (NULL == sll) {
        printf("List is empty\n");
        return;
    }
    while(sll)
    {
        printf("%d\t", sll->data);
        sll = sll->next;
    }
    printf("\n");
    return;
}

void insertbegin(node_t **sll, int data)
{
    node_t *temp = NULL;
    temp = (node_t *)malloc(sizeof(node_t));
    temp->data = data;
    temp->next = *sll;
    *sll = temp;
    return;
}

void removeDuplicates(node_t *sll)
{
    node_t *current = sll;
    node_t *mover, *temp;

    if (NULL == sll) {
        return;
    }

    while(current){
        mover = current;
        while(mover->next){
            if (current->data == mover->next->data){
                temp = mover->next;
                mover->next = mover->next->next;
                free(temp);
                temp = NULL;
            } else {
                mover = mover->next;
            }
        }
        current = current->next;
    }

    return;
}

int main()
{
    node_t *sll = NULL;
    
    /* Insert a node at the beginning of the list */
    insertbegin(&sll, 10);
    insertbegin(&sll, 20);
    insertbegin(&sll, 30);
    
    insertbegin(&sll, 10);
    insertbegin(&sll, 20);
    insertbegin(&sll, 10);
    
    /* print the elements of the list */
    printsll(sll);
    
    /* remove duplicates in an unsorted list */
    removeDuplicates(sll);
    /* print the elements of the list */
    printsll(sll);
    
    return 0;

}
