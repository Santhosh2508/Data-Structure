#include <stdio.h>
#include <stdlib.h>
#define QUE_SIZE 5
int choice, item, front, rear, Q[10];

void insert_rear()
{
    if (rear == QUE_SIZE - 1)
    {
        printf("Queue overflow\n");
        return;
    }
    Q[++rear] = item;
}

int delete_front()
{
    if (front > rear)
        return -1;
    return Q[front++];
}

void display()
{
    int i;
    if (front > rear)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("contents of the Queue\n");
    for (i = front; i <= rear; i++)
    {
        printf("%d\t", Q[i]);
    }
    printf("\n");
}

void main()
{
    front = 0;
    rear = -1;
    for (;;)
    {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.exit\n");
        printf("\nEnter your choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the item to be inserted\n");
            scanf("%d", &item);
            insert_rear();
            break;
        case 2:
            item = delete_front();
            if (item == -1)
                printf("Queue is empty\n");
            else
                printf("Item deleted is = %d\n", item);
            break;
        case 3:
            display();
            break;
        default:
            exit(0);
        }
    }
}