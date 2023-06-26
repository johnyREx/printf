#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

/**
 * struct specifier - struct for formst specifiers
 *
 * @spec: the format specifier
 * @f: The function associated with the format specifier
 */
typedef struct specifier
{
	char *spec;
	int (*f)(va_list);
} spec_t;

int _printf(const char *format, ...);
int print_c(va_list arg);
int print_s(va_list arg);
int print_d(va_list arg);
int print_i(va_list arg);
int print_percent(va_list arg);
int print_b(va_list arg);
int print_u(va_list arg);
int print_o(va_list arg);
int print_x(va_list arg);
int print_X(va_list arg);
int _putchar(char c);

#endif
