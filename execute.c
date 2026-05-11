#include "main.h"

/**
 * execute_cmd - Executes a command using fork and execve
 * @command: Full path of command
 *
 * Description: Creates child process and executes command.
 * Parent waits for child.
 */
void execute_cmd(char *command)
{
	pid_t pid;
	int status;
	char *argv[2];

	pid = fork();

	if (pid == -1)
	{
		perror("Error");
		return;
	}

	if (pid == 0)
	{
		argv[0] = command;
		argv[1] = NULL;

		if (execve(argv[0], argv, environ) == -1)
		{
			perror("./hsh");
			exit(1);
		}
	}
	else
	{
		wait(&status);
	}
}
