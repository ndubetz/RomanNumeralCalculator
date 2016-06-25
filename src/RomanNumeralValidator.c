#include <string.h>
#include <stdbool.h>

bool RomanNumeralValidator_can_convert(int arabic_number)
{
	return (arabic_number > 0) && (arabic_number < 4000);
}

bool RomanNumeralValidator_is_valid(char * roman_numeral)
{
	char VALID_NUMERALS[] = {'I','V','X','L','C','D','M'};
	int j;
	for(j = 0; j < strlen(VALID_NUMERALS); j++)
	{
		if(roman_numeral[0] == VALID_NUMERALS[j])
		{
			return true;
		}
	}
	return false;
}
