#include "Complex.hh"
#include "Arithmetics.hh"

/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    arg1 - pierwszy skladnik dodawania,
 *    arg2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
Complex operator+(Complex arg1, Complex arg2)
{
    Complex result;

    result.re = arg1.re + arg2.re;
    result.im = arg1.im + arg2.im;
    return result;
}

Complex operator-(Complex arg1, Complex arg2)
{
    Complex result;

    result.re = arg1.re - arg2.re;
    result.im = arg1.im - arg2.im;
    return result;
}

Complex operator*(Complex arg1, Complex arg2)
{
    Complex result;

    result.re = (arg1.re * arg2.re) - (arg1.im * arg2.im);
    result.im = (arg1.re * arg2.im) + (arg1.im * arg2.re);
    return result;
}

Complex operator/(Complex arg1, Complex arg2)
{
    Complex result;

    result = (arg1 * conjugate(arg2)) / absSquared(arg2);

    if(result.im == 0)
        result.im = 0;
    if(result.re == 0)
        result.re = 0;
    
    return result;
}

Complex operator/(Complex arg1, double arg2)
{
    arg1.re /= arg2;
    arg1.im /= arg2;
    return arg1;
}