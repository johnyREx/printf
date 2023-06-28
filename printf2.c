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
 * _printf - Prints output according to a format
 * @format: The format string
 *
 * Return: The number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
    int printed_chars;
    va_list args;
    conver_t funct_list[] = {
        {"c", p_char},
        {"s", p_string},
        {"%", p_percent},
        {NULL, NULL}
    };

    if (format == NULL)
        return (-1);

    va_start(args, format);
    printed_chars = parser(format, funct_list, args);
    va_end(args);

    return (printed_chars);
}

/**
 * parser - Parses the format string and calls the appropriate functions
 * @format: The format string
 * @funct_list: The list of conversion specifiers and their associated functions
 * @args: The va_list of arguments
 *
 * Return: The number of characters printed (excluding the null byte)
 */
int parser(const char *format, conver_t funct_list[], va_list args)
{
    int i, j, count = 0;

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
 * p_char - Prints a character
 * @args: The va_list of arguments
 *
 * Return: The number of characters printed
 */
int p_char(va_list args)
{
    char c = va_arg(args, int);
    _putchar(c);
    return (1);
}

/**
 * p_string - Prints a string
 * @args: The va_list of arguments
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
 * p_percent - Prints a percent character
 * @args: The va_list of arguments
 *
 * Return: The number
 */
