#include <stdlib.h>
#include <string.h>
#include <check.h>

#include "../src/Converter.h"

void test_arabic_to_roman(int arabic, char * roman)
{
    char * result = Converter_arabic_to_roman(arabic);
    ck_assert_str_eq(roman, result);
    free(result);
}

START_TEST (convert_single_digits)
{
	test_arabic_to_roman(   1, "I");		
    test_arabic_to_roman(   5, "V");		
    test_arabic_to_roman(  10, "X");		
    test_arabic_to_roman(  50, "L");		
    test_arabic_to_roman( 100, "C");		
    test_arabic_to_roman( 500, "D");		
    test_arabic_to_roman(1000, "M");		
}
END_TEST

START_TEST (convert_subtractive_numbers)
{
	test_arabic_to_roman(  4, "IV");		
    test_arabic_to_roman(  9, "IX");		
    test_arabic_to_roman( 40, "XL");		
    test_arabic_to_roman( 90, "XC");		
    test_arabic_to_roman(400, "CD");		
    test_arabic_to_roman(900, "CM");		
}
END_TEST

START_TEST (convert_additive_numbers)
{
    test_arabic_to_roman(   2, "II");		
    test_arabic_to_roman(   7, "VII");		
    test_arabic_to_roman(  13, "XIII");		
    test_arabic_to_roman(  16, "XVI");		
    test_arabic_to_roman(  52, "LII");		
    test_arabic_to_roman(  85, "LXXXV");		
    test_arabic_to_roman( 127, "CXXVII");		
    test_arabic_to_roman( 261, "CCLXI");		
    test_arabic_to_roman( 620, "DCXX");		
    test_arabic_to_roman(1011, "MXI");		
    test_arabic_to_roman(1776, "MDCCLXXVI");		
    test_arabic_to_roman(2300, "MMCCC");		
    test_arabic_to_roman(3002, "MMMII");		
    test_arabic_to_roman(3888, "MMMDCCCLXXXVIII");			
}
END_TEST

START_TEST (convert_mixed_numbers)
{
	test_arabic_to_roman(  14, "XIV");		    
    test_arabic_to_roman(  39, "XXXIX");		    
    test_arabic_to_roman(  49, "XLIX");		
    test_arabic_to_roman(  69, "LXIX");		
    test_arabic_to_roman(  94, "XCIV");		
    test_arabic_to_roman( 143, "CXLIII");		
    test_arabic_to_roman( 295, "CCXCV");		
    test_arabic_to_roman( 417, "CDXVII");		
    test_arabic_to_roman( 584, "DLXXXIV");		
    test_arabic_to_roman( 820, "DCCCXX");		
    test_arabic_to_roman( 942, "CMXLII");		
    test_arabic_to_roman(1492, "MCDXCII");		
    test_arabic_to_roman(1999, "MCMXCIX");		
    test_arabic_to_roman(2452, "MMCDLII");		
    test_arabic_to_roman(3999, "MMMCMXCIX");		    
}
END_TEST

START_TEST (convert_single_numerals)
{
	ck_assert_int_eq(Converter_roman_to_arabic("I"), 1);		
    ck_assert_int_eq(Converter_roman_to_arabic("V"), 5);		
    ck_assert_int_eq(Converter_roman_to_arabic("X"), 10);		
    ck_assert_int_eq(Converter_roman_to_arabic("L"), 50);		
    ck_assert_int_eq(Converter_roman_to_arabic("C"), 100);		
    ck_assert_int_eq(Converter_roman_to_arabic("D"), 500);		
    ck_assert_int_eq(Converter_roman_to_arabic("M"), 1000);		
}
END_TEST

START_TEST (convert_subtractive_numerals)
{
	ck_assert_int_eq(Converter_roman_to_arabic("IV"), 4);		
    ck_assert_int_eq(Converter_roman_to_arabic("IX"), 9);		
    ck_assert_int_eq(Converter_roman_to_arabic("XL"), 40);		
    ck_assert_int_eq(Converter_roman_to_arabic("XC"), 90);		
    ck_assert_int_eq(Converter_roman_to_arabic("CD"), 400);		
    ck_assert_int_eq(Converter_roman_to_arabic("CM"), 900);		
}
END_TEST

START_TEST (convert_additive_numerals)
{
    ck_assert_int_eq(Converter_roman_to_arabic("III"), 3);		
    ck_assert_int_eq(Converter_roman_to_arabic("VIII"), 8);		
    ck_assert_int_eq(Converter_roman_to_arabic("XI"), 11);		
    ck_assert_int_eq(Converter_roman_to_arabic("XXVII"), 27);		
    ck_assert_int_eq(Converter_roman_to_arabic("LV"), 55);		
    ck_assert_int_eq(Converter_roman_to_arabic("LXXVI"), 76);		
    ck_assert_int_eq(Converter_roman_to_arabic("CXI"), 111);		
    ck_assert_int_eq(Converter_roman_to_arabic("CCCLX"), 360);		
    ck_assert_int_eq(Converter_roman_to_arabic("DCCLXXVII"), 777);		
    ck_assert_int_eq(Converter_roman_to_arabic("MXXII"), 1022);		
    ck_assert_int_eq(Converter_roman_to_arabic("MDCCCXII"), 1812);		
    ck_assert_int_eq(Converter_roman_to_arabic("MMCI"), 2101);		
    ck_assert_int_eq(Converter_roman_to_arabic("MMDCLXVI"), 2666);		
    ck_assert_int_eq(Converter_roman_to_arabic("MMMCCCXXXIII"), 3333);		
}
END_TEST

START_TEST (convert_mixed_numerals)
{
	ck_assert_int_eq(Converter_roman_to_arabic("XIV"), 14);
	ck_assert_int_eq(Converter_roman_to_arabic("XXIX"), 29);
	ck_assert_int_eq(Converter_roman_to_arabic("XLIV"), 44);
	ck_assert_int_eq(Converter_roman_to_arabic("LXIX"), 69);
	ck_assert_int_eq(Converter_roman_to_arabic("XCIX"), 99);
	ck_assert_int_eq(Converter_roman_to_arabic("CXLIV"), 144);
	ck_assert_int_eq(Converter_roman_to_arabic("CCXCII"), 292);
	ck_assert_int_eq(Converter_roman_to_arabic("CDXX"), 420);
	ck_assert_int_eq(Converter_roman_to_arabic("DXIV"), 514);
	ck_assert_int_eq(Converter_roman_to_arabic("CMXCIX"), 999);
	ck_assert_int_eq(Converter_roman_to_arabic("MCDXLIX"), 1449);
	ck_assert_int_eq(Converter_roman_to_arabic("MMCDIV"), 2404);
	ck_assert_int_eq(Converter_roman_to_arabic("MMMDXIX"), 3519);
	ck_assert_int_eq(Converter_roman_to_arabic("MMMCMXCIX"), 3999);
}
END_TEST

TCase * ConverterTests(void)
{
	TCase * tc;
	tc = tcase_create("ConverterTests");
	tcase_add_test(tc, convert_single_digits);
	tcase_add_test(tc, convert_subtractive_numbers);
	tcase_add_test(tc, convert_additive_numbers);
	tcase_add_test(tc, convert_mixed_numbers);
	tcase_add_test(tc, convert_single_numerals);
	tcase_add_test(tc, convert_subtractive_numerals);
	tcase_add_test(tc, convert_additive_numerals);
	tcase_add_test(tc, convert_mixed_numerals);
	return tc;
}
