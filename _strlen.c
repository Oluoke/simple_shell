#include "shell.h"
/**
 * _strlen - Returns the length of a string.
 * @str: String to calculate the length of.
 *
 * Return: Length of the string.
 */
size_t _strlen(const char *str)
{
	size_t len = 0;

	while (*str != '\0')
	{
		len++;
		str++;
	}

	return (len);
}

