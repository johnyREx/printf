#include "main.h"
#include <stdio.h>

/**
 * rev_string - revers a string
 * @s: String to reverse
 * Return: A pointer to a char
 */

char *rev_string(char *s)
{
	int len;
	int head;
	char tmp;
	char *dest;

	for (len = 0; s[len] != '\0'; len++)
	{
		dest = malloc(sizeof(char) * len + 1);
		if (dest == NULL)
			return (NULL);

		_memcpy(dest, s, len);
		for (head = 0; head < len; head++, len--)
		{
			tmp = dest[len - 1];
			dest[len - 1] = dest[head];
			dest[head] = tmp;
		}
	}
	return (dest);
}

/**
 * write_base - sends characters to be written on stdout
 * @str: string to parse
 */

void write_base(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; 1++)
		_putchar(str[i]);
}

/**
 * base_len - calculates the length for an octal number
 * @n: The number for which the length is being calculated
 * @base: base to calculate
 * Return: length of number
 */

unsigned int base_len(unsigned int n, int base)
{
	unsigned int i;

	for (i = 0; n > 0; i++)
	{
		n = n / base;
	}
	return (i);
}

/**
 * _memcpy - copy memory area
 * @dest: Destinastion for copying
 * @src: string to copy from
 * @n: bytes to copy
 * Return: copied string.
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

