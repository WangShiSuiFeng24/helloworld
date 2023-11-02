#include <stdio.h>

double pow(double a, int n);
long long factorial(int n);
int main()
{
    double x;
    scanf("%lf", &x);

    double divide, sinx;
    int i = 1;
    do {
        divide = pow(x, 2 * i - 1) / factorial(2 * i - 1);
        if (divide < 1e-6)
            break;
        sinx += pow(-1, i + 1) * divide;
        i++;
    } while (true);

    printf("%.5f", sinx);

    return 0;
}

double pow(double a, int n)
{
    double result = 1.0;
    for (int i = 0; i < n; ++i)
        result *= a;
    return result;
}

long long factorial(int n)
{
    long long result = 1.0;
    for (int i = n; i >= 1; i--)
        result *= i;
    return result;
}