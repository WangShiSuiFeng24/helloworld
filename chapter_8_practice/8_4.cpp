#include <iostream>
using namespace std;
#include <cstring>
struct stringy
{
    char * str;
    int ct;
};

void set(stringy &, char *);
void show(const stringy &, int n = 1);

void show(const char *, int n = 1);
int main()
{
    stringy beany;
    char testing[] = "Reality isn't what it used to be.";

    set(beany, testing);

    show(beany);

    show(beany, 2);

    testing[0] = 'D';
    testing[1] = 'u';

    show(testing);
    show(testing, 3);
    show("Done!");

    return 0;
}

void set(stringy & sty, char * st)
{
    char *p = new char[strlen(st) + 1];
    sty.str = p;
    strcpy(sty.str, st);
    sty.ct = strlen(st);
}

void show(const stringy & sty, int n)
{
    if (n == 0)
        n++;
    for (int i = 0; i < n; ++i)
        cout << sty.str << endl;
}

void show(const char * st, int n)
{
    if (n == 0)
        n++;
    for (int i = 0; i < n; ++i)
        cout << st << endl;
}