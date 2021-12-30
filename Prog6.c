#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int q[10], front = 0, rear = -1;
void insert()
{
    int x;
    if ((front == 0 && rear == MAX - 1) || (front > 0 && rear == front - 1))
        printf("\nQueue overflow\n");
    else
        printf("\nEnter element to be inserted\n");
    scanf("%d", &x);
    if (rear == MAX - 1 && front > 0)
    {
        rear = 0;
        q[rear] = x;
    }
    else
    {
        if ((front == 0 && rear == -1) || (rear != front - 1))
            q[++rear] = x;
    }
}
void delet()
{
    int a;
    if ((front == 0) && (rear == -1))
    {
        printf("\nQueue is underflow\n");
        exit(0);
    }
    if (front == rear)
    {
        a = q[front];
        rear = -1;
        front = 0;
    }
    else if (front == MAX - 1)
    {
        a = q[front];
        front = 0;
    }
    else
        a = q[front++];
    printf("\nDeleted item is %d\n", a);
}
void display()
{
    int i, j;
    if (front == 0 && rear == -1)
    {
        exit(0);
    }
    if (front > rear)
    {
        for (i = 0; i <= rear; i++)
        {
            printf("%d\t", q[i]);
        }
        for (j = front; j < MAX - 1; j++)
        {
            printf("%d\t", q[j]);
        }
        printf("\nRear is at  %d\n", q[rear]);
        printf("Front is at  %d\n", q[front]);
    }
    else
    {
        for (i = front; i <= rear; i++)
        {
            printf("%d\t", q[i]);
        }
        printf("\nRear is at  %d\n", q[rear]);
        printf("Front is at  %d\n", q[front]);
    }
}
void main()
{
    int ch;
    while (1)
    {
        printf("\n1.Insert \n2.Delete \n3.Display \n4.Exit \nEnter your choice\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert();
            break;
        case 2:
            delet();
            break;
        case 3:
            printf("\nThe elements are\n");
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\nInvalid input\n");
            break;
        }
    }
}
