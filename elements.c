#include "main.h"

/**
 * print_number - takes a variable number of aruments using the va_list
 * @args: handle functions with a varible number of arguments
 *
 * Return: length of string
 */

int print_number(va_list args)
{
	int n;
	int check;
	int len;
	unsigned int num;

	n = va_arg(args, int);
	check = 1;
	len = 0;

	if (n < 0)
	{
		len += _putchar('-');
		num = n * -1;
	}
	else
		num = n;
	for (; num / check > 9;)
		check *= 10;
	for (; check != 0;)
	{
		len += _putchar('0' + num / check);
		num %= check;
		check /= 10;
	}
	return (len);
}

/**
 * print_unsigned_number - function that prints unsigned integer
 * @n: the int to print
 *
 * Return: 0 on success
 */
int print_unsigned_number(unsigned int n)
{
	int check;
	int len;
	unsigned int num;

	check = 1;
	len = 0;
	num = n;

	for (; num / check > 9;)
		check *= 10;

	for (; check != 0;)
	{
		len += _putchar('0' + num / check);
		num %= check;
		check /= 10;
	}
	return (len);
}

/**
 * p_char - prints a char on stdout
 * @args: handles function that takes a variable argument
 *
 * Return: 1 on success and -1 on error, and errno is se appropriately
 */
int p_char(va_list args)
{
	char value;

	value = va_arg(args, int);
	_putchar(value);
	return (1);
}
/**
 * p_string - prints a string
 * @args: hundles variadic function
 *
 * Return: a string
 */

int p_string(va_list args)
{
	int i;
	const char *s;

	s = va_arg(args, const char *);
	if (s == NULL)
		s = "(null)";
	for (i = 0; s[i] != '\0'; i++)
		_putchar(s[i]);
	return (i);
}

/**
 * p_percent - prints the modulus sign on stdout
 * @args: hundles a variadic function
 * Return: i on success
 */

int p_percent(__attribute__((unused))va_list args)
{
	_putchar('%');
	return (1);
}
