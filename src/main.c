#include <stdlib.h>
#include <stdio.h>

#include "RomanNumeralCalculator.h"

int main(int argc, char **argv)
{
	if (argc != 4) {
		printf("USAGE: %s ROMAN_NUMERAL [+|-] ROMAN_NUMERAL\n",
			       	argv[0]);
		return 1;
	}
	printf("RESULT: %s\n", RomanNumeralCalculator_evaluate(argv[1], argv[3], argv[2][0]));

	return 0;
}
