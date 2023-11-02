#include <stdio.h>

int pow(int a, int b);
int main()
{
    int n;
    long long result = 1;
    scanf("%d", &n);

    // 阶乘
    for (int i = n; i >= 1; i--)
        result *= i;
    printf("%d\n", result);

    // 2
    result = 0;
    int temp = 0;
    for (int i = 1; i <= n; i++)
    {
        temp = temp * 10 + n;
        result += temp;
    }
    printf("%d\n", result);

    // 3
    result = 0;
    temp = 0;
    for (int i = 1; i <= n; i++)
    {
        temp = temp * 10 + i;
        result += temp;
    }
    printf("%d\n", result);
}

int pow(int a, int b)
{
    int res = 1;
    for (int i = 1; i <= b; i++)
        res *= a;
    return res;
}