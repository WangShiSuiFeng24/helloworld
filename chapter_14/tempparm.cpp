// tempparm.cpp -- templates as parameters
#include <iostream>
#include "stacktp.h"

template <template <typename T> class Thing>
class Crab
{
private:
    Thing<int> s1;
    Thing<double> s2;

public:
    Crab(){}

    bool push(int a, double x) { return s1.push(a) && s2.push(x); }
    bool pop(int &a, double &x) { return s1.pop(a) && s2.pop(x); }
};

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;

    Crab<Stack> nubula;

    int ni;
    double nb;

    cout << "Enter int double pairs, such as 4 3.5 (0 0 to end):\n";
    while (cin>> ni>>nb && ni > 0 && nb > 0)
    {
        if (!nubula.push(ni,nb))
            break;
    }

    while (nubula.pop(ni, nb))
        cout << ni << ", " << nb << endl;

    cout << "Done.\n";

    return 0;
}