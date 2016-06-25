#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <check.h>

#include "../src/RomanNumeralValidator.h"

START_TEST (can_convert_to_roman_numeral)
{
	ck_assert_int_eq(RomanNumeralValidator_can_convert(0), false);
	ck_assert_int_eq(RomanNumeralValidator_can_convert(1), true);
	ck_assert_int_eq(RomanNumeralValidator_can_convert(2016), true);
	ck_assert_int_eq(RomanNumeralValidator_can_convert(3999), true);
	ck_assert_int_eq(RomanNumeralValidator_can_convert(4000), false);		
}
END_TEST

TCase * RomanNumeralValidatorTests(void)
{
	TCase * tc;
	tc = tcase_create("RomanNumeralValidatorTests");
	tcase_add_test(tc, can_convert_to_roman_numeral);
	return tc;
}

