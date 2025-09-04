#include "torres_shell.h"

size_t my_strlen(const char* str)
{
    if(str == NULL) return -1;
    size_t len = 0;

    while(*str)
    {
        len++;
        str++;
    }
    return len;
}

/*
    my_strcmp("cat", "cat");   // returns 0
    my_strcmp("bat", "cat");   // negative (<0), because 'b' < 'c'
    my_strcmp("dog", "do");    // positive (>0), because 'g' > '\0'
*/
// returns 0 if strings are equal. < 0 str1 < str2 , > 0 str1 > str2
int my_strcmp(const char* str1, const char* str2)
{
    if(str1 == NULL || str2 == NULL) { return 1; }

    while(*str1 && *str1 == *str2)
    {
        str1++;
        str2++;
    }

    return *(unsigned char*)str1 - *(unsigned char*)str2;
}

/* 
    Compares at most n characters.
    Stops early if a mismatch is found or either string ends.
    If the first n characters are the same, it returns 0, even if the strings differ later.
*/
//0: if strings are equal to n char. less than 0 str1 is less than str2. greater than 0 for opposite
int my_strncmp(const char* str1, const char* str2, size_t n)
{
    size_t i =0;

    while (i < n && str1[i] && str2[i])
    {
        if(str1[i] != str2[i])
        {
            return (unsigned char)str1[i] - (unsigned char)str2[i];
        }
        i++;
    }

    if(i == n)
    {
        return 0;
    } 
    else
    {
        return (unsigned char)str1[i] - (unsigned char)str2[i];
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
        if(my_strncmp(env[i], name, name_len) == 0 && env[i][name_len] == '=')
        {
            return &env[i][name_len + 1];
        }
    }
    return NULL;
}

char* my_strdup(const char* str)
{
    if(str == NULL) return NULL;

    size_t len = my_strlen(str);

    char* duplicate = (char*)malloc((len+1) * sizeof(char));

    if(duplicate == NULL) return NULL;

    my_strcopy(duplicate, str);

    return duplicate;
}

char* my_strcopy(char * destination, const char * source)
{
    char * ret = destination;

    while(*source)
    {
        *destination = *source;
        destination++;
        source++;
    }

    *destination = '\0';
    return ret;
}