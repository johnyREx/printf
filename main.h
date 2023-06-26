#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _putchar(char c);
int _printf(const char *format, ...);
int print_char(va_list arg);
int print_string(va_list arg);
int print_percent(va_list arg);
int print_integer(va_list arg);
int print_binary(va_list arg);
int print_unsigned(va_list arg);
int print_octal(va_list arg);
int print_hex(va_list arg);
int print_hex_upper(va_list arg);

#endif
