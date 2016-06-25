#include <stdlib.h>
#include <string.h>

#include "ArabicToRoman.h"

char * ArabicToRomanConverter_convert(int arabic_number)
{
    char * roman_numeral = calloc(16, sizeof(char));
    int i = 0;
    while(arabic_number > 0)
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
