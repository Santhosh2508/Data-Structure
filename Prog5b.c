#include <stdio.h>

// Global variable
int count = 0;

// Function declaration
void tower(int, char, char, char);

// Main function
int main()
{
    int n;
    printf("Enter the number of disk : ");
    scanf("%d", &n);
    printf("\nThe Sequence of moves involved in the Tower of Hanoi are : \n");
    tower(n, 'A', 'C', 'B');
    printf("\nThe Number of Moves : %d\n", count);
    return 0;
}

// Tower of Hanoi recursive function
void tower(int n, char from_peg, char to_peg, char aux_peg)
{
    if (n == 1)
    {
        printf("\nMove disk 1 from peg %c to peg %c\n", from_peg, to_peg);
        count++;
        return;
    }

    tower(n - 1, from_peg, aux_peg, to_peg);
    printf("\nMove disk %d from peg %c to peg %c\n", n, from_peg, to_peg);
    count++;

    tower(n - 1, aux_peg, to_peg, from_peg);
}