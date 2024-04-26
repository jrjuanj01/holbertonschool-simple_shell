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
 * @args: command to be executed
 * Return: the full path of the command to be executed or NULL if failed
 */
char **pathfinder(const char *name, char **args)
{
	char **env = environ;
	char *path, *poss, *full_path = NULL;
	size_t len;

	while (*env != NULL)
	{
		if (strncmp(*env, name, strlen(name)) == 0 && (*env)[strlen(name)] == '=')
		{
			full_path = strdup(*env + strlen(name) + 2);
			break;
		}
		++env;
	}
	path = strtok(full_path, ":");
	while (path != NULL)
	{
		len = snprintf(NULL, 0, "%s/%s", path, args[0]) + 1;
		poss = malloc(len);
		if (poss == NULL || full_path == NULL)
		{
			perror("Memory allocation error 2");
			exit(EXIT_FAILURE);
		}
		sprintf(poss, "%s/%s", path, args[0]);
		if (access(poss, X_OK) == 0)
		{
			args[0] = poss;
			executer(args);
			free(full_path);
			free(poss);
			return (args);
		}
		free(poss);
		path = strtok(NULL, ":");
	}
	free(full_path);
	return (NULL);
}

/**
 * token_maker - takes a string and parses it's components
 * @str: is the string to parse
 * Return: the array of strings of each part of the sentence
 */
char **token_maker(char *str)
{
	char **args = malloc(sizeof(char *) * INITIAL_CAPACITY);
	char *token;
	int amnt = 0;

	if (!args)
	{
		perror("Memory allocation error 1");
		exit(EXIT_FAILURE);
	}
	token = strtok(str, " \n");
	while (token != NULL)
	{
		args[amnt] = token;
		token = strtok(NULL, " \n");
		amnt++;
	}
	args[amnt] = NULL;
	return (args);
}
/*
 * empty - frees an array of strings
 * @str: the array of strings
 */
int empty(char **str)
{
	int idx1, idx2;

	for (idx1 = 0; str[idx1] != NULL ; idx1++)
	for (idx2 = 0; idx2 < idx1 ; idx2++)
		free(str[idx2]);
	free(str);
	return (0);
}
