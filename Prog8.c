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
} * head, *temp, *last;

void create()
{
    int ssn, phno;
    float sal;
    char name[20], dept[20], desg[20];
    temp = (struct node *)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->next = NULL;
    printf("\nEnter the SSN, Name, Dept, Desg, Salary, phone no.\n");
    scanf("%d %s %s %s %f %d", &ssn, name, dept, desg, &sal, &phno);
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
    if (head == NULL)
    {
        create();
        head = temp;
        last = head;
    }
    else
    {
        create();
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insertend()
{
    if (head == NULL)
    {
        create();
        head = temp;
        last = head;
    }
    else
    {
        create();
        last->next = temp;
        temp->prev = last;
        last = temp;
    }
}

void displaybeg()
{
    struct node *temp;
    temp = head;
    if (temp == NULL)
    {
        printf("\nList Empty\n");
        return;
    }
    printf("\nLinked list from begining\n");
    while (temp != NULL)
    {
        printf("%d %s %s %s %f %d\n", temp->ssn, temp->name, temp->dept, temp->desg, temp->sal, temp->phno);
        temp = temp->next;
    }
    printf("\nNumber of employees is %d\n", count);
}

int deleteend()
{
    struct node *temp;
    temp = head;
    if (temp->next == NULL)
    {
        free(temp);
        head = NULL;
    }
    else
    {
        temp = last->prev;
        temp->next = NULL;
        printf("\n%d %s %s %s %f %d\n", last->ssn, last->name, last->dept, last->desg, last->sal, last->phno);
        free(last);
    }
    count--;
    return 0;
}

int deletebeg()
{
    struct node *temp;
    temp = head;
    if (temp->next == NULL)
    {
        free(temp);
        head = NULL;
    }
    else
    {
        head = head->next;
        printf("\n%d %s %s %s %f %d\n", temp->ssn, temp->name, temp->dept, temp->desg, temp->sal, temp->phno);
        free(temp);
    }
    count--;
    return 0;
}

void main()
{
    int choice, n, i;
    head = NULL;
    temp = last = NULL;
    while (1)
    {
        printf("\n\n----------------MENU------------------\n");
        printf("1.Create a DLL \n2.Display from begining\n");
        printf("3.Insert at end \n4.Delete at end \n5.Insert at beg \n6.Delete at beg\n");
        printf("7.Exit\n--------------------------------------\n\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter no. of Employees : ");
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
            printf("\nINVALID INPUT\n");
            break;
        }
    }
}
