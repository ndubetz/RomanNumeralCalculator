#include <stdlib.h>
#include <string.h>

#include "ArabicToRoman.h"

int convert_numeral(char numeral)
{
    const char numeral_as_string[] = {numeral, '\0'};
	int i;
	for (i = 0; i < ARABIC_TO_ROMAN_LENGTH; i++)
	{
		if(strcmp(numeral_as_string, ARABIC_TO_ROMAN[i].roman) == 0)
		{
			return ARABIC_TO_ROMAN[i].arabic;
		}
	}
}

int Converter_roman_to_arabic(char * roman_numeral)
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

char * Converter_arabic_to_roman(int arabic_number)
{
	char * roman_numeral = calloc(16, sizeof(char));
    int i = 0;
    while(arabic_number)
    {
        if(arabic_number >= ARABIC_TO_ROMAN[i].arabic)
        {
            strcat(roman_numeral, ARABIC_TO_ROMAN[i].roman);
            arabic_number -= ARABIC_TO_ROMAN[i].arabic;
        }  
        else
        {
            i++;
        }
    }
    return roman_numeral;
}
