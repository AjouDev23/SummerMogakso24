#include <stdio.h>
int main()
{
    int N;
    scanf("%d", &N);
    getchar();

    char skillbox[200000];
    scanf("%s", skillbox);

    int LRuse[200000];
    int SKuse[200000];
    int LRtop = -1; // 스택상단
    int SKtop = -1;

    int result = 0;

    for (int i = 0; skillbox[i] != '\0'; i++)
    {
        char skill = skillbox[i];

        if (skill >= '0' && skill <= '9')
        {
            result++;
        }
        else if (skill == 'S')
        {
            SKuse[++SKtop] = skill; // 사전기술
        }
        else if (skill == 'K')
        {
            if (SKtop == -1) // 스택 비어있나?
            {
                break; // 비어있으면 중지
            }
            else
            {
                SKtop--; // pop (S-K매칭되니까 S제거)
                result++;
            }
        }
        else if (skill == 'L')
        {
            LRuse[++LRtop] = skill; // 사전기술
        }
        else if (skill == 'R')
        {
            if (LRtop == -1)
            {
                break;
            }
            else
            {
                LRtop--; // pop (L제거)
                result++;
            }
        }
    }

    printf("%d\n", result);

    return 0;
}