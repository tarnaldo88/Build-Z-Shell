#include "torres_shell.h"

char** parse_input(char* input)
{
    size_t buffer_size = MAX_INPUT;
    char** tokens = malloc(buffer_size * sizeof(char*));
    char* token =  NULL;
    size_t position = 0;
    size_t token_length = 0;

    if(!tokens)
    {
        perror("Malloc");
        exit(EXIT_FAILURE);
    }

     // Loop through each character in the input string
    for (size_t i = 0; input[i]; i++)    
    {
        // Skip leading whitesapce characters ' ' \n \t \r \a
        while (input[i] == ' ' || input[i] == '\n' || input[i] == '\t' || input[i] == '\r' || input[i] == '\a')
        {
            i++;
        }

        if(input[i] == '\0') break;

        token = &input[i];

        while (input[i] != '\0' && input[i] != ' ' && input[i] != '\n' && input[i] != '\t' && input[i] != '\r' && input[i] != '\a')
        {
            token_length++;
            i++;
        }

        tokens[position] = malloc((token_length + 1) * sizeof(char));

        if(!tokens[position]) 
        {
            perror("Malloc");
            exit(EXIT_FAILURE);
        }

        for (size_t j = 0; j < token_length; j++)
        {
            tokens[position][j] = token[j];
        }
        tokens[position][token_length] = '\0'; // Null terminate token
        position++;
        token_length = 0; // Reset for next token     
    }

    //Terminate array with NULL
    tokens[position] = NULL;

    return tokens;
}

//Free Allocated Tokens
void free_tokens(char** tokens)
{
    if (!tokens) return;

    for(size_t i = 0; tokens[i]; i++)
    {
        // free each token
        free(tokens[i]);
    }
    free(tokens);
}