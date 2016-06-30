#include <stdlib.h>
#include <string.h>
#include <check.h>

//#include "check_UpperCaseConverter.h"
#include "../src/UpperCaseConverter.h"

void test_conversion(char * input, char * actual)
{
	char * result = UpperCaseConverter_convert(input);
	ck_assert_str_eq(result, actual);
	free(result);
}

START_TEST (converts_lower_case_to_upper_case)
{
	test_conversion("ccxii", "CCXII");		
    test_conversion("cCxXiI", "CCXXII");
	test_conversion("mdlv", "MDLV");
	test_conversion("sandwich", "SANDWICH");
	test_conversion("qAzWsX", "QAZWSX");
}
END_TEST

START_TEST (does_not_convert_numbers)
{
	test_conversion("1234567890", "1234567890");		
	test_conversion("1a2b3c4d5e6f7g8h9i0", "1A2B3C4D5E6F7G8H9I0");		
}
END_TEST

TCase * UpperCaseConverterTests()
{
	TCase * tc;
	tc = tcase_create("UpperCaseConverterTests");
	tcase_add_test(tc, converts_lower_case_to_upper_case);
	tcase_add_test(tc, does_not_convert_numbers);
	return tc;
}
