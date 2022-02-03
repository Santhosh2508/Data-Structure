#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int front = -1, rear = -1, choice, item, Q[MAX];
void enqueue(int x)
{
    if (rear == MAX - 1)
    {
        printf("\nQueue is Overflow\n");
    }
    else if (rear == -1 && front == -1)
    {
        front = rear = 0;
        Q[rear] = x;
    }
    else
    {
        Q[++rear] = x;
    }
}
void dequeue(void)
{
    if (rear == -1 && front == -1)
    {
        printf("\nQueue is underflow\n");
    }
    else if (front == rear)
    {
        printf("\nThe deleted element is %d\n", Q[front]);
        front = rear = -1;
    }
    else
    {
        printf("\nThe deleted element is %d\n", Q[front]);
        Q[front++];
    }
}
void display(void)
{
    int i;
    if (front == -1 && rear == -1)
    {
        printf("\nQueue is Empty\n");
    }
    else
    {
        printf("\nThe content of Queue are:\n");
        for (i = front; i <= rear; i++)
        {
            printf("%d\t", Q[i]);
        }
        printf("\n\n");
    }
}
int main(void)
{
    while (1)
    {
        printf("\n1.Enqueue \n2.Dequeue \n3.Display \n4.Exit\n");
        printf("\nEnter your choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the Element to be Inserted\n");
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