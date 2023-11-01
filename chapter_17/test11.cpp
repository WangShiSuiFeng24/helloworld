#include <stdio.h>

int main()
{

    int count = 0;
    for (int i = 100; i < 1000; ++i)
    {
        if (i % 41 == 0)
        {
            int a = i / 10;
            int b = i % 100;
            if (a > b)
            {
                count++;
                printf("第%2d个数是%d: %d/41=%d %d>%d\n",
                       count, i, i, i / 41, a, b);
            }
        }
    }
}