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

TCase * ArabicToRomanConverterTests(void)
{
	TCase * tc;
	tc = tcase_create("ArabicToRomanConverterTests");
	tcase_add_test(tc, convert_single_digits);
	return tc;
}
