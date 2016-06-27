#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

char * get_upper_case_copy(char * numeral)
{
	char * copy_numeral = calloc(strlen(numeral), sizeof(char));
	int i;
	for(i = 0; i < strlen(numeral); i++)
	{
		copy_numeral[i] = toupper(numeral[i]);
	}
	return copy_numeral;
}

char * RomanNumeralCalculator_evaluate(char * numeral1, char * numeral2, char op)
{
    char * copy_numeral1 = get_upper_case_copy(numeral1);
    char * copy_numeral2 = get_upper_case_copy(numeral2);
    
    if(!RomanNumeralValidator_is_valid(copy_numeral1)
    	|| !RomanNumeralValidator_is_valid(copy_numeral2))
    {
    	free(copy_numeral1);
		free(copy_numeral2);
		return "Invalid Roman Numeral.";    	
    }
    
    int number1 = Converter_roman_to_arabic(copy_numeral1);
    int number2 = Converter_roman_to_arabic(copy_numeral2);    
    
    free(copy_numeral1);
	free(copy_numeral2);
			
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
