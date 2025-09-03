#include <stdio.h>

//MAIN OBJ of project
//Shell loop 
// Input Parsing
//Command executions 
// Built-in Commands exp. cd, pwd, echo, env, setenv, unsetenv, which, exit
//execute external commands
//manage environment variables
//manage path
//Error handling

void shell_loop(char** env)
{
    char* input = NULL;
    size_t input_size = 0;

    char** args;

    while(1)
    {
        getline(&input, &input_size, stdin);

        printf("Input: %s", input);
    }
} 

int main(int argc, char**argv, char** env)
{
    (void)argc;
    (void)argv;

    shell_loop(env); 
}