#include "shell.h"
/**
 * ogo_getline - A custom getline function to read input from the shell.
 * Return: The input string read from the user (or NULL on failure).
 */
char *ogo_getline(void)
{
	ssize_t _getline_;
	char *buf = NULL;
	size_t bufflen = 0;

	_getline_ = getline(&buf, &bufflen, stdin);

	if (_getline_ == -1)
	{
		free(buf);
		if (feof(stdin))
		{
			/* End of file (Ctrl-D) */
			_putchar('\n');
			exit(EXIT_SUCCESS);
		}
		else
		{
			/* Error reading line */
			perror("Failed to read input");
			exit(EXIT_FAILURE);
		}
	}

	if (_getline_ > 0 && buf[_getline_ - 1] == '\n')
	{
		/* Remove trailing newline character */
		buf[_getline_ - 1] = '\0';
	}

	return (buf);
}

