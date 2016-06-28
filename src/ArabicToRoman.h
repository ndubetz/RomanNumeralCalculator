

#ifndef _ARABIC_TO_ROMAN_H_
#define _ARABIC_TO_ROMAN_H_

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

#define ARABIC_TO_ROMAN_LENGTH sizeof(ARABIC_TO_ROMAN) / sizeof(ARABIC_TO_ROMAN[0])

#endif
