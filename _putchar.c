#include "main.h"
#include <unistd.h>

/**
 * _putchar - prints char c to stdout
 * @c: char to print
 *
 * Return: on success
 * on error, -1 is returned and errno is set appropriatly
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}