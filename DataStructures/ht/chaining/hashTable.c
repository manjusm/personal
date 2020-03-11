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
            hashItem_t *temp = ht->hashItems[i];
            hashItem_t *prev;
            if (!temp->next)
            {
                free(ht->hashItems[i]->value);
                free(ht->hashItems[i]);
                ht->hashItems[i] = NULL;
            }
            else
            {
               prev = temp;
               while(temp)
               {
                   temp = temp->next;
                   free(prev->value);
                   free(prev);
                   prev =  temp;
               }
            }
        }
    }
    free(ht->hashItems);
    free(ht);
}

void insert(int key, char *value, hashTable_t *ht)
{
    int index = hashFunction(key);
    //Get new item
    hashItem_t *item = (hashItem_t *) malloc(sizeof(hashItem_t));
    item->key = key;
    item->value = strdup(value);
    item->next = NULL;

    // No item at this index
    if (NULL == ht->hashItems[index])
    {
        ht->hashItems[index] = item;
        return;
    }

    //Item already exits. Add new entry at the end of the chain.
    hashItem_t *temp = ht->hashItems[index];
    while(NULL != temp->next)
    {
        temp = temp->next;
    }
    temp->next = item;

    return;
}

void delete(int key, hashTable_t *ht)
{
    int index = hashFunction(key);
    hashItem_t *current = ht->hashItems[index];
    hashItem_t *prev = current;

    //Item we are looking for is the only entry
    if (!current->next)
    {
        free(ht->hashItems[index]->value);
        free(ht->hashItems[index]);
        ht->hashItems[index] = NULL;
        return;
    }

    // Search for entry in chain
    if (current->key == key)
    {
        prev = current->next;
        free(current->value);
        free(current);
        ht->hashItems[index] = prev;
        return;
    }
    while(current && current->key != key)
    {
        prev = current;
        current = current->next;
    }
    prev->next = current->next;
    free(current->value);
    free(current);

    return;
}

hashItem_t *retrieve(int key, hashTable_t *ht)
{
    int index = hashFunction(key);
    hashItem_t *item = ht->hashItems[index];
    if (!item->next)
    {
        return item;
    }

    while(item && item->key != key)
    {
        item = item->next;
    }
    return item;
}

int main()
{
    hashTable_t *ht = createHashTable();
    insert(2, "Manju2", ht);
    insert(12, "Manju12", ht);
    insert(3, "Manju3", ht);
    insert(13, "Manju13", ht);
    hashItem_t *item = retrieve(2, ht);
    printf("%d %s\n", item->key, item->value);
    item = retrieve(12, ht);
    printf("%d %s\n", item->key, item->value);
    item = retrieve(3, ht);
    printf("%d %s\n", item->key, item->value);
    item = retrieve(13, ht);
    printf("%d %s\n", item->key, item->value);
    delete(2, ht);
    item = retrieve(12, ht);
    printf("%d %s\n", item->key, item->value);
    deleteHashTable(ht);
    return 0;
}
