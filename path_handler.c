#include "main.h"

/**
 * _getenv - Gets the value of an environment variable
 * @name: Name of the variable
 *
 * Return: Pointer to the value, or NULL if not found
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
 * build_path - Concatenates a directory path and a command
 * @dir: Directory path
 * @cmd: Command name
 *
 * Return: Full path string, or NULL on failure
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
 * find_path - Locates a command in the PATH directories
 * @command: The command to locate
 *
 * Return: Full path of the command if found, or NULL
 */
char *find_path(char *command)
{
	char *path, *path_copy, *token, *file_path;
	struct stat st;

	if (command == NULL)
		return (NULL);

	if (strchr(command, '/') != NULL)
	{
		if (stat(command, &st) == 0)
			return (strdup(command));
		return (NULL);
	}

	path = _getenv("PATH");
	if (path == NULL || strlen(path) == 0)
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
