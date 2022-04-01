#include <stdio.h>
#include <stdlib.h>

// Macro definition
#define MAX 5

struct employee
{
    int id, age;
    char name[25];
} emp[MAX];

// Function declaration
int hash(int key);

// Main function
void main()
{
    int i, choice, count = 0, index, key, ID, flag = 0;
    while (1)
    {
        printf("\nEnter : 1.Insert record\n");
        printf("\t2.Search record\n");
        printf("\t3.Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if (count == MAX)
            {
                printf("\nThe Hash Table is Full\n");
                break;
            }
            printf("\nEnter the Employee ID   : ");
            scanf("%d", &ID);
            key = hash(ID);
            printf("Home Address is  : %d ", key);
            for (i = 0; i < MAX; i++)
            {
                index = (key + i) % MAX;
                if (emp[index].id == 0)
                {
                    emp[index].id = ID;
                    printf("\nEnter the Employee Name : ");
                    scanf("%s", emp[index].name);
                    printf("Enter the Employee Age  : ");
                    scanf("%d", &emp[index].age);
                    count++;
                    printf("\nSuccesfully inserted at Actual Adrress  : %d\n", index);
                    break;
                }
            }
            break;
        case 2:
            printf("\nEnter Employee ID to be Searched : ");
            scanf("%d", &ID);
            key = hash(ID);
            for (i = 0; i < MAX; i++)
            {
                index = (key + i) % MAX;
                if (emp[index].id == 0)
                {
                    flag = 1;
                    break;
                }
                else if (emp[index].id == ID)
                {
                    printf("\nEmployee ID   : %d\n", emp[index].id);
                    printf("Employee Name : %s\n", emp[index].name);
                    printf("Employee Age  : %d\n", emp[index].age);
                    printf("\nSearch Length is : %d \n", i + 1);
                    break;
                }
            }
            if (flag == 1 || i == MAX)
            {
                printf("\nID not present\n");
            }
            break;
        case 3:
            return;
        default:
            printf("\nINVALID CHOICE\n");
        }
    }
}

// Function for Division Method Hash Function
int hash(int key)
{
    return key % MAX;
}