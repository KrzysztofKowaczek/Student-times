#include "Complex.hh"

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

/*!
 * Realizuje odejmowanie dwoch liczb zespolonych.
 * PRE:
 *      arg1 - pierwszy skladnik odejmowania,
 *      arg2 - drugi skladnik odejmowania.
 * POST:
 *      Zwraca roznice dwoch skladnikow przekazanych jako parametry.
 */ 
Complex operator-(Complex arg1, Complex arg2)
{
    Complex result;

    result.re = arg1.re - arg2.re;
    result.im = arg1.im - arg2.im;
    return result;
}

/*!
 * Realizuje mnozenie dwoch liczb zespolonych.
 * PRE:
 *      arg1 - pierwszy skladnik mnozenia,
 *      arg2 - drugi skladnik mnozenia.
 * POST:
 *      Zwraca iloczyn dwoch skladnikow przekazanych jako parametry.
 */ 
Complex operator*(Complex arg1, Complex arg2)
{
    Complex result;

    result.re = (arg1.re * arg2.re) - (arg1.im * arg2.im);
    result.im = (arg1.re * arg2.im) + (arg1.im * arg2.re);
    return result;
}

/*!
 * Realizuje dzielenie dwoch liczb zespolonych.
 * PRE:
 *      arg1 - pierwszy skladnik dzielenia,
 *      arg2 - drugi skladnik dzielenia.
 * POST:
 *      Zwraca iloraz dwoch skladnikow przekazanych jako parametry.
 */ 
Complex operator/(Complex arg1, Complex arg2)
{
    Complex result;

    result = (arg1 * Conjugate(arg2)) / AbsSquared(arg2);

    if(result.im == 0)
        result.im = 0;
    if(result.re == 0)
        result.re = 0;
    
    return result;
}

/*!
 * Realizuje dzielenie liczby zespolonej i rzeczywistej.
 * PRE:
 *      arg1 - liczba zespolona,
 *      arg2 - liczba rzeczywista.
 * POST:
 *      Zwraca iloraz dwoch skladnikow przekazanych jako parametry.
 */ 
Complex operator/(Complex arg1, double arg2)
{
    arg1.re /= arg2;
    arg1.im /= arg2;
    return arg1;
}

/*!
 * Realizuje sprzezenie liczby zespolonej.
 * PRE:
 *      c - liczba zespolona do sprzezenia.
 * POST:
 *      Zwraca sprzezona liczbe zespolona.
 */
Complex Conjugate(Complex c)
{
    c.im *= -1;
    return c;
}

/*!
 * Liczy kwadrat modulu liczby zespolonej.
 * PRE:
 *      c - liczba zespolona.
 * POST:
 *      Zwraca podniesiony do kwadratu modul liczby zespolonej.
 */
double AbsSquared(Complex c)
{
    double result = (c.re * c.re) + (c.im * c.im);
    return result;
}