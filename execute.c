#include "main.h"

/**
 * execute_cmd - Tokenizes and executes a command using fork and execve
 * @command: Raw input string containing the command and arguments
 */
void execute_cmd(char *command)
{
	pid_t pid;
	int status;
	char *argv[32]; /* Array to hold command and its arguments */
	char *token;
	int i = 0;

	/* 1. Tokenize the command string to remove trailing spaces and newlines */
	token = strtok(command, " \t\r\n\a");
	while (token != NULL && i < 31)
	{
		argv[i] = token;
		i++;
		token = strtok(NULL, " \t\r\n\a");
	}
	argv[i] = NULL;

	/* If the input was empty (only spaces or newlines), do nothing */
	if (argv[0] == NULL)
		return;

	/* 2. Fork and execute the clean command */
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return;
	}

	if (pid == 0)
	{
		/* Pass the tokenized array to execve */
		if (execve(argv[0], argv, environ) == -1)
		{
			/* Print standard error matching shell format */
			perror("./hsh");
			exit(127);
		}
	}
	else
	{
		wait(&status);
	}
}
