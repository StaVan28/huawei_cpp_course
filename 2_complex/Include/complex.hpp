
#ifndef COMPLEX_HPP_INCLUDED
#define COMPLEX_HPP_INCLUDED

//-----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <errno.h>
#include <string.h>

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

//------------------------

public:

//--------------------------------------------------

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

}; // Complex class

}  // Complex namespace

//-----------------------------------------------------------------------------

#endif // COMPLEX_HPP_INCLUDED
