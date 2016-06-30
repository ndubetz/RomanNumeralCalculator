#include <stdlib.h>
#include <string.h>
#include <check.h>

#include "../src/include/RomanNumeralCalculator.h"

void test_evaluation(char * numeral1, char * numeral2, char * expectedResult, char op)
{
	char * result = RomanNumeralCalculator_evaluate(numeral1, numeral2, op);
    ck_assert_str_eq(result, expectedResult);
    free(result);
}

void test_invalid_evaluation(char * numeral1, char * numeral2, char * expectedResult, char op)
{
	char * result = RomanNumeralCalculator_evaluate(numeral1, numeral2, op);
    ck_assert_str_eq(result, expectedResult);
}

START_TEST (evaluate_adds_numerals_plus_passed_in)
{
	test_evaluation("CCXII", "CXXI", "CCCXXXIII", '+');		
    test_evaluation("CCXXII", "CCXXII", "CDXLIV", '+');
	test_evaluation("CCCXXXIII", "CCXXII", "DLV", '+');
    test_evaluation("CCCXLIII", "CDXXIII", "DCCLXVI", '+');
    test_evaluation("CDLIV", "CDXXXIII", "DCCCLXXXVII", '+');
	test_evaluation("DCLIV", "DCXLIV", "MCCXCVIII", '+');
	test_evaluation("CMLXV", "DCXLIV", "MDCIX", '+');
	test_evaluation("CMXCV", "CMXLV", "MCMXL", '+');
	test_evaluation("MXCVI", "CMLV", "MMLI", '+');
	test_evaluation("MXCIX", "MXCV", "MMCXCIV", '+');
	test_evaluation("MMCIX", "MXCIX", "MMMCCVIII", '+');
	test_evaluation("XCV", "MMCM", "MMCMXCV", '+');
}
END_TEST

START_TEST (evaluate_subtracts_numerals_minus_passed_in)
{
	test_evaluation("MMMCMXCIX", "MMMDCLXXI", "CCCXXVIII", '-');		
    test_evaluation("MMMCDLXXVI", "MMMCCXLII", "CCXXXIV", '-');
	test_evaluation("MMMCCCXXXIII", "MMCMXCIX", "CCCXXXIV", '-');
    test_evaluation("MMMCXI", "MMDCLXXVIII", "CDXXXIII", '-');
    test_evaluation("MMCMLXIX", "MMCDLV", "DXIV", '-');
	test_evaluation("MMDCLIV", "MMCXLIV", "DX", '-');
	test_evaluation("MMDXX", "MCMXV", "DCV", '-');
	test_evaluation("MMCCCIX", "MDCXLII", "DCLXVII", '-');
	test_evaluation("MMCXCVI", "MCDXXXIII", "DCCLXIII", '-');
	test_evaluation("MCMXCIX", "MXCV", "CMIV", '-');
	test_evaluation("MDCCCVIII", "DCCIX", "MXCIX", '-');
	test_evaluation("MMCM", "DCV", "MMCCXCV", '-');
}
END_TEST

START_TEST (evaluate_returns_message_if_result_is_unable_to_convert_to_roman)
{
	test_invalid_evaluation("MCM", "MMM", 
		"Result cannot be converted to a roman numeral.", '+');
	test_invalid_evaluation("MCM", "MMM", 
		"Result cannot be converted to a roman numeral.", '-');
}
END_TEST

TCase * RomanNumeralCalculatorTests(void)
{
	TCase * tc;
	tc = tcase_create("RomanNumeralCalculatorTests");
	tcase_add_test(tc, evaluate_adds_numerals_plus_passed_in);
	tcase_add_test(tc, evaluate_subtracts_numerals_minus_passed_in);
	tcase_add_test(tc, evaluate_returns_message_if_result_is_unable_to_convert_to_roman);
	return tc;
}


