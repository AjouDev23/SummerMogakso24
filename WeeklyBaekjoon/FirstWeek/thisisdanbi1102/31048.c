#include <stdio.h>
int main()
{

    int t, x;
    scanf("%d", &t);

    for (int i = 0; i < t; i++)
    {
        scanf("%d", &x);

        if (x >= 5)
            printf("0\n");
        else if (x == 3)
            printf("6\n");
        else
            printf("%d\n", x);
    }
    return 0;
}
