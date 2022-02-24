include<stdio.h>
    include<stdlib.h> struct BST
{
    int item;
    struct BST *llink, *rlink;
};
typedef struct BST *NODE;
NODE insert(NODE);
void inorder(NODE);
void preorder(NODE);
void postorder(NODE);
NODE search(NODE, int);
NODE Delete(NODE, int);
void main()
{
    int choice, key;
    NODE root = NULL, tmp, parent;
    while (1)
    {
        printf("\n1.Create");
        printf("\n2.Traverse the Tree in Preorder, Inorder, Postorder");
        printf("\n3.Search");
        printf("\n4.Delete an element from the Tree");
        printf("\n5.Exit");
        printf("\nEnter your choice :");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            root = insert(root);
            break;
        case 2:
            if (root == NULL)
                printf("Tree Is Not Created");
            else
            {
                printf("\nThe Inorder display : ");
                inorder(root);
                printf("\nThe Preorder display : ");
                preorder(root);
                printf("\nThe Postorder display : ");
                postorder(root);
            }
            break;
        case 3:
            printf("\nEnter Element to be searched :");
            scanf("%d", &key);
            tmp = search(root, key);
            if (tmp == NULL)
                printf("Element does not exists\n");
            else
                printf("\nThe element %d found", tmp->item);
            break;
        case 4:
            printf("\nEnter Element to be deleted :");
            scanf("%d", &key);
            root = Delete(root, key);
            break;
        default:
            exit(0);
        }
    }
}
/* This function is for creating a binary search tree */
NODE insert(NODE root)
{
    NODE temp, cur, prev;
    int item;
    printf("\nEnter The Element ");
    scanf("%d", &item);
    temp = (NODE)malloc(sizeof(struct BST));
    temp->llink = NULL;
    temp->rlink = NULL;
    temp->item = item;
    if (root == NULL)
        return temp;
    prev = NULL;
    cur = root;
    while (cur != NULL)
    {
        prev = cur;
        if (item < cur->item)
            cur = cur->llink;
        else
            cur = cur->rlink;
    }
    if (item < prev->item)
        prev->llink = temp;
    else
        prev->rlink = temp;
    return root;
}
/* This function displays the tree in inorder fashion */ void
inorder(NODE root)
{
    if (root != NULL)
    {
        inorder(root->llink);
        printf("%d\t", root->item);
        inorder(root->rlink);
    }
}
/* This function displays the tree in preorder fashion */
void preorder(NODE root)
{
    if (root != NULL)
    {
        printf("%d\t", root->item);
        preorder(root->llink);
        preorder(root->rlink);
    }
}
/* This function displays the tree in postorder fashion */
void postorder(NODE root)
{
    if (root != NULL)
    {
        postorder(root->llink);
        postorder(root->rlink);
        printf("%d\t", root->item);
    }
}
NODE search(NODE root, int key)
{
    NODE cur;
    if (root == NULL)
        return NULL;
    cur = root;
    while (cur != NULL)
    {
        if (key == cur->item)
            return cur;
        if (key < cur->item)
            cur = cur->llink;
        else
            cur = cur->rlink;
    }
    return NULL;
}
NODE Delete(NODE root, int item)
{
    NODE cur, parent = NULL, suc, q;
    if (root == NULL)
    {
        printf("Tree is empty,Element does not exists\n");
        return root;
    }
    cur = root;
    while (cur != NULL)
    {
        if (item == cur->item)
            break;
        parent = cur;
        cur = (item < cur->item) ? cur->llink : cur->rlink;
    }
    if (cur == NULL)
    {
        printf("Item not found\n");
        return root;
    }
    if (cur->llink == NULL)
        q = cur->rlink;
    else if (cur->rlink == NULL)
        q = cur->llink;
    else
    {
        suc = cur->rlink;
        while (suc->llink != NULL)
            suc = suc->llink;
        suc->llink = cur->llink;
        q = cur->rlink;
    }
    if (parent == NULL)
        return q;
    if (cur == parent->llink)
        parent->llink = q;
    else
        parent->rlink = q;
    free(cur);
    return root;
}