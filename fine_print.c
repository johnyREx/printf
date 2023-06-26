#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * _printf - function that produces output accoding to format
 * @format: the char string
 * @...: an epilipsis to indicate continuation of arguments
 * Return: number of ints printed
 */

int _printf(const char *format, ...)
{
	va_list args;
	int printed_num = 0;
	int num, is_negative, temp, num_digits, i;
	char *buffer;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == 'd' || *format == 'i')
			{
				num = va_arg(args, int);
				is_negative = 0;
				if (num < 0)
				{
					write(1, "-", 1);
					printed_num++;
					num = -num;
					is_negative = 1;
				}
				num_digits = 1;
				temp = num;
				while (temp /= 10)
					num_digits++;

				buffer = malloc(sizeof(char) * num_digits + 1);
				for (i = num_digits - 1; i >= 0; i--)
				{
					buffer[i] = '0' + (num % 10);
					num /= 10;
				}
				buffer[num_digits] = '\0';
				write(1, buffer, num_digits);
				printed_num += num_digits;
				free(buffer);
				if (is_negative)
					printed_num++;
			}
			else
			{
				write(1, "%", 1);
				write(1, format, 1);
				printed_num += 2;
			}
		}
		else
		{
			write(1, format, 1);
			printed_num++;
		}
		format++;
	}
	va_end(args);
	return (printed_num);
}
