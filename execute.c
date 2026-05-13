#include "main.h"

/**
 * execute_cmd - Executes a command
 * @argv: arguments array
 */
void execute_cmd(char **argv)
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid == -1)
	{
		perror("Error");
		return;
	}

	if (pid == 0)
	{
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
