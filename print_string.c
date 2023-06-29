#include "main.h"

/**
 * p_reversed - Calls a function to reverse and print a string
 * @args: Arguments
 * Return: The amount of characters printed
 */

int p_reversed(va_list args)
{
	int len;
	char *str;
	char *ptr;

	str = va_arg(args, char *);
	if (str == NULL)
		return (-1);
	ptr = rev_string(str);
	if (ptr == NULL)
		return (-1);
	for (len = 0; ptr[len] != '\0'; len++)
		_putchar(ptr[len]);
	free(ptr);
	return (len);
}

/**
 * rot13 - converts string to rot13
 * @args: string to convert
 * Return: string converted
 */

int rot13(va_list args)
{
	int i;
	int x;
	char *str;
	char s[] = "ABCDEFGHIKLMNOPQRSTUVWXYZabcdefghijklmnopqwrstuvxyz";
	char u[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(args, char *);
	if (str == NULL)
		return (-1);
	for (i = 0; str[i] != '\0'; i++)
	{
		for (x = 0; x <= 52; x++)
		{
			if (str[i] == s[x])
			{
				_putchar(u[x]);
				break;
			}
		}
		if (x == 53)
			_putchar(str[i]);
	}
	return (i);
}
