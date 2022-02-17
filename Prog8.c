#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int count = 0;
struct node
{
    struct node *prev;
    int ssn, phno;
    float sal;
    char name[20], dept[20], desg[20];
    struct node *next;
} * h, *temp, *temp1, *temp2, *temp4;
void create()
{
    int ssn, phno;
    float sal;
    char name[20], dept[20], desg[20];
    temp = (struct node *)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->next = NULL;
    printf("\nEnter the ssn,name,dept,desg,salary,phno\n");
    scanf("%d%s%s%s%f%d", &ssn, name, dept, desg, &sal, &phno);
    temp->ssn = ssn;
    strcpy(temp->name, name);
    strcpy(temp->dept, dept);
    strcpy(temp->desg, desg);
    temp->sal = sal;
    temp->phno = phno;
    count++;
}
void insertbeg()
{
    if (h == NULL)
    {
        create();
        h = temp;
        temp1 = h;
    }
    else
    {
        create();
        temp->next = h;
        h->prev = temp;
        h = temp;
    }
}
void insertend()
{
    if (h == NULL)
    {
        create();
        h = temp;
        temp1 = h;
    }
    else
    {
        create();
        temp1->next = temp;
        temp->prev = temp1;
        temp1 = temp;
    }
}
void displaybeg()
{
    temp2 = h;
    if (temp2 == NULL)
    {
        printf("\nlist empty\n");
        return;
    }
    printf("\nlinked list from begining\n");
    while (temp2 != NULL)
    {
        printf("%d %s %s %s %f %d\n", temp2->ssn, temp2->name, temp2->dept, temp2->desg, temp2->sal, temp2->phno);
        temp2 = temp2->next;
    }
    printf("\nnumber of employees is %d\n", count);
}
int deleteend()
{
    struct node *temp;
    temp = h;
    if (temp->next == NULL)
    {
        free(temp);
        h = NULL;
        return 0;
    }
    else
    {
        temp2 = temp1->prev;
        temp2->next = NULL;
        printf("\n%d %s %s %s %f %d\n", temp1->ssn, temp1->name, temp1->dept, temp1->desg, temp1->sal, temp1->phno);
        free(temp1);
    }
    count--;
    return 0;
}
int deletebeg()
{
    struct node *temp;
    temp = h;
    if (temp->next == NULL)
    {
        free(temp);
        h = NULL;
    }
    else
    {
        h = h->next;
        printf("\n%d %s %s %s %f %d\n", temp->ssn, temp->name, temp->dept, temp->desg, temp->sal, temp->phno);
        free(temp);
    }
    count--;
    return 0;
}
void main()
{
    int ch, n, i;
    h = NULL;
    temp = temp1 = NULL;
    while (1)
    {
        printf("\n\n----------------MENU------------------\n1.create a DLL\n2.display frombegining\n");
        printf("3.insert at end\n4.delete at end\n5.insert at beg\n6.delete atbeg\n");
        printf("7.exit\n--------------------------------------\n\nEnter your choice\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter no.of employees\n");
            scanf("%d", &n);
            for (i = 0; i < n; i++)
                insertend();
            break;
        case 2:
            displaybeg();
            break;
        case 3:
            insertend();
            break;
        case 4:
            deleteend();
            break;
        case 5:
            insertbeg();
            break;
        case 6:
            deletebeg();
            break;
        case 7:
            exit(0);
            break;
        default:
            printf("\ninvalid input\n");
            break;
        }
    }
}
