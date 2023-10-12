#include "winec2.h"
#include <iostream>

template <class T1, class T2>
T1 &Pair<T1, T2>::first()
{
    return a;
}

template <class T1, class T2>
T2 &Pair<T1, T2>::second()
{
    return b;
}

Wine::Wine(const char *l, int y, const int yr[], const int bot[])
    : std::string(l), year(y), PairArray(ArrayInt(yr, y), ArrayInt(bot, y))
{}

Wine::Wine(const char *l, int y)
    : std::string(l), year(y), PairArray(ArrayInt(0, 0), ArrayInt(0, 0))
{}

void Wine::GetBottles()
{
    using std::cin;
    using std::cout;
    cout << "Enter " << (std::string &) *this << " data for " << year << " year(s):\n";
    PairArray::first().resize(year);
    PairArray::second().resize(year);

    for (int i = 0; i < year; ++i)
    {
        cout << "Enter year: ";
        cin >> PairArray::first()[i];
        cout << "Enter bottles for that year: ";
        cin >> PairArray::second()[i];
    }
}

const std::string & Wine::Label() const
{
    return (const std::string &)*this;
}

int Wine::sum() const
{
    return PairArray::second().sum();
}

void Wine::Show()
{
    using std::cout;
    using std::endl;
    cout << "Wine: " << (const std::string &) *this << endl;
    cout << "   Year    Bottles" << endl;
    for (int i = 0; i < year; ++i)
    {
        cout << "   " << PairArray::first()[i];
        cout << "    " << PairArray::second()[i] << endl;
    }
}