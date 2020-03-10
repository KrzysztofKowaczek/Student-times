#include "Expression.hh"
#include "Complex.hh"
#include <iostream>

/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */


/*!
 * Wyswietla wyrazenie liczb zespolonych.
 * PRE:
 *      expr - wyrazenie liczb zespolonych.
 */
void Display(Expression expr)
{
    Display(expr.arg1);
    switch(expr.op)
    {
        case kAddition:
        std::cout << "+";
        break;
        case kMultiplication:
        std::cout << "*";
        break;
        case kSubtraction:
        std::cout << "-";
        break;
        case kDivision:
        std::cout << "/";
        break;
    }
    Display(expr.arg2);
}


/*!
 * Wyswietla pojedyncza liczbe zespolona w postaci (x+yi).
 * PRE:
 *      c - liczba zespolona.
 */
void Display(Complex c)
{
    if(c.im < 0)
        std::cout << "(" << c.re << c.im << "i" << ")";
    else 
        std::cout << "(" << c.re << "+" << c.im << "i" << ")";
}

/*!
 * Rozwiazuje wyrazenie liczb zespolonych.
 * PRE:
 *      expr - wyrazenie liczb zespolonych.
 * POST:
 *      Zwraca wynik wyrazenia liczb zespolonych.
 */
Complex Solve(Expression expr)
{
    Complex result;
    switch(expr.op)
    {
        case kAddition:
            result = expr.arg1 + expr.arg2;
            break;
        case kMultiplication:
            result = expr.arg1 * expr.arg2;
            break;
        case kSubtraction:
            result = expr.arg1 - expr.arg2;
            break;
        case kDivision:
            result = expr.arg1 / expr.arg2;
            break;
    }
    return result;
}