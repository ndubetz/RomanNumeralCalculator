/*
	TODO: replace with a regular expression
*/

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define VALID_NUMERALS_LENGTH 7

const char * VALID_NUMERALS = "IVXLCDM";

bool validate_order(char numeral, char previous_numeral)
{
	char * numIndex = strchr(VALID_NUMERALS, numeral);	
	char * prevIndex = strchr(VALID_NUMERALS, previous_numeral);
	return prevIndex - numIndex >= 0;
}

bool has_two_fives_digits(char numeral, char previous_numeral)
{
	bool two_Vs = numeral == previous_numeral && previous_numeral == 'V';
	bool two_Ls = numeral == previous_numeral && previous_numeral == 'L'; 
	bool two_Ds = numeral == previous_numeral && previous_numeral == 'D';
	return two_Vs || two_Ls || two_Ds;
}

bool validate_numeral(char numeral)
{
	int i;
	for(i = 0; i < VALID_NUMERALS_LENGTH; i++)
	{
		if(numeral == VALID_NUMERALS[i])
		{
			return true;
		}
	}
	return false;
}

bool RomanNumeralValidator_is_valid(char * roman_numeral)
{
	int j;
	char previous_numeral = 0;
	for(j = 0; j < strlen(roman_numeral); j++)
	{
		if(!validate_numeral(roman_numeral[j]))
		{
			return false;
		}
		
		if(has_two_fives_digits(roman_numeral[j], previous_numeral))
		{
			return false;
		}
		if(previous_numeral && !validate_order(roman_numeral[j], previous_numeral))
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
