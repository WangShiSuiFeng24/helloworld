#include <iostream>

double factorial(int);

int main()
{
    using namespace std;
    int num;

    cout << "Enter an integer: ";
    while (cin >> num)
    {
        if (num >= 0)
            cout << num << "! = " << factorial(num) << endl;
        else
            cout << "Need a positive number!" << endl;
        cout << "Enter an integer: ";
    }
    return 0;
}

double factorial(int n)
{
    if (0 == n)
        return 1;
    return n * factorial(n - 1);
}