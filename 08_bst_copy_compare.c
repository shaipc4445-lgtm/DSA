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

struct node* copy(struct node *root)
{
    struct node *p;
    if(root == NULL) return NULL;
    p = create(root->data);
    p->left  = copy(root->left);
    p->right = copy(root->right);
    return p;
}

int compare(struct node *t1, struct node *t2)
{
    if(t1 == NULL && t2 == NULL) return 1;
    if(t1 == NULL || t2 == NULL) return 0;
    if(t1->data != t2->data)     return 0;
    return compare(t1->left, t2->left) && compare(t1->right, t2->right);
}

struct node* mirror(struct node *root)
{
    struct node *temp;
    if(root == NULL) return NULL;
    mirror(root->left);
    mirror(root->right);
    temp = root->left; root->left = root->right; root->right = temp;
    return root;
}

int main()
{
    struct node *root1 = NULL, *root2 = NULL;
    int ch, val;
    do {
        printf("\n1.Insert(T1) 2.Display(T1) 3.Copy 4.Compare 5.Mirror(T1) 6.Insert(T2) 7.Exit\nChoice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1: printf("Value: "); scanf("%d",&val); root1=insert(root1,val); break;
            case 2: printf("T1 Inorder: "); inorder(root1); printf("\n"); break;
            case 3: root2=copy(root1); printf("Copied! T2 Inorder: "); inorder(root2); printf("\n"); break;
            case 4: printf("%s\n", compare(root1,root2)?"Trees are EQUAL":"Trees are NOT EQUAL"); break;
            case 5: mirror(root1); printf("T1 after mirror: "); inorder(root1); printf("\n"); break;
            case 6: printf("Value: "); scanf("%d",&val); root2=insert(root2,val); break;
            case 7: break;
            default: printf("Invalid!\n");
        }
    } while(ch != 7);
    return 0;
}
