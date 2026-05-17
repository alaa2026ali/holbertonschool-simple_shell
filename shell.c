#include "main.h"

/**
 * parse_line - Splits a line into arguments tokens
 * @line: The input line string
 * @argv: The array to store argument tokens
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
 * process_command - Checks and executes the command
 * @argv: Array of arguments
 * @line: The input line pointer for memory freeing
 */
void process_command(char **argv, char *line)
{
	char *check_path;

	if (argv[0] == NULL)
		return;

	check_path = find_path(argv[0]);
	if (check_path == NULL)
	{
		fprintf(stderr, "./hsh: 1: %s: not found\n", argv[0]);
		if (!isatty(STDIN_FILENO))
		{
			free(line);
			exit(127);
		}
	}
	else
	{
		free(check_path);
		execute_cmd(argv);
	}
}

/**
 * main - Entry point for the simple shell
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
		process_command(argv, line);
	}
	free(line);
	return (0);
}
