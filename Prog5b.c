#include <stdio.h>

void tower(int n, char, char, char);

int main()
{
    int n;
    printf("Enter the number of disk\n");
    scanf("%d", &n);
    printf("The Sequence of moves involved in the Tower of Hanoi are\n");
    tower(n, 'A', 'C', 'B');
    return 0;
}

void tower(int n, char from_peg, char to_peg, char aux_peg)
{
    if (n == 1)
    {
        printf("\nMove disk 1 from peg %c to peg %c\n", from_peg, to_peg);
        return;
    }
    tower(n - 1, from_peg, aux_peg, to_peg);
    printf("\nMove disk %d from peg %c to peg %c\n", n, from_peg, to_peg);
    tower(n - 1, aux_peg, to_peg, from_peg);
}