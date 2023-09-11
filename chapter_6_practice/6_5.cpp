#include <iostream>

int main()
{
    using namespace std;

    float tax, salary = 0.0;

    tax = 0;
    cout << "Hello, enter your salary to calculate tax: ";
    while (cin >> salary && salary >= 0)
    {
        if (salary <= 5000)
            tax = 0.0;
        else if (salary <= 15000)
            tax = 5000 * 0.0 + (salary - 5000) * 0.1;
        else if (salary <= 35000)
            tax = 5000 * 0.0 + 10000 * 0.1 + (salary - 15000) * 0.15;
        else if (salary > 35000)
            tax = 5000 * 0.0 + 10000 * 0.1 + 20000 * 0.15 + (salary - 35000) * 0.20;

        cout << "Your salary is " << salary << " tvarps, and you should pay ";
        cout << tax << " tvarps." << endl;
        cout << "Hello, enter your salary to calculate tax: ";
    }
    cout << "Bye!" << endl;
    return 0;
}