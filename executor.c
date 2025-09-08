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
        return child_process(args,env);
    }
    
}

//Attempts to execute command by searching paths and the current directory
int child_process(char** args, char** env)
{

}
