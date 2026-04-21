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

int height(struct node *root)
{
    int lh, rh;
    if(root == NULL) return 0;
    lh = height(root->left);
    rh = height(root->right);
    return 1 + (lh > rh ? lh : rh);
}

int isBalanced(struct node *root)
{
    int bf;
    if(root == NULL) return 1;
    bf = height(root->left) - height(root->right);
    if(bf > 1 || bf < -1) return 0;
    return isBalanced(root->left) && isBalanced(root->right);
}

int main()
{
    struct node *root = NULL;
    int ch, val;
    do {
        printf("\n1.Insert 2.Inorder 3.Height 4.IsBalanced 5.Exit\nChoice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1: printf("Value: "); scanf("%d",&val); root=insert(root,val); break;
            case 2: printf("Inorder: "); inorder(root); printf("\n"); break;
            case 3: printf("Height = %d\n", height(root)); break;
            case 4: printf("%s\n", isBalanced(root)?"Tree is BALANCED":"Tree is NOT BALANCED"); break;
            case 5: break;
            default: printf("Invalid!\n");
        }
    } while(ch != 5);
    return 0;
}
