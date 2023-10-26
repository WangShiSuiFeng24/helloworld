#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool palindromic(string & s);
void show(const char &c);
void convert(char &c);
int main()
{
    string s = "ming an dong";
    for_each(s.begin(), s.end(), show);
    cout << endl;

    for_each(s.rbegin(), s.rend(), show);
    cout << endl;

    string::iterator si;
    for (si = s.begin(); si != s.end(); ++si)
        cout << *si;
    cout << endl;

    string::reverse_iterator sr;
    for (sr = s.rbegin(); sr != s.rend(); ++sr)
        cout << *sr;
    cout << endl;

    cout << "Enter a string: ";
    while (getline(cin, s))
    {
        if (palindromic(s))
            cout << s << " 是回文" << endl;
        else
            cout << s << " 不是回文" << endl;
    }

    return 0;
}

bool palindromic(string & s)
{
    string s_ = s;
    reverse(s.begin(), s.end());
    return s == s_;
}

void show(const char &c)
{
    cout << c;
}
