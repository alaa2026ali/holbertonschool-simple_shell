#include "main.h"

/**
 * _getenv - get environment variable value
 * @name: variable name
 *
 * Return: pointer to value, or NULL
 */
char *_getenv(const char *name)
{
	int i, len;

	if (name == NULL || environ == NULL)
		return (NULL);

	len = strlen(name);
	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(environ[i], name, len) == 0 && environ[i][len] == '=')
			return (environ[i] + len + 1);
	}
	return (NULL);
}

/**
 * build_path - join directory and command
 * @dir: directory path
 * @cmd: command name
 *
 * Return: full path string, or NULL
 */
char *build_path(char *dir, char *cmd)
{
	char *file_path;

	file_path = malloc(strlen(dir) + strlen(cmd) + 2);
	if (file_path == NULL)
		return (NULL);

	strcpy(file_path, dir);
	strcat(file_path, "/");
	strcat(file_path, cmd);
	return (file_path);
}

/**
 * find_path - look for command in PATH directories
 * @command: command to find
 *
 * Return: full path of command, or NULL
 */
char *find_path(char *command)
{
	char *path, *path_copy, *token, *file_path;
	struct stat st;

	if (command == NULL)
		return (NULL);
	if (stat(command, &st) == 0)
		return (strdup(command));
	path = _getenv("PATH");
	if (path == NULL)
		return (NULL);
	path_copy = strdup(path);
	if (path_copy == NULL)
		return (NULL);
	token = strtok(path_copy, ":");
	while (token != NULL)
	{
		file_path = build_path(token, command);
		if (file_path && stat(file_path, &st) == 0)
		{
			free(path_copy);
			return (file_path);
		}
		free(file_path);
		token = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}
