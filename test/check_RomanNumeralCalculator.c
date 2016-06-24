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

START_TEST (addition_up_to_10)
{
	test_addition("I", "I", "II");		
	test_addition("I", "I", "II");		
    test_addition("II", "I", "III");
	test_addition("II", "II", "IV");
    test_addition("III", "II", "V");
    test_addition("IV", "I", "V");
	test_addition("IV", "II", "VI");
	test_addition("IV", "IV", "VIII");
	test_addition("V", "IV", "IX");
	test_addition("V", "V", "X");
	test_addition("IX", "I", "X");
	test_addition("II", "VIII", "X");
}
END_TEST

Suite * RomanNumeralSuite(void)
{
	Suite * s;
	TCase * tc;
	
	s = suite_create("AllTests");
 
	tc = tcase_create("AllTests");
	tcase_add_test(tc, addition_up_to_10);
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

