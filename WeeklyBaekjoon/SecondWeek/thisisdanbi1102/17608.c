#include <stdio.h>
int main()
{

    int N;
    scanf("%d", &N);

    int stick[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &stick[i]);
    }

    int count = 0;
    int max = 0;

    for (int i = N - 1; i >= 0; i--)
    {
        if (stick[i] > max)
        {
            count++;
            max = stick[i];
        }
    }

    printf("%d", count);

    return 0;
}

// 리스트 거꾸로 순회하면서 처음꺼보다 높은거만 세기?