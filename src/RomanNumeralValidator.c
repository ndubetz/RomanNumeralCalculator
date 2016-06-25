#include <string.h>
#include <stdbool.h>

#define VALID_NUMERALS_LENGTH 7

const char VALID_NUMERALS[] = {'I','V','X','L','C','D','M'};

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

bool RomanNumeralValidator_can_convert(int arabic_number)
{
	return (arabic_number > 0) && (arabic_number < 4000);
}

bool RomanNumeralValidator_is_valid(char * roman_numeral)
{
	int j;
	char previous_numeral;
	bool has_invalid_numeral;
	
	for(j = 0; j < strlen(roman_numeral); j++)
	{
		has_invalid_numeral = !validate_numeral(roman_numeral[j]);
		
		if(has_two_fives_digits(roman_numeral[j], previous_numeral))
		{
			return false;
		}
		previous_numeral = roman_numeral[j];
		
	}
	
	return !(has_invalid_numeral);
}
