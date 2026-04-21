#include <stdio.h>
#define MAX 10

int a[MAX][MAX], n;
int visited[MAX];
int queue[MAX], front, rear;

void enqueue(int v) { queue[rear++] = v; }
int  dequeue()      { return queue[front++]; }
int  isempty()      { return front == rear; }

void bfs(int start)
{
    int i, v;
    for(i = 0; i < n; i++) visited[i] = 0;
    front = rear = 0;
    visited[start] = 1;
    enqueue(start);
    printf("\nBFS Traversal: ");
    while(!isempty()) {
        v = dequeue();
        printf("%d ", v);
        for(i = 0; i < n; i++)
            if(a[v][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                enqueue(i);
            }
    }
    printf("\n");
}

int main()
{
    int i, j, start;
    printf("Enter number of vertices: "); scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    printf("Enter starting vertex: "); scanf("%d", &start);
    bfs(start);
    return 0;
}
