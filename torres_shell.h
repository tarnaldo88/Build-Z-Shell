#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include<sys/wait.h>

#define MAX_INPUT 1024
#define MAX_PATH 256

char** parse_input(char* input);
void free_tokens(char** tokens);
int shell_builts(char **args,char** env, char* initial_directory);

//Built-in function implementations
int command_cd(char** args, char* initial_directory);
int command_pwd();
int command_echo(char** args, char** env);
int command_env(char** env);
int command_which(char** args, char** env);

char** command_setenv(char** args, char** env);
char** command_unsetenv(char** args, char** env);

//Executor
int executor(char** args, char** env);
int child_process(char** args, char** env);


//helper function
int my_strcmp(const char* str1, const char* str2);
size_t my_strlen(const char* str);
int my_strncmp(const char* str1, const char* str2, size_t n);
char* my_getenv(const char* name, char** env);
char* my_strdup(const char* str);
char* my_strcopy(char * destination, const char * source);
char* my_strtok(char* str, const char* delimiter);
char* my_strch(const char* str, char c);
char* my_strncopy(char* dest, const char* src, size_t n);
