
#ifndef COMPLEX_H_INCLUDED
#define COMPLEX_H_INCLUDED

//-----------------------------------------------------------------------------

namespace Clx
{

const double EPSILON_BORDER = 1e-6;

//!

struct Complex 
{
    double real_;
    double imag_;

    // constructs
    Complex();
    Complex(double real, double imag);
    Complex(const Complex& clx);

   ~Complex();
   
    Complex& operator = (const Complex& clx); 

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
    Complex operator + () const;
    Complex operator - () const;    

    // comparison
    bool operator == (const Complex& clx) const;
    bool operator != (const Complex& clx) const;

    // other funcs
    double modul() const;
    void   print() const;

}; // Complex class

double is_different(double value_1, double value_2);

}  // Complex namespace

//-----------------------------------------------------------------------------

#endif // COMPLEX_H_INCLUDED
