#include "Arithmetics.hh"
#include "Complex.hh"

Complex conjugate(Complex c)
{
    c.im *= -1;
    return c;
}

double absSquared(Complex c)
{
    double result = (c.re * c.re) + (c.im * c.im);
    return result;
}