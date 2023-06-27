#include "main.h"

/**
 * p_integer - ptints an in on stdout
 * @args: hundles a variadic function
 *
 * Return: the integer printed
 */

int p_integer(va_list args)
{
        int n;

        n = print_number(args);
        return (n);
}
