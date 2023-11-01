#include <stdio.h>

int main()
{
    int a, b;
    float x, y;
    char c1, c2;

    scanf_s("a=%db=%d", &a, &b);

    while(getchar() != '\n') continue;
    scanf_s("%f%e", &x, &y);
    
    while(getchar() != '\n') continue;
    scanf_s("%c%c", &c1, sizeof(c1), &c2, sizeof(c2));

    printf("a=%d b=%d\n", a, b);
    printf("x=%f y=%e\n", x, y);
    printf("c1=%c c2=%c\n", c1, c2);
}