#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <sys/wait.h>

char *pathfinder(const char *name, char *cmnd)
{
	printf("Finding Path %s/%s", name, cmnd);
	/*
	extern char **environ;
	char **env = environ;
	char *path, *poss, *full_path = NULL;

	while (*env != NULL)
	{
		if (strncmp(*env, name, strlen(name)) == 0 && (*env)[strlen(name)] == '=')
		{
			full_path = malloc(sizeof(*env));
			full_path = (*env + strlen(name) + 1);
		}
		++env;
	}
	path = strtok(full_path,":");
	poss = malloc(sizeof(path + cmnd[0] + 1));
	while (path != NULL)
	{
		sprintf(poss, "%s/%s", path, cmnd);
		if (access(poss, X_OK) == 0)
			return (path);
		path = strtok(NULL,":");
	}*/
	return (NULL);
}

char **replicator(char *str)
{
	/*printf("Tokenized %s\n", str);
	return (NULL);*/
	char **args = malloc(10 * sizeof(char *));
	char *token;
	int num_args = 0;

	if (!args)
		perror ("malloc");
	token = strtok(str, " \n");
	while (token != NULL && num_args < 9)
	{
		args[num_args++] = token;
		token = strtok(NULL, " \n");
	}
	args[num_args] = NULL;
	return (args);
}

int revenant(char *args)
{
	printf("Executed %s\n", args);
	return(0);
}

int main(void)
{
	char *cmnd, *copy, **args; // *path;
	size_t len = 0;
	int idx;

	printf("$ ");

	while (1)
	{
		//Fetching input
		if (getline(&cmnd, &len, stdin) == -1)
			perror("getline");
		cmnd[strcspn(cmnd, "\n")]= '\0';
		copy = strdup(cmnd);

		//If cmnd is full path
		if ((access(cmnd, X_OK) == 0))
			revenant(cmnd);
		printf("%s is not a full path\n", copy);
		args = replicator(copy); //Tokenize the command
		
		for (idx = 0; args != NULL; idx++)
			printf("args are = %s", args[idx]);
		//Execute section
		/*path = pathfinder("PATH", args[0]);
		if (path == NULL)
			perror("pathfinder");
		revenant(path);*/

		printf("$ ");
	}
	return (0);
}
