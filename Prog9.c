#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node
{
    int expo, coef;
    struct node *next;
} * NODE;

// Function declaration
NODE insert(NODE head, int expo, int coef);
NODE create();
NODE add(NODE p1, NODE p2);
int eval(NODE poly);
void display(NODE head);

// Function for insertion
NODE insert(NODE head, int expo, int coef)
{
    NODE poly, cur;
    poly = (NODE)malloc(sizeof(struct node));
    poly->expo = expo;
    poly->coef = coef;
    poly->next = NULL;

    if (head->next == head)
    {
        head->next = poly;
        poly->next = head;
        return (head);
    }

    if (expo > head->next->expo)
    {
        poly->next = head->next;
        head->next = poly;
        return (head);
    }

    if (expo == head->next->expo)
    {
        head->next->coef += coef;
        return (head);
    }

    cur = head->next;

    while (cur->next != head && expo <= cur->next->expo)
        cur = cur->next;

    if (poly->expo == cur->expo)
        cur->coef += coef;
    else
    {
        poly->next = cur->next;
        cur->next = poly;
    }
    return (head);
}

// Function to create poly
NODE create()
{
    int n, i, expo, coef;
    NODE head;
    head = (NODE)malloc(sizeof(struct node));
    head->next = head;
    printf("\n\nEnter NO. of terms of polynomial ==> ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("\n\nEnter coef & expo of poly %d ==> ", i + 1);
        scanf("%d %d", &coef, &expo);
        head = insert(head, expo, coef);
    }
    return (head);
}

// Function for addition of two Polynomial
NODE add(NODE p1, NODE p2)
{
    NODE poly;
    NODE head;
    head = (NODE)malloc(sizeof(struct node));
    head->next = head;
    printf("\n\nAddition of polynomial ==> ");

    poly = p1->next;

    do
    {
        head = insert(head, poly->expo, poly->coef);
        poly = poly->next;
    } while (poly != p1);

    poly = p2->next;
    do
    {
        head = insert(head, poly->expo, poly->coef);
        poly = poly->next;
    } while (poly != p2);

    return (head);
}

// Function for evaluation of polynomial
int eval(NODE head)
{
    NODE poly;
    int x, ans = 0;
    printf("\n\nEnter the value of x = ");
    scanf("%d", &x);
    poly = head->next;
    do
    {
        ans += poly->coef * pow(x, poly->expo);
        poly = poly->next;
    } while (poly != head);

    return ans;
}

// Function for display
void display(NODE head)
{
    NODE poly, cur;
    poly = head->next;
    printf("\n\n\tThe polynomial is ==> ");

    do
    {
        printf("%dx^(%d)", poly->coef, poly->expo);
        poly = poly->next;
        if (poly != head)
            printf("+");
    } while (poly != head);
}

// Main Function
void main()
{
    int ans, choice, done = 0;
    NODE poly, poly1, poly2, poly3;
    poly1 = poly2 = poly3 = NULL;

    do
    {
        printf("\n\t----------------<< MENU >>---------------");
        printf("\n\tPolynomial Operations :");
        printf(" 1.Add");
        printf("\n\t\t\t\t2.Evaluate");
        printf("\n\t\t\t\t3.Exit");
        printf("\n\t-------------------------------------------");
        printf("\n\n\n\tEnter your choice ==> ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            poly1 = create();
            display(poly1);
            poly2 = create();
            display(poly2);
            poly3 = add(poly1, poly2);
            display(poly3);
            break;
        case 2:
            poly = create();
            display(poly);
            ans = eval(poly);
            printf("\n\nValue of polynomial = %d", ans);
            break;
        case 3:
            exit(0);
            break;
        default:
            printf("\n\n\tINVALID INPUT");
            break;
        }
        printf("\n\n\nDo you want to continue, Enter 1 : ");
        scanf("%d", &done);
    } while (done == 1);
}