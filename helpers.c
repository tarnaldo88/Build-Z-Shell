#include "torres_shell.h"

/*
    my_strcmp("cat", "cat");   // returns 0
    my_strcmp("bat", "cat");   // negative (<0), because 'b' < 'c'
    my_strcmp("dog", "do");    // positive (>0), because 'g' > '\0'
*/
// returns 0 if strings are equal. < 0 str1 < str2 , > 0 str1 > str2
int my_strcmp(const char* str1, const char* str2)
{
    while(*str1 && *str1 == *str2)
    {
        str1++;
        str2++;
    }

    return *(unsigned char*)str1 - *(unsigned char*)str2;
}

char * my_getenv(const char* name, char** env)
{
    
}