#include "main.h"

/**
 * execute_cmd - Executes a command using fork and execve
 * @command: command to execute
 */
void execute_cmd(char *command)
{
	pid_t pid;
	int status;
	char *argv[2];

	pid = fork();

	if (pid == -1)
	{
		return;
	}

	if (pid == 0)
	{
		argv[0] = command;
		argv[1] = NULL;

		/* Try executing command */
		if (execve(argv[0], argv, environ) == -1)
			exit(1);
	}
	else
		wait(&status);
}
