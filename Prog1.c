#include <stdio.h>
#include <stdlib.h>

// Global Variable
int array[10];
int n, ELEM, POS, i;

// Function prototype
void display();
void insert();
void delete();

// Main function
void main()
{
    int choice;
    printf("\nEnter the size of the array element : ");
    scanf("%d", &n);
    printf("\nEnter the elements of the array: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
    while (1)
    {
        printf("\n\n----MENU----\n");
        printf("1.DISPLAY \n2.INSERT \n3.DELETE \n4.EXIT");
        printf("\n----------\n");
        printf("\nENTER YOUR CHOICE: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            display();
            break;
        case 2:
            insert();
            break;
        case 3:
            delete();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\nINVALID CHOICE\n");
            break;
        }
    }
}

// Display Array Elements
void display()
{
    printf("\nThe array elements are : ");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", array[i]);
    }
}

// Insert an element into Array
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

// Delete an element from Array
void delete()
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