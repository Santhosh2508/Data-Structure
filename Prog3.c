#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_size 5

int stack[max_size], top = -1, flag = 1;
int i, temp, item, rev[max_size], num[max_size];

void push();
void pop();
void display();
void pali();

int main()
{
    int choice;
    printf("\n-----------------------STACK OPERATIONS-----------------------\n");
    printf("1.PUSH\n");
    printf("2.POP\n");
    printf("3.PALINDROME\n");
    printf("4.DISPLAY\n");
    printf("5.EXIT\n");
    printf("-----------------------------------------------------------------------");

    while (1)
    {
        printf("\nEnter your choice:\t");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push();
            flag = 1;
            break;
        case 2:
            pop();
            if (flag)
                printf("\nThe popped element is : %d\n", item);
            temp = top;
            break;
        case 3:
            pali();
            top = temp;
            break;
        case 4:
            display();
            break;
        case 5:
            return 0;
            break;

        default:
            break;
        }
    }
}

void push()
{
    if (top == max_size - 1)
    {
        printf("\nStack Overflow\n");
    }
    else
    {
        printf("\nEnter the element to be inserted :\t");
        scanf("%d", &item);
        top = top + 1;
        stack[top] = item;
    }
    temp = top;
}

void pop()
{
    if (top == -1)
    {
        printf("\nStack underflow\n");
        flag = 0;
    }
    else
    {
        item = stack[top];
        top = top - 1;
    }
}

void pali()
{
    i = 0;
    int check = 0;
    if (top == -1)
    {
        printf("\nPush some elements into the stack first\n");
    }
    else
    {
        while (top != -1)
        {
            rev[top] = stack[top];
            pop();
        }
        top = temp;
        for (i = 0; i <= temp; i++)
        {
            if (stack[top--] == rev[i])
            {
                if (i == temp)
                {
                    printf("\nPalindrome\n");
                    check = 1;
                }
            }
        }
        if (check == 0)
        {
            printf("\nNot palindrome\n");
        }
    }
}

void display()
{
    int i;
    top = temp;
    if (top == -1)
    {
        printf("\nStack is empty\n");
    }
    else
    {
        printf("\nThe stack elements are : \n");
        for (i = top; i >= 0; i--)
        {
            printf("%d\t", stack[i]);
        }
    }
}