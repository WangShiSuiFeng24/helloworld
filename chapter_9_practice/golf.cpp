#include <iostream>
#include <string>
#include <cstring>
#include "golf.h"

using namespace std;

void setgolf(golf & g, const char * name, int hc)
{
    int i;
    const char *p = name;
    for (i = 0; i < Len && *p; ++i, ++p)
        g.fullname[i] = *p;
    g.fullname[i] = '\0';
    g.handicap = hc;
}

int setgolf(golf & g)
{
    string str;
    cout << "Enter the name: ";
    getline(cin, str);
    if (str[0] != '\0')
    {
        int i;
        for (i = 0; i < Len && i < str.size(); ++i)
            g.fullname[i] = str[i];
        cout << "Enter the handicap: ";
        while (!(cin>>g.handicap))
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout << "Enter the golf's handicap: ";
        }
        return 1;
    }
    else
        return 0;
}

void handicap(golf & g, int hc)
{
    g.handicap = hc;
}

void showgolf(const golf & g)
{
    cout << "Name: " << g.fullname << ", handicap is " << g.handicap << endl;
}