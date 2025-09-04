#include "torres_shell.h"

//commands accepted for cd: cd [path], cd - (prev dir), cd ~ (home dir), cd .., handle non exist dir, permission issues
int command_cd(char** args, char* initial_directory)
{
    (void) initial_directory;
    // CD requires path 
    if(args[1] == NULL)
    {
        perror("CD requires path- example: \"cd [path]\"\n");
        return -1;
    } 
    else if(chdir(args[1]) == 0)
    {
        printf("cd worked, placeholder\n");
    } 
    else
    {
        perror("CD");
        return -1;
    }

    return 0;
}

int command_pwd()
{
    char* cwd = NULL;
    size_t size = 0;

    //Using dynamic allocation
    cwd = getcwd(NULL, size);

    if (cwd != NULL)
    {
        printf("%s\n", cwd);
        free(cwd);
    }
    else
    {
        perror("getcwd failed.\n");
        return -1;
    }    

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
    printf("\n");
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
