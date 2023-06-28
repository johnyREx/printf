#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * struct convert - struct for format converters.
 * @sym: The format converter.
 * @f: The function associated with a format converter.
 */

struct convert
{
	char *sym;
	int (*f)(va_list);
};
typedef struct convert conver_t;

int _putchar(char c);
int _printf(const char *format, ...);
void _vprintf(const char *format, va_list args);
int parser(const char *format, conver_t funct_list[], va_list args);
int p_char(va_list args);
int p_string(va_list args);
int p_percent(va_list args);
int unsigned_number(va_list args);
int print_number(va_list args);
int p_binary(va_list args);
int p_reversed(va_list args);
int rot13(va_list args);
int print_unsigned_number(unsigned int n);
int print_integer(va_list args);
int p_octal(va_list args);
int p_hex(va_list args);
int p_heX(va_list args);
unsigned int base_len(unsigned int, int);
char *rev_string(char *);
void write_base(char *str);
char *_memcpy(char *dest, char *src, unsigned int n);

#endif
