#include "emp.h"
#include <iostream>

using namespace std;
abstr_emp::abstr_emp() : fname("none"), lname("none"), job("none")
{}

abstr_emp::abstr_emp(const string &fn, const string &ln,
                     const string &j)
    : fname(fn), lname(ln), job(j)
{}

abstr_emp::~abstr_emp()
{}

void abstr_emp::ShowAll() const
{
    cout << "NAME: " << fname << "." << lname << endl;
    cout << "JOB TITLE: " << job << endl;
}

void abstr_emp::SetAll()
{
    cout << "Enter the first name: ";
    getline(cin, fname);
    cout << "Enter the last name: ";
    getline(cin, lname);
    cout << "Enter the job title: ";
    getline(cin, job);
}

ostream & operator<<(ostream & os, const abstr_emp & e)
{
    os << "NAME: " << e.fname << "." << e.lname << endl;
    os << "JOB TITLE: " << e.job << endl;
    return os;
}

// employee
employee::employee() : abstr_emp()
{}

employee::employee(const string &fn, const string &ln,
                   const string &j)
    : abstr_emp(fn, ln, j)
{}

void employee::ShowAll() const
{
    abstr_emp::ShowAll();
}

void employee::SetAll() 
{
    abstr_emp::SetAll();
}

// manager
manager::manager() : abstr_emp(), inchargeof(0)
{}

manager::manager(const string &fn, const string &ln,
                 const string &j, int ico)
    : abstr_emp(fn, ln, j), inchargeof(ico)
{}

manager::manager(const abstr_emp & e, int ico)
    : abstr_emp(e), inchargeof(ico)
{}

manager::manager(const manager & m)
    : abstr_emp(m)
{
    inchargeof = m.inchargeof;
}

void manager::ShowAll() const
{
    abstr_emp::ShowAll();
    cout << "IN CHARGE OF: " << inchargeof << endl;
}

void manager::SetAll()
{
    abstr_emp::SetAll();
    cout << "Enter the number of in charge: ";
    cin >> inchargeof;
    
    while (cin.get() != '\n')
        continue;
}

// fink
fink::fink() : abstr_emp(), reportsto("none")
{}

fink::fink(const string &fn, const string &ln,
           const string &j, const string &rpo)
    : abstr_emp(fn, ln, j), reportsto(rpo)
{}

fink::fink(const abstr_emp & e, const string & rpo)
    : abstr_emp(e), reportsto(rpo)
{}

fink::fink(const fink & f)
    : abstr_emp(f)
{
    reportsto = f.reportsto;
}

void fink::ShowAll() const
{
    abstr_emp::ShowAll();
    cout << "REPORT TO" << reportsto << endl;
}

void fink::SetAll()
{
    abstr_emp::SetAll();
    cout << "Enter the reports to whom: ";
    getline(cin, reportsto);
}

// highfink
highfink::highfink()
{}

highfink::highfink(const string &fn, const string &ln,
                   const string &j, const string &rpo, int ico)
    : abstr_emp(fn, ln, j), fink(fn, ln, j, rpo), manager(fn, ln, j, ico)
{}                   

highfink::highfink(const abstr_emp & e, const string & rpo, int ico)
    : abstr_emp(e), fink(e, rpo), manager(e, ico)
{}

highfink::highfink(const fink & f, int ico)
    : abstr_emp(f), fink(f), manager(f, ico)
{}

highfink::highfink(const manager &m, const string &rpo)
    : abstr_emp(m), fink(m, rpo), manager(m)
{}

highfink::highfink(const highfink & h)
    :abstr_emp(h), fink(h), manager(h)
{}

void highfink::ShowAll() const
{
    manager::ShowAll();
    cout << "Reportsto: " << ReportsTo() << endl;
    cout << endl;
}

void highfink::SetAll()
{
    manager::SetAll();
    cout << "Enter the reportsto: ";
    getline(cin, fink::ReportsTo());
}