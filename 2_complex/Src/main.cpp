
#include "complex.hpp"

int main() 
{
    Complex::Complex my_complex(1, 2);

    std::ofstream out;
    out << my_complex;

    return 0;
}
