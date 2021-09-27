#include <cmath>

//!

#include "double.hpp"

//------------------------------------------

double is_different(double value_1, double value_2)
{
	if (fabs(value_1 - value_2) > EPSILON)
		return value_1 - value_2;
	else
		return 0;
}

//---------------------