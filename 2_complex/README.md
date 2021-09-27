# Complex number

This my realization on Complex number.

## Installation

Clone the repository. 

    git clone https://github.com/StaVan28/huawei_cpp_course.git huawei

Go to the List project.

    cd huawei/2_complex

And install

    make install

After this step you can use my lists)

Compilation and launch

    make 

Launch tests

    make tests

## Example of use 

```C++
    #include "complex.hpp"

    int main()
    {   
        // init Complex  
        Clx::Complex gthb_example(1.5, 2);
        // or
        // With default (0; 0)
        Clx::Complex gthb_example_default;

        // Also implemented set_{real, imag}() funcs:
        gthb_example_default.set_real(7);
        gthb_example_default.set_imag(4.6);

        // Complex number have realization this basic operations: 
        // +, -, *, / (also +=, -=, *=, /=)
        // With complex numbers and double
        double dbl_exemple_1 = 3.3;
        double dbl_exemple_2 = 0.5;

        //( (1.5, 2) => (4.8, 2) )
        gthb_example += dbl_exemple_1; 

        //( (7, 4.6) => (2.4, 1) )
        gthb_example_default = gthb_example * dbl_exemple_2;

        //to convince us, we will display it on the screen
        gthb_example_default.print();
    }
```

    
