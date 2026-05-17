#include "main.h"

/**
 * execute_cmd - Executes a command using a child process
 * @argv: Array of arguments
 * @last_status: Pointer to the last command exit status
 */
void execute_cmd(char **argv, int *last_status)
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
		*last_status = 127;
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
		if (WIFEXITED(status))
			*last_status = WEXITSTATUS(status);
	}

	free(actual_command);
}
