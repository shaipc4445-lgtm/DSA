#include <stdio.h>
#include <stdlib.h>

struct node { int data; struct node *left; struct node *right; };

struct node* create(int val)
{
    struct node *p = (struct node*)malloc(sizeof(struct node));
    p->data = val; p->left = NULL; p->right = NULL;
    return p;
}

struct node* insert(struct node *root, int val)
{
    if(root == NULL) return create(val);
    if(val < root->data)      root->left  = insert(root->left,  val);
    else if(val > root->data) root->right = insert(root->right, val);
    else printf("Duplicate %d not inserted.\n", val);
    return root;
}

void levelOrder(struct node *root)
{
    if(root == NULL) { printf("Tree is empty.\n"); return; }

    struct node *q[100];
    int front = 0, rear = -1;
    int level = 0;

    q[++rear] = root;

    while(front <= rear)
    {
        int size = rear - front + 1;   /* number of nodes at current level */

        printf("Level %d  |  Nodes: %d  |  Values: ", level, size);

        while(size--)
        {
            struct node *curr = q[front++];
            printf("%d ", curr->data);

            if(curr->left  != NULL) q[++rear] = curr->left;
            if(curr->right != NULL) q[++rear] = curr->right;
        }

        printf("\n");
        level++;
    }

    printf("\nTotal levels: %d\n", level);
}

int main()
{
    struct node *root = NULL;
    int n, val, ch;

    do {
        printf("\n1.Insert  2.Level-Order Display  3.Exit\nEnter choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                printf("How many values to insert? ");
                scanf("%d", &n);
                for(int i = 0; i < n; i++)
                {
                    printf("Enter value %d: ", i+1);
                    scanf("%d", &val);
                    root = insert(root, val);
                }
                break;

            case 2:
                printf("\n--- Level-wise Traversal ---\n");
                levelOrder(root);
                break;

            case 3:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while(ch != 3);

    return 0;
}
