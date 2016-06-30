

#ifndef _ARABIC_TO_ROMAN_H_
#define _ARABIC_TO_ROMAN_H_

struct arabic_to_roman 
{
    const int arabic;
    const char * roman;
};

extern struct arabic_to_roman ARABIC_TO_ROMAN[];
extern int arabic_to_roman_length;

#endif
