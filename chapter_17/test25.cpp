#include <stdio.h>

int main()
{
    for (int k = 2; k < 10000; ++k)
    {
        int num = k;
        int temp = k - 1;
        int i;
        for (i = 2; i < num; ++i)
        {
            if (num % i == 0)
            {
                temp -= i;
            }
        }
        if (temp == 0)
            printf("%d ", k);
    }
    return 0;
}