#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>

/* Access to environment variables */
extern char **environ;

/* Function prototype */
/* void execute_cmd(char *command); */
void execute_cmd(char **argv);
char *_getenv(const char *name);
char *find_path(char *command);

#endif /* MAIN_H */
