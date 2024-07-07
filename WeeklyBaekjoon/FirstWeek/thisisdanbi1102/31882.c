#include <stdio.h>

int N;

int forcounting(char *str)
{
    long long total = 0;
    long long length = 0;

    for (int i = 0; i < N; i++)
    {
        if (str[i] == '2')
        {
            length++;

            if (str[i + 1] != '2' || i >= N - 1)
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
    scanf("%d\n", &N);

    char strnum[N + 1];

    scanf("%s", strnum);

    forcounting(strnum);

    return 0;
}
