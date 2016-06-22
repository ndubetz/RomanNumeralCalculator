#include <stdlib.h>
#include <string.h>

void apply_subtraction(char * sum)
{
    sum[strlen(sum) - 3] = 'V';
    sum[strlen(sum) - 2] = NULL;    
}

char * RomanNumeralCalculator_add(char * number1, char * number2)
{
    char * sum = calloc(strlen(number1) + strlen(number2) + 1, sizeof(char));
    strcpy(sum, number1);
    strcat(sum, number2);    

    if(strlen(sum) > 3)
    {
        apply_subtraction(sum);
    }

	return sum;
}
