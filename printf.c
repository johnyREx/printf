#include "main.h"
#include <unistd.h>
#include <stdlib.h>

/**
 * _putchar - Writes a character to stdout
 * @c: The character to be written
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _printf - prints output according to a format
 * @format: The format string
 *
 * Return: the number of characters printed (excluding the null byte)
 */

int parser(const char *format, va_list args)
{
	int i, j, count = 0;
	conver_t funct_list[] = {
		{"c", p_char},
		{"s", p_string},
		{"%", p_percent};
		(NULL, NULL}
	};

	i = 0;
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			j = 0;
			while (funct_list[j].sym != NULL)
			{
				if (format[i + 1] == funct_list[j].sym[0])
				{

					count += funct_list[j].f(args);
					i++;
					break;
				}
				j++;
			}
			if (funct_list[j].sym == NULL)
			{
				_putchar(format[i]);
				count++;
			}
		}
		else
		{
			_putchar(format[i]);
			count++;
		}
		i++;
	}

	return (count);
}

/**
 * -_char - prints a character
 *  @args: the Va_list of arguments
 *
 *  Return: The number of characters printed
 */

int p_char(va_list args)
{
	char c = va_arg(args, int);
	_putchar(c);

	return (1);
}

/**
 * p_string - Prints a string
 * @args: The va_list Arguments
 *
 * Return: The number of characters printed
 */

int p_string(va_list args)
{
	char *str = va_arg(args, char *);
	int len = 0;

	if (str == NULL)
		str = "(null)";

	while (str[len])
	{
		_putchar(str[len]);
		len++;
	}

	return (len);
}

/**
 * p_percent - prints a percent character
 * @args: The va_list or arguments
 *
 * Return: The number of characters printed
 */

int p_percent(va_list args)
{
	(void)args;
	_putchar('%');
	return (1);
}
