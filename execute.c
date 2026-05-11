#include "main.h"

/**
 * execute_cmd - Executes a command using fork and execve
 * @command: The command to execute (full path only)
 *
 * Description: Creates a child process to execute a command.
 * The parent process waits for the child to finish.
 */
void execute_cmd(char *command)
{
	pid_t pid;
	int status;
	char *argv[2];

	/* Create a new process */
	pid = fork();

	if (pid == -1)
	{
		perror("Error");
		return;
	}

	/* Child process */
	if (pid == 0)
	{
		argv[0] = command;
		argv[1] = NULL;

		/* Execute command */
		if (execve(argv[0], argv, environ) == -1)
		{
			perror("./hsh");
			exit(1);
		}
	}
	else
	{
		/* Parent process waits for child */
		wait(&status);
	}
}
