#include "main.h"

/**
 * print_number - prints a number send to tis function
 * @args: number of arguments
 * Return: the number of arguments printed
 */

int print_number(va_list args)
{
	int n;
	int div;
	int len;
	unsigned int num;

	n = va_arg(args, int);
	div = 1;
	len = 0;

	if (n < 0)
	{
		len += _putchar('-');
		num = n * -1;
	}
	else
		num = n;
	for (; num / div > 9; )
		div *= 10;
	for (; div != 0; )
	{
		len += _putchar('0' + num / div);
		num %= div;
		div /= 10;
	}
	return (len);
}

/**
 * print_unsigned_number - prints an unsigned number
 * @n: unsigned integer to be printed
 * Return: the number printed
 */

int print_unsigned_number(unsigned int n)
{
	int div;
	int len;
	unsigned int num;

	div = 1;
	len = 0;

	num = n;

	for (; num / div > 9; )
		div *= 10;

	for(; div != 0; )
	{
		len += _putchar('0' + num / div);
		num %= div;
		div /= 10;
	}
	return (len);
}
