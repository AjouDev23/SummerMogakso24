#include <stdio.h>

int N;

int forcounting(char *str)
{
    int total = 0;
    int length = 0;

    for (int i = 0; i < N; i++)
    {
        if (str[i] == '2')
        {
            length++;

            if (str[i + 1] != '2' || i >= N)
            {
                for (int j = 1; j < length + 1; j++)
                {
                    total += j * (length - j + 1);
                }
                length = 0;
            }
        }
    }
    printf("%d", total);
    return total;
}

int main()
{
    char strnum[N + 1];

    scanf("%d\n", &N);

    scanf("%s", strnum);

    forcounting(strnum);

    return 0;
}
