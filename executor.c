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
}
