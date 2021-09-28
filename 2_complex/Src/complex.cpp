
#include "complex.hpp"

//-----------------------------------

Clx::Complex::Complex() :
    real_{0},
    imag_{0}
{}

//-----------------------------------

Clx::Complex::Complex(double real, double imag)
{
    if (set_real(real))
    {
        fprintf(stderr, "SOLUTION: Real part = 0\n");
        real_ = 0;
    }

    if (set_imag(imag))
    {
        fprintf(stderr, "SOLUTION: Imag part = 0\n");
        imag_ = 0;
    }
}

//------------------------

Clx::Complex::~Complex()
{}

//------------------------

Clx::Complex::Complex(const Clx::Complex& clx) :
    real_{clx.real_},
    imag_{clx.imag_}    
{}

//------------------------

Clx::Complex& Clx::Complex::operator = (const Clx::Complex& clx)
{
    real_ = clx.real_;
    imag_ = clx.imag_;

    return *this;
}

//------------------------

bool Clx::Complex::set_real(double real)
{
    if (std::isnan(real))
    {
        fprintf(stderr, "ERROR! NAN in real part\n");
        return ISNAN_ERROR;
    }

    real_ = real;
    return 0;
}

//------------------------

bool Clx::Complex::set_imag(double imag)
{
    if (std::isnan(imag))
    {
        fprintf(stderr, "ERROR! NAN in imag part\n");
        return ISNAN_ERROR;
    }

    imag_ = imag;
    return 0;
}

//------------------------

void Clx::Complex::print() const
{
    printf("(%lg;%lg)\n", real_, imag_);
}

//------------------------

Clx::Complex Clx::Complex::operator + (const Complex& clx) const
{
    Clx::Complex tmp_complex;

    tmp_complex.real_ = real_ + clx.real_;
    tmp_complex.imag_ = imag_ + clx.imag_;    

    return tmp_complex;
}

//------------------------

Clx::Complex Clx::Complex::operator - (const Complex& clx) const
{
    Clx::Complex tmp_complex;

    tmp_complex.real_ = real_ - clx.real_;
    tmp_complex.imag_ = imag_ - clx.imag_;    

    return tmp_complex;
}

//------------------------

Clx::Complex Clx::Complex::operator * (const Complex& clx) const
{
    Clx::Complex tmp_complex;

    tmp_complex.real_ = real_ * clx.real_ - imag_ * clx.imag_;
    tmp_complex.imag_ = real_ * clx.imag_ + imag_ * clx.real_;    

    return tmp_complex;
}

//------------------------

Clx::Complex Clx::Complex::operator / (const Complex& clx) const
{
    double modul = clx.modul();
    if (!is_different(modul, 0))
    {
        fprintf(stderr, "ERROR! Division on zero!");
        return *this;
    }

    Clx::Complex tmp_complex;

    tmp_complex.real_ = (real_ * clx.real_ + imag_ * clx.imag_) / modul;
    tmp_complex.imag_ = (imag_ * clx.real_ - real_ * clx.imag_) / modul;    

    return tmp_complex;    
}

//------------------------

double Clx::Complex::modul() const
{
    return real_ * real_ + imag_ * imag_;
}

//------------------------

Clx::Complex& Clx::Complex::operator += (const Clx::Complex& clx)
{
    real_ = real_ + clx.real_;
    imag_ = imag_ + clx.imag_;    

    return *this;        
}

//------------------------

Clx::Complex& Clx::Complex::operator -= (const Clx::Complex& clx)
{
    real_ = real_ - clx.real_;
    imag_ = imag_ - clx.imag_;    

    return *this;
}

//------------------------

Clx::Complex& Clx::Complex::operator *= (const Clx::Complex& clx)
{
    Complex tmp_clx(*this);

    real_ = tmp_clx.real_ * clx.real_ - tmp_clx.imag_ * clx.imag_;
    imag_ = tmp_clx.real_ * clx.imag_ + tmp_clx.imag_ * clx.real_;

    return *this;
}

//------------------------

Clx::Complex& Clx::Complex::operator /= (const Clx::Complex& clx)
{
    double modul = clx.modul();
    if (!is_different(modul, 0))
    {
        fprintf(stderr, "ERROR! Division on zero!");
        return *this;
    }

    Complex tmp_clx(*this);

    real_ = (tmp_clx.real_ * clx.real_ + tmp_clx.imag_ * clx.imag_) / modul;
    imag_ = (tmp_clx.imag_ * clx.real_ - tmp_clx.real_ * clx.imag_) / modul;

    return *this;    
}

//------------------------

Clx::Complex Clx::Complex::operator + (double num) const
{
    Clx::Complex tmp_complex;

    tmp_complex.real_ = real_ + num;
    tmp_complex.imag_ = imag_;

    return tmp_complex;
}

//------------------------

Clx::Complex Clx::Complex::operator - (double num) const
{
    Clx::Complex tmp_complex;

    tmp_complex.real_ = real_ - num;
    tmp_complex.imag_ = imag_;    

    return tmp_complex;
}

//------------------------

Clx::Complex Clx::Complex::operator * (double num) const
{
    Clx::Complex tmp_complex;

    tmp_complex.real_ = real_ * num;
    tmp_complex.imag_ = imag_ * num;    

    return tmp_complex;
}

//------------------------

Clx::Complex Clx::Complex::operator / (double num) const
{
    if (!is_different(num, 0))
    {
        fprintf(stderr, "ERROR! Division on zero!");
        return *this;
    }

    Clx::Complex tmp_complex;

    tmp_complex.real_ = real_ / num;
    tmp_complex.imag_ = imag_ / num;    

    return tmp_complex;
}

//------------------------

Clx::Complex& Clx::Complex::operator += (double num)
{
    real_ = real_ + num;    

    return *this;        
}

//------------------------

Clx::Complex& Clx::Complex::operator -= (double num)
{
    real_ = real_ - num;    

    return *this;        
}

//------------------------

Clx::Complex& Clx::Complex::operator *= (double num)
{
    real_ = real_ * num;
    imag_ = imag_ * num;    

    return *this;        
}

//------------------------

Clx::Complex& Clx::Complex::operator /= (double num)
{
    if (!is_different(num, 0))
    {
        fprintf(stderr, "ERROR! Division on zero!");
        return *this;
    }

    real_ = real_ / num;
    imag_ = imag_ / num;    

    return *this;
}

//------------------------

Clx::Complex Clx::Complex::operator + () const
{
    return *this;
}

//------------------------

Clx::Complex Clx::Complex::operator - ()
{
    Clx::Complex tmp_complex;

    tmp_complex.real_ = -real_;
    tmp_complex.imag_ = -imag_;    

    return tmp_complex;
}

//------------------------

bool Clx::Complex::operator == (const Clx::Complex& clx) const
{
    return (!is_different(real_, clx.real_) && !is_different(imag_, clx.imag_));
}

//------------------------

bool Clx::Complex::operator != (const Clx::Complex& clx) const
{
    return (is_different(real_, clx.real_) || is_different(imag_, clx.imag_));
}

//------------------------