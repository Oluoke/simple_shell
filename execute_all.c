#include "shell.h"
/**
 * execute_builtin_command - Handles builtin commands in the shell.
 * @command: The command and its arguments.
 * @valget: The input string from getline.
 */
void execute_builtin_command(char **command, char *valget);
void execute_builtin_command(char **command, char *valget)
{
	char *builtin_commands[] = {"exit", "env", "setenv", "unsetenv", "cd", "#"};

	if (_strcmp(command[0], "exit") == 0)
	{
		/* ... exit logic ... */
	}
	else if (_strcmp(command[0], "env") == 0)
	{
		/* ... env logic ... */
	}
	else if (_strcmp(command[0], "setenv") == 0)
	{
		/* ... setenv logic ... */
	}
	else if (_strcmp(command[0], "unsetenv") == 0)
	{
		/* ... unsetenv logic ... */
	}
	else if (_strcmp(command[0], "cd") == 0)
	{
		/* ... cd logic ... */
	}
	else if (_strcmp(command[0], "#") == 0)
	{
		/* ... comment logic ... */
	}
	else
	{
		if (is_executable(command[0]))
		{
			call_and_execute(command, valget);
		}
		else
		{
			char *ms = "./hsh: %s: command not found\n";

			_fprintf(stderr, ms, command[0]);
			free(valget);
			free(command);
			exit(EXIT_FAILURE);
		}
	}
}

/**
 * is_executable - Checks if a file is executable.
 * @filename: The name of the file to check.
 * Return: 1 if executable, 0 otherwise.
 */
int is_executable(const char *filename)
{
	struct stat st;

	if (stat(filename, &st) == 0 && (st.st_mode & S_IXUSR))
		return (1);
	return (0);
}

