

#include "include/ArabicToRoman.h" 

struct arabic_to_roman ARABIC_TO_ROMAN[] =
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

int arabic_to_roman_length = sizeof(ARABIC_TO_ROMAN) / sizeof(struct arabic_to_roman);

