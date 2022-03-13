#include <stdio.h>

// Global Varible
char stack[25];
int top = -1;

// Function Prototype
void infix_to_postfix(char infix[25], char postfix[25]);
void push(char symbol);
char pop();
int precd(char op);

// Main Function
void main()
{
    char infix[25], postfix[25];
    printf("Enter infix Expression : ");
    scanf("%s", infix);
    infix_to_postfix(infix, postfix);
    printf("Postfix Expression :  %s\n", postfix);
}

// Push symbol into Stack
void push(char symbol)
{
    stack[++top] = symbol;
}

// Pop item from stack
char pop()
{
    return stack[top--];
}

// Operators Precedence
int precd(char op)
{
    int p;
    switch (op)
    {
    case '^':
        p = 3;
        break;
    case '*':
    case '/':
    case '%':
        p = 2;
        break;
    case '+':
    case '-':
        p = 1;
        break;
    case '(':
        p = 0;
        break;
    case '#':
        p = -1;
        break;
    }
    return p;
}

// Convertion of infix to postfix Function
void infix_to_postfix(char infix[25], char postfix[25])
{
    int i, pos = 0;
    char symbol, item;
    push('#');
    for (i = 0; infix[i] != '\0'; i++)
    {
        symbol = infix[i];
        switch (symbol)
        {
        case '(':
            push(symbol);
            break;
        case ')':
            item = pop();
            while (item != '(')
            {
                postfix[pos++] = item;
                item = pop();
            }
            break;
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
        case '^':
            while (precd(stack[top]) >= precd(symbol))
            {
                item = pop();
                postfix[pos++] = item;
            }
            push(symbol);
            break;
        default:
            postfix[pos++] = symbol;
            break;
        }
    }

    while (top > 0)
    {
        item = pop();
        postfix[pos++] = item;
    }
    postfix[pos] = '\0';
}