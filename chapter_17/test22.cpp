#include <stdio.h>
int main()
{
    int a, b;
    scanf("%d%d", &a, &b);

    int sum = 0;

    for (int i = 0; i < b - a + 1; i++)
    {
        printf("%5d", a + i);
        if (i % 5 == 4)
            printf("\n");
        else
            printf(" ");
    }
    printf("\n");

    for (int i = a; i <= b; i++)
        sum += i;
    printf("Sum = %d", sum);

    return 0;
}