#include "main.h"

/**
 * execute_cmd - Tokenizes and executes a command using fork and execve
 * @command: Raw input string containing the command
 */
void execute_cmd(char *command)
{
	pid_t pid;
	int status;
	char *argv[32]; /* Safe array size to hold commands and arguments */
	char *token;
	int i = 0;

	/* Strip trailing/leading spaces, tabs, and newlines */
	token = strtok(command, " \t\r\n\a");
	while (token != NULL && i < 31)
	{
		argv[i] = token;
		i++;
		token = strtok(NULL, " \t\r\n\a");
	}
	argv[i] = NULL;

	/* If input was empty or only spaces, do nothing */
	if (argv[0] == NULL)
		return;

	pid = fork();
	if (pid == -1)
		return;

	if (pid == 0)
	{
		if (execve(argv[0], argv, environ) == -1)
		{
			/* Safe exit to allow the main loop to continue parsing */
			exit(127);
		}
	}
	else
	{
		wait(&status);
	}
}
