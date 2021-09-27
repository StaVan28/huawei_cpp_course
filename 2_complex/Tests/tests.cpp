
#include "tests.hpp"

//-------------------------------------------------------------

void Clx::ComplexTests::unit_tests()
{
	test_1_default_constr();
	
	test_2_constr();

	test_3_copy_constr();

	test_4_assignm_oper();

	test_5_get_real();

	test_6_get_imag();

	test_7_set_real();

	test_8_set_imag();

	test_9_pl_clx();

	test_10_mn_clx();

	test_11_ml_clx();

	test_12_dv_clx();

	test_13_pleq_clx();

	test_14_mneq_clx();

	test_15_mleq_clx();

	test_16_dveq_clx();

	test_17_pl_dbl();

	test_18_mn_dbl();

	test_19_ml_dbl();

	test_20_dv_dbl();

	test_21_pleq_dbl();

	test_22_mneq_dbl();

	test_23_mleq_dbl();

	test_24_dveq_dbl();

	test_25_pl_unary();

	test_26_mn_unary();

	test_27_eq_oper();

	test_28_uneq_oper();

    return;
}

//----------------

void Clx::ComplexTests::test_1_default_constr()
{
	printf("Test { 1}: ");

	Complex test_clx;

	if (!is_different(test_clx.real_, 0) && !is_different(test_clx.imag_, 0))
		printf("Success! [V]\n");
	else
		printf("ERROR ERROR ERROR! [X]\n");

    return;
}

//----------------

void Clx::ComplexTests::test_2_constr()
{
	printf("Test { 2}: ");

	Complex test_clx(1.01, -123.43);

	if (!is_different(test_clx.real_, 1.01) && !is_different(test_clx.imag_, -123.43))
		printf("Success! [V]\n");
	else
		printf("ERROR ERROR ERROR! [X]\n");

    return;
}

//----------------

void Clx::ComplexTests::test_3_copy_constr()
{
	printf("Test { 3}: ");

	Complex test_clx_1(-2.03, -1073.3);
	Complex test_clx_2(test_clx_1);

	if (!is_different(test_clx_2.real_, -2.03) && !is_different(test_clx_2.imag_, -1073.3))
		printf("Success! [V]\n");
	else
		printf("ERROR ERROR ERROR! [X]\n");

    return;
}

//----------------

void Clx::ComplexTests::test_4_assignm_oper()
{
	printf("Test { 4}: ");

	Complex test_clx_1(-2.03, -1073.3);
	Complex test_clx_2 = test_clx_1;

	if (!is_different(test_clx_2.real_, -2.03) && !is_different(test_clx_2.imag_, -1073.3))
		printf("Success! [V]\n");
	else
		printf("ERROR ERROR ERROR! [X]\n");

    return;
}

//----------------

void Clx::ComplexTests::test_5_get_real()
{
	printf("Test { 5}: ");

	Complex test_clx(9909, -5634.2);

	if (!is_different(test_clx.get_real(), 9909))
		printf("Success! [V]\n");
	else
		printf("ERROR ERROR ERROR! [X]\n");

    return;
}

//----------------

void Clx::ComplexTests::test_6_get_imag()
{
	printf("Test { 6}: ");

	Complex test_clx(9909, -5634.2);

	if (!is_different(test_clx.get_imag(), -5634.2))
		printf("Success! [V]\n");
	else
		printf("ERROR ERROR ERROR! [X]\n");

    return;
}

//----------------

void Clx::ComplexTests::test_7_set_real()
{
	printf("Test { 7}: ");

	Complex test_clx(9909, -5634.2);
	test_clx.set_real(-9302.1829);

	if (!is_different(test_clx.real_, -9302.1829))
		printf("Success! [V]\n");
	else
		printf("ERROR ERROR ERROR! [X]\n");

    return;
}

//----------------

void Clx::ComplexTests::test_8_set_imag()
{
	printf("Test { 8}: ");

	Complex test_clx(9909, -5634.2);
	test_clx.set_imag(-9302.1829);

	if (!is_different(test_clx.imag_, -9302.1829))
		printf("Success! [V]\n");
	else
		printf("ERROR ERROR ERROR! [X]\n");

    return;
}

//----------------

void Clx::ComplexTests::test_9_pl_clx()
{
	printf("Test { 9}: ");

	Complex test_clx_1(9909, -5634.2);
	Complex test_clx_2(1, 19.2);

	Complex test_clx = test_clx_1 + test_clx_2;

	if (!is_different(test_clx.real_, 9910) && !is_different(test_clx.imag_, -5615))
		printf("Success! [V]\n");
	else
		printf("ERROR ERROR ERROR! [X]\n");

    return;
}

//----------------

void Clx::ComplexTests::test_10_mn_clx()
{
	printf("Test {10}: ");

	Complex test_clx_1(9909, -5634.2);
	Complex test_clx_2(1, 19.2);

	Complex test_clx = test_clx_1 - test_clx_2;

	if (!is_different(test_clx.real_, 9908) && !is_different(test_clx.imag_, -5653.4))
		printf("Success! [V]\n");
	else
		printf("ERROR ERROR ERROR! [X]\n");

    return;
}

//----------------

void Clx::ComplexTests::test_11_ml_clx()
{
	printf("Test {11}: ");

	Complex test_clx_1(9909, -5634.2);
	Complex test_clx_2(1, 0.5);

	Complex test_clx = test_clx_1 * test_clx_2;

	if (!is_different(test_clx.real_, 12726.1) && !is_different(test_clx.imag_, -679.7))
		printf("Success! [V]\n");
	else
		printf("ERROR ERROR ERROR! [X]\n");

    return;
}

//----------------

void Clx::ComplexTests::test_12_dv_clx()
{
	printf("Test {12}: ");

	Complex test_clx_1(9909, -5634.2);
	Complex test_clx_2(1, 0.5);

	Complex test_clx = test_clx_1 / test_clx_2;

	if (!is_different(test_clx.real_, 5673.52) && !is_different(test_clx.imag_, -8470.96))
		printf("Success! [V]\n");
	else
		printf("ERROR ERROR ERROR! [X]\n");

    return;
}

//----------------

void Clx::ComplexTests::test_13_pleq_clx()
{
	printf("Test {13}: ");

	Complex test_clx_1(-7438.14, 12939);
	Complex test_clx_2(123, -12); 

	test_clx_2 += test_clx_1;

	if (!is_different(test_clx_2.real_, -7315.14) && !is_different(test_clx_2.imag_, 12927))
		printf("Success! [V]\n");
	else
		printf("ERROR ERROR ERROR! [X]\n");

    return;
}

//----------------

void Clx::ComplexTests::test_14_mneq_clx()
{
	printf("Test {14}: ");

	Complex test_clx_1(-7438.14, 12939);
	Complex test_clx_2(123, -12); 

	test_clx_2 -= test_clx_1;

	if (!is_different(test_clx_2.real_, 7561.14) && !is_different(test_clx_2.imag_, -12951))
		printf("Success! [V]\n");
	else
		printf("ERROR ERROR ERROR! [X]\n");

    return;
}

//----------------

void Clx::ComplexTests::test_15_mleq_clx()
{
	printf("Test {15}: ");

	Complex test_clx_1(-34.14, 19);
	Complex test_clx_2(12.2, 22.1); 

	test_clx_2 *= test_clx_1;

	if (!is_different(test_clx_2.real_, -836.408) && !is_different(test_clx_2.imag_, -522.694))
		printf("Success! [V]\n");
	else
		printf("ERROR ERROR ERROR! [X]\n");

    return;
}

//----------------

void Clx::ComplexTests::test_16_dveq_clx()
{
	printf("Test {16}: ");

	Complex test_clx_1(3, 4);
	Complex test_clx_2(12.2, 22.1); 

	test_clx_2 /= test_clx_1;

	if (!is_different(test_clx_2.real_, 5) && !is_different(test_clx_2.imag_, 0.7))
		printf("Success! [V]\n");
	else
		printf("ERROR ERROR ERROR! [X]\n");

    return;
}

//----------------

void Clx::ComplexTests::test_17_pl_dbl()
{
	printf("Test {17}: ");

	Complex test_clx_1(9909, -5634.2);
	double test_dbl = -12;

	Complex test_clx = test_clx_1 + test_dbl;

	if (!is_different(test_clx.real_, 9897) && !is_different(test_clx.imag_, -5634.2))
		printf("Success! [V]\n");
	else
		printf("ERROR ERROR ERROR! [X]\n");

    return;
}

//----------------

void Clx::ComplexTests::test_18_mn_dbl()
{
	printf("Test {18}: ");

	Complex test_clx_1(9909, -5634.2);
	double test_dbl = -12;

	Complex test_clx = test_clx_1 - test_dbl;

	if (!is_different(test_clx.real_, 9921) && !is_different(test_clx.imag_, -5634.2))
		printf("Success! [V]\n");
	else
		printf("ERROR ERROR ERROR! [X]\n");

    return;
}

//----------------

void Clx::ComplexTests::test_19_ml_dbl()
{
	printf("Test {19}: ");

	Complex test_clx_1(9909, -5634.2);
	double test_dbl = 2;

	Complex test_clx = test_clx_1 * test_dbl;

	if (!is_different(test_clx.real_, 19818) && !is_different(test_clx.imag_, -11268.4))
		printf("Success! [V]\n");
	else
		printf("ERROR ERROR ERROR! [X]\n");

    return;
}

//----------------

void Clx::ComplexTests::test_20_dv_dbl()
{
	printf("Test {20}: ");

	Complex test_clx_1(9909, -5634.2);
	double test_dbl = 2;

	Complex test_clx = test_clx_1 / test_dbl;

	if (!is_different(test_clx.real_, 4954.5) && !is_different(test_clx.imag_, -2817.1))
		printf("Success! [V]\n");
	else
		printf("ERROR ERROR ERROR! [X]\n");

    return;
}

//----------------

void Clx::ComplexTests::test_21_pleq_dbl()
{
	printf("Test {21}: ");

	Complex test_clx(12.2, 22.1);
	double test_dbl = 8;

	test_clx += test_dbl;

	if (!is_different(test_clx.real_, 20.2) && !is_different(test_clx.imag_, 22.1))
		printf("Success! [V]\n");
	else
		printf("ERROR ERROR ERROR! [X]\n");

    return;
}

//----------------

void Clx::ComplexTests::test_22_mneq_dbl()
{
	printf("Test {22}: ");

	Complex test_clx(12.2, 22.1);
	double test_dbl = 8;

	test_clx -= test_dbl;

	if (!is_different(test_clx.real_, 4.2) && !is_different(test_clx.imag_, 22.1))
		printf("Success! [V]\n");
	else
		printf("ERROR ERROR ERROR! [X]\n");

    return;
}

//----------------

void Clx::ComplexTests::test_23_mleq_dbl()
{
	printf("Test {23}: ");

	Complex test_clx(12.2, 22.1);
	double test_dbl = 8;

	test_clx *= test_dbl;

	if (!is_different(test_clx.real_, 97.6) && !is_different(test_clx.imag_, 176.8))
		printf("Success! [V]\n");
	else
		printf("ERROR ERROR ERROR! [X]\n");

    return;
}

//----------------

void Clx::ComplexTests::test_24_dveq_dbl()
{
	printf("Test {24}: ");

	Complex test_clx(12.2, 22.1);
	double test_dbl = 8;

	test_clx /= test_dbl;

	if (!is_different(test_clx.real_, 1.525) && !is_different(test_clx.imag_, 2.7625))
		printf("Success! [V]\n");
	else
		printf("ERROR ERROR ERROR! [X]\n");

    return;
}

//----------------

void Clx::ComplexTests::test_25_pl_unary()
{
	printf("Test {25}: ");

	Complex test_clx(1.01, -123.43);

	test_clx = +test_clx;

	if (!is_different(test_clx.real_, 1.01) && !is_different(test_clx.imag_, -123.43))
		printf("Success! [V]\n");
	else
		printf("ERROR ERROR ERROR! [X]\n");

    return;
}

//----------------

void Clx::ComplexTests::test_26_mn_unary()
{
	printf("Test {26}: ");

	Complex test_clx(1.01, -123.43);

	test_clx = -test_clx;

	if (!is_different(test_clx.real_, -1.01) && !is_different(test_clx.imag_, 123.43))
		printf("Success! [V]\n");
	else
		printf("ERROR ERROR ERROR! [X]\n");

    return;
}

//----------------

void Clx::ComplexTests::test_27_eq_oper()
{
	printf("Test {27}: ");

	Complex test_clx_1(3.90, 4.23);
	Complex test_clx_2(3.90, 4.23); 

	if (!is_different(test_clx_1.real_, test_clx_2.real_) && \
		!is_different(test_clx_1.imag_, test_clx_2.imag_))
		printf("Success! [V]\n");
	else
		printf("ERROR ERROR ERROR! [X]\n");

    return;
}

//----------------

void Clx::ComplexTests::test_28_uneq_oper()
{
	printf("Test {28}: ");

	Complex test_clx_1(3, 4);
	Complex test_clx_2(12.2, 22.1); 

	if (is_different(test_clx_1.real_, test_clx_2.real_) || \
		is_different(test_clx_1.imag_, test_clx_2.imag_))
		printf("Success! [V]\n");
	else
		printf("ERROR ERROR ERROR! [X]\n");

    return;
}

//----------------
