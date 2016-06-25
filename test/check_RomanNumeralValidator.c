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

START_TEST (valid_digits)
{
	ck_assert_int_eq(RomanNumeralValidator_is_valid("I"), true);
	ck_assert_int_eq(RomanNumeralValidator_is_valid("V"), true);
	ck_assert_int_eq(RomanNumeralValidator_is_valid("X"), true);
	ck_assert_int_eq(RomanNumeralValidator_is_valid("L"), true);
	ck_assert_int_eq(RomanNumeralValidator_is_valid("C"), true);
	ck_assert_int_eq(RomanNumeralValidator_is_valid("D"), true);
	ck_assert_int_eq(RomanNumeralValidator_is_valid("M"), true);
}
END_TEST

START_TEST (invalid_digits)
{
	ck_assert_int_eq(RomanNumeralValidator_is_valid("J"), false);
	ck_assert_int_eq(RomanNumeralValidator_is_valid("1"), false);
	ck_assert_int_eq(RomanNumeralValidator_is_valid(""),  false);
}
END_TEST

TCase * RomanNumeralValidatorTests(void)
{
	TCase * tc;
	tc = tcase_create("RomanNumeralValidatorTests");
	tcase_add_test(tc, can_convert_to_roman_numeral);
	tcase_add_test(tc, valid_digits);
	tcase_add_test(tc, invalid_digits);
	return tc;
}

