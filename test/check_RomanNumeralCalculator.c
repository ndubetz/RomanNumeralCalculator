#include <stdlib.h>
#include <string.h>
#include <check.h>

#include "../src/RomanNumeralCalculator.h"

START_TEST (adds_I_and_I_to_get_II)
{
	char * number1      = "I";
	char * number2      = "I";
	char * expectedSum  = "II";
	char * result;

	result = RomanNumeralCalculator_add(number1, number2);
	ck_assert_str_eq(result, expectedSum);

    free(result);		
}
END_TEST

START_TEST (adds_II_and_I_to_get_III)
{
	char * number1        = "I";
	char * number2        = "II";
	char * expectedSum    = "III";
    char * result;

	result = RomanNumeralCalculator_add(number1, number2);
	ck_assert_str_eq(result, expectedSum);

    free(result);
}
END_TEST

START_TEST (adds_II_and_II_to_get_IV)
{
	char * number1        = "II";
	char * number2        = "II";
	char * expectedSum    = "IV";
    char * result;

	result = RomanNumeralCalculator_add(number1, number2);
	ck_assert_str_eq(result, expectedSum);

    free(result);
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

