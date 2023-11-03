#include "shell.h"
/**
 * err_putchar - Prints a character to the standard error.
 * @c: Character to be printed.
 * Return: Number of characters printed (always 1).
 */
int err_putchar(char c)
{
	return (write(STDERR_FILENO, &c, 1));
}

/**
 * print_integer - Prints an integer to the standard error.
 * @val: Integer to be printed.
 */
void print_integer(int val)
{
	if (val < 0)
	{
		err_putchar('-');
		val = -val;
	}

	if (val == 0)
	{
		err_putchar('0');
		return;
	}

	if (val / 10 != 0)
	{
		print_integer(val / 10);
	}
	err_putchar('0' + val % 10);
}

/**
 * _integer_length - Counts the number of digits in an integer.
 * @integer: Integer to find the length of.
 * Return: Length of the integer.
 */
int _integer_length(int integer)
{
	int length = 0;

	if (integer <= 0)
	{
		length = 1;  /* Account for the negative sign or zero */
	}

	while (integer != 0)
	{
		integer /= 10;
		length++;
	}

	return (length);
}

