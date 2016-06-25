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

START_TEST (no_fives_digit_appears_more_than_once)
{
	ck_assert_int_eq(RomanNumeralValidator_is_valid("MDLV"), true);
	ck_assert_int_eq(RomanNumeralValidator_is_valid("VV"),  false);
	ck_assert_int_eq(RomanNumeralValidator_is_valid("DD"),  false);
	ck_assert_int_eq(RomanNumeralValidator_is_valid("LL"),  false);
	ck_assert_int_eq(RomanNumeralValidator_is_valid("XVV"),  false);
	ck_assert_int_eq(RomanNumeralValidator_is_valid("MMDDCC"),  false);
	ck_assert_int_eq(RomanNumeralValidator_is_valid("DCCCLLXVI"),  false);
}
END_TEST

START_TEST (numerals_in_proper_order)
{
	ck_assert_int_eq(RomanNumeralValidator_is_valid("MDCLXVI"), true);
	ck_assert_int_eq(RomanNumeralValidator_is_valid("CIL"), false);
	ck_assert_int_eq(RomanNumeralValidator_is_valid("LIC"),  false);
	ck_assert_int_eq(RomanNumeralValidator_is_valid("XID"),  false);
	ck_assert_int_eq(RomanNumeralValidator_is_valid("VIM"),  false);
	ck_assert_int_eq(RomanNumeralValidator_is_valid("XVX"),  false);
	ck_assert_int_eq(RomanNumeralValidator_is_valid("LVC"),  false);
	ck_assert_int_eq(RomanNumeralValidator_is_valid("CVD"),  false);
	ck_assert_int_eq(RomanNumeralValidator_is_valid("DVM"),  false);
	ck_assert_int_eq(RomanNumeralValidator_is_valid("LXD"),  false);
	ck_assert_int_eq(RomanNumeralValidator_is_valid("CXM"),  false);
	ck_assert_int_eq(RomanNumeralValidator_is_valid("CLC"),  false);
	ck_assert_int_eq(RomanNumeralValidator_is_valid("DLD"),  false);
	ck_assert_int_eq(RomanNumeralValidator_is_valid("MLM"),  false);
	ck_assert_int_eq(RomanNumeralValidator_is_valid("MDM"),  false);	
}
END_TEST

START_TEST (numerals_in_proper_order_subraction_cases)
{
	ck_assert_int_eq(RomanNumeralValidator_is_valid("MCDXLIV"), true);
	ck_assert_int_eq(RomanNumeralValidator_is_valid("MCMXCIX"), true);
}
END_TEST

TCase * RomanNumeralValidatorTests(void)
{
	TCase * tc;
	tc = tcase_create("RomanNumeralValidatorTests");
	tcase_add_test(tc, can_convert_to_roman_numeral);
	tcase_add_test(tc, valid_digits);
	tcase_add_test(tc, invalid_digits);
	tcase_add_test(tc, no_fives_digit_appears_more_than_once);
	tcase_add_test(tc, numerals_in_proper_order);
	tcase_add_test(tc, numerals_in_proper_order_subraction_cases);
	return tc;
}

