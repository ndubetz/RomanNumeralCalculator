#include <stdlib.h>
#include <string.h>
#include <check.h>

#include "check_Converter.h"
#include "check_RomanNumeralValidator.h"
#include "../src/RomanNumeralCalculator.h"

void test_addition(char * numeral1, char * numeral2, char * expectedSum)
{
    char * result = RomanNumeralCalculator_add(numeral1, numeral2);
    ck_assert_str_eq(result, expectedSum);
    free(result);
}

START_TEST (addition_returns_sum)
{
	test_addition("CCXII", "CXXI", "CCCXXXIII");		
    test_addition("CCXXII", "CCXXII", "CDXLIV");
	test_addition("CCCXXXIII", "CCXXII", "DLV");
    test_addition("CCCXLIII", "CDXXIII", "DCCLXVI");
    test_addition("CDLIV", "CDXXXIII", "DCCCLXXXVII");
	test_addition("DCLIV", "DCXLIV", "MCCXCVIII");
	test_addition("CMLXV", "DCXLIV", "MDCIX");
	test_addition("CMXCV", "CMXLV", "MCMXL");
	test_addition("MXCVI", "CMLV", "MMLI");
	test_addition("MXCIX", "MXCV", "MMCXCIV");
	test_addition("MMCIX", "MXCIX", "MMMCCVIII");
}
END_TEST

/*
    TODO 
    add subtraction cases
*/


Suite * RomanNumeralSuite(void)
{
	Suite * s;
	TCase * tc;
	
	s = suite_create("AllTests");
 
	tc = tcase_create("RomanNumeralCalculatorTests");
	tcase_add_test(tc, addition_returns_sum);
	suite_add_tcase(s, tc);
    suite_add_tcase(s, ConverterTests());
	suite_add_tcase(s, RomanNumeralValidatorTests());
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

