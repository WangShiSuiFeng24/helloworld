#include <iostream>
#include <array>

const int ArSize = 101;

int main()
{
    using namespace std;
    array<long double, ArSize> factorials;
    factorials[0] = 1;

    for (int i = 1; i < ArSize; ++i)
        factorials[i] = i * factorials[i - 1];

    for (int i = 0; i < ArSize; ++i)
        cout << i << "! = " << factorials[i] << endl;

    return 0;
}