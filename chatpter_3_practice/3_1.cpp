#include <iostream>
#include <cfloat>
int main()
{
    using namespace std;
    cout << "sizeof (L'p') = " << sizeof(L'p') << endl;

    cout << char(88) << endl;
    cout << (char)88 << endl;
    cout.put((char)88);

    cout << DBL_DIG << endl;

    auto x = U'/U0002155';
    cout << x  << endl;
    return 0;
}