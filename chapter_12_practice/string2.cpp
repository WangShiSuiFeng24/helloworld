// compile with 12_2.cpp
#include "string2.h"
#include <cstring>
#include <cctype>

int String::num_strings = 0;

String::String()
{
    str = new char[1];
    str[0] = '\0';
    len = 0;
    num_strings++;
}

String::String(const char * s)
{
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    num_strings++;
}

String::String(const String & st)
{
    len = st.length();
    str = new char[len + 1];
    std::strcpy(str, st.str);
    num_strings++;
}

String::~String()
{
    if (str != nullptr)
        delete[] str;
    --num_strings;
}

void String::stringlow()
{
    for (int i = 0; i < len; ++i)
        str[i] = std::tolower(str[i]);
}

void String::stringup()
{
    for (int i = 0; i < len; ++i)
        str[i] = std::toupper(str[i]);
}

int String::has(char c) const
{
    int count;
    for (int i = 0; i < len; ++i)
        if (c == str[i])
            ++count;
    return count;
}

String & String::operator=(const char *s)
{
    delete[] str;
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    return *this;
}
String & String::operator=(const String & st)
{
    if (this == &st)
        return *this;
    delete[] str;
    len = st.length();
    str = new char[len + 1];
    std::strcpy(str, st.str);
    return *this;
}

char & String::operator[](int i)
{
    return str[i];
}

const char & String::operator[](int i) const
{
    return str[i];
}

String operator+(const String &s, const String &st)
{
    String result;
    result.len = s.len + st.len;
    result.str = new char[result.len + 1];
    std::strcpy(result.str, s.str);
    std::strcat(result.str, st.str);
    return result;
}

String operator+(const char *st, const String &s)
{
    String result;
    result.len = strlen(st) + s.len;
    result.str = new char[result.len + 1];
    std::strcpy(result.str, st);
    std::strcat(result.str, s.str);
    return result;
}

bool operator<(const String &st1, const String &st2) 
{
    return (strcmp(st1.str, st2.str) < 0);
}

bool operator>(const String &st1, const String &st2)
{
    return (strcmp(st1.str, st2.str) > 0);
}

bool operator==(const String &st1, const String &st2)
{
    return (strcmp(st1.str, st2.str) == 0);
}

std::ostream & operator<<(std::ostream & os, const String & st)
{
    os << st.str;
    return os;
}

std::istream & operator>>(std::istream & is, String & st)
{
    char temp[String::CINLIM];
    is.get(temp, String::CINLIM);
    if (is)
        st = temp;
    while (is && is.get() != '\n')
        continue;
    return is;
}

int String::HowMany()
{
    return num_strings;
}