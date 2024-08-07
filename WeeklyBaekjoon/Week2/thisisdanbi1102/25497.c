#include <stdio.h>
int main()
{
    int N;
    scanf("%d", &N);
    getchar();

    char skillbox[1000];

    scanf("%s", skillbox);

    char LRskill[1000]; // 대충 스택?
    char SKskill[1000];
    int LRtop = -1; // 스택 비어있을때 상단
    int SKtop = -1;

    int skillnum = 0;

    for (int i = 0; skillbox[i] != '0'; i++)
    {
        char skill = skillbox[i];
    }
}