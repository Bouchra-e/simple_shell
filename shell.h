#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

void display_prompt(void);
void execute_command(char *command);
void handle_command(char *command);
int main(void);

#endif /* SHELL_H */
