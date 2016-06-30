#include <stdlib.h>
#include <string.h>
#include <check.h>

#include "../src/include/App.h"

START_TEST (improper_arg_count_returns_usage)
{
	int arg_count = 30;
	char * argv[4];
	argv[0] = "roman_calculator";
	char * expected_usage = "USAGE: roman_calculator ROMAN_NUMERAL [+|-] ROMAN_NUMERAL\n";
	char * result = App_run(arg_count, argv);
	ck_assert_str_eq(result, expected_usage);
	free(result);
}
END_TEST

START_TEST (unsupported_operator_returns_message)
{
	int arg_count = 4;
	char * argv[4];
	argv[0] = "roman_calculator";
	argv[1] = "i";
	argv[2] = "|";
	argv[3] = "v";
	char * expected_message = "Invalid Operator.\n";
	char * result = App_run(arg_count, argv);
	ck_assert_str_eq(result, expected_message);
	free(result);
}
END_TEST

START_TEST (invalid_roman_numeral_returns_message_first_numeral)
{
	int arg_count = 4;
	char * argv[4];
	argv[0] = "roman_calculator";
	argv[1] = "pizza";
	argv[2] = "+";
	argv[3] = "V";
	char * expected_message = "Invalid Roman Numeral.\n";
	char * result = App_run(arg_count, argv);
	ck_assert_str_eq(result, expected_message);
	free(result);
}
END_TEST

START_TEST (invalid_roman_numeral_returns_message_second_numeral)
{
	int arg_count = 4;
	char * argv[4];
	argv[0] = "roman_calculator";
	argv[1] = "VI";
	argv[2] = "-";
	argv[3] = "no";
	char * expected_message = "Invalid Roman Numeral.\n";
	char * result = App_run(arg_count, argv);
	ck_assert_str_eq(result, expected_message);
	free(result);
}
END_TEST

START_TEST (converts_to_upper_case_before_validation)
{
	int arg_count = 4;
	char * argv[4];
	argv[0] = "roman_calculator";
	argv[1] = "mdVIi";
	argv[2] = "+";
	argv[3] = "CliX";
	char * expected_message = "RESULT: MDCLXVI\n";
	char * result = App_run(arg_count, argv);
	ck_assert_str_eq(result, expected_message);
	free(result);
}
END_TEST


START_TEST (valid_args_evaluates_expression)
{
	int arg_count = 4;
	char * argv[4];
	argv[0] = "roman_calculator";
	argv[1] = "XV";
	argv[2] = "-";
	argv[3] = "IX";
	char * expected_message = "RESULT: VI\n";
	char * result = App_run(arg_count, argv);
	ck_assert_str_eq(result, expected_message);
	free(result);
}
END_TEST

TCase * AppTests(void)
{
	TCase * tc;
	tc = tcase_create("AppTests");
	tcase_add_test(tc, improper_arg_count_returns_usage);
	tcase_add_test(tc, unsupported_operator_returns_message);
	tcase_add_test(tc, invalid_roman_numeral_returns_message_first_numeral);
	tcase_add_test(tc, invalid_roman_numeral_returns_message_second_numeral);
	tcase_add_test(tc, converts_to_upper_case_before_validation);
	tcase_add_test(tc, valid_args_evaluates_expression);
	return tc;
}
