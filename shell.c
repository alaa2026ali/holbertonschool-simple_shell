#include "main.h"
#include <string.h>

/**
 * main - simple shell entry point
 *
 * Return: 0
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	char *token;
	char *argv[1024];
	int i;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("#cisfun$ ");

		nread = getline(&line, &len, stdin);
		if (nread == -1)
		{
			if (isatty(STDIN_FILENO))
				printf("\n");
			break;
		}

		if (line[nread - 1] == '\n')
			line[nread - 1] = '\0';

		i = 0;
		token = strtok(line, " ");

		while (token != NULL)
		{
			argv[i] = token;
			i++;
			token = strtok(NULL, " ");
		}
		argv[i] = NULL;

		if (argv[0] != NULL)
		}

	free(line);
	return (0);
}
