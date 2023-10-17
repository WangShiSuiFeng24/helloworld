#include <iostream>

#include <cmath>
#include <stdexcept>
using namespace std;

class bad_hmean : public std::logic_error
{
public:
    bad_hmean(const string what_arg = "HMean, Invalid argument ")
        : logic_error(what_arg){}
};

class bad_gmean : public std::logic_error
{
public:
    bad_gmean(const string what_arg = "GMean, Invalid argument ")
        : logic_error(what_arg){}
};

double hmean(double a, double b);
double gmean(double a, double b);

int main()
{
    double x, y, z;

    cout << "Enter two numbers: ";
    while (cin >> x >> y)
    {
        try{
            z = hmean(x, y);
            cout << "Harmonic mean of " << x << " and " << y
                 << " is " << z << endl;
            cout << "Geometric mean of " << x << " and " << y << " is " << gmean(x, y) << endl;

            cout << "Enter next set of numbers < q to quit >: ";
        }
        catch (bad_hmean & bg)
        {
            bg.what();
            cout << "Try again.\n";
            continue;
        }
        catch (bad_gmean & hg)
        {
            hg.what();
            cout << "Sorry, you don't get to play any more.\n";
            break;
        }
    }
    cout << "Bye!\n";
    return 0;
}

double hmean(double a, double b)
{
    if (a == -b)
        throw bad_hmean();
    return 2.0 * a * b / (a + b);
}

double gmean(double a, double b)
{
    if (a < 0 || b < 0)
        throw bad_gmean();
    return sqrt(a * b);
}