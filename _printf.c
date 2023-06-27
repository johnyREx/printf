#include "main.h"
#include <unistd.h>

/**
 * _printf - produces output according to a format
 * @format: character string
 *
 * Return: number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);
	if (format == NULL)
		return (-1);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;

			if (*format == '%')
			{
				count += write(1, "%", 1);
			}
			else if (*format == 'c')
			{
				int c = va_arg(args, int);
				count += write(1, &c, 1);
			}
			else if (*format == 's')
			{
				char *s = va_arg(args, char *);
				if (s == NULL)
					s = "(null)";
				count += write(1, s, _strlen(s));
			}
		}
		else
		{
			count += write(1, format, 1);
		}

		format++;
	}

	va_end(args);

	return (count);
}
