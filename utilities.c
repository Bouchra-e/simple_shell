#include "utility.h"
#define BUFFER_SIZE 1024
/**
 * tokenize - Tokenize a string into an array of tokens.
 * @line: The string to tokenize.
 *
 * Return: An array of tokens.
 */

char **tokenize(char *line)
{
const char *delimiters = " \t\n\r\a";
char **tokens = malloc(sizeof(char *) * BUFFER_SIZE);
char *token;
int index = 0;

if (tokens == NULL)
{
perror("malloc error");
exit(EXIT_FAILURE);
}
token = strtok(line, delimiters);
while (token != NULL)
{
tokens[index] = token;
index++;

token = strtok(NULL, delimiters);
}
tokens[index] = NULL;

return (tokens);
}

/**
 * free_args - Free the memory allocated for an array of arguments.
 * @args: The array of arguments.
 */

void free_args(char **args)
{
int i = 0;
while (args[i] != NULL)
{
free(args[i]);
i++;
}
free(args);
}
