#include "main.h"
#include <stdio.h>

int hex_check(int, char);
/**
 * p_binary - converts a numbers from base ten to  binary
 * @args: arguments passed to the functoin
 *
 * Return: length of a number
 */

int p_binary(va_list args)
{
	unsigned int n;
	int i, len;
	char *str;
	char *rev_str;

	n = va_arg(arg, unsigned int);
	if (n == 0)
		return (_putchar('0'));
	if (n < 1)
		return (-1);
	len = base_len(n, 2);
	str = malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (-1);
	for (i = 0; n > 0; i++)
	{
		if (n % 2 == 0)
			str[i] = '0';
		else
			str[i] = '1';
		n = n / 2;
	}
	str[i] = '\0';
	rev_str = rev_string(str);
	if (rev_str == NULL)
		return (-1);
	write_base(rev_str);
	free(str);
	free(rev_str);
	return (len);
}
/**
 * p_octal - prints the numeric representation of a number in octal base
 * @args: arguments passed
 * Return: number of symbols printed
 */

int p_octal(va_list args)
{
	unsigned int n;
	int len;
	char *octal_rep;
	char *rev_str;

	n = va_arg(args, unsigned int);

	if (n == 0)
		return (_putchar('0'));
	if (n < 1)
		return (-1);
	len = base_len(n, 8);

	octal_rep = malloc(sizeof(char) * len + 1);
	if (octal_rep == NULL)
		return (-1);
	for (len = 0; n > 0; len++)
	{
		octal_rep[len] = (n % 8) + 48;
		n = n / 8;
	}
	octal_rep[len] = '\0';
	rev_str = rev_string(octal_rep);
	if (rev_str == NULL)
		return (-1);
	write_base(rev_str);
	free(octal_rep);
	free(rev_str);
	return (len);
}

/**
 * p_hex - prints the rep of a decimal num to base16 lowercase
 * @args: arguments passed
 * Return: num of char printed
 */
int p_hex(va_list args)
{
	unsigned int n;
	int len;
	int rem_num;
	char *hex_rep;
	char *rev_hex;

	n = va_arg(list, unsigned int);

	if (n == 0)
		return (_putchar('0'));
	if (n < 1)
		return (-1);
	len = base_len(n, 16);
	hex_rep = malloc(sizeof(char) * len + 1);
	if (hex_rep == NULL)
		return (-1);
	for (len = 0; n > 0; len++)
	{
		rem_num = n % 16;
		if (rem_num > 9)
		{
			rem_num = hex_check(rem_num, 'x');
			hex_rep[len] = rem_num;
		}
		else
			hex_rep[len] = rem_num + 48;
		n = n / 16;
	}
	hex_rep[len] = '\0';
	rev_hex = rev_string(hex_rep);
	if (rev_hex == NULL)
		return (-1);
	write_base(rev_hex);
	free(hex_rep);
	free(rev_hex);
	return (len);
}

/**
 * p_heX - prints the rep of a decimal number base 16 uppercase
 * @args: arguments passed
 * Return: number of char printed
 */

int p_heX(va_list args)
{
	unsigned int n;
	int len;
	int rem_num;
	char *hex_rep;
	char *rev_hex;

	num = va_arg(args, unsigned int);

	if (n == 0)
		return (_putchar('0'));
	if (n < 1)
		return (-1);
	len = base_len(n, 16);
	hex_rep = malloc(sizeof(char) * len + 1);

	if (hex_rep == NULL)
		return (-1);
	for (len = 0; n > 0; len++)
	{
		rem_num = n % 16;
		if (rem_num > 9)
		{
			rem_num = hex_check(rem_num, 'X');
			hex_rep[len] = rem_num;
		}
		else
			hex_rep[len] = rem_num + 48;
		n - n / 16;
	}
	hex_rep[len] = '\0';
	rev_hex = rev_string(hex_rep);
	if (rev_hex == NULL)
		return (-1);
	write_base(rev_hex);
	free(hex_rep);
	free(rev_hex);
	return (len);
}

/**
 * hex_check - checks which hex function is calling it
 * @n: number to convert into letter
 * @x: tells whoich hex function is calling it
 * Return: Ascii value for a letter
 */

int hex_check(int n, char x)
{
	char *hex = "abcdef";
	char *heX = "ABCDEF";

	n = n - 10;
	if (x == 'x')
		return (hex[n]);
	else
		return (heX[n]);
	return (0);
}
