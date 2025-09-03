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

    for(size_t i = 0; input[i]; i++)
    {
        token = &input[i];

        while(input[i] && input[i] == ' ')
        {
            token_length++;
            i++;
        }

        tokens[position] = malloc(token_length + 1 * sizeof(char));

        if(!tokens[position])
        {
            perror("Malloc");
            exit(EXIT_FAILURE);
        }

        for(size_t j = 0; j < token_length; j++)
        {
            //getting position of token and placing each char in
            tokens[position][j] = token[j];
        }

        tokens[position][token_length] = '\0';
        position++;
        //reset for the next token
        token_length = 0; 
    }

    //Terminate array with NULL
    tokens[position] = NULL;

    return tokens;
}