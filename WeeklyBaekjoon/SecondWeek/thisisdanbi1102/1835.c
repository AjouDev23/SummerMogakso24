#include <stdio.h>
int main()
{
    int N;
    scanf("%d", &N);

    int final[N];
    for (int i = 0; i < N; i++)
    {
        final[i] = 0; // 최종으로 뽑을거 일단 0
    }

    int now = 0; // 지금 ㅇㄷ?

    for (int i = 1; i <= N; i++)
    {
        int countnum = i; // countnum으로 카드 배치될 위치 찾으려고 빈자리 수 num

        while (countnum > 0)
        {
            if (final[now] == 0) // 빈자리 찾은거
            {
                countnum--;
            }
            now++; // 다음위치로
            if (now == N)
            {
                now = 0;
            }
        }

        while (final[now] != 0) // 빈자리 찾을때까지 계속 반복
        {
            now++;
            if (now == N)
            {
                now = 0;
            }
        }
        final[now] = i; // 지금 위치에 지금 카드 i배치
    }
    for (int i = 0; i < N; i++)
    {
        printf("%d ", final[i]);
    }
    printf("\n");

    return 0;
}
