typedef struct entry_s
{
    int connectedVertex;
    int weight;
    struct entry_s *next;
} entry_t;

typedef struct graph_s
{
    int v;
    entry_t **entryItem;
}graph_t;


typedef struct node_s
{
    int data;
    struct node_s *next;
} node_t;

