#include "shell.h"

/**
 * _fprintf - A function that handles error output.
 * @stream: The file descriptor (not used in this implementation).
 * @format: Format specifier arguments.
 *
 * Return: The number of characters printed (excluding null byte).
 */
int _fprintf(FILE *stream, const char *format, ...);
int _fprintf(FILE *stream, const char *format, ...)
{
	int printed_chars = 0;
	va_list args;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;

			if (*format == '\0')
				break;

			if (*format == 'c')
			{
				char c_val = va_arg(args, int);

				err_putchar(c_val);
				printed_chars++;
			}
			else if (*format == 's')
			{
				char *s_val = va_arg(args, char *);
				int len = 0;

				while (s_val[len] != '\0')
				{
					err_putchar(s_val[len]);
					len++;
				}
				printed_chars += len;
			}
			else if (*format == 'd')
			{
				int val = va_arg(args, int);
				int len = _integer_length(val);

				print_integer(val);
				printed_chars += len;
			}
			else
			{
				err_putchar('%');
				err_putchar(*format);
				printed_chars += 2;
			}
		}
		else
		{
			err_putchar(*format);
			printed_chars++;
		}

		format++;
	}

	va_end(args);

	return (printed_chars);
}

