#include <stdio.h>
#include <string.h>

// 와 잠만 이거 C로 하니까 역대급 비효율을 느끼는데 파이썬으로 하면 몇줄만에 끝날거같아

int main()
{

    int N;
    scanf("%d\n", &N);

    for (int i = 0; i < N; i++)
    {
        char casenum[100];
        char *words[26];
        int wrdcount = 0;

        fgets(casenum, 100, stdin);

        char *token = strtok(casenum, " "); // 공백 기준 분리
        while (token != NULL)
        {
            words[wrdcount] = token; // 현재 단어 포인터를 words 배열에...
            wrdcount++;
            token = strtok(NULL, " ");
        }

        printf("Case #%d: ", i + 1);
        for (int j = wrdcount - 1; j >= 0; j--)
        {
            printf("%s", words[j]);
            if (j > 0)
            {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}