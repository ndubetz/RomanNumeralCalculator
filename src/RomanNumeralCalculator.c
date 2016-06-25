#include <stdlib.h>
#include <string.h>

#include "Converter.h"

char * RomanNumeralCalculator_evaluate(char * numeral1, char * numeral2, char op)
{
    int number1 = Converter_roman_to_arabic(numeral1);
    int number2 = Converter_roman_to_arabic(numeral2);    
    
    if(op == '+')
	{
		return Converter_arabic_to_roman(number1 + number2);
	}
	else if(op == '-')
	{
		return Converter_arabic_to_roman(number1 - number2);
	}
	else
	{
		return "Invalid Operator.";
	}
}
