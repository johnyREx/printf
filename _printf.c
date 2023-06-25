#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - output of the format string.
 * @format: character string
 *
 * Return: Number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;
	char c;
	char *str;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;

			switch (*format)
			{
				case 'c':
					c = va_arg(args, int);
					write(1, &c, 1);
					printed_chars++;
					break;
				case 's':
					str = va_arg(args, char *);
					if (str == NULL)
						str = "(null)";
					while (*str)
					{
						write(1, str, 1);
						str++;
						printed_chars++;
					}
					break;
				case '%':
					write(1, "%", 1);
					printed_chars++;
					break;
				default:
					write(1, "%", 1);
					write(1, &(*format), 1);
					printed_chars += 2;
					break;
			}
		}
		else
		{
			write(1, &(*format), 1);
			printed_chars++;
		}

		format++;
	}

	va_end(args);

	return (printed_chars);
}
