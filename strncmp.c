#include "shell.h"
/**
 * _strcmp - Compare two strings
 * @s1: First string to be compared
 * @s2: Second string to be compared
 *
 * Return: 0 if strings are equal, negative value if s1 < s2,
 * positive value if s1 > s2
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}

	/* Strings are equal up to the length of the shorter string */
	if (s1[i] == '\0' && s2[i] == '\0')
		return (0);
	else if (s1[i] == '\0')
		return (-1); /* s1 is shorter */
	else
		return (1);  /* s2 is shorter */
}

