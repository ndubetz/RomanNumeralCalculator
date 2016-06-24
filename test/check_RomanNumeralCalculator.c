#include <stdlib.h>
#include <string.h>
#include <check.h>

#include "../src/RomanNumeralCalculator.h"

void test_addition(char * numeral1, char * numeral2, char * expectedSum)
{
    char * result = RomanNumeralCalculator_add(numeral1, numeral2);
    ck_assert_str_eq(result, expectedSum);
    free(result);
}

START_TEST (adds_I_and_I_to_get_II)
{
	test_addition("I", "I", "II");		
}
END_TEST

START_TEST (adds_II_and_I_to_get_III)
{
    test_addition("II", "I", "III");
}
END_TEST

START_TEST (adds_II_and_II_to_get_IV)
{
	test_addition("II", "II", "IV");
}
END_TEST

START_TEST (adds_III_and_II_to_get_V)
{
    test_addition("III", "II", "V");
}
END_TEST

START_TEST (adds_IV_and_I_to_get_V)
{
    test_addition("IV", "I", "V");
}
END_TEST

START_TEST (adds_IV_and_II_to_get_VI)
{
	test_addition("IV", "II", "VI");
}
END_TEST

START_TEST (adds_IV_and_IV_to_get_VIII)
{
	test_addition("IV", "IV", "VIII");
}
END_TEST

START_TEST (adds_V_and_IV_to_get_IX)
{
	test_addition("V", "IV", "IX");
}
END_TEST

START_TEST (adds_V_and_V_to_get_X)
{
	test_addition("V", "V", "X");
}
END_TEST

START_TEST (adds_IX_and_I_to_get_X)
{
	test_addition("IX", "I", "X");
}
END_TEST

START_TEST (adds_II_and_VIII_to_get_X)
{
	test_addition("II", "VIII", "X");
}
END_TEST

Suite * RomanNumeralSuite(void)
{
	Suite * s;
	TCase * tc;
	
	s = suite_create("AllTests");
 
	tc = tcase_create("AllTests");
	tcase_add_test(tc, adds_I_and_I_to_get_II);	
	tcase_add_test(tc, adds_II_and_I_to_get_III);
	tcase_add_test(tc, adds_II_and_II_to_get_IV);
	tcase_add_test(tc, adds_III_and_II_to_get_V);
    tcase_add_test(tc, adds_IV_and_I_to_get_V);
    tcase_add_test(tc, adds_IV_and_II_to_get_VI);
    tcase_add_test(tc, adds_IV_and_IV_to_get_VIII);
    tcase_add_test(tc, adds_V_and_IV_to_get_IX);
    tcase_add_test(tc, adds_V_and_V_to_get_X);
    tcase_add_test(tc, adds_IX_and_I_to_get_X);
    tcase_add_test(tc, adds_II_and_VIII_to_get_X);

	suite_add_tcase(s, tc);
	return s;
}

int main(int argc, char **argv)
{
	Suite * s;
	SRunner * runner;
	int number_fails;
	
	s = RomanNumeralSuite();
	runner = srunner_create(s);
	srunner_run_all(runner, CK_NORMAL);
	number_fails = srunner_ntests_failed(runner);
	srunner_free(runner);

	return number_fails;
}

