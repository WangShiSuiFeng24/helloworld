#include <stdio.h>

int main()
{
    int a, b, c;
    char ch;
    // scanf("%d %d %d", &a, &b, &c);
    scanf("%d", &a);
    if ((ch = getchar()) == ',')
        scanf("%d,%d", &b, &c);
    else
        scanf("%d %d", &b, &c);

    printf("'%d', '%d',%d", a, b, c);
}