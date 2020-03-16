typedef struct entry_s
{
    int connectedVertex;
    struct entry_s *next;
} entry_t;

typedef struct graph_s
{
    int v;
    entry_t **entryItem;
}graph_t;
