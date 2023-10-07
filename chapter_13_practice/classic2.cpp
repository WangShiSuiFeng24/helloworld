#include "classic2.h"
#include <iostream>
#include <cstring>

using namespace std;

Cd::Cd(const char *s1, const char *s2, int n, double x)
{
    performers = new char[strlen(s1) + 1];
    strcpy(performers, s1);
    label = new char[strlen(s2) + 1];
    strcpy(label, s2);
    selections = n;
    playtime = x;
}

Cd::Cd(const Cd & d)
{
    performers = new char[strlen(d.performers) + 1];
    label = new char[strlen(d.label) + 1];
    strcpy(performers, d.performers);
    strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;
}

Cd::Cd()
{
    performers = new char[1];
    label = new char[1];
    performers[0] = '\0';
    label[0] = '\0';
    selections = 0;
    playtime = 0.0;
}

Cd::~Cd()
{
    if (performers != nullptr)
        delete[] performers;
    if (label != nullptr)
        delete[] label;
}

void Cd::Report() const
{
    cout << "Performers: " << performers << endl;
    cout << "Label: " << label << endl;
    cout << "Selections: " << selections << endl;
    cout << "Playtime: " << playtime << endl;
}

Cd & Cd::operator=(const Cd & d)
{
    if (this == &d)
        return *this;
    delete[] d.performers;
    delete[] d.label;
    performers = new char[strlen(d.performers) + 1];
    label = new char[strlen(d.label) + 1];
    strcpy(performers, d.performers);
    strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;
    return *this;
}

Classic::Classic() : Cd()
{
    works = new char[1];
    works[0] = '\0';
}

Classic::Classic(const Classic & c) : Cd(c)
{
    works = new char[strlen(c.works) + 1];
    strcpy(works, c.works);
}

Classic::Classic(const char *s1, const char *s2, const char *s3, int n, double x)
    : Cd(s1, s2, n, x)
{
    works = new char[strlen(s3) + 1];
    strcpy(works, s3);
}

Classic::~Classic()
{
    if (works != nullptr)
        delete[] works;
}

void Classic::Report() const
{
    Cd::Report();
    cout << "Works: " << works << endl;
}

Classic & Classic::operator=(const Classic & c)
{
    if (this == &c)
        return *this;
    Cd::operator=(c);
    delete[] works;
    works = new char[strlen(c.works) + 1];
    strcpy(works, c.works);
    return *this;
}
