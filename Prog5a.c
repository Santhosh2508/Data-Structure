#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define MAX 50
int stack[MAX];
char post[MAX];
int top = -1;

void pushstack(int temp);
void calculator(char c);

void main()
{
    int i;
    printf("Enter the Postfix Expression\n");
    scanf("%s", post);
    for (i = 0; i < strlen(post); i++)
    {
        if(post[i]>='0'&&post[i]<='9')
        {
            pushstack(i);
        }
        if (post[i] == '+' || post[i] == '-' || post[i] == '*' || post[i] == '/' || post[i] == '^')
        {
            calculator(post[i]);
        }
    }
    printf("\nResult = %d\n", stack[top]);
}

void pushstack(int temp)
{
    top++;
    stack[top] = (int)(post[temp] - 48);
}

void calculator(char c)
{
    int a, b, ans;
    a = stack[top];
    stack[top] = '\0';
    top--;
    b = stack[top];
    stack[top] = '\0';
    top--;
    switch (c)
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
    default:
        ans = 0;
        break;
    }
    top++;
    stack[top] = ans;
}