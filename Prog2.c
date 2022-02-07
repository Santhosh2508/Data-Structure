#include <stdio.h>

//Main Fuction
void main()
{
    char STR[50], PAT[20], REP[20], ANS[100];
    int i, j, m, c, k, flag = 0;
    printf("\nEnter the MAIN string : ");
    gets(STR);
    printf("\n\nEnter the PATTERN string: ");
    gets(PAT);
    printf("\n\nEnter the REPLACE string : ");
    gets(REP);
    i = m = c = j = 0;
    //iterates STR Characters
    while (STR[c] != '\0')
    {
        //checking for match
        if (STR[m] == PAT[i])
        {
            i++;
            m++;
            if (PAT[i] == '\0')
            {
                //replace string in ANS string
                flag = 1;
                for (k = 0; REP[k] != '\0'; k++, j++)
                {
                    ANS[j] = REP[k];
                }
                i = 0;
                c = m;
            }
        }
        else //mismatch
        {
            ANS[j] = STR[c];
            j++;
            c++;
            m = c;
            i = 0;
        }
    }
    ANS[j] = '\0';
    if (flag == 0)
    {
        printf("\n\nPattern does not found\n");
    }
    else
    {
        printf("\n\nTHE RESULTANT string is : %s\n", ANS);
    }
}