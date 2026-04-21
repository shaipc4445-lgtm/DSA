#include <stdio.h>
#define MAX 10

int a[MAX][MAX], n;
int indegree[MAX];
int queue[MAX], front, rear;

void enqueue(int v) { queue[rear++] = v; }
int  dequeue()      { return queue[front++]; }
int  isempty()      { return front == rear; }

void calculateIndegree()
{
    int i, j;
    for(i = 0; i < n; i++) {
        indegree[i] = 0;
        for(j = 0; j < n; j++)
            indegree[i] += a[j][i];  /* column sum = indegree */
    }
}

void topologicalSort()
{
    int i, v, count;
    calculateIndegree();
    front = rear = 0;
    count = 0;
    for(i = 0; i < n; i++)
        if(indegree[i] == 0) enqueue(i);
    printf("\nTopological Order: ");
    while(!isempty()) {
        v = dequeue();
        printf("%d ", v);
        count++;
        for(i = 0; i < n; i++) {
            if(a[v][i] == 1) {
                indegree[i]--;
                if(indegree[i] == 0) enqueue(i);
            }
        }
    }
    printf("\n");
    if(count != n) printf("Graph has CYCLE - topological sort not possible.\n");
    else printf("Sort complete (%d vertices processed).\n", count);
}

int main()
{
    int i, j;
    printf("Enter number of vertices: "); scanf("%d", &n);
    printf("Enter adjacency matrix (0/1):\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    topologicalSort();
    return 0;
}
