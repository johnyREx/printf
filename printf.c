#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

/**
 * _printf - prints the output according to a format string
 * @format: character string
 *
 * Return: number of characters printed (except bull byte)
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
					len += putchar(va_arg(args, int));
					break;
				case 's':
					str = va_arg(args, char*);
					if (!str)
						str = "(null)";
					len += puts(str);
					break;
				case '%':
					len += putchar('%');
					break;
				default:
					len += putchar('%');
					len += putchar(*format);
					break;
			}
		}
		else
			len += putchar(*format);
		format++;
	}
	va_end(args);
	return (len);
}
