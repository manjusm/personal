#include <stdio.h>
#include <stdlib.h>

#define MAX 10
#define init        0
#define visited     1
#define tobevisited 2

int n; // Number of vertices
int adj_matrix[MAX][MAX]; // adjacency matrix
int state[MAX];

void create_graph();
void df_traversal();
void DFS(int vertex);

void create_graph()
{
    int count, max_edge, origin, dest;
    printf("\nEnter the number of vertices : ");
    scanf("%d", &n);
    max_edge = n*(n-1);

    for (count = 0; count < max_edge; count++){
        
        printf("\nPlease enter source and target : (0 0 to quit)");
        scanf("%d %d", &origin, &dest);
        
        if (origin == 0 && dest == 0){
            break;
        }

        if (origin < 1 || dest < 1 || origin > n || dest > n) {
            printf("\nVertices are numbered from 1 to n\n");
            count--;
            continue;
        }
        if (origin == dest){
            printf("\nEdge originating and terminating on the same vertex is not acceptable");
            count--;
            continue;
        }

        adj_matrix[origin][dest] = 1; /* undirected graph */
        adj_matrix[dest][origin] = 1;
    }
    return;
}

void DFS(int vertex)
{
    int i;
    
    state[vertex] = visited;
    printf("%d\t", vertex);
    for (i = 1; i <= n; i++){
        if (adj_matrix[vertex][i] == 1 && state[i] == init){
            DFS(i);
        }
    }
}

void df_traversal()
{
    int v;
    for ( v = 1; v <= n; v++){
        state[v] = init;
    }
    printf("\nEnter the vertex to start traversal\n");
    scanf("%d", &v);
    DFS(v);
    printf("\n");
    return;
}

int main()
{
    create_graph();
    df_traversal();
    return 0;
}
