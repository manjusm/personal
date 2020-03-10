//Key-value pair
typedef struct htItem_s
{
    int     key;
    char   *value;
}hashItem_t;

typedef struct hashTable_s
{
    int         size;   // size of the hash table
    int         count;  // Indicates the current number of items in hash table
    hashItem_t   **hashItems;
}hashTable_t;
