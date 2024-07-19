#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int _printf(const char *format, ...);

typedef struct check
{
	char *input;

	int (*f)(va_list);
} ck;

int write_char(va_list list);
int write_string(va_list list);
int write_number(va_list list);
int print_mod(va_list list);
int get_op(const char *format, va_list list);

int _putchar(char c);

#endif /* MAIN_H */
