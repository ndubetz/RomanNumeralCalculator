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

START_TEST (convert_additive_numerals)
{
	ck_assert_str_eq("II", ArabicToRomanConverter_convert(2));		
    ck_assert_str_eq("VII", ArabicToRomanConverter_convert(7));
    ck_assert_str_eq("XIII", ArabicToRomanConverter_convert(13));
    ck_assert_str_eq("XVI", ArabicToRomanConverter_convert(16));
    ck_assert_str_eq("LII", ArabicToRomanConverter_convert(52));
    ck_assert_str_eq("LXXXV", ArabicToRomanConverter_convert(85));
    ck_assert_str_eq("CXXVII", ArabicToRomanConverter_convert(127));
    ck_assert_str_eq("CCLXI", ArabicToRomanConverter_convert(261));
    ck_assert_str_eq("DCXX", ArabicToRomanConverter_convert(620));
    ck_assert_str_eq("MXI", ArabicToRomanConverter_convert(1011));
    ck_assert_str_eq("MDCCLXXVI", ArabicToRomanConverter_convert(1776));
    ck_assert_str_eq("MMCCC", ArabicToRomanConverter_convert(2300));
    ck_assert_str_eq("MMMII", ArabicToRomanConverter_convert(3002));
    ck_assert_str_eq("MMMDCCCLXXXVIII", ArabicToRomanConverter_convert(3888));
}
END_TEST

START_TEST (convert_mixed_numerals)
{
	ck_assert_str_eq("XIV", ArabicToRomanConverter_convert(14));		
    ck_assert_str_eq("XXXIX", ArabicToRomanConverter_convert(39));		
    ck_assert_str_eq("XLIX", ArabicToRomanConverter_convert(49));
    ck_assert_str_eq("LXIX", ArabicToRomanConverter_convert(69));
    ck_assert_str_eq("XCIV", ArabicToRomanConverter_convert(94));
    ck_assert_str_eq("CXLIII", ArabicToRomanConverter_convert(143));
    ck_assert_str_eq("CCXCV", ArabicToRomanConverter_convert(295));
    ck_assert_str_eq("CDXVII", ArabicToRomanConverter_convert(417));
    ck_assert_str_eq("DLXXXIV", ArabicToRomanConverter_convert(584));
    ck_assert_str_eq("DCCCXX", ArabicToRomanConverter_convert(820));
    ck_assert_str_eq("CMXLII", ArabicToRomanConverter_convert(942));
    ck_assert_str_eq("MCDXCII", ArabicToRomanConverter_convert(1492));
    ck_assert_str_eq("MCMXCIX", ArabicToRomanConverter_convert(1999));
    ck_assert_str_eq("MMCDLII", ArabicToRomanConverter_convert(2452));
    ck_assert_str_eq("MMMCMXCIX", ArabicToRomanConverter_convert(3999));
}
END_TEST

TCase * ArabicToRomanConverterTests(void)
{
	TCase * tc;
	tc = tcase_create("ArabicToRomanConverterTests");
	tcase_add_test(tc, convert_single_digits);
	tcase_add_test(tc, convert_subtractive_numerals);
	tcase_add_test(tc, convert_additive_numerals);
	return tc;
}
