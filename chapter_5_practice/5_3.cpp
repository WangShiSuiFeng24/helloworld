#include <iostream>
using namespace std;
int main()
{
    double input_number;
    double sum = 0;
    do
    {
        cout << "Enter a number: ";
        cin >> input_number;
        sum += input_number;
    } while (input_number);

    cout << "The total sum of number you input is " << sum << endl;
    return 0;
}