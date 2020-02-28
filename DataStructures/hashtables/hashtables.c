#include "hashtables.h"

int lookup (node *table[], char *key) {
    int index = hash(key, TABLESIZE);
    node *it = table[index];

    while(it != NULL && strcmp(it->data, key) != 0)
    {
        it = it->next;
    }
    return (it != NULL);
}

unsigned int hash(const char *key, int tablesize) {
    int index = toupper(key[0]) - 'A';
    return index % tablesize;
}

int insert (node *table[], char *key) {
    int index;
    if (lookup(table, key)) {
        printf("Word is already present");
        return -1;
    }
    index = hash(key, TABLESIZE);
    node *new = (node * ) malloc(sizeof(struct node));
    if (NULL == new) {
        return -1;
    }
    new->data = (char *) malloc(strlen(key) + 1);
    if (NULL == new->data) {
        return -1;
    }
    strcpy(new->data, key);
    new->next = table[index];
    table[index] = new;
    return 0;
}

int delete (node *table[], char *key) {
    return 0;
}

int populate_hashtable(node *table[], FILE *file) {
    char word[50];
    char c;

    do {
        c = fscanf(file, "%s", word);
        size_t ln = strlen(word);
        if (word[ln] == '\n') {
            word[ln] ='\0';
        }

        insert(table, word);

    }while(c != EOF);
    return 0;
}

int main() {
    FILE *INPUT = NULL;
    node *table[TABLESIZE] = {0};
    int found = 0;
    char word[50];
    char c;

    INPUT = fopen("INPUT", "r");
    if (NULL == INPUT) {
        printf("File open failed\n");
        return -1;
    }
    populate_hashtable(table, INPUT);
    fclose(INPUT);
    printf("Hash table is ready\n");

    FILE *CHECK = NULL;
    CHECK = fopen("CHECK", "r");
    
    do {

        c = fscanf(CHECK, "%s", word);
        size_t ln = strlen(word);
        if(word[ln] == '\n') {
            word[ln] = '\0';
        }
        if (lookup(table, word)) {
            found++;
        }

    } while(c != EOF);

    printf("%d\n", found);

    return 0;
}
