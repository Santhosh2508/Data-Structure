#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int count = 0;
struct node
{
    int sem;
    char
        name[20],
        branch[20], usn[20], phno[10];
    struct node *next;
}
    *first = NULL,
    *last = NULL, *temp = NULL, *temp1;
void create()
{
    int sem;
    char name[20], branch[20], usn[20], phno[10];
    temp = (struct node *)malloc(sizeof(struct node));
    printf("enter usn name branch sem phno of student\n");
    scanf("%s%s%s%d%s", usn, name, branch, &sem, &phno);
    strcpy(temp->usn, usn);
    strcpy(temp->name, name);
    strcpy(temp->branch, branch);
    temp->sem = sem;
    strcpy(temp->phno, phno);
    temp->next = NULL;
    count++;
}
void insert_atfirst()
{
    if (first == NULL)
    {
        create();
        first = temp;
        last = first;
    }
    else
    {
        create();
        temp->next = first;
        first = temp;
    }
}
void insert_atlast()
{
    if (first == NULL)
    {
        create();
        first = temp;
        last = first;
    }
    else
    {
        create();
        last->next = temp;
        last = temp;
    }
}
void display()
{
    temp1 = first;
    if (temp1 == NULL)
    {
        printf("list empty\n");
        return;
    }
    printf("linked list elements from begining\n");
    while (temp1 != NULL)
    {
        printf("%s %s %s %d %s\n", temp1->usn, temp1 -> name, temp1->branch, temp1->sem, temp1 -> phno);
        temp1 = temp1->next;
    }
    printf("no.of students is %d\n", count);
}
int deleteend()
{
    struct node *temp;
    temp = first;
    if (temp->next == NULL)
    {
        free(temp);
        first = NULL;
    }
    else
    {
        while (temp->next != last)
            temp = temp->next;
        printf("%s %s %s %d %s\n", last->usn, last->name, last->branch,
               last->sem, last->phno);
        free(last);
        temp->next = NULL;
        last = temp;
    }
    count--;
    return 0;
}
int deletefront()
{
    struct node *temp;
    temp = first;
    if (temp->next == NULL)
    {
        free(temp);
        first = NULL;
        return 0;
    }
    else
    {
        first = temp->next;
        printf("%s %s %s %d %s\n", temp->usn, temp -> name, temp->branch, temp->sem, temp -> phno);
        free(temp);
    }
    count--;
    return 0;
}
void main()
{
    int ch, n, i;
    first = NULL;
    temp = temp1 = NULL;
    while (1)
    {
        printf("---------------------MENU-------------------\n1.create a SLL\n");
        printf("2.display\n3.insert at end\n4.delete at end\n5.insert at beg\n");
        printf("6.delete at beg\n7.exit\n----------------------------------------\n");
        printf("enter ur choice\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("enter number of students\n");
            scanf("%d", &n);
            for (i = 0; i < n; i++)
                insert_atfirst();
            break;
        case 2:
            display();
            break;
        case 3:
            insert_atlast();
            break;
        case 4:
            deleteend();
            break;
        case 5:
            insert_atfirst();
            break;
        case 6:
            deletefront();
            break;
        case 7:
            exit(0);
            break;
        default:
            printf("invalid input\n");
            break;
        }
    }
}
