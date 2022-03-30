#include <stdio.h>
#include <stdlib.h>

struct BST
{
    int data;
    struct BST *llink;
    struct BST *rlink;
};
typedef struct BST *NODE;

// Fuction declaration
NODE create();
void insert(NODE root, NODE newnode);
void inorder(NODE root);
void preorder(NODE root);
void postorder(NODE root);
void search(NODE root);

// Main Function
void main()
{
    int choice, i, n;
    NODE root = NULL, newnode;
    while (1)
    {
        printf("\n\n~~~~BST MENU~~~~");
        printf("\n1.Create a BST");
        printf("\n2.BST Traversals");
        printf("\n3.Search");
        printf("\n4.Exit");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\n\nEnter the number of Elements : ");
            scanf("%d", &n);
            for (i = 0; i < n; i++)
            {
                newnode = create();

                if (root == NULL)
                    root = newnode;
                else
                    insert(root, newnode);
            }
            break;
        case 2:
            if (root == NULL)
                printf("\nTree is Not Created\n");
            else
            {
                printf("\nThe Preoder display   : ");
                preorder(root);

                printf("\nThe Inorder display   : ");
                inorder(root);

                printf("\nThe Postorder display : ");
                postorder(root);
            }
            break;
        case 3:
            search(root);
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\nINVALID CHOICE\n");
            break;
        }
    }
}

// Function to Create a Node
NODE create()
{
    NODE temp;
    temp = (NODE)malloc(sizeof(struct BST));
    printf("\nEnter the Element : ");
    scanf("%d", &temp->data);
    temp->llink = NULL;
    temp->rlink = NULL;
}

// Funcion for insertion of Node in BST
void insert(NODE root, NODE newnode)
{
    if (newnode->data < root->data)
    {
        if (root->llink == NULL)
            root->llink = newnode;
        else
            insert(root->llink, newnode);
    }

    if (newnode->data > root->data)
    {
        if (root->rlink == NULL)
            root->rlink = newnode;
        else
            insert(root->rlink, newnode);
    }
}

// Function to search an node/element
void search(NODE root)
{
    int key;
    NODE cur;

    if (root == NULL)
    {
        printf("\nBST is empty.\n");
        return;
    }

    printf("\nEnter Element to searched : ");
    scanf("%d", &key);

    cur = root;

    while (cur != NULL)
    {
        if (cur->data == key)
        {
            printf("\nKey Elements is present in BST\n");
            return;
        }

        if (key < cur->data)
            cur = cur->llink;
        else
            cur = cur->rlink;
    }
    printf("\nKey Elements is not found in the BST\n");
}

// Preorder Traversal Function
void preorder(NODE root)
{
    if (root == NULL)
        return;
    printf("%d\t", root->data);
    preorder(root->llink);
    preorder(root->rlink);
}

// Inorder Traversal Function
void inorder(NODE root)
{
    if (root == NULL)
        return;
    inorder(root->llink);
    printf("%d\t", root->data);
    inorder(root->rlink);
}

// Postorder Traversal Functon
void postorder(NODE root)
{
    if (root == NULL)
        return;
    postorder(root->llink);
    postorder(root->rlink);
    printf("%d\t", root->data);
}