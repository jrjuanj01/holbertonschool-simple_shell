#include "shell.h"

/**
 * main - acts as an interactive shell
 * Return: 0 on success
 */
int main(void)
{
	char *cmnd, **args, **path;
	size_t len = 0;
	int input = 0;

	while (1)
	{
		printf("$ ");
		if (getline(&cmnd, &len, stdin) == -1)
		{
			perror("Memory allocation error");
			exit(EXIT_FAILURE);
		}
		input++;
		cmnd[strcspn(cmnd, "\n")] = '\0';
		args = token_maker(cmnd);
		if (args[0] == NULL)
		{
			free(args);
			continue;
		}
		if (strcmp(args[0], "exit") == 0)
			break;
		if (access(args[0], X_OK) == 0)
			executer(args);
		path = pathfinder("PATH", args);
		if (path == NULL)
			printf("./hsh: %i: %s not found\n", input, args[0]);
		free(args);
	}
	free(cmnd);
	free(args);
	return (0);
}
