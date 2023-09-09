#include <iostream>
using namespace std;
int main()
{
    int min, max;

    cout << "Enter the min number: ";
    cin >> min;
    cout << "Enter the max number: ";
    cin >> max;

    int sum = 0;
    for (int i = min; i <= max; i++)
        sum += i;

    cout << "The sum of " << min << " +...+ " << max << " is ";
    cout << sum << endl;

    return 0;
}