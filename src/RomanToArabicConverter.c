#include <stdlib.h>
#include <string.h>

#include "RomanToArabic.h"

int RomanToArabicConverter_convert(char * roman_numeral)
{
    int i;
    for(i = 0; i < ROMAN_TO_ARABIC_LENGTH; i++)
    {
        if(strcmp(roman_numeral, ROMAN_TO_ARABIC[i].roman) == 0)
        {
            return ROMAN_TO_ARABIC[i].arabic;
        }
    }
}
