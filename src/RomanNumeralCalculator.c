#include <stdlib.h>
#include <string.h>

char * decompose(char * sum)
{            
    int i;
    int length = strlen(sum);
    char * result;
    for(i = 0; i < length; i++)
    {
        if(sum[i] == 'V')
        {
            char * IIII = "IIII";
            char * left = calloc(i + 1, sizeof(char)); 
            char * right = calloc(length - i, sizeof(char));
            char * result = calloc(length + 3, sizeof(char));
            strncpy(left, sum, i - 1);
            strncpy(right, sum + i + 1, length - i + 1);
            strcpy(result, left);
            strcat(result, IIII);
            strcat(result, right);
            return result;
        }
    }    
    return sum;
}

void simplify(char * sum)
{   
    if(strcmp(sum, "IIII") == 0)
    {
        sum[1] = 'V';
        sum[2] = NULL;
    }
    if(strcmp(sum, "IIIII") == 0)
    {
        sum[0] = 'V';
        sum[1] = NULL;    
    }
}

char * RomanNumeralCalculator_add(char * number1, char * number2)
{
    char * sum = calloc(21, sizeof(char));
    strcpy(sum, number1);
    strcat(sum, number2);
    sum = decompose(sum);    
    simplify(sum);
    return sum;
}
