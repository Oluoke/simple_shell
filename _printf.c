#include "shell.h"
#include <stdarg.h>
#include <stdlib.h>

/**
 * _printf - Custom printf function that prints to standard output.
 * @format: Format specifier for characters to be printed.
 *
 * Return: Number of characters printed successfully.
 *
 */
int _printf(const char *format, ...);
int _printf(const char *format, ...)
{
	int fmt_idx, printed_chars = 0;
	va_list fmt_spec_args;

	va_start(fmt_spec_args, format);

	if (format == NULL)
		return (-1);

	for (fmt_idx = 0; format[fmt_idx] != '\0'; fmt_idx++)
	{
		if (format[fmt_idx] == '%')
		{
			fmt_idx++;

			if (format[fmt_idx] == '%')
			{
				_putchar('%');
				printed_chars++;
			}
			else if (format[fmt_idx] == 'c')
			{
				char chr_val = va_arg(fmt_spec_args, int);

				if (chr_val)
				{
					_putchar(chr_val);
					printed_chars++;
				}
				else
				{
					exit(-1);
				}
			}
			else if (format[fmt_idx] == 's')
			{
				char *_val = va_arg(fmt_spec_args, char *);

				for (; *_val; _val++)
				{
					_putchar(*_val);
					printed_chars++;
				}
			}
		}
		else
		{
			_putchar(format[fmt_idx]);
			printed_chars++;
		}
	}

	va_end(fmt_spec_args);

	return (printed_chars);
}

