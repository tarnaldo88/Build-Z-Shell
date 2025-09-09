#include "torres_shell.h"

char* get_path(char** env);
char** split_paths(char * paths, int* count);

//Executes a command by forking and running it in a child process
int executor(char** args, char** env)
{
    pid_t pid;
    int status;
    pid = fork();

    if(pid == -1)
    {
        perror("fork");
        return EXIT_FAILURE;
    }

    if (pid == 0)
    {
        //In child
        child_process(args, env);

        //execve failed in child_process.
        return EXIT_FAILURE;
    }
    else
    {
        if (waitpid(pid, &status, 0) == -1)
        {
            perror("waitpid");
            return EXIT_FAILURE;
        }
        if (WIFEXITED(status))
        {
            return WEXITSTATUS(status);
        }
        else if (WIFSIGNALED(status))
        {
            fprintf(stderr, "Process killed by signal %d\n", WTERMSIG(status));
            return EXIT_FAILURE;
        }
        else
        {
            return EXIT_FAILURE;
        }
    }
}

//Attempts to execute command by searching paths and the current directory
int child_process(char** args, char** env)
{
    char* path_string = get_path(env);
    int num_paths;
    char** paths_list = split_paths(path_string, &num_paths);

    // for (size_t i = 0; paths_list[i]; i++)
    // {
    //     printf("paths %s\n", paths_list[i]);
    // } 
    
    //access() execve()
    for (int i = 0; i < num_paths; i++)
    {
        char full_path[MAX_INPUT];
        snprintf(full_path, sizeof(full_path), "%s/%s", paths_list[i], args[0]);

        if (access(full_path, X_OK) == 0)
        {
            execve(full_path, args, env);
            perror("execve"); // only reached if execve fails
            exit(EXIT_FAILURE);
        }        
    }

    for (int i = 0; paths_list[i]; i++)
    {
        free(paths_list[i]);
    }    

    free(path_string);
    free(paths_list);

    //Attempt to execute command in the current working directory
    char *cwd = getcwd(NULL, 0);
    
    if (cwd != NULL)
    {
        char full_cwd_path[MAX_INPUT];
        snprintf(full_cwd_path, sizeof(full_cwd_path), "%s/%s", cwd, args[0]);
        free(cwd);

        execve(full_cwd_path, args, env);
        perror("execve"); // only reached if execve fails
        exit(EXIT_FAILURE);
    }
    else
    {
        perror("getcwd");
    }

    fprintf(stderr, "command not found: %s\n", args[0]);
    return EXIT_FAILURE;
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
    size_t size_of_path = my_strlen(paths);
    char paths_copy[size_of_path + 1];

    my_strncopy(paths_copy, paths, sizeof(paths_copy));
    paths_copy[sizeof(paths_copy) - 1] = '\0';

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

    // Null-terminate array
    result = realloc(result, ((*count + 1) * sizeof(char*)));
    result[*count] = NULL;

    return result;
}