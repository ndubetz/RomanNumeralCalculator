#include <stdlib.h>
#include <string.h>
#include <check.h>

#include "../src/include/ArabicToRomanConverter.h"

void test_arabic_to_roman(int arabic, char * roman)
{
    char * result = ArabicToRomanConverter_convert(arabic);
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

TCase * ArabicToRomanConverterTests(void)
{
	TCase * tc;
	tc = tcase_create("ArabicToRomanConverterTests");
	tcase_add_test(tc, convert_single_digits);
	tcase_add_test(tc, convert_subtractive_numbers);
	tcase_add_test(tc, convert_additive_numbers);
	tcase_add_test(tc, convert_mixed_numbers);
	return tc;
}

