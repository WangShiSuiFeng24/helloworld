#include <iostream>
#include <string>
#include <cctype>
using namespace std;
void uppercase(string &s);

int main()
{
    string str;

    cout << "Enter a string (q to quit): ";
    while (getline(cin, str) && str != "q")
    {
        uppercase(str);
        cout << str << endl;

        cout << "Next string (q to quit): ";
    }
    cout << "Bye." << endl;
    return 0;
}

void uppercase(string & s)
{
    for (int i = 0; i < s.size(); ++i)
    {
        s[i] = toupper(s[i]);
    }
}