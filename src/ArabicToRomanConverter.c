#include <stdlib.h>
#include <string.h>

char * ArabicToRomanConverter_convert(int arabic_number)
{
    char * roman_numeral = calloc(15, sizeof(char));
    while(arabic_number > 0)
    {        
        if(arabic_number >= 1000)
        {
            strcat(roman_numeral, "M");
            arabic_number -= 1000;
        }
        else if(arabic_number >= 900)
        {
            strcat(roman_numeral, "CM");
            arabic_number -= 900;
        }
        else if(arabic_number >= 500)
        {
            strcat(roman_numeral, "D");
            arabic_number -= 500;
        }
        else if(arabic_number >= 400)
        {
            strcat(roman_numeral, "CD");
            arabic_number -= 500;
        }
        else if(arabic_number >= 100)
        {
            strcat(roman_numeral, "C");
            arabic_number -= 100;
        }
        else if(arabic_number >= 90)
        {
            strcat(roman_numeral, "XC");
            arabic_number -= 100;
        }
        else if(arabic_number >= 50)
        {
            strcat(roman_numeral, "L");
            arabic_number -= 50;
        }
        else if(arabic_number >= 40)
        {
            strcat(roman_numeral, "XL");
            arabic_number -= 40;
        }   
        else if(arabic_number >= 10)
        {
            strcat(roman_numeral, "X");
            arabic_number -= 10;
        }        
        else if(arabic_number >= 9)
        {
            strcat(roman_numeral, "IX");
            arabic_number -= 9;
        }
        else if(arabic_number >= 5)
        {
            strcat(roman_numeral, "V");
            arabic_number -= 5;
        }
        else if(arabic_number >= 4)
        {
            strcat(roman_numeral, "IV");
            arabic_number -= 4;
        }
        else
        {
            strcat(roman_numeral, "I");
            arabic_number -= 1;
        }    
    }
    return roman_numeral;
}
