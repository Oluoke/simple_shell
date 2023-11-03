#include "shell.h"
void call_and_execute(char *args[], char *valget);

/**
 * call_and_execute - Execute the given command and handle exit status
 * @args: Command line arguments to execute
 * @valget: this is the getline value to be freed.
 */

void call_and_execute(char *args[], char *valget)
{
	pid_t pid_fork_val;

	int _status;

	pid_fork_val = fork();

	if (pid_fork_val == -1)
	{
		perror("Fork Error");

		free(valget);
		free(args);

		exit(EXIT_FAILURE);
	}

	if (pid_fork_val == 0)
	{
		if (strchr(args[0], '/') != NULL)
		{
			if (execve(args[0], args, environ) == -1)
			{
				perror("Error: Execution terminated");
				free(valget);
				free(args);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			char *path = ogo_getenv("PATH");
			char *token = ogo_strtok(path, ":");

			while (token != NULL)
			{
				char executable_file[MAX_INPUT_SIZE];

				strcpy(executable_file, token);
				strcat(executable_file, "/");
				strcat(executable_file, args[0]);

				if (access(executable_file, X_OK) != -1)
				{
					execve(executable_file, args, environ);
				}

				token = ogo_strtok(NULL, ":");
			}
			_fprintf(stderr, "./hsh: %d: %s: cannot find\n", 1, args[0]);
			free(valget);
			free(args);
			exit(127);
		}
	}
	else
	{
		do {
			waitpid(pid_fork_val, &_status, 0);

			if (WIFEXITED(_status))
			{
				free(valget);
				free(args);
				exit(WEXITSTATUS(_status));
			}
			if (WIFSIGNALED(_status))
			{
				raise(WTERMSIG(_status));
			}
		} while (WIFEXITED(_status) && WIFSIGNALED(_status));
	}
}
