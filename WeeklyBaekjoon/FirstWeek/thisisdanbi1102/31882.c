#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N;

int forcounting(char *str)
{
    int groupcount = 0;
    int total = 0;

    for (int i = 0; i < N; i++)
    {
        if (str[i] == '2')
        {
            int grplength = 1;
            for (int j = i + 1; j < str[j] == '2'; j++)
            {
                grplength++;
                i = j;
            }

            int groupsum = grplength * (grplength + 1) / 2;
            total += groupsum;
            groupcount++;
        }
    }
    printf("%d", total);
}

int main()
{

    char strnum[N + 1];

    scanf("%d\n", &N);
    // strnum = (char *)malloc((N + 1) * sizeof(char));

    scanf("%c", &strnum);

    forcounting(strnum);

    return 0;
}
