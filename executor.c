#include "torres_shell.h"

//Executes a command by forking and running it in a child process
int executor(char** args, char** env)
{
    __pid_t pid;
    int status;
    pid = fork();

    if(pid == -1)
    {
        perror("fork");
        return EXIT_FAILURE;
    }

    if (pid == 0)
    {
        if(child_process(args,env))
        {
            perror("execve");
            return EXIT_FAILURE;
        }
    }
    else
    {
        if (waitpid(pid, &status, 0) == -1)
        {
            perror("waitpid");
            return EXIT_FAILURE;
        }
        
        if (WIFSIGNALED(status))
        {
            printf("Process terminated by signal: %d\n", WTERMSIG(status));
        }
        
    }
    return EXIT_SUCCESS;
}

//Attempts to execute command by searching paths and the current directory
int child_process(char** args, char** env)
{
    char* path_string = get_path(env);


    return EXIT_FAILURE;
}


char* get_path(char** env)
{
    for (size_t i = 0; env[i]; i++)
    {
        if (my_strncmp(env[i], "PATH=", 5) == 0)
        {
            return my_strdup(env[i] + 5);
        }
        
    }
    return NULL;
}