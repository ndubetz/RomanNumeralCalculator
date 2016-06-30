#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "App.h"
#include "UpperCaseConverter.h"
#include "RomanNumeralValidator.h"
#include "RomanNumeralCalculator.h"

char * App_run(int argc, char ** argv)
{
	char * program_name = argv[0];
	char * numeral1     = UpperCaseConverter_convert(argv[1]);
	char * numeral2     = UpperCaseConverter_convert(argv[3]);
	char   operator     = argv[2][0];
	
	char * buffer = calloc(60, sizeof(char));
	
	if(argc != 4)
	{
		sprintf(buffer, "USAGE: %s ROMAN_NUMERAL [+|-] ROMAN_NUMERAL\n", program_name);
	}
	else if(!(operator == '+' || operator == '-'))
	{
		strcpy(buffer, "Invalid Operator.\n");
	}
	else if(!(RomanNumeralValidator_is_valid(numeral1)
			&& RomanNumeralValidator_is_valid(numeral2)))
	{
		strcpy(buffer, "Invalid Roman Numeral.\n");
	}
	else
	{
		sprintf(buffer, "RESULT: %s\n", 
			RomanNumeralCalculator_evaluate(numeral1, numeral2, operator));
	}
	
	free(numeral1);
	free(numeral2);
	
	return buffer;
}
