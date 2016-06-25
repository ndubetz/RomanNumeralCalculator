#include <stdlib.h>
#include <string.h>

#include "Converter.h"
#include "RomanNumeralValidator.h"

char * convert_result(int result)
{
	if(!RomanNumeralValidator_can_convert(result))
		{
			return "Result cannot be converted to a roman numeral.";
		}
	return Converter_arabic_to_roman(result);
}

char * RomanNumeralCalculator_evaluate(char * numeral1, char * numeral2, char op)
{
    if(!RomanNumeralValidator_is_valid(numeral1)
    	|| !RomanNumeralValidator_is_valid(numeral2))
    {
		return "Invalid Roman Numeral.";    	
    }
    
    int number1 = Converter_roman_to_arabic(numeral1);
    int number2 = Converter_roman_to_arabic(numeral2);    
    
    switch(op)
	{
		case '+':
			return convert_result(number1 + number2);
		case '-':
			return convert_result(number1 - number2);
		default:
			return "Invalid Operator.";
	}
}
