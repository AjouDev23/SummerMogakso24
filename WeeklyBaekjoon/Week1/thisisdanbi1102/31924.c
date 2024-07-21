#include <stdio.h>

int N;
char map[100][100];

int xdir[] = {-1, 1, 0, 0, -1, -1, 1, 1}; // 위, 아래, 왼, 오, 왼위, 왼아래, 오위, 오아래
int ydir[] = {0, 0, -1, 1, -1, -1, 1, 1}; // 마찬가지

int dirSearch(int x, int y, int direction)
{

    for (int i = 0; i < 5; i++)
    {
        int newx = x + xdir[direction] * i; // x에서 xdir[direction]으로 i만큼 이동
        int newy = y + ydir[direction] * i;
    }
}

int main()
{

    return 0;
}