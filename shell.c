#include "shell.h"
#include <stdbool.h>
int main(void);

/**
 * main - Entry point for simple shell.
 * Return: 0 on sucess.
 */

int main(void)
{
	bool interactive_shell;

	char *_getline_;

	char **cmd_args;

	char *_prompt = "Marv&Dan$ ", *token;

	int _idx = 0;


	interactive_shell = isatty(fileno(stdin));


	while (true)
	{

		if (interactive_shell)
		{
			_printf("%s", _prompt);

			fflush(stdout);

			_getline_ = ogo_getline();

			if (_getline_ == NULL)
			{
				break;
			}

		}
		else
		{
			_getline_ = ogo_non_interactive_getline();

			if (_getline_ == NULL)
			{

				break;
			}
		}

		if (strstr(_getline_, ";") != NULL)
		{

			free(_getline_);
			continue;
		}
		cmd_args = malloc(sizeof(char *) * (MAX_ARGS + 1));

		if (cmd_args == NULL)
		{
			perror("Memory Allocation Fail");
			exit(EXIT_FAILURE);
		}

		token = ogo_strtok(_getline_, " \t\r\n\a");

		while (token != NULL && _idx < MAX_ARGS)
		{
			cmd_args[_idx] = token;

			_idx++;

			token = ogo_strtok(NULL, " \t\r\n\a");
		}

		cmd_args[_idx] = NULL;

		if (!_idx)
		{
			free(_getline_);
			free(cmd_args);

			continue;
		}

		execute_builtin_command(cmd_args, _getline_);

		free(_getline_);
		free(cmd_args);

		if (interactive_shell == 0)
		{
			break;
		}
	}

	return (0);
}
