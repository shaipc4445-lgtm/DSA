#include <stdio.h>
#include <stdlib.h>

struct node { int data; struct node *left; struct node *right; };

struct node* create(int val)
{
    struct node *p = (struct node*)malloc(sizeof(struct node));
    p->data = val; p->left = NULL; p->right = NULL; return p;
}
struct node* insert(struct node *root, int val)
{
    if(root == NULL) return create(val);
    if(val < root->data)      root->left  = insert(root->left,  val);
    else if(val > root->data) root->right = insert(root->right, val);
    return root;
}
void inorder(struct node *root)
{
    if(root) { inorder(root->left); printf("%d ", root->data); inorder(root->right); }
}

int count(struct node *root)
{
    if(root == NULL) return 0;
    return 1 + count(root->left) + count(root->right);
}

int countLeaf(struct node *root)
{
    if(root == NULL) return 0;
    if(root->left == NULL && root->right == NULL) return 1;
    return countLeaf(root->left) + countLeaf(root->right);
}

int main()
{
    struct node *root = NULL;
    int ch, val;
    do {
        printf("\n1.Insert 2.Inorder 3.Count 4.CountLeaf 5.Exit\nChoice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1: printf("Value: "); scanf("%d",&val); root=insert(root,val); break;
            case 2: printf("Inorder: "); inorder(root); printf("\n"); break;
            case 3: printf("Total nodes = %d\n", count(root)); break;
            case 4: printf("Leaf nodes  = %d\n", countLeaf(root)); break;
            case 5: break;
            default: printf("Invalid!\n");
        }
    } while(ch != 5);
    return 0;
}
