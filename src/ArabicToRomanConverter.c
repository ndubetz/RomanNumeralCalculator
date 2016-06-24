#include <stdlib.h>
#include <string.h>

char * ArabicToRomanConverter_convert(int arabic_number)
{
    switch(arabic_number)
    {
        case 1000:
            return "M";
        case 500:
            return "D";
        case 100:
            return "C";
        case 50:
            return "L";
        case 10:
            return "X";
        case 5:
            return "V";
        case 1:
            return "I";    
    }
}
