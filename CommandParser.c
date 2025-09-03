#include "torres_shell.h"

int command_cd(char** args, char* initial_directory)
{
    // CD requires path 
    if(args[1] == NULL)
    {
        perror("CD requires path\n");
        return -1;
    }

    return 0;
}

int command_pwd()
{
    return 0;
}

int command_echo(char **args, char **env)
{
    if(args[1] == NULL)
    {
        perror("Echo requires message to echo.\n");
        return -1;
    }
    for(size_t i = 1; args[i]; i++)
    {
        printf("%s ", args[i]);
    }
    return 0;
}

int command_env(char **env)
{
    return 0;
}

int command_which(char **args, char **env)
{
    return 0;
}

char **command_setenv(char **args, char **env)
{
    return NULL;
}

char ** command_unsetenv(char ** args, char ** env)
{
return NULL;
}
