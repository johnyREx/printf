#include "main.h"
#include <stdarg.h>
#include <stdio.h>
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
	char *str;
	int len = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			switch (*++format)
			{
				case 'c':
					len += _putchar(va_arg(args, int));
					break;
				case 's':
					str = va_arg(args, char*);
					if (!str)
						str = "(null)";
					len += _puts(str);
					break;
				case '%':
					len += _putchar('%');
					break;
				default:
					len += _putchar('%');
					len += _putchar(*format);
					break;
			}
		}
		else
			len += _putchar(*format);
		format++;
	}
	va_end(args);
	return (len);
}
