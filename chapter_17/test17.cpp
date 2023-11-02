#include <stdio.h>

int help(int num);
int main()
{
    int num;
    printf("请输入一个大于1的正整数:", &num);
    scanf("%d", &num);

    int i;
    i = help(num);
    if (i * i > num)
        printf("%d是素数\n", num);
    else
    {
        printf("%d = ", num);
        while (i * i < num)
        {
            printf("%d x ", i);
            num = num / i;
            i = help(num);
        }
        printf("%d", num);
    }

    return 0;
}

int help(int num)
{
    int i;
    for (i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
            break;
    }
    return i;
}