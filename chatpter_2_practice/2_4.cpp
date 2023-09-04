#include <iostream>
using namespace std;

int main()
{
    int years;
    cout << "Enter your age: ";
    cin >> years;
    cout << "You are " << years << " years old, or ";
    cout << 12 * years << " months old." << endl;
    return 0;
}