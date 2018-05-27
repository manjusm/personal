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

void deletesll(node_t *sll)
{
    node_t *temp;
    while (sll){
        temp = sll;
        sll = sll->next;
        free(temp);
        temp = NULL; 
    }
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

void insertatPosition(node_t **sll, int data, int position)
{
    node_t *temp = NULL;
    node_t *temp1 = *sll;
    temp = (node_t *) malloc(sizeof(node_t));
    temp->data = data;
    temp->next = NULL;   

    /* if the position is 0 or the list itself is NULL, add the element at the
     * beginning */ 
    if (position && temp1)
    {    
        while(temp1->next && (position-1))
        {
            temp1 = temp1->next;
            position = position-1;
        }
        temp->next = temp1->next;
        temp1->next = temp;
    } else {
        temp->next = *sll;
        *sll = temp;
    }
    
    return;
}

void deleteatPosition(node_t **sll, int position)
{
    node_t *temp = NULL;
    node_t *temp1 = NULL;

    if(NULL == *sll) {
        return;
    }

    temp = *sll;

    if (position) {
        while(temp->next && (position-1)) {
            temp = temp->next;
            position--;
        }
        /* list doesn't have the number of elementrs as specified by position */
        if (--position){
            return;
        }
        temp1 = temp->next;
        temp->next = temp1->next;
        free(temp1);
    } else {
        *sll = temp->next;
        free(temp);   
    }
   
    return;
}

void reversesll(node_t **sll)
{
    node_t *prev = NULL;
    node_t *current = *sll;
    node_t *next;

    while(current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *sll = prev;
    return;
}

void printsllRecursive(node_t *sll)
{
    if (NULL == sll){
        printf("\n");
        return;
    }
    printf("%d\t", sll->data);
    printsllRecursive(sll->next);
    return;
}

void printsllReverse(node_t *sll)
{
    if (NULL == sll){
        return;
    }
    printsllReverse(sll->next);
    printf("%d\t", sll->data);
    return;
}

int main()
{
    node_t *sll = NULL;
    
    /* Insert a node at the beginning of the list */
    insertbegin(&sll, 10);
    insertbegin(&sll, 20);
    insertbegin(&sll, 30);
    
    /* print the elements of the list */
    printsll(sll);

    /* insert an element at position x */
    insertatPosition(&sll, 40, 2);  
    insertatPosition(&sll, 50, 0);  
    insertatPosition(&sll, 60, 5);  
    insertatPosition(&sll, 70, 8);  

    /* print the elements of the list */
    printsll(sll);

    /* Delete the node at a given position x */
    deleteatPosition(&sll, 3);
    deleteatPosition(&sll, 0);
    deleteatPosition(&sll, 8);
    
    /* print the elements of the list */
    printsll(sll);

    /* Reverse sll */
    reversesll(&sll);

    /* print the elements of the list */
    printsll(sll);

    /* Reverse sll */
    reversesll(&sll);

    /* print the elements of the list */
    printsll(sll);

    /*  recursion *  
     * ===========*/
    printf("Recursion\n");
    printsllRecursive(sll);
    
    /* print sll in reverse */
    printsllReverse(sll);
    printf("\n");
    
    deletesll(sll);
    sll = NULL;
    /* print the elements of the list */
    printsll(sll);
    return;
}
