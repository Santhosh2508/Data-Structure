#include <stdio.h>

char a[25];
int top = -1;
void infix_postfix(char infix[25], char postfix[25]);
void push(char symbol);
int precd(char op);

void push(char symbol)
{
    a[++top] = symbol;
}

char pop()
{
    char item;
    item = a[top--];
    return (item);
}

int precd(char op)
{
    int r;
    switch (op)
    {
    case '^':
        r = 3;
        break;
    case '*':
    case '/':
        r = 2;
        break;
    case '%':
    case '+':
    case '-':
        r = 1;
        break;
    case '(':
        r = 0;
        break;
    case '#':
        r = -1;
        break;
    }
    return (r);
}

void infix_postfix(char infix[25], char postfix[25])
{
    int i, p = 0;
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
                postfix[p++] = item;
                item = pop();
            }
            break;
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
        case '%':
            while (precd(a[top]) >= precd(symbol))
            {
                item = pop();
                postfix[p++] = item;
            }
            push(symbol);
            break;
        default:
            postfix[p++] = symbol;
            break;
        }
    }
    while (top > 0)
    {
        item = pop();
        postfix[p++] = item;
    }
    postfix[p] = '\0';
}

void main()
{
    char infix[25], postfix[25];
    printf("Enter infix expression\n");
    scanf("%s", infix);
    infix_postfix(infix, postfix);
    printf("Postfix Expression : %s\n", postfix);
}