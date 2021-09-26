
#ifndef COMPLEX_HPP_INCLUDED
#define COMPLEX_HPP_INCLUDED

//-----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <errno.h>
#include <string.h>
#include <fstream>

//!

#include "consts.hpp"

//-----------------------------------------------------------------------------

namespace Complex
{

class Complex 
{

private:

    double real_ = POISON;
    double imag_ = POISON;

//--------------------------------------------------

public:

//------------------------

Complex() = delete;

//------------------------

Complex(double real, double imag) :
    real_{real},
    imag_{imag}
{}

//------------------------

~Complex()
{
    real_ = POISON;
    imag_ = POISON;
}

//------------------------

double get_real() const
{
    return real_;
}

//------------------------

double get_imag() const
{
    return imag_;
}

//------------------------

void set_real(double real)
{
    real_ = real;
}

//------------------------

void set_imag(double imag)
{
    imag_ = imag;
}


//------------------------

friend std::ostream& operator << (std::ostream& out, const Complex& clx)
{
    out << "(" << clx.real_ << ";" << clx.imag_ << ")" << std::endl;
    return out;
}

//------------------------

void print() const
{
    printf("(%lg;%lg)\n", real_, imag_);
}

}; // Complex class

}  // Complex namespace

//-----------------------------------------------------------------------------

#endif // COMPLEX_HPP_INCLUDED
