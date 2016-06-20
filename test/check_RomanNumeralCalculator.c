#include <string.h>
#include <check.h>

#include "RomanNumeralCalculator.h"

START_TEST ("adds I and I to get II")
{
	char * i = "I";
	char * ii = "II";
	char * result = RomanNumeralCalculator_add(i, i);
	ck_assert_str_eq(result, ii);		
}
END_TEST
