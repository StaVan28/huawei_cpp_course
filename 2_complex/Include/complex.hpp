
#ifndef COMPLEX_HPP_INCLUDED
#define COMPLEX_HPP_INCLUDED

//-----------------------------------------------------------------------------

#include <iostream>
#include <cmath>

//!

#include "consts.hpp"
#include "double.hpp"

//-----------------------------------------------------------------------------

namespace Clx
{

class Complex 
{

private:

    double real_;
    double imag_;

//--------------------------------------------------

public:

    // constructs
    Complex();
    Complex(double real, double imag);

    // rule of 3
   ~Complex();
    Complex(const Complex& clx);
    Complex& operator = (const Complex& clx);  

    // getters
    double get_real() const;
    double get_imag() const;

    // setters
    bool set_real(double real);
    bool set_imag(double imag);

    // operations with complex number
    Complex operator + (const Complex& clx) const;
    Complex operator - (const Complex& clx) const;
    Complex operator * (const Complex& clx) const;
    Complex operator / (const Complex& clx) const;

    Complex& operator += (const Complex& clx);
    Complex& operator -= (const Complex& clx);
    Complex& operator *= (const Complex& clx);
    Complex& operator /= (const Complex& clx);

    // operations with double
    Complex operator + (double num) const;
    Complex operator - (double num) const;
    Complex operator * (double num) const;
    Complex operator / (double num) const;

    Complex& operator += (double num);
    Complex& operator -= (double num);
    Complex& operator *= (double num);
    Complex& operator /= (double num);

    // unary operations
    Complex operator + ();
    Complex operator - ();

    // comparison
    bool operator == (const Complex& clx) const;
    bool operator != (const Complex& clx) const;

    // other funcs
    double modul() const;
    void   print() const;

}; // Complex class

}  // Complex namespace

//-----------------------------------------------------------------------------

#endif // COMPLEX_HPP_INCLUDED
