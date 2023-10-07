#include "classic.h"
#include <iostream>
#include <cstring>

using namespace std;

Cd::Cd(const char *s1, const char *s2, int n, double x)
{
    strncpy(performers, s1, 49);
    performers[49] = '\0';
    strncpy(label, s2, 19);
    label[19] = '\0';
    selections = n;
    playtime = x;
}

Cd::Cd(const Cd & d)
{
    strcpy(performers, d.performers);
    strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;
}

Cd::Cd()
{
    performers[0] = '\0';
    label[0] = '\0';
    selections = 0;
    playtime = 0.0;
}

Cd::~Cd()
{}

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
    strcpy(performers, d.performers);
    strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;
    return *this;
}

Classic::Classic() : Cd()
{
    works[0] = '\0';
}

Classic::Classic(const Classic & c) : Cd(c)
{
    strcpy(works, c.works);
}

Classic::Classic(const char *s1, const char *s2, const char *s3, int n, double x)
    : Cd(s1, s2, n, x)
{
    strncpy(works, s3, 49);
    works[49] = '\0';
}

Classic::~Classic()
{}

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
    strcpy(works, c.works);
    return *this;
}
