#include "shell.h"

/**
 *  * execute_command - Execute the given command and handle exit status
 *   * @args: Command line arguments to execute
 *    * @valget: Value obtained from getline to be freed.
 */
void execute_command(char *args[], char *valget);
void execute_command(char *args[], char *valget)
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
			char *path = ldb_getenv("PATH");
			char *token = ldb_strtok(path, ":");

			while (token != NULL)
			{
				char executable_file[MAX_INPUT_SIZE];

				snprintf(executable_file, sizeof(executable_file),
						"%s/%s", token, args[0]);

				if (access(executable_file, X_OK) != -1)
				{
					execve(executable_file, args, environ);
				}

				token = ldb_strtok(NULL, ":");
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

