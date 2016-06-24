#include <stdlib.h>
#include <string.h>
#include <check.h>

#include "../src/ArabicToRomanConverter.h"

START_TEST (convert_single_digits)
{
	ck_assert_str_eq("I", ArabicToRomanConverter_convert(1));		
    ck_assert_str_eq("V", ArabicToRomanConverter_convert(5));
    ck_assert_str_eq("X", ArabicToRomanConverter_convert(10));
    ck_assert_str_eq("L", ArabicToRomanConverter_convert(50));
    ck_assert_str_eq("C", ArabicToRomanConverter_convert(100));
    ck_assert_str_eq("D", ArabicToRomanConverter_convert(500));
    ck_assert_str_eq("M", ArabicToRomanConverter_convert(1000));
}
END_TEST

START_TEST (convert_subtractive_numerals)
{
	ck_assert_str_eq("IV", ArabicToRomanConverter_convert(4));		
    ck_assert_str_eq("IX", ArabicToRomanConverter_convert(9));
    ck_assert_str_eq("XL", ArabicToRomanConverter_convert(40));
    ck_assert_str_eq("XC", ArabicToRomanConverter_convert(90));
    ck_assert_str_eq("CD", ArabicToRomanConverter_convert(400));
    ck_assert_str_eq("CM", ArabicToRomanConverter_convert(900));
}
END_TEST

TCase * ArabicToRomanConverterTests(void)
{
	TCase * tc;
	tc = tcase_create("ArabicToRomanConverterTests");
	tcase_add_test(tc, convert_single_digits);
	tcase_add_test(tc, convert_subtractive_numerals);
	return tc;
}
