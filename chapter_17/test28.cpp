#include <stdio.h>

int main()
{
    int x, i, cnt = 0;
    printf("Enter a integer: \n");
    scanf("%d", &x);

    char num[10];
    do {
        if (x % 2 == 1)
            num[cnt] = '1';
        else
            num[cnt] = '0';
        x /= 2;
        cnt++;
    } while (x > 0);

    for (i = cnt - 1; i >= 0; i--)
        printf("%c", num[i]);

    return 0;
}