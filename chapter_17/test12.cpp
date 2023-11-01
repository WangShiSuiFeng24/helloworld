#include <stdio.h>
int main()
{
    int R, x, y, z;
    scanf("%d%d%d%d", &R, &x, &y, &z);

    int length_square = x * x + y * y + z * z;
    int R_square = R * R * R;
    if (length_square < R_square)
        printf("In the Sphere.");
    else if (length_square == R_square)
        printf("On the Sphere.");
    else
        printf("Outside the Sphere.");

    return 0;
}