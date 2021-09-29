
#ifndef TESTS_H_INCLUDED
#define TESTS_H_INCLUDED

//-----------------------------------------------------------------------------

struct ComplexTests
{
	void unit_tests();

	void test_1_default_constr();
	
	void test_2_constr();

	void test_3_copy_constr();

	void test_4_assignm_oper();

	void test_5_get_real();

	void test_6_get_imag();

	void test_7_set_real();

	void test_8_set_imag();

	void test_9_pl_clx();

	void test_10_mn_clx();

	void test_11_ml_clx();

	void test_12_dv_clx();

	void test_13_pleq_clx();

	void test_14_mneq_clx();

	void test_15_mleq_clx();

	void test_16_dveq_clx();

	void test_17_pl_dbl();

	void test_18_mn_dbl();

	void test_19_ml_dbl();

	void test_20_dv_dbl();

	void test_21_pleq_dbl();

	void test_22_mneq_dbl();

	void test_23_mleq_dbl();

	void test_24_dveq_dbl();

	void test_25_pl_unary();

	void test_26_mn_unary();

	void test_27_eq_oper();

	void test_28_uneq_oper();
	
}; // ComplexTests struct

//-----------------------------------------------------------------------------

#endif // TESTS_H_INCLUDED