;#include <stdio.h>
#define MAX 10
int a[MAX][MAX], n;

void create()
{
    int i, j;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
}

void display()
{
    int i, j;
    printf("\nAdjacency Matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
            printf("%d\t", a[i][j]);
        printf("\n");
    }
}

void degree()
{
    int i, j, indegree, outdegree;
    printf("\nVertex\tIndegree\tOutdegree\tTotaldegree\n");
    for(i = 0; i < n; i++)
    {
        indegree = 0; outdegree = 0;
        for(j = 0; j < n; j++) outdegree += a[i][j];
        for(j = 0; j < n; j++) indegree  += a[j][i];
        printf("%d\t%d\t\t%d\t\t%d\n", i, indegree, outdegree, indegree+outdegree);
    }
}

int main()
{
    int ch;
    create();
    do {
        printf("\n1.Display  2.Degree  3.Exit\nChoice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1: display(); break;
            case 2: degree();  break;
            case 3: break;
            default: printf("Invalid!\n");
        }
    } while(ch != 3);
    return 0;
}
