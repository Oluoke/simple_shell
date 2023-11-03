#include "shell.h"
char *ogo_non_interactive_getline(void);

/**
 * ogo_non_interactive_getline - this is the custom getline function for..
 * .. the non-interactive shell, it works like the traditional getline but uses
 * the read function to get the input from the file stream.
 * Return: On succes, it returns the pointer to the array of characters
 * read from the filestream.
 */

char *ogo_non_interactive_getline(void)
{
	ssize_t _read_val;

	char *buf, *mem, c;

	int idx = 0, maximum_size = 1024;

	buf = malloc(maximum_size * sizeof(char));

	if (buf == NULL)
	{
		perror("Memory Allocation Fail");

		exit(1);
	}

	while ((_read_val = read(STDIN_FILENO, &c, 1)) > 0)
	{
		if (c == EOF || c == '\n')
		{
			break;
		}

		buf[idx++] = c;

		if (idx >= (maximum_size - 1))
		{
			maximum_size = maximum_size + 1024;

			mem = realloc(buf, maximum_size);

			if (mem == NULL)
			{
				perror("Reallocation of memory failed");

				free(buf);

				exit(1);
			}

			buf = mem;
		}
	}


	if (_read_val == -1)
	{
		perror("Error");
		free(buf);
		exit(1);
	}

	if (_read_val == 0)
	{
		free(buf);

		exit(1);
	}

	buf[idx] = '\0';

	return (buf);
}
