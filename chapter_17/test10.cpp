#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    scanf("%d", &n);

    int j, count = 0;
    for (int i = 100; i < n; ++i)
    {
        for (j = 2; j <= sqrt(i); j++)
            if (i % j == 0)
                break;
        if (j > sqrt(i))
        {   
            printf("%d", i);
            if (count % 8 == 7)
                printf("\n");
            else
                printf(" ");
            count++;
        }
    }
}