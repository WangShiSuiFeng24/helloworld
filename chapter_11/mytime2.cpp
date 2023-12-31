// mytime2.cpp -- implementing Time method
#include <iostream>
#include "mytime2.h"

Time::Time()
{
    hours = minutes = 0;
}

Time::Time(int h, int m)
{
    hours = h;
    minutes = m;
}

void Time::AddMin(int m)
{
    minutes = (m + minutes) % 60;
    hours += (m + minutes) / 60;
}

void Time::AddHr(int h)
{
    hours += h;
}

void Time::Reset(int h, int m)
{
    minutes = (m + minutes) % 60;
    hours = (hours + h) + (m + minutes) / 60;
}

Time Time::operator+(const Time & t) const
{
    Time sum;

    sum.minutes = (t.minutes + minutes) % 60;
    sum.hours = (t.hours + hours) + (t.minutes + minutes) / 60;

    return sum;
}

Time Time::operator-(const Time & t) const
{
    Time diff;
    int tot1, tot2;

    tot1 = t.minutes + 60 * t.hours;
    tot2 = minutes + 60 * hours;

    diff.minutes = (tot2 - tot1) % 60;
    diff.hours = (tot2 - tot1) / 60;

    return diff;
}

Time Time::operator*(double n) const
{
    Time result;

    int totalminutes;
    totalminutes = n * (minutes + 60 * hours);

    result.minutes = totalminutes % 60;
    result.hours = totalminutes / 60;

    return result;
}

void Time::Show() const
{
    std::cout << hours << " hours, " << minutes << " minutes";
}