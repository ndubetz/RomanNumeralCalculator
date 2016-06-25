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

START_TEST (convert_subtractive_numerals)
{
	ck_assert_int_eq(RomanToArabicConverter_convert("IV"), 4);		
    ck_assert_int_eq(RomanToArabicConverter_convert("IX"), 9);		
    ck_assert_int_eq(RomanToArabicConverter_convert("XL"), 40);		
    ck_assert_int_eq(RomanToArabicConverter_convert("XC"), 90);		
    ck_assert_int_eq(RomanToArabicConverter_convert("CD"), 400);		
    ck_assert_int_eq(RomanToArabicConverter_convert("CM"), 900);		
}
END_TEST

START_TEST (convert_additive_numerals)
{
    ck_assert_int_eq(RomanToArabicConverter_convert("III"), 3);		
    ck_assert_int_eq(RomanToArabicConverter_convert("VIII"), 8);		
    ck_assert_int_eq(RomanToArabicConverter_convert("XI"), 11);		
    ck_assert_int_eq(RomanToArabicConverter_convert("XXVII"), 27);		
    ck_assert_int_eq(RomanToArabicConverter_convert("LV"), 55);		
    ck_assert_int_eq(RomanToArabicConverter_convert("LXXVI"), 76);		
    ck_assert_int_eq(RomanToArabicConverter_convert("CXI"), 111);		
    ck_assert_int_eq(RomanToArabicConverter_convert("CCCLX"), 360);		
    ck_assert_int_eq(RomanToArabicConverter_convert("DCCLXXVII"), 777);		
    ck_assert_int_eq(RomanToArabicConverter_convert("MXXII"), 1022);		
    ck_assert_int_eq(RomanToArabicConverter_convert("MDCCCXII"), 1812);		
    ck_assert_int_eq(RomanToArabicConverter_convert("MMCI"), 2101);		
    ck_assert_int_eq(RomanToArabicConverter_convert("MMDCLXVI"), 2666);		
    ck_assert_int_eq(RomanToArabicConverter_convert("MMMCCCXXXIII"), 3333);		
}
END_TEST

START_TEST (convert_mixed_numerals)
{
	ck_assert_int_eq(RomanToArabicConverter_convert("XIV"), 14);
	ck_assert_int_eq(RomanToArabicConverter_convert("XXIX"), 29);
	ck_assert_int_eq(RomanToArabicConverter_convert("XLIV"), 44);
	ck_assert_int_eq(RomanToArabicConverter_convert("LXIX"), 69);
	ck_assert_int_eq(RomanToArabicConverter_convert("XCIX"), 99);
	ck_assert_int_eq(RomanToArabicConverter_convert("CXLIV"), 144);
	ck_assert_int_eq(RomanToArabicConverter_convert("CCXCII"), 292);
	ck_assert_int_eq(RomanToArabicConverter_convert("CDXX"), 420);
	ck_assert_int_eq(RomanToArabicConverter_convert("DXIV"), 514);
	ck_assert_int_eq(RomanToArabicConverter_convert("CMXCIX"), 999);
	ck_assert_int_eq(RomanToArabicConverter_convert("MCDXLIX"), 1449);
	ck_assert_int_eq(RomanToArabicConverter_convert("MMCDIV"), 2404);
	ck_assert_int_eq(RomanToArabicConverter_convert("MMMDXIX"), 3519);
	ck_assert_int_eq(RomanToArabicConverter_convert("MMMCMXCIX"), 3999);
}
END_TEST

TCase * RomanToArabicConverterTests(void)
{
	TCase * tc;
	tc = tcase_create("RomanToArabicConverterTests");
	tcase_add_test(tc, convert_single_numerals);
	tcase_add_test(tc, convert_subtractive_numerals);
	tcase_add_test(tc, convert_additive_numerals);
	tcase_add_test(tc, convert_mixed_numerals);
	return tc;
}
