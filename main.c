#include "torres_shell.h"


//MAIN OBJ of project
//Shell loop 
// Input Parsing
//Command executions 
// Built-in Commands exp. cd, pwd, echo, env, setenv, unsetenv, which, exit
//execute external commands
//manage environment variables
//manage path
//Error handling

// cd, pwd, echo, env, setenv, unsetenv, which, exit
int shell_builts(char **args,char** env, char* initial_directory)
{
    char* cmd = args[0];
    char* token = args[1];
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
        
        if(args[0] == NULL)
        {
            shell_builts(args, env, initial_directory);
        }
    }
} 

int main(int argc, char**argv, char** env)
{
    (void)argc;
    (void)argv;

    shell_loop(env); 
}