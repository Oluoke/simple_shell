#include "shell.h"
char *ogo_strtok(char *str, const char *delim);
/**
 * ogo_strtok - dan mavy custom function that tokenizes a string
 * it works based on the delimiter of the string to be tokenized.
 * @str: string to be tokenized which is the first argument.
 * @delim: this represents the delimiter ofthe string in what pattern
 * to be splitted.
 * Return: tokenized string on success, else NULL.
 */

char *ogo_strtok(char *str, const char *delim)
{
	static char *next_token;

	char *new_token;

	if (str != NULL)
	{
		next_token = str;
	}

	if (*next_token == '\0' || next_token == NULL)
	{
		return (NULL);
	}

	while (*next_token != '\0' && strchr(delim, *next_token) != NULL)
	{
		next_token++;
	}

	if (*next_token == '\0')
	{
		return (NULL);
	}

	new_token = next_token;

	while (*next_token != '\0' && strchr(delim, *next_token) == NULL)
	{
		next_token = next_token + 1;
	}

	if (*next_token != '\0')
	{
		*next_token = '\0';

		next_token = next_token + 1;
	}

	return (new_token);
}

