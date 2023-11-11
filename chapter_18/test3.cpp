#include <iostream>
// #include <stdio.h>
int add(int x, int y);
int main()
{
    int a;
    int b;
    while (scanf("%d%d",&a, &b))
        printf("a + b = %d\n", add(a, b));
}

int add(int x, int y)
{
    while (y != 0)
    {
        int temp = x ^ y;
        y = (x & y) << 1;
        x = temp;
    }
    return x;
}