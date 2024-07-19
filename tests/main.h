#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _printf(const char *format, ...);
int _putchar(char c);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int print_int(va_list args);
int print_unsigned(va_list args);
int print_octal(va_list args);
int print_hex(va_list args, int uppercase);
int print_pointer(va_list args);
int print_base(unsigned long int num, int base, const char *digits);
int print_number(unsigned long int num);
int handle_format(const char *format, va_list args);
int handle_specifier(const char *format, int *i, va_list args);
int print_unknown_specifier(char specifier);

#endif /* MAIN_H */
