#include "shell.h"

#define BUFFER_SIZE 1024

/**
 * execute_command - Executes the given command.
 * @command: The command to execute.
 * Description: This function executes the specified command using the
 * execvp() system call. If the execution fails, an error message is printed.
 */

void execute_command(char *command)
{
pid_t pid = fork();

if (pid == -1)
{
perror("fork");
exit(EXIT_FAILURE);
}

if (pid == 0)
{
char *token;
char *command_name;
char *arguments[100];
int i = 0;

token = strtok(command, " ");
command_name = token;

while (token != NULL)
{
arguments[i] = token;
i++;
token = strtok(NULL, " ");
}
arguments[i] = NULL;

if (execvp(command_name, arguments) == -1)
{
perror(command_name);
exit(EXIT_FAILURE);
}
}

if (wait(NULL) == -1)
{
perror("wait");
exit(EXIT_FAILURE);
}
}

/**
 * handle_command - Handles the received command.
 * @command: The command to handle.
 * Description: This function parses the command into separate arguments
 * using whitespace as a delimiter. The arguments are stored in the 'arguments'
 * array for further processing.
 */

void handle_command(char *command)
{
char *token;
char *arguments[100];
int i = 0;
int j;

token = strtok(command, " ");

while (token != NULL)
{
arguments[i] = token;
i++;
token = strtok(NULL, " ");
}
arguments[i] = NULL;

printf("Command arguments:\n");
for (j = 0; j < i; j++)
{
printf("- %s\n", arguments[j]);
}
}

/**
* display_prompt - Display the shell prompt
*/

void display_prompt(void)
{
printf("#cisfun$ ");
fflush(stdout);
}

/**
* main - Main function of the shell
* Description: Read user input, execute commands, and display the prompt.
* Return: Always 0.
*/

int main(void)
{
char command[BUFFER_SIZE];

while (1)
{
display_prompt();

if (fgets(command, sizeof(command), stdin) == NULL)
{
printf("\n");
break;
}

command[strcspn(command, "\n")] = '\0';

if (strcmp(command, "exit") == 0)
{
break;
}

handle_command(command);
execute_command(command);
}

return (EXIT_SUCCESS);
}
