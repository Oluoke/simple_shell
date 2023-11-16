#include "shell.h"
#include <stdarg.h>

/**
 * _fprintf - A function that handles error output.
 * @stream: The file descriptor.
 * @format: Format specifier arguments.
 *
 *  Return: The number of characters printed.
 */

int _fprintf(FILE *stream, const char *format, ...);
int _fprintf(FILE *stream, const char *format, ...)
{
	int printed_chars = 0;
	va_list specifier_args;

	(void)stream;  /* Unused parameter */

	va_start(specifier_args, format);

	for (int i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '%')
			{
				/* Print a literal '%' */
				err_putchar('%');
			}
			else if (format[i] == 'c')
			{
				/* Print a character */
				char c_val = va_arg(specifier_args, int);

				if (c_val)
				{
					err_putchar(c_val);
					printed_chars++;
				}
			}
			else if (format[i] == 's')
			{
				/* Print a string */
				char *_val = va_arg(specifier_args, char *);

				for (; *_val; _val++)
				{
					err_putchar(*_val);
					printed_chars++;
				}
			}
			else if (format[i] == 'd')
			{
				/* Print an integer */
				int val = va_arg(specifier_args, int);

				if (val == 0)
					return (-1);
				int len = _integer_length(val);

				print_integer(val);
				printed_chars += len;
			}
		}
		else
		{
			/* Print other characters */
			err_putchar(format[i]);
			printed_chars++;
		}
	}

	va_end(specifier_args);

	return (printed_chars);
}

