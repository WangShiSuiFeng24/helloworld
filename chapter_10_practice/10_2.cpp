#include <string>
#include <iostream>
#include <cstring>

using namespace std;

class Person
{
private:
    static const int LIMIT = 25;
    string lname;
    char fname[LIMIT];
public:
    Person();
    Person(const string &ln, const char *fn = "Heyyou");
    void Show() const;
    void FormalShow() const;
};

Person::Person()
{
    lname = "";
    fname[0] = '\0';
}

Person::Person(const string & ln, const char *fn)
{
    lname = ln;
    strcpy(fname, fn);
}

void Person::Show() const
{
    if (lname == "" && fname[0] == '\0')
        cout << "No Name." << endl;
    else
        cout << "Person Name: " << fname << "." << lname << endl;
}

void Person::FormalShow() const
{
    if (lname == "" && fname[0] == '\0')
        cout << "No Name." << endl;
    else
        cout << "Person Name: " << lname << "." << fname << endl;
}

int main()
{
    Person one;
    Person two("Smythecraft");
    Person three("Dimwiddy", "Sam");
    cout << endl;
    one.FormalShow();
    two.FormalShow();
    three.FormalShow();

    return 0;
}