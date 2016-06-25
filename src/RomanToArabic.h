

struct roman_to_arabic 
{
    const int arabic;
    const char * roman;
};

const struct roman_to_arabic ROMAN_TO_ARABIC[] =
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

#define ROMAN_TO_ARABIC_LENGTH sizeof(ROMAN_TO_ARABIC) / sizeof(ROMAN_TO_ARABIC[0])

