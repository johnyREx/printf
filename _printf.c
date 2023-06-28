#include "main.h"
#include <stdarg.h>
#include <stdint.h>

/**
 * _printf - a function that produces output according to a format.
 * @format: a character string.
 * @...: An ellipsis to indicate continuation of  arguments.
 *
 * Return: Number of characters printed(excluding the null terminator).
 */

int _printf(const char *format, ...)
{
	int printed_chars;

	conver_t funct_list[] = {
		{"c", p_char},
		{"s", p_string},
		{"%", p_percent},
		{"d", p_integer},
		{"i", p_integer},
		{"b", p_binary},
		{"r", p_reversed},
		{"R", rot13},
		{"u", unsigned_integer},
		{"o", p_octal},
		{"x", p_hex},
		{"X", p_hex},
		{NULL, NULL}
	};

	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	printed_chars = parser(format, funct_list, args);
	va_end(args);

	return (printed_chars);
}
