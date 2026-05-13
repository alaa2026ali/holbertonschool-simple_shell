#include "main.h"

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

		if (nread == -1)
		{
			if (isatty(STDIN_FILENO))
				printf("\n");
			break;
		}

		line[strcspn(line, "\n")] = '\0';

		start = line;
		while (*start == ' ' || *start == '\t')
			start++;

		if (*start != '\0')
			execute_cmd(start);
	}

	free(line);
	return (0);
}
