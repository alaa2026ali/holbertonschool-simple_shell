#include "main.h"

/**
 * main - Simple UNIX command line interpreter
 *
 * Description: Displays prompt, reads input,
 * and executes commands using fork + execve.
 *
 * Return: Always 0
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("#cisfun$ ");

		nread = getline(&line, &len, stdin);

		/* Handle EOF */
		if (nread == -1)
		{
			if (isatty(STDIN_FILENO))
				printf("\n");
			break;
		}

		/* FIX: safe newline removal */
		line[strcspn(line, "\n")] = '\0';

		/* Ignore empty input */
		if (line[0] != '\0')
			execute_cmd(line);
	}

	free(line);
	return (0);
}
