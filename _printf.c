#include "shell.h"
/**
 * _printf - Custom printf function that handles %c and %s format specifiers.
 * @format: Format specifier for characters to be printed.
 * Return: Number of characters printed successfully (excluding null byte).
 */
int _printf(const char *format, ...);
int _printf(const char *format, ...)
{
	int printed_chars = 0;
	va_list args;

	va_start(args, format);

	if (format == NULL)
		return (-1);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;

			if (*format == '\0')
				break;

			if (*format == 'c')
			{
				char chr_val = va_arg(args, int);

				_putchar(chr_val);
				printed_chars++;
			}
			else if (*format == 's')
			{
				char *str_val = va_arg(args, char *);
				int len = 0;

				while (str_val[len] != '\0')
				{
					_putchar(str_val[len]);
					len++;
				}

				printed_chars += len;
			}
			else
			{
				_putchar('%');
				_putchar(*format);
				printed_chars += 2;
			}
		}
		else
		{
			_putchar(*format);
			printed_chars++;
		}

		format++;
	}

	va_end(args);

	return (printed_chars);
}

