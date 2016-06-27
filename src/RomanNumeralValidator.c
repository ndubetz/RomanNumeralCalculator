/*
	TODO: replace with a single regular expression
			that does most of the work
*/

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

char * get_index(char numeral)
{
	return strchr(VALID_NUMERALS, numeral);
}

bool increment_counts(char numeral)
{
	int index = (get_index(numeral) - get_index('I'));
	NUMERAL_COUNTS[index]++;
}

bool validate_counts()
{
	int i;
	for(i = 0; i < NUMERALS; i++){
		int count_limit = (i % 2 == 0) 
			? ONES_DIGIT_LIMIT 
			: FIVES_DIGIT_LIMIT;
		if(NUMERAL_COUNTS[i] > count_limit){
			return false;
		} 
	}
	return true;
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

bool validate_numeral(char * num_index)
{
	return num_index >= get_index('I') && num_index <= get_index('M');
}

bool validate(char numeral, char * num_index, char * prev_index)
{
	return validate_numeral(num_index)
		&& validate_order(numeral, num_index, prev_index)
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
