#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

/* Function prototypes */
int _printf(const char *format, ...);

int _putchar(char c);

int print_char(va_list args);
int print_string(va_list args);
int print_int(va_list args);
int print_unsigned(va_list args);
int print_percent(va_list args);
int print_octal(va_list args);
int print_hexadecimal(va_list args);
int print_unknown_specifier(char specifier);

int handle_format(const char *format, va_list args);

int handle_specifier(const char *format, int *i, va_list args);

#endif /* MAIN_H */
