#include <stdio.h>

// Global Variable
char STR[50], PAT[50], REP[50], ANS[100];

// Find and Replace String Match
void stringmatch()
{
    // c-m-index STR, i-index pattern, k-index replace, j-index ANS
    int i, m, c, j, k, occ = 0;
    i = m = c = j = 0;
    // iterates STR Characters
    while (STR[c] != '\0')
    {
        // checking for match
        if (STR[m] == PAT[i])
        {
            i++;
            m++;
            if (PAT[i] == '\0')
            {
                // replace string in ANS string
                occ++;
                for (k = 0; REP[k] != '\0'; k++, j++)
                {
                    ANS[j] = REP[k];
                }
                i = 0;
                c = m;
            }
        }
        else // mismatch
        {
            ANS[j] = STR[c];
            j++;
            c++;
            m = c;
            i = 0;
        }
    }
    ANS[j] = '\0';
    if (occ == 0)
    {
        printf("\n\nPattern does not found\n");
    }
    else
    {
        printf("\n\nNumber of Occurances = %d\n", occ);
        printf("\nTHE RESULTANT string is : %s\n", ANS);
    }
}

// Main Fuction
void main()
{
    printf("\nEnter the MAIN string : ");
    gets(STR);
    printf("\n\nEnter the PATTERN string: ");
    gets(PAT);
    printf("\n\nEnter the REPLACE string : ");
    gets(REP);
    stringmatch();
}