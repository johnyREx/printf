#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

/**
 * _printf - prints output according to a format
 * @format: format string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
    int count = 0;
    va_list args;

    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            if (*format == 'c')
                count += print_char(va_arg(args, int));
            else if (*format == 's')
                count += print_string(va_arg(args, char *));
            else if (*format == '%')
                count += print_percent();
            else
                return (-1);
        }
        else
        {
            count += _putchar(*format);
        }
        format++;
    }

    va_end(args);

    return (count);
}
