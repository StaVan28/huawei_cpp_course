
#include "complex.hpp"

int main() 
{
    Clx::Complex my_complex1(1, 2);
    Clx::Complex my_complex2(NAN, 4);

    Clx::Complex my_complex = my_complex1 - my_complex2;

    my_complex.print();

    return 0;
}
