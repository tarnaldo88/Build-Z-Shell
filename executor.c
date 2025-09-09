#include "torres_shell.h"

char* get_path(char** env);
char** split_paths(char * paths, int* count);

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
        if(child_process(args,env) != 0)
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
    int num_paths;
    char** paths_list = split_paths(path_string, &num_paths);

    for (size_t i = 0; paths_list[i]; i++)
    {
        printf("paths %s ", paths_list[i]);
    } 
    printf("\n");
    return EXIT_SUCCESS;
}

//Fetches PATH variable
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

//split the path string into individuals
char** split_paths(char * paths, int* count)
{
    char** result = NULL;
    char* token;
    char paths_copy[MAX_PATH];

    my_strncopy(paths_copy, paths, sizeof(paths_copy));
    paths_copy[sizeof(paths_copy - 1)] = '\0';

    token = my_strtok(paths_copy, ":");
    *count = 0;

    while(token)
    {
        result = realloc(result, ((*count + 1) * sizeof(char*)));
        if (!result)
        {
            perror("realloc");
            return NULL;
        }
        result[*count] = my_strdup(token);
        
        if (!result[*count])
        {
            perror("my_strdup");
            return NULL;
        }
        
        (*count)++;
        token= my_strtok(NULL, ":");
    }

    return result;
}