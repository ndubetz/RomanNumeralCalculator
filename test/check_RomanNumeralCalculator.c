#include <stdlib.h>
#include <string.h>
#include <check.h>

#include "check_Converter.h"
#include "check_RomanNumeralValidator.h"
#include "../src/RomanNumeralCalculator.h"

void test_addition(char * numeral1, char * numeral2, char * expectedSum)
{
    char * result = RomanNumeralCalculator_evaluate(numeral1, numeral2, '+');
    ck_assert_str_eq(result, expectedSum);
    free(result);
}

void test_subtraction(char * numeral1, char * numeral2, char * expectedSum)
{
    char * result = RomanNumeralCalculator_evaluate(numeral1, numeral2, '-');
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

START_TEST (subtraction_returns_difference)
{
	test_subtraction("MMMCMXCIX", "MMMDCLXXI", "CCCXXVIII");		
    test_subtraction("MMMCDLXXVI", "MMMCCXLII", "CCXXXIV");
	test_subtraction("MMMCCCXXXIII", "MMCMXCIX", "CCCXXXIV");
    test_subtraction("MMMCXI", "MMDCLXXVIII", "CDXXXIII");
    test_subtraction("MMCMLXIX", "MMCDLV", "DXIV");
	test_subtraction("MMDCLIV", "MMCXLIV", "DX");
	test_subtraction("MMDXX", "MCMXV", "DCV");
	test_subtraction("MMCCCIX", "MDCXLII", "DCLXVII");
	test_subtraction("MMCXCVI", "MCDXXXIII", "DCCLXIII");
	test_subtraction("MCMXCIX", "MXCV", "CMIV");
	test_subtraction("MDCCCVIII", "DCCIX", "MXCIX");
}
END_TEST

START_TEST (evaluate_adds_numerals_plus_passed_in)
{
	char * expectedSum = "MMCMXCV";
	char * result = RomanNumeralCalculator_evaluate("XCV", "MMCM", '+');
    ck_assert_str_eq(result, expectedSum);
    free(result);
}
END_TEST

START_TEST (evaluate_subtracts_numerals_minus_passed_in)
{
	char * expectedSum = "MMCCXCV";
	char * result = RomanNumeralCalculator_evaluate("MMCM", "DCV", '-');
    ck_assert_str_eq(result, expectedSum);
    free(result);
}
END_TEST

START_TEST (evaluate_returns_message_if_invalid_operator_passed_in)
{
	char * expectedSum = "Invalid Operator.";
	char * result = RomanNumeralCalculator_evaluate("MCM", "DII", '%');
    ck_assert_str_eq(result, expectedSum);
}
END_TEST

Suite * RomanNumeralSuite(void)
{
	Suite * s;
	TCase * tc;
	
	s = suite_create("AllTests");
 
	tc = tcase_create("RomanNumeralCalculatorTests");
	tcase_add_test(tc, addition_returns_sum);
	tcase_add_test(tc, subtraction_returns_difference);
	tcase_add_test(tc, evaluate_adds_numerals_plus_passed_in);
	tcase_add_test(tc, evaluate_subtracts_numerals_minus_passed_in);
	tcase_add_test(tc, evaluate_returns_message_if_invalid_operator_passed_in);
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

