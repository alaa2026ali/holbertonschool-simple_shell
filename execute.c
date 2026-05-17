#include "main.h"

/**
 * execute_cmd - Executes a command using a child process
 * @argv: Array of arguments
 */
void execute_cmd(char **argv)
{
	pid_t pid;
	int status;
	char *actual_command;

	if (argv == NULL || argv[0] == NULL)
		return;

	actual_command = find_path(argv[0]);
	if (actual_command == NULL)
	{
		fprintf(stderr, "./hsh: 1: %s: not found\n", argv[0]);
		return;
	}

	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		free(actual_command);
		return;
	}

	if (pid == 0)
	{
		if (execve(actual_command, argv, environ) == -1)
		{
			perror("./hsh");
			free(actual_command);
			exit(127);
		}
	}
	else
	{
		wait(&status);
	}

	free(actual_command);
}
