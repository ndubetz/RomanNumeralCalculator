#include <stdlib.h>
#include <string.h>

#include "RomanNumeralCalculator.h"
#include "ArabicToRomanConverter.h"
#include "RomanToArabicConverter.h"
#include "RomanNumeralValidator.h"

char * convert_result(int result)
{
	if(!RomanNumeralValidator_can_convert(result))
		{
			return "Result cannot be converted to a roman numeral.";
		}
	return ArabicToRomanConverter_convert(result);
}

char * RomanNumeralCalculator_evaluate(char * numeral1, char * numeral2, char op)
{
    int number1 = RomanToArabicConverter_convert(numeral1);
    int number2 = RomanToArabicConverter_convert(numeral2);    
    		
    switch(op)
	{
		case '+':
			return convert_result(number1 + number2);
		case '-':
			return convert_result(number1 - number2);
	}
}
