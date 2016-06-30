#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "UpperCaseConverter.h"

char * UpperCaseConverter_convert(char * numeral)
{
	char * copy_numeral = calloc(strlen(numeral), sizeof(char));
	int i;
	for(i = 0; i < strlen(numeral); i++)
	{
		copy_numeral[i] = toupper(numeral[i]);
	}
	return copy_numeral;
}

