#include "main.h"

/**
 * main - Simple UNIX command line interpreter
 *
 * Description: Displays a prompt, reads user input,
 * and executes commands using a child process.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	while (1)
	{
		/* Display prompt only in interactive mode */
		if (isatty(STDIN_FILENO))
			printf("#cisfun$ ");

		/* Read input from user */
		nread = getline(&line, &len, stdin);

		/* Handle EOF (Ctrl+D) */
		if (nread == -1)
		{
			if (isatty(STDIN_FILENO))
				printf("\n");
			break;
		}

		/* Remove newline character */
		if (line[nread - 1] == '\n')
			line[nread - 1] = '\0';

		/* Ignore empty lines */
		if (line[0] != '\0')
			execute_cmd(line);
	}

	free(line);
	return (0);
}
