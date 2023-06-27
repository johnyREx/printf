#include "main.h"
#include <stdarg.h>
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
	char c;
	char *s;

	va_start(args, format);

	while (*format)
	{
		if (*format != '%')
		{
			count += _putchar(*format);
		}
		else
		{
			format++;
			switch (*format)
			{
				case 'c':
					c = (char)va_arg(args, int);
					count += _putchar(c);
					break;
				case 's':
					s = va_arg(args, char *);
					count += _puts(s);
					break;
				case '%':
					count += _putchar('%');
					break;
				default:
					count += _putchar(*format);
					break;
			}
		}
		format++;
	}

	va_end(args);
	return (count);
}

