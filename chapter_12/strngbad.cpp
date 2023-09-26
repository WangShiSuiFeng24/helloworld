// strngbad.cpp -- StringBad class methods
#include <cstring>
#include "strngbad.h"
using std::cout;

// initializing static class member
int StringBad::num_strings = 0;

// class methods
// construct StringBad from C string
StringBad::StringBad(const char * s)
{
    len = std::strlen(s);       // set size
    str = new char[len + 1];    // allot storage
    std::strcpy(str, s);        // initialize pointer
    num_strings++;
    cout << num_strings << ": \"" << str
         << "\" obeject created\n"; // For Your Information
}

StringBad::StringBad()
{
    len = 4;
    str = new char[4];
    std::strcpy(str, "C++");
    num_strings++;
    cout << num_strings << ": \"" << str
         << "\" object created\n"; // FYI
}

StringBad::StringBad(const StringBad & s)
{
    num_strings++;
    len = s.len;
    str = new char[len + 1];
    std::strcpy(str, s.str);
    cout << num_strings << ": \"" << str
         << "\" object created\n";
}

StringBad::~StringBad()         // necessary destructor
{
    cout << "\"" << str << "\" object deleted, ";   // FYI
    --num_strings;
    cout << num_strings << " left\n";
    delete[] str;
}

StringBad & StringBad::operator=(const StringBad & s)
{
    if (this == &s)
        return *this;
    delete[] str;
    len = s.len;
    str = new char[len + 1];
    std::strcpy(str, s.str);
    return *this;
}

std::ostream & operator<<(std::ostream& os, const StringBad & st)
{
    os << st.str;
    return os;
}