#include "torres_shell.h"
#include <stddef.h>


//MAIN OBJ of project
//Shell loop 
// Input Parsing
//Command executions 
// Built-in Commands exp. cd, pwd, echo, env, setenv, unsetenv, which, exit
//execute external commands
//manage environment variables
//manage path
//Error handling

// Built-in: cd, pwd, echo, env, setenv, unsetenv, which, exit
int shell_builts(char **args, char** env, char* initial_directory)
{
    if(my_strcmp(args[0], "cd") == 0)
    {
        return command_cd(args, initial_directory);
    }
    else if(my_strcmp(args[0], "pwd") == 0)
    {
        return command_pwd();
    }
    else if(my_strcmp(args[0], "echo") == 0)
    {
        return command_echo(args, env);
    }
    else if(my_strcmp(args[0], "env") == 0)
    {
        return command_env(env);
    }
    else if(my_strcmp(args[0], "setenv") == 0)
    {
        char** result = command_setenv(args, env);
    }
    else if(my_strcmp(args[0], "unsetenv") == 0)
    {
        char** result = command_unsetenv(args, env);
    }
    else if(my_strcmp(args[0], "which") == 0)
    {
        return command_which(args, env);
    }
    else if(my_strcmp(args[0], "exit") == 0 || my_strcmp(args[0], "quit") == 0)
    {
        printf("Goodbye!\n");
        exit(EXIT_SUCCESS);
    }
    else
    {
        printf("Unknown Command: %s\n", args[0]);
        //executor();
    }

    return 0;
}

void shell_loop(char** env)
{
    char* input = NULL;
    size_t input_size = 0;

    char** args;

    char* initial_directory = getcwd(NULL, 0);

    while(1)
    {
        printf("[torres_shell]> ");

        //returns -1 when it is the end of file (EOF), ctrl + D
        if (getline(&input, &input_size, stdin) == -1)
        {
            perror("getline");
            break;
        }

        // printf("Input: %s", input);

        args = parse_input(input);

        // for(size_t i = 0; args[i]; i++)
        // {
        //     printf("args: %s", args[i]);
        //     printf("\n");
        // }  
        
        if(args[0])
        {
            shell_builts(args, env, initial_directory);
        }

        if (args)
        {
            free_tokens(args);
            args = NULL;
        }
    }

    if (input)
    {
        free(input);
    }

    if (initial_directory)
    {
        free(initial_directory);
    }
} 

int main(int argc, char**argv, char** env)
{
    (void)argc;
    (void)argv;

    shell_loop(env); 
}