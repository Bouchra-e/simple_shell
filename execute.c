#include "shell.h"
#include "utility.h"

/**
 * execute_command - Execute a command in a child process.
 * @command: The command to execute.
 */
void execute_command(char *command)
{
pid_t pid = fork();

if (pid == -1)
{
perror("fork error");
exit(EXIT_FAILURE);
}
else if (pid == 0)
{
char **args = tokenize(command);
if (execve(args[0], args, NULL) == -1)
{
perror("execve error");
}
free_args(args);
exit(EXIT_FAILURE);
}
else
{
wait(NULL);
}
}

/**
 * run_shell - Run the shell prompt and execute user commands.
 */
void run_shell(void)
{
pid_t pid;
char buffer[MAX_BUFFER_SIZE];

while (1)
{
printf("$ ");
if (fgets(buffer, MAX_BUFFER_SIZE, stdin) == NULL)
break;

buffer[strcspn(buffer, "\n")] = '\0';

pid = fork();

if (pid == -1)
{
perror("fork error");
exit(EXIT_FAILURE);
}
else if (pid == 0)
{
char **args = tokenize(buffer);
if (execve(args[0], args, NULL) == -1)
{
perror("execve error");
}
free_args(args);
exit(EXIT_FAILURE);
}
else
{
int status;
if (wait(&status) == -1)
{
perror("wait error");
exit(EXIT_FAILURE);
}
}
}
}
