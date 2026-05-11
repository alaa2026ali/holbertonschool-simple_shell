#ifndef MAIN_H
#define MAIN_H

/* Standard libraries */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/* Access to environment variables */
extern char **environ;

/* Function prototype */
void execute_cmd(char *command);

#endif /* MAIN_H */
