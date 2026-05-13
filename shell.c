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

/**
 * main - Simple UNIX command line interpreter
 *
 * Return: Always 0
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	char *start;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("#cisfun$ ");

		nread = getline(&line, &len, stdin);

		/* Handle EOF (Ctrl+D) or end of pipe stream */
		if (nread == -1)
		{
			if (isatty(STDIN_FILENO))
				printf("\n");
			break;
		}

		/* Cleanly remove trailing newline character */
		line[strcspn(line, "\n")] = '\0';

		/* Advance pointer past any leading whitespace */
		start = line;
		while (*start == ' ' || *start == '\t')
			start++;

		/* Execute only if the evaluated string contains text */
		if (*start != '\0')
			execute_cmd(start);
	}

	free(line);
	return (0);
}
