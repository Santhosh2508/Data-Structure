#include <stdio.h>
#include <stdlib.h>
//Global Variable
int array[10];
int n, ELEM, POS, i;
//Function prototype
void create();
void display();
void insert();
void delete ();
//Main function
void main()
{
    int choice;
    while (1)
    {
        printf("\n\n----MENU----\n");
        printf("1.CREATE \n2.DISPLAY \n3.INSERT \n4.DELETE \n5.EXIT");
        printf("\n----------\n");
        printf("\nENTER YOUR CHOICE: ");
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
            printf("\nINVALID CHOICE\n");
            break;
        }
    }
}

//Creating an Array
void create()
{
    printf("\nEnter the size of the array element : ");
    scanf("%d", &n);
    printf("\nEnter the elements of the array: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
}

//Display Array Elements
void display()
{
    printf("\nThe array elements are : ");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", array[i]);
    }
}

//Insert an element into Array
void insert()
{
    printf("\nEnter the position for the new element:  ");
    scanf("%d", &POS);
    printf("\nEnter the element to be inserted :  ");
    scanf("%d", &ELEM);
    for (i = n - 1; i >= POS - 1; i--)
    {
        array[i + 1] = array[i];
    }
    array[POS - 1] = ELEM;
    n++;
}

//Delete an element from Array
void delete ()
{
    printf("\nEnter the position of the element to be deleted:  ");
    scanf("%d", &POS);
    ELEM = array[POS - 1];
    for (i = POS - 1; i < n - 1; i++)
    {
        array[i] = array[i + 1];
    }
    n--;
    printf("\nThe deleted element is : %d\n", ELEM);
}