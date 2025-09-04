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

//Examples: echo $PATH, echo -n Hello, echo message
int command_echo(char **args, char **env)
{
    //default echo ends with newline
    int new_line = 1;

    //skipping -n
    size_t i = 1;

    if(args[i] != NULL && my_strcmp(args[1], "-n") == 0)
    {
        new_line = 0;
        i++;
        // printf("\n")
    }

    //Process remaining
    for(; args[i]; i++)
    {
        if(args[i][0] == '$')
        {
            //handle env variables
            char* val = my_getenv(args[i] + 1, env);
            if(val)
            {
                printf("%s", val);
            }
            // else
            // {
            //     printf("");
            // }
        }
        else
        {
            printf("%s ", args[i]);
        }
        
        //if the line: printf("%s ", args[i]); didnt have the space ' ' in the print statement
        // if(args[i + 1] != NULL)
        // {
        //     printf(" ");
        // }
    }

    if(new_line) printf("\n");
    return 0;
}

int command_env(char **env)
{
    size_t index = 0;

    while (env[index] != NULL)
    {
        printf("%s", env[index]);
        index++;
    }    
    return 0;
}

//Search for the command in PATH
char* find_command_in_path(char* command, char** env)
{
    //store the PATH value
    char* path_env = NULL;
    //duplicate of PATH    
    char* path = NULL;
    //tokenize dirs from the PATH
    char* token = NULL;
    //Buffer to construct full paths
    char full_path[1024];

    //locate the PATH
    path_env = my_getenv(command, env);    

    if (!path_env)
    {
        //no usable path was found
        return NULL;
    }

    //duplicate path
    path = my_strdup(path_env);

    printf("Path: %s\n", path);
    return path;    
}

int command_which(char **args, char **env)
{
    if(args[1] == NULL){
        perror("An argument was not passed.\n");
        return -1;
    }

    //List of built in commands
    const char* built_in_commands[] = {"cd", "pwd", "echo", "env", "setenv", "unsetenv", "which", "exit"};
    for (size_t i = 0; built_in_commands[i]; i++)
    {
        if(my_strcmp(args[1], built_in_commands[i]) == 0)
        {
            printf("%s: shell built-in command\n", args[1]);
            return 0;
        }
    }

    //check external commands
    char* full_path = find_command_in_path(args[1], env);
    

    return 1;
}

char **command_setenv(char **args, char **env)
{
    return NULL;
}

char ** command_unsetenv(char ** args, char ** env)
{
return NULL;
}

