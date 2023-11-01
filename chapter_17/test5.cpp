#include <iostream>
main()
{
    int n, i;
    scanf("%d", &n);

    for (i = 1; i <= n; ++i)
    {
        if (i % 2 == 1)
            printf("%-2d", i);
    }
}