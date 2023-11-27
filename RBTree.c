#include <stdio.h>
#include <stdlib.h>

static char BLACK = 'B';
static char RED = 'R';

struct RBTNode
{
    int data;
    char color;
    struct RBTNode *left;
    struct RBTNode *right;
    struct RBTNode *parent;
} *root = NULL, *LEAF;
struct RBTNode *new (int item)
{
    struct RBTNode *temp = (struct RBTNode *)malloc(sizeof(struct RBTNode));
    temp->data = item;
    temp->left = temp->right = temp->parent = NULL;
    temp->color = RED;
    return temp;
}
struct RBTNode *parent(struct RBTNode *key)
{
    return key->parent;
}
struct RBTNode *grandparent(struct RBTNode *key)
{
    struct RBTNode *par = parent(key);
    if (par == NULL)
        return NULL;
    return parent(par);
}
struct RBTNode *sibling(struct RBTNode *key)
{
    struct RBTNode *par = parent(key);
    if (par == NULL)
        return NULL;
    if (key == par->left)
        return par->right;
    else
        return par->left;
}
struct RBTNode *uncle(struct RBTNode *key)
{
    struct RBTNode *par = parent(key);
    struct RBTNode *gp = grandparent(key);
    if (gp == NULL)
        return NULL;
    return sibling(par);
}
void LRotate(struct RBTNode *key)
{
    struct RBTNode *nnew = key->right;
    struct RBTNode *par = parent(key);
    key->right = nnew->left;
    nnew->left = key;
    key->parent = nnew;
    if (key->right != NULL)
        key->right->parent = key;
    if (par != NULL)
    {
        if (key == par->left)
            par->left = nnew;
        else if (key == par->right)
            par->right = nnew;
    }
    nnew->parent = par;
}
void RRotate(struct RBTNode *key)
{
    struct RBTNode *nnew = key->left;
    struct RBTNode *par = parent(key);
    key->left = nnew->right;
    nnew->right = key;
    key->parent = nnew;
    if (key->left != NULL)
        key->left->parent = key;
    if (par != NULL)
    {
        if (key == par->left)
            par->left = nnew;
        else if (key == par->right)
            par->right = nnew;
    }
    nnew->parent = par;
}
int is_leaf(struct RBTNode *key)
{
    if (key->right == NULL && key->left == NULL)
        return 1;
    else
        return 0;
}
struct RBTNode *search(struct RBTNode *temp, int val)
{
    int diff;
    while (!is_leaf(temp))
    {
        diff = val - temp->data;
        if (diff > 0)
        {
            temp = temp->right;
        }
        else if (diff < 0)
        {
            temp = temp->left;
        }
        else
        {
            return temp;
        }
    }
    return 0;
}
void replace(struct RBTNode *key, struct RBTNode *child)
{
    child->parent = key->parent;
    if (key == key->parent->left)
    {
        key->parent->left = child;
    }
    else
    {
        key->parent->right = child;
    }
}
void delc6(struct RBTNode *key)
{
    struct RBTNode *sib = sibling(key);
    sib->color = key->parent->color;
    key->parent->color = BLACK;
    if (key == key->parent->left)
    {
        sib->right->color = BLACK;
        LRotate(key->parent);
    }
    else
    {
        sib->left->color = BLACK;
        RRotate(key->parent);
    }
}
void delc5(struct RBTNode *key)
{
    struct RBTNode *sib = sibling(key);

    if (sib->color == BLACK)
    {
        if ((key == key->parent->left) && (sib->right->color == BLACK) && (sib->left->color == RED))
        {
            sib->color = RED;
            sib->left->color = BLACK;
            RRotate(sib);
        }
        else if ((key == key->parent->right) && (sib->left->color == BLACK) && (sib->right->color == RED))
        {
            sib->color = RED;
            sib->right->color = BLACK;
            LRotate(sib);
        }
    }
    delc6(key);
}
void delc4(struct RBTNode *key)
{
    struct RBTNode *sib = sibling(key);

    if ((key->parent->color == RED) && (sib->color == BLACK) && (sib->left->color == BLACK) && (sib->right->color == BLACK))
    {
        sib->color = RED;
        key->parent->color = BLACK;
    }
    else
    {
        delc5(key);
    }
}
void delc3(struct RBTNode *key)
{
    struct RBTNode *sib = sibling(key);
    if ((key->parent->color == BLACK) && (sib->color == BLACK) && (sib->left->color == BLACK) && (sib->right->color == BLACK))
    {
        sib->color = RED;
        delc1(key->parent);
    }
    else
    {
        delc4(key);
    }
}
void delc2(struct RBTNode *key)
{
    struct RBTNode *sib = sibling(key);

    if (sib->color == RED)
    {
        key->parent->color = RED;
        sib->color = BLACK;
        if (key == key->parent->left)
            LRotate(key->parent);
        else
            RRotate(key->parent);
    }
    delc3(key);
}
void delc1(struct RBTNode *key)
{
    if (key->parent != NULL)
        delc2(key);
}
void delete (struct RBTNode *key)
{
    struct RBTNode *child = is_leaf(key->right) ? key->left : key->right;
    replace(key, child);
    if (key->color == BLACK)
    {
        if (child->color == RED)
            child->color = BLACK;
        else
            delc1(child);
    }
    free(key);
}
void insertion(struct RBTNode *root, struct RBTNode *key)
{
    if (root != NULL && key->data < root->data)
    {
        if (root->left != LEAF)
        {
            insertion(root->left, key);
            return;
        }
        else
        {
            root->left = key;
        }
    }
    else if (root != NULL)
    {
        if (root->right != LEAF)
        {
            insertion(root->right, key);
            return;
        }
        else
            root->right = key;
    }
    key->parent = root;
    key->left = LEAF;
    key->right = LEAF;
    key->color = RED;
}
void insert1(struct RBTNode *key)
{
    if (parent(key) == NULL)
        key->color = BLACK;
}
void insert2(struct RBTNode *key)
{
    return;
}
void insert3(struct RBTNode *key)
{
    parent(key)->color = BLACK;
    uncle(key)->color = BLACK;
    grandparent(key)->color = RED;
    insert_fix(grandparent(key));
}
void insert4step2(struct RBTNode *key)
{
    struct RBTNode *par = parent(key);
    struct RBTNode *gp = grandparent(key);
    if (key == par->left)
        RRotate(gp);
    else
        LRotate(gp);
    par->color = BLACK;
    gp->color = RED;
}
void insert4(struct RBTNode *key)
{
    struct RBTNode *par = parent(key);
    struct RBTNode *gp = grandparent(key);
    if (key == gp->left->right)
    {
        LRotate(par);
        key = key->left;
    }
    else if (key == gp->right->left)
    {
        RRotate(par);
        key = key->right;
    }
    insert4step2(key);
}
void insert_fix(struct RBTNode *key)
{
    if (parent(key) == NULL)
    {
        insert1(key);
    }
    else if (parent(key)->color == BLACK)
    {
        insert2(key);
    }
    else if (uncle(key)->color == RED)
    {
        insert3(key);
    }
    else
    {
        insert4(key);
    }
}
struct RBTNode *insert(struct RBTNode *root, struct RBTNode *key)
{
    insertion(root, key);
    insert_fix(key);
    root = key;
    while (parent(root) != NULL)
        root = parent(root);
    return root;
}
void inorderTree(struct RBTNode *root)
{
    struct RBTNode *temp = root;
    if (temp != NULL)
    {
        inorderTree(temp->left);
        printf(" %d--%c ->", temp->data, temp->color);
        inorderTree(temp->right);
    }
}
void postorderTree(struct RBTNode *root)
{
    struct RBTNode *temp = root;

    if (temp != NULL)
    {
        postorderTree(temp->left);
        postorderTree(temp->right);
        printf(" %d--%c ->", temp->data, temp->color);
    }
}
void traversal(struct RBTNode *root)
{
    if (root != NULL)
    {
        printf("root is %d-- %c\n", root->data, root->color);
        printf("Inorder tree traversal\n");
        inorderTree(root);
        printf("END");
        printf("\n");
        printf("postorder tree traversal\n");
        postorderTree(root);
        printf("END");
        printf("\n");
    }
}
void main()
{
    LEAF = malloc(sizeof(struct RBTNode));
    LEAF->color = BLACK;
    LEAF->left = NULL;
    LEAF->right = NULL;
    LEAF->data = 0;
    int choice, val, var;
    while (1)
    {
        printf("Select The Operation You Want to Perform :\n1:Insert\n2:Delete\n3:Traverse\n4:Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if (root == NULL)
            {
                printf("Enter the Root Value :\n");
            }
            else
            {
                printf("Enter the Node Value :\n");
            }
            scanf("%d", &val);
            new (val);
            root = insert(root, new (val));
            printf("The root is now : %d\n", root->data);
            break;
        case 2:
            printf("Enter the Key you want to delete :\n");
            scanf("%d", &var);
            delete (search(root, var));
            break;
        case 3:
            traversal(root);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid Choice\n");
        }
    }
}