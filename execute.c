#include "main.h"

/**
 * execute_cmd - executes a command
 * @argv: array of arguments
 */
void execute_cmd(char **argv)
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid == -1)
		return;

	if (pid == 0)
	{
		execve(argv[0], argv, environ);
		exit(1);
	}
	else
		wait(&status);
}
