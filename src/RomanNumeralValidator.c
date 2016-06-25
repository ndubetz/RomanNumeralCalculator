/*
	TODO: replace with a regular expression
*/

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define VALID_NUMERALS_LENGTH 7

const char * VALID_NUMERALS = "IVXLCDM";

char * get_index(char numeral)
{
	return strchr(VALID_NUMERALS, numeral);
}

bool validate_order(char * num_index, char * prev_index)
{
	return prev_index - num_index >= 0;
}

bool has_two_fives_digits(char * num_index, char * prev_index)
{
	bool two_Vs = num_index == prev_index && prev_index == get_index('V');
	bool two_Ls = num_index == prev_index && prev_index == get_index('L');
	bool two_Ds = num_index == prev_index && prev_index == get_index('D');
	return two_Vs || two_Ls || two_Ds;
}

bool validate_numeral(char * num_index)
{
	return num_index >= get_index('I') && num_index <= get_index('M');
}

bool validate(char * num_index, char * prev_index)
{
	return validate_numeral(num_index)
		&& validate_order(num_index, prev_index)
		&& !has_two_fives_digits(num_index, prev_index);
}

bool RomanNumeralValidator_is_valid(char * roman_numeral)
{
	int j;
	char previous_numeral = 0;
	for(j = 0; j < strlen(roman_numeral); j++)
	{
		char * num_index = get_index(roman_numeral[j]);	
		char * prev_index = get_index(previous_numeral);
		if(!validate(num_index, prev_index))
		{
			return false;
		}
		previous_numeral = roman_numeral[j];
	}
	return strlen(roman_numeral) > 0;
}

bool RomanNumeralValidator_can_convert(int arabic_number)
{
	return (arabic_number > 0) && (arabic_number < 4000);
}
