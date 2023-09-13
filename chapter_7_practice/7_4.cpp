#include <iostream>
long double probability(double fnumbers, double snumber, double picks);
int main()
{
    using namespace std;

    cout << "Field number is 45, and special number is 27." << endl;
    cout << "The probability is one of the: " << probability(45, 27, 5) << endl;

    return 0;
}

long double probability(double fnumbers, double snumber, double picks)
{
    long double p1 = 1.0, p2;
    double f, p;
    for (f = fnumbers, p = picks; p > 0; f--, p--)
        p1 = p1 * f / p;
    p2 = snumber;

    return p1 * p2;
}