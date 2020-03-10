#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hashTable.h"

int hashFunction(int key)
{
    return (key % 10);
}

hashTable_t * createHashTable()
{
    hashTable_t *ht = (hashTable_t *) malloc(sizeof(hashTable_t));
    ht->size = 10;
    ht->count = 0;
    ht->hashItems = (hashItem_t **)calloc(ht->size, sizeof(hashItem_t));
    return ht;
}

void deleteHashTable(hashTable_t *ht)
{
    if (NULL == ht)
    {
        printf("Hash table doesn't exist\n");
        return;
    }
    for (int i = 0; i < ht->size; i++)
    {
        if (ht->hashItems[i])
        {
            free(ht->hashItems[i]->value);
            free(ht->hashItems[i]);
            ht->hashItems[i] = NULL;
        }
    }
    free(ht->hashItems);
    free(ht);
}

void insert(int key, char *value, hashTable_t *ht)
{
    int index = hashFunction(key);
    hashItem_t *item = (hashItem_t *) malloc(sizeof(hashItem_t));
    item->key = key;
    item->value = strdup(value);
    ht->hashItems[index] = item;
    return;
}

void delete(int key, hashTable_t *ht)
{
    int index = hashFunction(key);
    free(ht->hashItems[index]->value);
    free(ht->hashItems[index]);
    ht->hashItems[index] = NULL;
    return;
}

hashItem_t *retrieve(int key, hashTable_t *ht)
{
    int index = hashFunction(key);
    return ht->hashItems[index];
}

void update(int key, char *value, hashTable_t *ht)
{
    int index = hashFunction(key);
    hashItem_t *item = ht->hashItems[index];
    free(item->value);
    item->value = strdup(value);
    return;
}

int main()
{
    hashTable_t *ht = createHashTable();
    insert(2, "Manju", ht);
    hashItem_t *item = retrieve(2, ht);
    printf("%d %s\n", item->key, item->value);
    update(2, "Manju SM", ht);
    item = retrieve(2, ht);
    printf("%d %s\n", item->key, item->value);
    delete(2, ht);
    deleteHashTable(ht);
    return 0;
}
