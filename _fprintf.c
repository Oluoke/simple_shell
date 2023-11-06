#include "shell.h"
int _fprintf(FILE *stream, const char *format, ...);

/**
 * _fprintf - A function that handles error output.
 * @stream: The file descriptor.
 * @format: format specifer arguments.
 *
 * Return: The length of string
 */

int _fprintf(FILE *stream, const char *format, ...)
{
	int i;

	int printed_chars = 0;

	va_list specifier_args;

	(void)stream;

	va_start(specifier_args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i = i + 1;

			if (format[i] == '%')
			{
				err_putchar('%');
			}
			else if (format[i] == 'c')
			{
				char c_val = va_arg(specifier_args, int);

				if (c_val)
				{
					err_putchar(c_val);
					printed_chars = printed_chars + 1;
				}

			}
			else if (format[i] == 's')
			{
				char *_val = va_arg(specifier_args, char *);

				int _idx = 0;

				int _len = 0;

				for (_idx = 0; _val[_idx] != '\0'; _idx++)
				{
					err_putchar(_val[_idx]);
				}

				while (*_val != '\0')
				{
					_len = _len + 1;

					_val = _val + 1;
				}

				printed_chars = printed_chars + _len;
			}
			else if (format[i] == 'd')
			{
				int len = 0;

				int val = va_arg(specifier_args, int);

				if (val == 0)
				{
					return (-1);
				}

				len = _integer_length(val);

				print_integer(val);
				printed_chars = printed_chars + len;
			}
		}
		else
		{
			err_putchar(format[i]);
			printed_chars = printed_chars + 1;
		}
	}

	va_end(specifier_args);

	return (printed_chars);

}
