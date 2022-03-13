#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

// Macro definition
#define MAX 25

// Global variable
int stack[MAX];
int top = -1;

// Function declaration
void push(int item);
int pop();
void calculator(char op);

// Main function
void main()
{
    char post[MAX], symbol;
    int i, result;
    printf("Enter the Postfix Expression : ");
    scanf("%s", post);
    for (i = 0; i < strlen(post); i++)
    {
        symbol = post[i];

        if (symbol >= '0' && symbol <= '9')
        {
            push(symbol - '0');
        }
        if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == '^' || symbol == '%')
        {
            calculator(symbol);
        }
    }
    result = pop();
    printf("\nResult = %d\n", result);
}

// Push item into stack
void push(int item)
{
    stack[++top] = item;
}

// Pop item from stack
int pop()
{
    return stack[top--];
}

// Evaluate the expression
void calculator(char op)
{
    int a, b, ans;
    a = pop();
    b = pop();

    switch (op)
    {
    case '+':
        ans = b + a;
        break;
    case '-':
        ans = b - a;
        break;
    case '*':
        ans = b * a;
        break;
    case '/':
        ans = b / a;
        break;
    case '^':
        ans = pow(b, a);
        break;
    case '%':
        ans = b % a;
        break;
    }
    push(ans);
}