#include <stdlib.h>
#include <string.h>
#include <check.h>

#include "../src/RomanToArabicConverter.h"

START_TEST (convert_single_numerals)
{
	ck_assert_int_eq(RomanToArabicConverter_convert("I"), 1);		
    ck_assert_int_eq(RomanToArabicConverter_convert("V"), 5);		
    ck_assert_int_eq(RomanToArabicConverter_convert("X"), 10);		
    ck_assert_int_eq(RomanToArabicConverter_convert("L"), 50);		
    ck_assert_int_eq(RomanToArabicConverter_convert("C"), 100);		
    ck_assert_int_eq(RomanToArabicConverter_convert("D"), 500);		
    ck_assert_int_eq(RomanToArabicConverter_convert("M"), 1000);		
}
END_TEST

TCase * RomanToArabicConverterTests(void)
{
	TCase * tc;
	tc = tcase_create("RomanToArabicConverterTests");
	tcase_add_test(tc, convert_single_numerals);
	return tc;
}
