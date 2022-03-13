#include <stdio.h>
#include <stdlib.h>

// Macro definition
#define MAX 5

// Global variable
int front = -1, rear = -1, Queue[MAX];

// Insert item into Queue
void enqueue()
{
    int item;
    if ((rear + 1) % MAX == front)
    {
        printf("\nCircular Queue is Overflow\n");
    }
    else
    {
        printf("\nEnter the Element to be Inserted : ");
        scanf("%d", &item);

        if (front == -1 && rear == -1)
        {
            front = rear = 0;
            Queue[rear] = item;
        }
        else
        {
            rear = (rear + 1) % MAX;
            Queue[rear] = item;
        }
    }
}

// Delete item from Queue
void dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("\nCircular Queue is Underflow\n");
    }
    else if (front == rear)
    {
        printf("\nThe deleted Element is %d\n", Queue[front]);
        front = rear = -1;
    }
    else
    {
        printf("\nThe Deleted Element is %d\n", Queue[front]);
        front = (front + 1) % MAX;
    }
}

// Display Queue Element
void display()
{
    int i = front;
    if (front == -1 && rear == -1)
    {
        printf("\nCircular Queue is Underflow\n");
    }
    else
    {
        printf("\nCircular Queue contents are : \n");
        printf("Front[%d]-> ", front);
        while (i != rear)
        {
            printf("%d\t", Queue[i]);
            i = (i + 1) % MAX;
        }
        printf("%d", Queue[i]);
        printf(" <-Rear[%d]\n", rear);
    }
}

// Main function
int main()
{
    int choice;
    while (1)
    {
        printf("\n\n~~Main Menu~~\n");
        printf("1.Enqueue \n2.Dequeue \n3.Display \n4.Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\nInvalid Choice\n");
            break;
        }
    }
    return 0;
}