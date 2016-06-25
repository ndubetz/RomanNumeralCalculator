/*
	TODO: replace with a single regular expression
			that does most of the work
*/

#include <string.h>
#include <stdbool.h>

#define VALID_NUMERALS_LENGTH 7

int I_count;
int X_count;
int C_count;
int M_count;
const char * VALID_NUMERALS = "IVXLCDM";

void init_counts()
{
	I_count = 0;
	X_count = 0;
	C_count = 0;
	M_count = 0;
}

char * get_index(char numeral)
{
	return strchr(VALID_NUMERALS, numeral);
}

bool increment_counts(char numeral)
{
	switch(numeral)
	{
		case 'I':
			I_count++;
			break;
		case 'X':
			X_count++;
			break;
		case 'C':
			C_count++;
			break;
		case 'M':
			M_count++;
			break;
	}
}

bool validate_counts()
{
	return I_count < 4 && X_count < 4 && C_count < 4 && M_count < 4;
}

bool is_valid_subtraction(char * num_index, char * prev_index)
{
	return (prev_index - num_index == -1 
			|| prev_index - num_index == -2)
		&& (prev_index == get_index('I') 
			||	prev_index == get_index('X')
			||  prev_index == get_index('C'));
}

bool validate_order(char numeral, char * num_index, char * prev_index)
{
	bool valid_subtraction = is_valid_subtraction(num_index, prev_index);
	if(!valid_subtraction)
	{
		increment_counts(numeral);
	}
	return prev_index - num_index >= 0
		|| valid_subtraction;
}

bool has_two_fives_digits(char * num_index, char * prev_index)
{
	bool two_Vs = num_index == prev_index && prev_index == get_index('V');
	bool two_Ls = num_index == prev_index && prev_index == get_index('L');
	bool two_Ds = num_index == prev_index && prev_index == get_index('D');
	return two_Vs || two_Ls || two_Ds;
}

bool validate_numeral(char * num_index)
{
	return num_index >= get_index('I') && num_index <= get_index('M');
}

bool validate(char numeral, char * num_index, char * prev_index)
{
	return validate_numeral(num_index)
		&& validate_order(numeral, num_index, prev_index)
		&& validate_counts()
		&& !has_two_fives_digits(num_index, prev_index);
}

bool RomanNumeralValidator_is_valid(char * roman_numeral)
{
	init_counts();
	int roman_numeral_length = strlen(roman_numeral);
	char previous_numeral = 0;
	
	int j;
	for(j = 0; j < roman_numeral_length; j++)
	{
		char numeral = roman_numeral[j];
		char * num_index = get_index(numeral);	
		char * prev_index = get_index(previous_numeral);
		
		if(!validate(numeral, num_index, prev_index))
		{
			return false;
		}
		
		previous_numeral = numeral;
	}
	return roman_numeral_length > 0;
}

bool RomanNumeralValidator_can_convert(int arabic_number)
{
	return (arabic_number > 0) && (arabic_number < 4000);
}
