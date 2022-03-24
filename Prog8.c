#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    struct node *prev;
    int ssn;
    float sal;
    char name[20], dept[20], desg[20], phno[10];
    struct node *next;
};
typedef struct node *NODE;

// Global Variable
int count = 0;
NODE first, last, temp;

// Crate a node
void create()
{
    temp = (NODE)malloc(sizeof(struct node));
    printf("\nEnter the SSN, Name, Dept, Desg, Salary, Phone NO.\n");
    scanf("%d %s %s %s %f %s", &temp->ssn, temp->name, temp->dept, temp->desg, &temp->sal, temp->phno);
    temp->prev = NULL;
    temp->next = NULL;
    count++;
}

// Front Insertion
void insertfront()
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
        first->prev = temp;
        first = temp;
    }
}

// End Insertion
void insertend()
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
        temp->prev = last;
        last = temp;
    }
}

// Display the DLL from Front
void display()
{
    NODE cur;
    cur = first;
    if (first == NULL)
    {
        printf("\nLinked List Empty\n");
        return;
    }

    printf("\nLinked list elements form Begining\n\n");

    while (cur != NULL)
    {
        printf("|SSN : %d | Name : %s | Dept : %s | Designation : %s | Salary : %.2f | Phone NO. : %s |\n", cur->ssn, cur->name, cur->dept, cur->desg, cur->sal, cur->phno);
        cur = cur->next;
    }
    printf("\nNumber of Employees is %d\n", count);
}

// End Deletion
int deleteend()
{
    NODE temp;

    if (first == NULL)
    {
        printf("\nLinked List is Empty\n");
    }
    else
    {
        if (first->next == NULL)
        {
            printf("\n|SSN : %d | Name : %s | Dept : %s | Designation : %s | Salary : %.2f | Phone NO. : %s |\n", first->ssn, first->name, first->dept, first->desg, first->sal, first->phno);
            free(first);
            first = NULL;
        }
        else
        {
            temp = last->prev;
            temp->next = NULL;
            printf("\n|SSN : %d | Name : %s | Dept : %s | Designation : %s | Salary : %.2f | Phone NO. : %s |\n", last->ssn, last->name, last->dept, last->desg, last->sal, last->phno);
            free(last);
            last = temp;
        }
        count--;
    }
    return 0;
}

// Front Deletion
int deletefront()
{
    NODE temp;
    temp = first;

    if (first == NULL)
    {
        printf("\nLinked list is Empty\n");
    }
    else
    {
        if (first->next == NULL)
        {
            printf("\n|SSN : %d | Name : %s | Dept : %s | Designation : %s | Salary : %.2f | Phone NO. : %s |\n", first->ssn, first->name, first->dept, first->desg, first->sal, first->phno);
            free(first);
            first = NULL;
        }
        else
        {
            first = first->next;
            first->prev = NULL;
            printf("\n|SSN : %d | Name : %s | Dept : %s | Designation : %s | Salary : %.2f | Phone NO. : %s |\n", temp->ssn, temp->name, temp->dept, temp->desg, temp->sal, temp->phno);
            free(temp);
        }
        count--;
    }
    return 0;
}

// Double Ended Queue
void dequeue()
{
    int choice;
    while (1)
    {
        printf("\n~~~Demo Double Ended Queue Operation~~~\n");
        printf("1.Insert Queue Front \n2.Delete Queue Front\n");
        printf("3.Insert Queue Rear \n4.Delete Queue Rear\n");
        printf("5.Display \n6.Exit\n");
        printf("Enter your choice for DEQueue : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insertfront();
            break;
        case 2:
            deletefront();
            break;
        case 3:
            insertend();
            break;
        case 4:
            deletefront();
            break;
        case 5:
            display();
            break;
        default:
            return;
        }
    }
}

// Main Function
void main()
{
    int choice, i, n;
    while (1)
    {
        printf("\n\n----------------MENU------------------\n");
        printf("1.Create a DLL \n2.Display \n");
        printf("3.Insert at End \n4.Delete at End \n");
        printf("5.Insert at Front \n6.Delete at Front\n");
        printf("7.Double Ended Queue using DLL \n8.Exit\n");
        printf("--------------------------------------\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter No. of Employee : ");
            scanf("%d", &n);
            for (i = 0; i < n; i++)
                insertend();
            break;
        case 2:
            display();
            break;
        case 3:
            insertend();
            break;
        case 4:
            deleteend();
            break;
        case 5:
            insertfront();
            break;
        case 6:
            deletefront();
            break;
        case 7:
            dequeue();
            break;
        case 8:
            exit(0);
            break;
        default:
            printf("\nINVALID INPUT\n");
            break;
        }
    }
}