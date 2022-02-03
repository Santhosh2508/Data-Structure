#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int front = -1, rear = -1, item, Queue[MAX];
void enqueue(int x)
{
    if (((rear + 1) % MAX) == front)
    {
        printf("\nQueue is overflow\n");
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        Queue[rear] = x;
    }
    else
    {
        rear = (rear + 1) % MAX;
        Queue[rear] = x;
    }
}
void dequeue(void)
{
    if (front == -1 && rear == -1)
    {
        printf("\nQueue is Overflow\n");
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
void display(void)
{
    int i = front;
    if (front == -1 && rear == -1)
    {
        printf("\nQueue is Overflow\n");
    }
    else
    {
        printf("\nQueue is :\n");
        while (i != rear)
        {
            printf("%d\t", Queue[i]);
            i = (i + 1) % MAX;
        }
        printf("%d\n", Queue[i]);
        printf("\nRear is at %d\n", Queue[rear]);
        printf("Front is at %d\n", Queue[front]);
    }
    printf("\n\n");
}
int main(void)
{
    int choice;
    while (1)
    {
        printf("\n1.Enqueue \n2.Dequeue \n3.Display \n4.Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\n\nEnter the Element to be Inserted\n");
            scanf("%d", &item);
            enqueue(item);
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