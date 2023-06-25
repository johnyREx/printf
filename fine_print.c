#include "main.h"
#include <stdarg.h>
#include <unistd.h>

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
	int num, is_negative, divisor, temp, digit, digits, i;
	char c;

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
				digits = 0;
				temp = num;
				while (temp != 0)
				{
					temp /= 10;
					digits++;
				}
				if (digits == 0)
				{
					write(1, "0", 1);
					printed_num++;
				}
				else
				{
					divisor = 1;
					for(i = 1; 1 < digits; i++)
						divisor *= 10;
					while (divisor != 0)
					{
						digit = num / divisor;
						c = '0' + digit;
						write(1, &c, 1);
						printed_num++;
						num %= divisor;
						divisor /= 10;
					}
				}
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
