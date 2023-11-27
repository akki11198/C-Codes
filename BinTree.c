#include <stdio.h>
#include <stdlib.h>

typedef struct btnode
{
    struct btnode *left;
    struct btnode *right;
    int data;
} BTNODE;

typedef struct bintree
{
    BTNODE *root;
} TREE;
TREE *maketree()
{
    TREE *t = (TREE *)malloc(sizeof(TREE));
    if (t == NULL)
        return t;
    t->root = NULL;
    return t;
}
void ins(BTNODE *root, BTNODE *p)
{
    if (root->data > p->data)
    {
        if (root->left == NULL)
            root->left = p;
        else
            ins(root->left, p);
    }
    else if (root->data < p->data)
    {
        if (root->right == NULL)
            root->right = p;
        else
            ins(root->right, p);
    }
}
void insert(TREE *t, int value)
{
    if (t == NULL)
        return;
    BTNODE *p = (BTNODE *)malloc(sizeof(BTNODE));
    if (p == NULL)
        return;
    p->left = p->right = NULL;
    p->data = value;

    if (t->root == NULL)
        t->root = p;
    else
        ins(t->root, p);
}
void pre(BTNODE *root)
{
    if (root != NULL)
    {
        printf("%d-> ", root->data);
        pre(root->left);
        pre(root->right);
    }
}
void preorder(TREE *t)
{
    if (t == NULL)
    {
        printf("NULL\n");
        return;
    }
    pre(t->root);
    printf("end\n");
}
void in(BTNODE *root)
{
    if (root != NULL)
    {
        in(root->left);
        printf("%d-> ", root->data);
        in(root->right);
    }
}
void inorder(TREE *t)
{
    if (t == NULL)
    {
        printf("NULL\n");
        return;
    }
    in(t->root);
    printf("end\n");
}
void post(BTNODE *root)
{
    if (root != NULL)
    {
        post(root->left);
        post(root->right);
        printf("%d-> ", root->data);
    }
}
void postorder(TREE *t)
{
    if (t == NULL)
    {
        printf("NULL\n");
        return;
    }
    post(t->root);
    printf("end\n");
}
void main()
{
    int n, key, i;
    TREE *tr;
    tr = maketree();
    printf("Enter the no of nodes : ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the %d Node value : ", i);
        scanf("%d", &key);
        insert(tr, key);
    }
    printf("Preorder Traversal Is : \n");
    preorder(tr);
    printf("Inorder Traversal Is : \n");
    inorder(tr);
    printf("Postorder Traversal Is : \n");
    postorder(tr);
}