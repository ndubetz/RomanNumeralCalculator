#include <stdlib.h>
#include <string.h>

#include "Converter.h"

char * RomanNumeralCalculator_add(char * numeral1, char * numeral2)
{
    int number1 = Converter_roman_to_arabic(numeral1);
    int number2 = Converter_roman_to_arabic(numeral2);    
    char * sum = Converter_arabic_to_roman(number1 + number2);    
    return sum;
}
