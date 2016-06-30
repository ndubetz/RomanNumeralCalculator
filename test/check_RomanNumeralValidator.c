#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <check.h>

#include "../src/include/RomanNumeralValidator.h"

START_TEST (can_convert_to_roman_numeral)
{
	ck_assert_int_eq(RomanNumeralValidator_can_convert(1), true);
	ck_assert_int_eq(RomanNumeralValidator_can_convert(2016), true);
	ck_assert_int_eq(RomanNumeralValidator_can_convert(3999), true);

	ck_assert_int_eq(RomanNumeralValidator_can_convert(0), false);
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
	
	ck_assert_int_eq(RomanNumeralValidator_is_valid("IIV"), false);
	ck_assert_int_eq(RomanNumeralValidator_is_valid("IVI"), false);
	ck_assert_int_eq(RomanNumeralValidator_is_valid("IIX"), false);
	ck_assert_int_eq(RomanNumeralValidator_is_valid("IXI"), false);
	ck_assert_int_eq(RomanNumeralValidator_is_valid("IXV"), false);
	ck_assert_int_eq(RomanNumeralValidator_is_valid("XXL"), false);
	ck_assert_int_eq(RomanNumeralValidator_is_valid("XLX"), false);
	ck_assert_int_eq(RomanNumeralValidator_is_valid("XXC"), false);
	ck_assert_int_eq(RomanNumeralValidator_is_valid("XCX"), false);
	ck_assert_int_eq(RomanNumeralValidator_is_valid("XCL"), false);
	ck_assert_int_eq(RomanNumeralValidator_is_valid("CCD"), false);
	ck_assert_int_eq(RomanNumeralValidator_is_valid("CDC"), false);
	ck_assert_int_eq(RomanNumeralValidator_is_valid("CCM"), false);
	ck_assert_int_eq(RomanNumeralValidator_is_valid("CMC"), false);
	ck_assert_int_eq(RomanNumeralValidator_is_valid("CMD"), false);
}
END_TEST

START_TEST (validate_counts_number_of_digits)
{
	ck_assert_int_eq(RomanNumeralValidator_is_valid("III"), true);
	ck_assert_int_eq(RomanNumeralValidator_is_valid("XXX"), true);
	ck_assert_int_eq(RomanNumeralValidator_is_valid("CCC"), true);
	ck_assert_int_eq(RomanNumeralValidator_is_valid("MMM"), true);
	ck_assert_int_eq(RomanNumeralValidator_is_valid("XXXIX"), true);
	ck_assert_int_eq(RomanNumeralValidator_is_valid("CCCXC"), true);
	ck_assert_int_eq(RomanNumeralValidator_is_valid("MMMCM"), true);
	ck_assert_int_eq(RomanNumeralValidator_is_valid("MDLV"), true);

	ck_assert_int_eq(RomanNumeralValidator_is_valid("IIII"), false);
	ck_assert_int_eq(RomanNumeralValidator_is_valid("XXXX"), false);
	ck_assert_int_eq(RomanNumeralValidator_is_valid("CCCC"), false);
	ck_assert_int_eq(RomanNumeralValidator_is_valid("MMMM"), false);	
	ck_assert_int_eq(RomanNumeralValidator_is_valid("VV"),  false);
	ck_assert_int_eq(RomanNumeralValidator_is_valid("DD"),  false);
	ck_assert_int_eq(RomanNumeralValidator_is_valid("LL"),  false);
	ck_assert_int_eq(RomanNumeralValidator_is_valid("XVV"),  false);
	ck_assert_int_eq(RomanNumeralValidator_is_valid("MMDDCC"),  false);
	ck_assert_int_eq(RomanNumeralValidator_is_valid("DCCCLLXVI"),  false);
}
END_TEST

TCase * RomanNumeralValidatorTests(void)
{
	TCase * tc;
	tc = tcase_create("RomanNumeralValidatorTests");
	tcase_add_test(tc, can_convert_to_roman_numeral);
	tcase_add_test(tc, valid_digits);
	tcase_add_test(tc, invalid_digits);
	tcase_add_test(tc, validate_counts_number_of_digits);
	tcase_add_test(tc, numerals_in_proper_order);
	tcase_add_test(tc, numerals_in_proper_order_subraction_cases);
	return tc;
}

