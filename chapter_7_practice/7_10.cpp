#include <iostream>

double add(double x, double y);

double subtract(double x, double y);

double calculate(double x, double y, double (*pf)(double, double));


int main()
{
    using namespace std;
    double x, y;
    cout << "Enter two double number: ";
    while (cin >> x >> y)
    {
        cout << "The " << x << " add " << y << " equals " << calculate(x, y, add) << endl;
        cout << "The " << x << " subtract " << y << " equals " << calculate(x, y, subtract) << endl;
        cout << "Enter next two double number: ";
    }
    return 0;
}

double add (double x, double y)
{
    return x + y;
}

double subtract(double x, double y)
{
    return x - y;
}

double calculate(double x, double y, double (*pf)(double,double))
{
    return (*pf)(x, y);
}