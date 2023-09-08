// textin4.cpp -- reading chars with cin.get()
#include <iostream>
int main()
{
    using namespace std;
    int ch;
    int count = 0;              // should be int, not char

    while ((ch = cin.get()) != EOF) // test for end-of-file
    {
        cout.put(char(ch));
        ++count;
    }
    cout << endl
         << count << " characters read\n";
    return 0;
}