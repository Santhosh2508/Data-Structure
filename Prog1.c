#include <stdio.h>
#include <stdlib.h>
int a[20];
int n, val, pos, i;
/*fuction prototype*/
void create();
void display();
void insert();
void delete ();
/*main fuction*/
void main()
{
    int choice = 1;
    while (choice)
    {
        printf("\n\n------------------------MENU------------------------\n");
        printf("1.CREATE\n");
        printf("2.DISPLAY\n");
        printf("3.INSERT\n");
        printf("4.DELETE\n");
        printf("5.EXIT\n");
        printf("-----------------------------------------------------------");
        printf("\n ENTER YOUR CHOICE: \t");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            insert();
            break;
        case 4:
            delete ();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("INVALID ENTRY");
            break;
        }
    }
}
//Creating an array
void create()
{
    printf("\nEnter the size of the array element: \t");
    scanf("%d", &n);
    printf("\nEnter the elments of the array: \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    display();
}
//Display the array elements
void display()
{
    printf("\nThe array elements are : \n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
}
//Inserting an element into the array
void insert()
{
    printf("\nEnter the position for the new element: \t");
    scanf("%d", &pos);
    printf("\nEnter the element to be inserted: \t");
    scanf("%d", &val);
    for (i = n - 1; i >= pos; i--)
    {
        a[i + 1] = a[i];
    }
    a[pos] = val;
    n = n + 1;
    display();
}
//Deleting elements of array
void delete ()
{
    printf("\nEnter the position of the element to be deleted: \t");
    scanf("%d", &pos);
    val = a[pos];
    for (i = pos; i < n - 1; i++)
    {
        a[i] = a[i + 1];
    }
    n = n - 1;
    printf("\nThe deleted element is : %d", val);
    display();
}
