#include <stdlib.h>
#include <stdio.h>

#include "RomanNumeralValidator.h"
#include "RomanNumeralCalculator.h"

char * App_run(int argc, char ** argv)
{
	char * program_name = argv[0];
	char * numeral1     = argv[1];
	char * numeral2     = argv[3];
	char   operator     = argv[2][0];
	
	char * buffer = calloc(60, sizeof(char));
	
	if(argc != 4)
	{
		sprintf(buffer, "USAGE: %s ROMAN_NUMERAL [+|-] ROMAN_NUMERAL\n", program_name);
		return buffer;
	}
	else if(!(operator == '+' || operator == '-'))
	{
		sprintf(buffer, "Invalid Operator.\n");
		return buffer;
	}
	else if(!(RomanNumeralValidator_is_valid(numeral1)
			&& RomanNumeralValidator_is_valid(numeral2)))
	{
		sprintf(buffer, "Invalid Roman Numeral.\n");
		return buffer;	
	}
	else
	{
		sprintf(buffer, "RESULT: %s\n", 
			RomanNumeralCalculator_evaluate(numeral1, numeral2, operator));
		return buffer;	
	}
}
