#include "main.h"

/**
 * execute_cmd - Tokenizes a string into arguments and executes the binary
 * @command: Raw input string containing the command line
 */
void execute_cmd(char *command)
{
	pid_t pid;
	int status;
	char *argv[32];
	char *token;
	int i = 0;

	token = strtok(command, " \t\r\n\a");
	while (token != NULL && i < 31)
	{
		argv[i] = token;
		i++;
		token = strtok(NULL, " \t\r\n\a");
	}
	argv[i] = NULL;

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
