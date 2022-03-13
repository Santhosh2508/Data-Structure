#include <stdio.h>
#include <stdlib.h>

// Macro Defination
#define MAX 5

// Global variable
int stack[MAX], top = -1;

// Function prototype
void push();
int pop();
void display();
void palindrome();

// Main Function
void main()
{
    int choice, item;

    while (1)
    {
        printf("\n----------------STACK OPERATIONS---------------\n");
        printf("1.PUSH\n");
        printf("2.POP\n");
        printf("3.PALINDROME\n");
        printf("4.DISPLAY\n");
        printf("5.EXIT\n");
        printf("-----------------------------------------------");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            item = pop();
            if (item != -1)
            {
                printf("\nThe item popped is %d \n", item);
            }
            break;
        case 3:
            if (top == -1)
            {
                printf("\nStack Underflow\n");
            }
            else
            {
                palindrome();
            }
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("\nINVALID CHOICE\n");
            break;
        }
    }
}

// Push item into Stack
void push()
{
    int item;
    if (top == MAX - 1)
    {
        printf("\nStack Overflow\n");
    }
    else
    {
        printf("\nEnter the item to be pushed: ");
        scanf("%d", &item);
        stack[++top] = item;
    }
}

// Pop item from Stack
int pop()
{
    if (top == -1)
    {
        printf("\nStack Underflow\n");
        return -1;
    }
    else
    {
        return stack[top--];
    }
}

// Display the Stack item
void display()
{
    int i;
    if (top == -1)
    {
        printf("\nStack Underflow\n");
    }
    else
    {
        printf("\nThe stack elements are : \n");
        for (i = top; i >= 0; i--)
        {
            printf("| %d |\n", stack[i]);
        }
    }
}

// Checking for Palindrome for Stack Item
void palindrome()
{
    int flag = 1, i;
    printf("\nStack content are: \n");
    for (i = top; i >= 0; i--)
    {
        printf("| %d |\n", stack[i]);
    }
    printf("\nReverse of stack content are: \n");
    for (i = 0; i <= top; i++)
    {
        printf("| %d |\n", stack[i]);
    }
    for (i = 0; i <= top / 2; i++)
    {
        if (stack[i] != stack[top - i])
        {
            flag = 0;
            break;
        }
    }
    if (flag == 1)
    {
        printf("\nIt is palindrome\n");
    }
    else
    {
        printf("\nIt is not palindrome\n");
    }
}
