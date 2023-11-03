#include "shell.h"

/**
 * _putchar - Prints a character to the standard output.
 * @c: Character to be printed.
 * Return: The printed character to stdout.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * ogo_strncmp - Compares two strings up to a specified number of bytes.
 * @s1: First string to be compared.
 * @s2: Second string to be compared.
 * @n: Number of bytes to compare.
 * Return: 0 if the strings are equal, otherwise the difference between the
 * characters that mismatch.
 */
int ogo_strncmp(char *s1, char *s2, int n)
{
	while (*s1 != '\0' && *s2 != '\0' && n > 0)
	{
		if (*s1 != *s2)
		{
			return (*s1 - *s2);
		}

		s1++;
		s2++;
		n--;
	}

	return (0);
}

