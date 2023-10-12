#include "winec.h"
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
    : label(l), year(y), info(ArrayInt(yr, y), ArrayInt(bot, y))
{}

Wine::Wine(const char *l, int y)
    : label(l), year(y), info(ArrayInt(0, 0), ArrayInt(0, 0))
{}

void Wine::GetBottles()
{
    using std::cin;
    using std::cout;
    cout << "Enter " << label << " data for " << year << " year(s):\n";
    info.first().resize(year);
    info.second().resize(year);

    for (int i = 0; i < year; ++i)
    {
        cout << "Enter year: ";
        cin >> info.first()[i];
        cout << "Enter bottles for that year: ";
        cin >> info.second()[i];
    }
}

const std::string & Wine::Label() const
{
    return label;
}

int Wine::sum() const
{
    return info.second().sum();
}

void Wine::Show()
{
    using std::cout;
    using std::endl;
    cout << "Wine: " << label << endl;
    cout << "   Year    Bottles" << endl;
    for (int i = 0; i < year; ++i)
    {
        cout << "   " << info.first()[i];
        cout << "    " << info.second()[i] << endl;
    }
}