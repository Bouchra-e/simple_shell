#ifndef UTILITY_H
#define UTILITY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **tokenize(char *line);
void free_args(char **args);

#endif /* UTILITY_H */
