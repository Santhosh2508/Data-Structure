#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char name[25], branch[3], usn[10], sem, phno[10];
    struct node *next;
};
typedef struct node *NODE;

// Global variable
int count = 0;
NODE first = NULL, last = NULL, temp = NULL;

// Create a Node
void create()
{
    temp = (NODE)malloc(sizeof(struct node));
    printf("\nEner the USN, Name, Branch, Sem, Phone No. of the Student : \n");
    scanf("%s %s %s %c %s", temp->usn, temp->name, temp->branch, &temp->sem, temp->phno);
    temp->next = NULL;
    count++;
}

// Front insertion
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
        first = temp;
    }
}

// End insertion
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
        last = temp;
    }
}

// Display the SLL from front
void display()
{
    NODE cur = first;
    int num = 1;

    if (first == NULL)
    {
        printf("\nLinked List Empty\n");
        return;
    }

    printf("\nLinked List elements from Begining\n");

    while (cur != NULL)
    {
        printf("\n||%d| USN : %s | Name : %s | Branch : %s | Sem : %c | Phone No. : %s |\n", num, cur->usn, cur->name, cur->branch, cur->sem, cur->phno);
        cur = cur->next;
        num++;
    }

    printf("\nNo. of Students : %d\n", count);
}

// End delete
int deleteend()
{
    NODE cur = first;

    if (first == NULL)
    {
        printf("\nLinked List is Empty\n");
    }
    else
    {
        if (first->next == NULL)
        {
            printf("\n| USN : %s | Name : %s | Branch : %s | Sem : %c | Phone No. : %s |\n", temp->usn, temp->name, temp->branch, temp->sem, temp->phno);
            free(first);
            first = NULL;
        }
        else
        {
            while (cur->next != last)
                cur = cur->next;

            printf("\n| USN : %s | Name : %s | Branch : %s | Sem : %c | Phone No. : %s |\n", last->usn, last->name, last->branch, last->sem, last->phno);
            free(last);
            cur->next = NULL;
            last = cur;
        }
        count--;
    }
    return 0;
}

// Front delete
int deletefront()
{
    NODE temp = first;

    if (first == NULL)
    {
        printf("\nLinked List is Empty\n");
    }
    else
    {
        printf("\n| USN : %s | Name : %s | Branch : %s | Sem : %c | Phone No. : %s |\n", temp->usn, temp->name, temp->branch, temp->sem, temp->phno);
        first = temp->next;
        free(temp);
        count--;
    }
    return 0;
}

// Demonstration of Stack
void stackdemo()
{
    int choice;
    while (1)
    {
        printf("\n~~~Stack Demo using SLL~~~\n");
        printf("1.Push Operation \n2.Pop operation \n3.Display \n4.Exit\n");
        printf("Enter your choice for Stack demo : ");
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
            display();
            break;
        default:
            return;
        }
    }
    return;
}

// Main function
void main()
{
    int choice, n, i;

    while (1)
    {
        printf("\n-------------------MENU-------------------\n");
        printf("1.Create a SLL\n");
        printf("2.Display\n");
        printf("3.Insert At End\n");
        printf("4.Delete At End\n");
        printf("5.Stack Demo using SLL(Insertion and Deletion at Front)\n");
        printf("6.Exit");
        printf("\n------------------------------------------\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter number of Students : ");
            scanf("%d", &n);
            for (i = 0; i < n; i++)
            {
                insertend();
            }
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
            stackdemo();
            break;
        case 6:
            return;
            break;
        default:
            printf("\nINVALID INPUT\n");
            break;
        }
    }
}
