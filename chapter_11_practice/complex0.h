#ifndef COMPLEX0_H_
#define COMPLEX0_H_
#include <iostream>
class complex
{
private:
    double real;
    double imaginary;
public:
    complex(double real = 0.0, double imaginary = 0.0);
    ~complex();

    complex operator+(const complex &c) const;
    complex operator-(const complex &c) const;
    complex operator*(const complex &c) const;
    //complex operator*(double n) const;
    complex operator~() const;

    friend complex operator*(double n, const complex &c);
    friend std::istream &operator>>(std::istream &is, complex &c);
    friend std::ostream &operator<<(std::ostream &os, const complex &c);
};

#endif