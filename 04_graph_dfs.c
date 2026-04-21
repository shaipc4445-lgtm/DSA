#include <stdio.h>
#define MAX 10

int a[MAX][MAX], n;
int visited[MAX];

void dfs(int v)
{
    int i;
    visited[v] = 1;
    printf("%d ", v);
    for(i = 0; i < n; i++)
        if(a[v][i] == 1 && visited[i] == 0)
            dfs(i);
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
    for(i = 0; i < n; i++) visited[i] = 0;
    printf("\nDFS Traversal: ");
    dfs(start);
    printf("\n");
    return 0;
}
