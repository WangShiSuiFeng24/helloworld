#include <iostream>
#include "complex0.h"

complex::complex(double real, double imaginary)
{
    this->real = real;
    this->imaginary = imaginary;
}

complex::~complex()
{}

complex complex::operator+(const complex & c) const
{
    return complex(real + c.real, imaginary + c.imaginary);
}

complex complex::operator-(const complex & c) const
{
    return complex(real - c.real, imaginary - c.imaginary);
}

complex complex::operator*(const complex & c) const
{
    return complex(real * c.real - imaginary * c.imaginary, real * c.imaginary + imaginary * c.real);
}

complex complex::operator~() const
{
    return complex(real, -imaginary);
}

complex operator*(double x, const complex & c)
{
    return complex(x * c.real, x * c.imaginary);
}

std::istream & operator>>(std::istream & is, complex & c)
{
    std::cout << "real: ";
    if (!(is >> c.real))
        return is;
    std::cout << "imaginary: ";
    is >> c.imaginary;
    return is;
}

std::ostream & operator<<(std::ostream & os, const complex & c)
{
    os << "(" << c.real << ", " << c.imaginary << "i)";
    return os;
}