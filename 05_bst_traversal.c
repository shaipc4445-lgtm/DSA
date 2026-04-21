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

void inorder(struct node *root)
{
    if(root != NULL) { inorder(root->left); printf("%d ", root->data); inorder(root->right); }
}
void preorder(struct node *root)
{
    if(root != NULL) { printf("%d ", root->data); preorder(root->left); preorder(root->right); }
}
void postorder(struct node *root)
{
    if(root != NULL) { postorder(root->left); postorder(root->right); printf("%d ", root->data); }
}

void search(struct node *root, int val)
{
    if(root == NULL) { printf("%d NOT FOUND.\n", val); return; }
    if(val == root->data) { printf("%d FOUND.\n", val); return; }
    if(val < root->data) search(root->left, val);
    else search(root->right, val);
}

int main()
{
    struct node *root = NULL;
    int ch, val;
    do {
        printf("\n1.Insert 2.Inorder 3.Preorder 4.Postorder 5.Search 6.Exit\nChoice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1: printf("Value: "); scanf("%d",&val); root=insert(root,val); break;
            case 2: printf("Inorder:   "); inorder(root);   printf("\n"); break;
            case 3: printf("Preorder:  "); preorder(root);  printf("\n"); break;
            case 4: printf("Postorder: "); postorder(root); printf("\n"); break;
            case 5: printf("Search value: "); scanf("%d",&val); search(root,val); break;
            case 6: break;
            default: printf("Invalid!\n");
        }
    } while(ch != 6);
    return 0;
}
