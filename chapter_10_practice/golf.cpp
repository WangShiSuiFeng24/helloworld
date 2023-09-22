// compile with 9_3.cpp
#include <iostream>
#include "golf.h"
#include <cstring>

golf::golf()
{
    using std::cin;
    using std::cout;
    using std::endl;

    char name[Len] = {'\0'};
    int hc;
    cout << "Please enter the name: ";
    cin.getline(name, Len);

    cout << "Please enter the handicap: ";
    while (!(cin >> hc))
    {
        cin.clear();
        while (cin.get() != '\n')
            continue;
        cout << "Please enter the golf's handicap: ";
    }
    cout << name << "::" << hc << endl;
    strcpy(fullname, name);
    handicap = hc;
}

golf::golf(const char * name, int hc)
{
    strcpy(fullname, name);
    handicap = hc;
}

golf::~golf()
{

}

void golf::sethandicap(int hc)
{
    handicap = hc;
}

void golf::showgolf() const
{
    std::cout << "Name : " << fullname << ", Handicap is " << handicap << std::endl;
}