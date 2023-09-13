#include <iostream>
double harmonic_mean(double, double);

int main()
{
    using namespace std;
    double d1, d2;

    cout << "Enter two numbers: ";
    while (cin >> d1 >> d2)
    {
        if (d1 == 0 || d2 == 0)
            break;
        cout << "The result of " << d1 << " and " << d2 << " is " << harmonic_mean(d1, d2) << endl;
        cout << "\nNext two numbers: ";
    }
    cout << "Done!\n";
    return 0;
}

double harmonic_mean(double d1, double d2)
{
    return 2.0 * d1 * d2 / (d1 + d2);
}