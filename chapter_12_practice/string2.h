#ifndef STRING2_H_
#define STRING2_H_
#include <iostream>

class String
{
private:
    char *str;
    int len;
    static int num_strings;
    static const int CINLIM = 80;

public:
    String();
    String(const char * s);
    String(const String &);
    ~String();
    int length() const { return len; }

    void stringlow();
    void stringup();
    int has(char c) const;

    String &operator=(const String &);
    String &operator=(const char *);
    char &operator[](int i);
    const char &operator[](int i) const;

    friend String operator+(const String &s, const String &st);
    friend String operator+(const char *s, const String &st);

    friend bool operator<(const String &st1, const String &st2);
    friend bool operator>(const String &st1, const String &st2);
    friend bool operator==(const String &st1, const String &st2);
    friend std::ostream &operator<<(std::ostream &os, const String &st);
    friend std::istream &operator>>(std::istream &is, String &st);

    static int HowMany();
};
#endif