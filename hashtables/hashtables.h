#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TABLESIZE 5

/* Node for chained implementation */
typedef struct node {
    char *data;
    struct node *next;
} node;

/* Function prototypes */
/*  hash function
    Input : word and table size
    Output : Index of the bucket */
unsigned int hash(const char *, int);

/*  Lookup function 
    Input : table and key
    Output : True or false */
int lookup(node *table[], char *);

/*  Insert
    Input: table and the key
    Output : Success/failure */
int insert(node *table[], char *);

/*  Delete
    Input : table and key
    Output : Success/failure */
int delete(node *table[], char *);
