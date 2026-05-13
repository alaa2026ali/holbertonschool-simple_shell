#include "main.h"

/**
 * execute_cmd - Executes a command using argv
 * @argv: arguments array
 */
void execute_cmd(char **argv)
{
	pid_t pid;
	int status;

	if (argv[0] == NULL)
		return;

	pid = fork();

	if (pid == -1)
		return;

	if (pid == 0)
	{
		if (execve(argv[0], argv, environ) == -1)
		{
			perror("./hsh");
			exit(127);
		}
	}
	else
	{
		wait(&status);
	}
}
