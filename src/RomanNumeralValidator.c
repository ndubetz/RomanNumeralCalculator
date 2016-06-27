#include <string.h>
#include <stdbool.h>

#define NUMERALS 7
#define ONES_DIGIT_LIMIT 3
#define FIVES_DIGIT_LIMIT 1

int NUMERAL_COUNTS[NUMERALS];
const char * VALID_NUMERALS = "IVXLCDM";

void init_counts()
{
	int i;
	for(i = 0; i < NUMERALS; i++)
	{
		NUMERAL_COUNTS[i] = 0;
	} 
}

int get_index(char numeral)
{
	return strchr(VALID_NUMERALS, numeral) - strchr(VALID_NUMERALS, 'I');
}

void increment_count(int num_index)
{
	NUMERAL_COUNTS[num_index]++;
}

void increment_counts_for_subtraction(int num_index, int prev_index)
{
	if(prev_index - num_index == -1)
	{
		NUMERAL_COUNTS[num_index - 1] += (ONES_DIGIT_LIMIT - 1);
		increment_count(num_index);	
	}
	else
	{
		NUMERAL_COUNTS[num_index - 2] += (ONES_DIGIT_LIMIT - 1);	
		NUMERAL_COUNTS[num_index - 1]  = FIVES_DIGIT_LIMIT;	
		NUMERAL_COUNTS[num_index]      = ONES_DIGIT_LIMIT;	
	}
}

bool validate_counts()
{
	int i;
	for(i = 0; i < NUMERALS; i++){
		int count_limit = (i % 2 == 0) 
			? ONES_DIGIT_LIMIT 
			: FIVES_DIGIT_LIMIT;
		if(NUMERAL_COUNTS[i] > count_limit)
		{
			return false;
		} 
	}
	return true;
}

bool is_valid_subtraction(int num_index, int prev_index)
{
	return (prev_index - num_index == -1 
			|| prev_index - num_index == -2)
		&& (prev_index == get_index('I') 
			||	prev_index == get_index('X')
			||  prev_index == get_index('C'));
}

bool validate_order(int num_index, int prev_index)
{
	bool valid_subtraction = is_valid_subtraction(num_index, prev_index);
	if(valid_subtraction)
	{
		increment_counts_for_subtraction(num_index, prev_index);
	}
	else
	{
		increment_count(num_index);
	}
	return prev_index - num_index >= 0
		|| valid_subtraction;
}

bool validate_numeral(int num_index)
{
	return num_index >= get_index('I') && num_index <= get_index('M');
}

bool validate(int num_index, int prev_index)
{
	return validate_numeral(num_index)
		&& validate_order(num_index, prev_index)
		&& validate_counts();
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
		int num_index = get_index(numeral);	
		int prev_index = get_index(previous_numeral);
		
		if(!validate(num_index, prev_index))
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
