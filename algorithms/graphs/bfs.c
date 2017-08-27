#include <stdio.h>
#include <stdlib.h>

#define MAX 10
#define init        0
#define visited     1
#define tobevisited 2

int n; // Number of vertices
int adj_matrix[MAX][MAX]; // adjacency matrix
int state[MAX];

/* QUEUE */
int  queue[MAX], front = -1, rear = -1;
void write(int vertex);
int  read();
int  is_empty();

void create_graph();
void bf_traversal();
void BFS(int vertex);

int is_empty()
{
    if (front == -1 || front > rear){
        return 1;
    }
    return 0;
}


int read()
{
    if (is_empty()){
        printf("\nqueue is empty\n");
        exit(0);
    }

    return queue[front++];
}

void write(int vertex)
{
    if (rear == MAX - 1){
        printf("\nOverflow\n");
        return;
    }
    
    if(front == -1){
        front++;
    }

    queue[++rear] = vertex;
}

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

        if (origin < 1 || dest < 1 || origin > n || dest > n) ){
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

void BFS(int vertex)
{
    int i;
    write(vertex);

    while (!is_empty()){
        vertex = read();
        printf("%d\t", vertex); 
        state[vertex] = visited;

        for (i = 1; i <= n; i++){
            if (adj_matrix[vertex][i] == 1 && state[i] == init){
                state[i] = tobevisited;
                write(i);
            }
        }
    }
}

void bf_traversal()
{
    int v;
    for ( v = 1; v <= n; v++){
        state[v] = init;
    }
    printf("\nEnter the vertex to start traversal\n");
    scanf("%d", &v);
    BFS(v);
    printf("\n");
    return;
}

int main()
{
    create_graph();
    bf_traversal();
    return 0;
}
