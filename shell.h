#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <sys/wait.h>

#define INITIAL_CAPACITY 10

extern char **environ;
int executer(char **cmnd);
char **pathfinder(const char *name, char **cmnd);
char **token_maker(char *str);

#endif /* SHELL_H */
