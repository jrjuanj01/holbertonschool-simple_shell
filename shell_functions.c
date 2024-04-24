#include "shell.h"

/**
 * executer - executes the given command
 * @cmnd: given command
 * Return: status number
 */
int executer(char **cmnd)
{
	pid_t my_pid = fork();

	if (my_pid == 0)
		execve(cmnd[0], cmnd,  NULL);
	else
		wait(NULL);
	return (0);
}

/**
 * pathfinder - finds the path of the command to be executed
 * @name: name of the path to be found
 * @cmnd: command to be executed
 * Return: the full path of the command to be executed or NULL if failed
 */
char **pathfinder(const char *name, char **cmnd)
{
	char **env = environ;
	char *path, *poss, *path_copy, *full_path = NULL;

	while (*env != NULL)
	{
		if (strncmp(*env, name, strlen(name)) == 0 && (*env)[strlen(name)] == '=')
		{
			full_path = strdup(*env + strlen(name) + 1);
			break;
		}
		++env;
	}
	path_copy = strdup(full_path);
	path = strtok(path_copy, ":");
	poss = malloc(strlen(path) + strlen(cmnd[0]) + 2);
	if (path_copy == NULL || poss == NULL || full_path == NULL)
	{
		perror("Memory allocation error");
		exit(EXIT_FAILURE);
	}
	while (path != NULL)
	{
		sprintf(poss, "%s/%s", path, cmnd[0]);
		if (access(poss, X_OK) == 0)
		{
			cmnd[0] = poss;
			executer(cmnd);
			free(full_path);
			free(path_copy);
			free(poss);
			return (cmnd);
		}
		path = strtok(NULL, ":");
	}
	free(full_path);
	free(path_copy);
	free(poss);
	return (NULL);
}

/**
 * token_maker - takes a string and parses it's components
 * @str: is the string to parse
 * Return: the array of strings of each part of the sentence
 */
char **token_maker(char *str)
{
	size_t capacity = INITIAL_CAPACITY;
	char **args = malloc(capacity * sizeof(char *));
	char *token;
	int amnt = 0;

	if (!args)
	{
		perror("Memory allocation error");
		exit(EXIT_FAILURE);
	}
	token = strtok(str, " \n");
	while (token != NULL && amnt < INITIAL_CAPACITY)
	{
		args[amnt++] = token;
		token = strtok(NULL, " \n");
	}
	args[amnt] = NULL;
	return (args);
}
