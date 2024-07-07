#include <stdio.h>

int N;

void forcounting(char *str)
{
    long long total = 0;
    long long length = 0;

    for (long long i = 0; i < N; i++)
    {
        if (str[i] == '2')
        {
            length++;

            if (str[i + 1] != '2')
            {
                
                length = 0;
            }
        }
    }
    printf("%d", total);
}

int main()
{
    scanf("%d", &N);

    char strnum[N + 1];

    scanf("%s", strnum);

    forcounting(strnum);

    return 0;
}
