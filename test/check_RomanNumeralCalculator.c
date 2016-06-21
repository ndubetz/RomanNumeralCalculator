#include <string.h>
#include <check.h>

#include "../src/RomanNumeralCalculator.h"

START_TEST (adds_I_and_I_to_get_II)
{
	char * i      = "I";
	char * ii     = "II";
	char * result = RomanNumeralCalculator_add(i, i);
	ck_assert_str_eq(result, ii);		
}
END_TEST

START_TEST (adds_II_and_I_to_get_III)
{
	char * i      = "I";
	char * ii     = "II";
	char * iii    = "III";
	char * result = RomanNumeralCalculator_add(ii, i);
	ck_assert_str_eq(result, iii);
}
END_TEST

Suite * RomanNumeralSuite(void)
{
	Suite * s;
	TCase * tc;
	
	s = suite_create("AllTests");
 
	tc = tcase_create("AllTests");
	tcase_add_test(tc, adds_I_and_I_to_get_II);	
	tcase_add_test(tc, adds_II_and_I_to_get_III);

	suite_add_tcase(s, tc);
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

