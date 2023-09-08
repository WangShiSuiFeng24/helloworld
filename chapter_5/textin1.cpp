// textin1.cpp -- reading chars with a while loop
#include <iostream>
int main()
{
    using namespace std;
    char ch;
    int count = 0;              // use basic input
    cout << "Enter characters; enter # to quit:\n";
    cin >> ch;                  // get a character
    while (ch != '#')
    {
        cout << ch;
        ++count;
        cin >> ch;
    }
    cout << endl
         << count << " characters read\n";
    return 0;
}