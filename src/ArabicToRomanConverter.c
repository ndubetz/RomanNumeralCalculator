#include <stdlib.h>
#include <string.h>

struct arabic_to_roman 
{
    const int arabic;
    const char * roman;
};

const struct arabic_to_roman ARABIC_TO_ROMAN[] =
{
    {1000,  "M"},
    { 900, "CM"},
    { 500,  "D"},
    { 400, "CD"},
    { 100,  "C"},
    {  90, "XC"},
    {  50,  "L"},
    {  40, "XL"},
    {  10,  "X"},
    {   9, "IX"},
    {   5,  "V"},
    {   4, "IV"},
    {   1,  "I"}
};

char * ArabicToRomanConverter_convert(int arabic_number)
{
    char * roman_numeral = calloc(16, sizeof(char));
    int i = 0;
    while(arabic_number > 0)
    {
        if(arabic_number >= ARABIC_TO_ROMAN[i].arabic)
        {
            strcat(roman_numeral, ARABIC_TO_ROMAN[i].roman);
            arabic_number -= ARABIC_TO_ROMAN[i].arabic;
        }  
        else
        {
            i++;
        }
    }
    return roman_numeral;
}
