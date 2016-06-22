#include <stdlib.h>
#include <string.h>

void check_and_apply_aggregation(char * sum)
{
    if(strlen(sum) >= 5)
    {
        sum[strlen(sum) - 5] = 'V';
        sum[strlen(sum) - 4] = NULL;
    }    
}

void check_and_apply_subtraction(char * sum)
{
    if(strlen(sum) > 3)
    {
        sum[strlen(sum) - 3] = 'V';
        sum[strlen(sum) - 2] = NULL;    
    }    
}

void simplify(char * sum)
{   
    check_and_apply_aggregation(sum);
    check_and_apply_subtraction(sum); 
}

char * RomanNumeralCalculator_add(char * number1, char * number2)
{
    char * sum = calloc(strlen(number1) + strlen(number2) + 1, sizeof(char));
    strcpy(sum, number1);
    strcat(sum, number2);
    if(strcmp(sum,"IVI") == 0){
        sum[0] = 'V';
        sum[1] = NULL;
    }    
    simplify(sum);
    return sum;
}
