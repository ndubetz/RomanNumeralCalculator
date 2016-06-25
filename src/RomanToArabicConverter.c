#include <stdlib.h>
#include <string.h>

#include "RomanToArabic.h"

int convert_numeral(char numeral)
{
    const char numeral_as_string[] = {numeral, '\0'};
	int i;
	for (i = 0; i < ROMAN_TO_ARABIC_LENGTH; i++)
	{
		if(strcmp(numeral_as_string, ROMAN_TO_ARABIC[i].roman) == 0)
		{
			return ROMAN_TO_ARABIC[i].arabic;
		}
	}
}

int RomanToArabicConverter_convert(char * roman_numeral)
{
	int arabic_number = 0;
    int previous_value = 0;
    int i;
    for(i = strlen(roman_numeral); i-- ;)
    {
    	int digit_value = convert_numeral(roman_numeral[i]);
        arabic_number += (digit_value >= previous_value) 
        	?  digit_value 
        	: -digit_value;
        previous_value = digit_value;
    }
    return arabic_number;
}

