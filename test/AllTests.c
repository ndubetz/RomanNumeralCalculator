#include <check.h>

#include "check_ArabicToRomanConverter.h"
#include "check_RomanToArabicConverter.h"
#include "check_RomanNumeralCalculator.h"
#include "check_RomanNumeralValidator.h"
#include "check_UpperCaseConverter.h"
#include "check_App.h"

Suite * RomanNumeralSuite(void)
{
	Suite * s;
	s = suite_create("AllTests"); 
	suite_add_tcase(s, AppTests());
    suite_add_tcase(s, RomanToArabicConverterTests());
 	suite_add_tcase(s, ArabicToRomanConverterTests());
 	suite_add_tcase(s, RomanNumeralCalculatorTests());
	suite_add_tcase(s, RomanNumeralValidatorTests());
	suite_add_tcase(s, UpperCaseConverterTests());
	return s;
}

int main(int argc, char **argv)
{
	Suite * s;
	SRunner * runner;
	int number_fails;
	
	s = RomanNumeralSuite();
	runner = srunner_create(s);
	srunner_run_all(runner, CK_NORMAL);
	number_fails = srunner_ntests_failed(runner);
	srunner_free(runner);

	return number_fails;
}

