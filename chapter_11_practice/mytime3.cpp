#include "mytime3.h"
#include <iostream>
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
    minutes = (minutes + m) % 60;
    hours += (minutes + m) / 60;
}

void Time::AddHr(int h)
{
    hours += h;
}

void Time::Reset(int h, int m)
{
    hours = h;
    minutes = m;
}

Time operator+(const Time & t1, const Time & t2)
{
    Time sum;

    sum.minutes = (t1.minutes + t2.minutes) % 60;
    sum.hours = (t1.hours + t2.hours) + (t1.minutes + t2.minutes) / 60;

    return sum;
}

Time operator-(const Time & t1, const Time & t2)
{
    Time diff;

    int tot1, tot2;
    tot1 = t1.minutes + 60 * t1.hours;
    tot2 = t2.minutes + 60 * t2.hours;

    diff.minutes = (tot1 - tot2) % 60;
    diff.hours = (tot1 - tot2) / 60;

    return diff;
}

Time operator*(const Time & t, double n)
{
    Time result;

    long total_minutes = t.minutes + 60 * t.hours;

    result.minutes = (long)(n * total_minutes) % 60;
    result.hours = (n * total_minutes) / 60;

    return result;
}

std::ostream & operator<<(std::ostream & os, const Time & t)
{
    os << t.hours << " hours, " << t.minutes << " minutes";
    return os;
}