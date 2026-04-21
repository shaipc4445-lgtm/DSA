#include <stdio.h>
#include <stdlib.h>
#define MAX 10

struct node { int data; struct node *next; };
struct node *adj[MAX];
int n;

void create()
{
    int i, edges, u, v;
    struct node *newnode, *temp;
    printf("Enter number of vertices: "); scanf("%d", &n);
    for(i = 0; i < n; i++) adj[i] = NULL;
    printf("Enter number of edges: "); scanf("%d", &edges);
    printf("Enter edges (u v):\n");
    for(i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = v; newnode->next = NULL;
        if(adj[u] == NULL) adj[u] = newnode;
        else {
            temp = adj[u];
            while(temp->next != NULL) temp = temp->next;
            temp->next = newnode;
        }
    }
}

void display()
{
    int i; struct node *temp;
    printf("\nAdjacency List:\n");
    for(i = 0; i < n; i++) {
        printf("%d -> ", i);
        temp = adj[i];
        while(temp != NULL) { printf("%d -> ", temp->data); temp = temp->next; }
        printf("NULL\n");
    }
}

void degree()
{
    int i, j, indegree, outdegree; struct node *temp;
    printf("\nVertex\tIndegree\tOutdegree\tTotaldegree\n");
    for(i = 0; i < n; i++) {
        outdegree = 0; indegree = 0;
        temp = adj[i];
        while(temp != NULL) { outdegree++; temp = temp->next; }
        for(j = 0; j < n; j++) {
            temp = adj[j];
            while(temp != NULL) { if(temp->data == i) indegree++; temp = temp->next; }
        }
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
        }
    } while(ch != 3);
    return 0;
}
