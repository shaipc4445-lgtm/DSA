#include <stdio.h>
#define infinity 99

int a[15][15], spanning[15][15], n;

int prims()
{
    int cost[15][15], u, v, min_distance, distance[15], from[15];
    int visited[15], no_of_edges, i, min_cost, j;

    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++) {
            cost[i][j] = (a[i][j] == 0) ? infinity : a[i][j];
            spanning[i][j] = 0;
        }

    distance[0] = 0;
    visited[0]  = 1;
    for(i = 1; i < n; i++) {
        distance[i] = cost[0][i];
        from[i]     = 0;
        visited[i]  = 0;
    }

    min_cost    = 0;
    no_of_edges = n - 1;

    while(no_of_edges > 0) {
        min_distance = infinity;
        for(i = 1; i < n; i++)
            if(visited[i] == 0 && distance[i] < min_distance) {
                v = i;
                min_distance = distance[i];
            }
        u = from[v];
        spanning[u][v] = spanning[v][u] = distance[v];
        no_of_edges--;
        visited[v] = 1;
        for(i = 1; i < n; i++)
            if(visited[i] == 0 && cost[i][v] < distance[i]) {
                distance[i] = cost[i][v];
                from[i] = v;
            }
        min_cost += cost[u][v];
    }
    return min_cost;
}

int main()
{
    int i, j, total;
    printf("Enter no. of vertices: "); scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    total = prims();
    printf("\nSpanning tree matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) printf("%d\t", spanning[i][j]);
        printf("\n");
    }
    printf("\nTotal cost of spanning tree = %d\n", total);
    return 0;
}
