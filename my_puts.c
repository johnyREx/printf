#include "main.h"

/**
 * _puts - Custom puts imlementation
 * @str: string to print
 *
 * Return: Number of char printed(excluding the null terminator)
 */

int _puts(char *str)
{
	int i = 0;

	if (str)
	{
		while (str[i])
		{
			_putchar(str[i]);
			i++;
		}
	}
	return (i);
}
