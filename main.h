#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

/* Access to environment variables */
extern char **environ;

/* Function prototype */
/* void execute_cmd(char *command); */
void execute_cmd(char **argv);

#endif /* MAIN_H */
