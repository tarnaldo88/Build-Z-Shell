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

size_t my_strlen(const char* str)
{
    size_t len = 0;

    while(*str)
    {
        len++;
        str++;
    }
    return len;
}

//0: if strings are equal to n char. less than 0 str1 is less than str2. greater than 0 for opposite
int my_strncmp(const char* str1, const char* str2, size_t n)
{
    size_t i =0;

    while (i < n && str1[i] && str2[i])
    {
        if(str1[i] != str2[i])
        {
            return *(unsigned char*)str1[i] - *(unsigned char*)str2[i];
        }
        i++;
    }

    if(i == n)
    {
        return 0;
    } 
    else
    {
        return *(unsigned char*)str1[i] - *(unsigned char*)str2[i];
    }
    
}

char * my_getenv(const char* name, char** env)
{
    if(name == NULL || env == NULL)
    {
        return NULL;
    }

    size_t name_len = my_strlen(name);

    for(size_t i = 0; env[i];i++)
    {
        //check if env[i] starts with PATH=
        if(my_strcmp(env[i]) == 0)
        {

        }
    }
}