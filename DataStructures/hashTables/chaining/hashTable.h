//Key-value pair
typedef struct htItem_s
{
    int             key;
    char            *value;
    struct htItem_s *next;
}hashItem_t;

typedef struct hashTable_s
{
    int             size;   // size of the hash table
    hashItem_t      **hashItems;
}hashTable_t;
