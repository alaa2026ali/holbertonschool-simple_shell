#ifndef MAIN_H
#define MAIN_H

/* --- Standard Libraries --- */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

/* --- External Environment Variable --- */
extern char **environ;

/* --- Function Prototypes --- */

/**
 * prompt - Displays the shell prompt to standard output.
 */
void prompt(void);

/**
 * handle_command - Main logic to read and process a command line.
 * @line: The input string received from the user.
 */
void handle_command(char *line);

/**
 * tokenize - Splits a string into an array of tokens (arguments).
 * @line: The input string to be parsed.
 * Return: A pointer to an array of strings (tokens).
 */
char **tokenize(char *line);

/**
 * execute - Forks a child process and executes a command.
 * @args: An array of strings representing the command and its arguments.
 * Return: 0 on success, or appropriate error code.
 */
int execute(char **args);

#endif /* MAIN_H */
