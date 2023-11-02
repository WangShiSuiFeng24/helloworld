#include <stdio.h>

int main()
{
    float x, sum, ave;
    int p;
    sum = 0;

    for (p = 1; p <= 1000; p++)
    {
        scanf("%f", &x);
        sum = sum + x;
        if (sum >= 10000)
            break;
    }
    ave = sum / p;
    printf("p=%d, ave=%f\n", p, ave);
    return 0;
}