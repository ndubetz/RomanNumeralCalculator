#include <stdlib.h>
#include <string.h>

int roman_to_arabic(char * roman_numeral)
{
    int length = strlen(roman_numeral);
    int i;
    int arabic_number = 0;
    for(i = length; i--;)
    {
        switch(roman_numeral[i])
        {
            case 'X':
                if(length - i > 0 && roman_numeral[i - 1] == 'I')
                {
                    arabic_number += 9;
                    i--;
                }
                else
                {
                    arabic_number += 10;
                }
                break;
            case 'V':
                if(length - i > 0 && roman_numeral[i - 1] == 'I')
                {
                    arabic_number += 4;
                    i--;
                }
                else
                {
                    arabic_number += 5;
                }
                break;
            case 'I':
                arabic_number++;
                break;
            default:
                break;
        }            
    }
    return arabic_number;
}

char * arabic_to_roman(int number)
{
    char * roman_numeral = calloc(16, sizeof(char));
    while(number > 0)
    {
        if(number >= 10)
        {
            strcat(roman_numeral, "X");
            number -= 10;
        }        
        else if(number >= 9)
        {
            strcat(roman_numeral, "IX");
            number -= 9;
        }
        else if(number >= 5)
        {
            strcat(roman_numeral, "V");
            number -= 5;
        }
        else if(number >= 4)
        {
            strcat(roman_numeral, "IV");
            number -= 4;
        }
        else
        {
            strcat(roman_numeral, "I");
            number -= 1;
        }
    }
    return roman_numeral;
}

char * RomanNumeralCalculator_add(char * numeral1, char * numeral2)
{
    int number1 = roman_to_arabic(numeral1);
    int number2 = roman_to_arabic(numeral2);    
    char * sum = arabic_to_roman(number1 + number2);    
    return sum;
}
