#include "main.h"

/**
 * parse_line - Splits a line into arguments
 * @line: The line to split
 * @argv: The array to store arguments
 */
void parse_line(char *line, char **argv)
{
	char *token;
	int i = 0;

	token = strtok(line, " \t");
	while (token != NULL)
	{
		argv[i] = token;
		i++;
		token = strtok(NULL, " \t");
	}
	argv[i] = NULL;
}

/**
 * main - Simple shell entry point
 *
 * Return: Always 0
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	char *argv[1024];

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

		parse_line(line, argv);

		if (argv[0] != NULL)
		{
			if (find_path(argv[0]) == NULL)
			{
				fprintf(stderr, "./hsh: 1: %s: not found\n", argv[0]);
				if (!isatty(STDIN_FILENO))
				{
					free(line);
					exit(127);
				}
			}
			else
				execute_cmd(argv);
		}
	}
	free(line);
	return (0);
}
