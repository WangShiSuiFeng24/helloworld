#include <iostream>
#include <cctype>

using namespace std;

bool palindromic(string & s);

int main()
{
    string st;
    cout << "Enter the string to test: ";
    getline(cin, st);
    cout << "String " << st << " is ";
    if (palindromic(st))
        cout << "a palindromic string. " << endl;
    else
        cout << "not a palindromic string. " << endl;
}

bool palindromic(string & s)
{
    string::iterator phead, ptail;

    while (ptail > phead)
    {
        if (!isalpha(*phead))
        {
            phead++;
            continue;
        }

        if (!isalpha(*ptail))
        {
            ptail--;
            continue;
        }

        if (toupper(*phead) == toupper(*ptail))
        {
            phead++;
            ptail--;
        }
        else
            return false;
    }
    return true;
}