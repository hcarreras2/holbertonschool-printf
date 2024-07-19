#include "main.h"

/**
* handle_format - handles the format specifiers
* @format: format string containing the characters and the specifiers
* @args: list of arguments
*
* Return: number of characters printed
*/
int handle_format(const char *format, va_list args)
{
	int i = 0;

	int printed_chars = 0;

	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			printed_chars += handle_specifier(format, &i, args);
		}
		else
		{
			_putchar(format[i]);
			printed_chars++;
		}
		i++;
	}
	return (printed_chars);
}

/**
* handle_specifier - handles a single format specifier
* @format: format string containing the characters and the specifiers
* @i: pointer to the current position in the format string
* @args: list of arguments
*
* Return: number of characters printed
*/
int handle_specifier(const char *format, int *i, va_list args)
{
	int printed_chars = 0;

	switch (format[*i])
	{
		case 'c':
			printed_chars += print_char(args);
			break;
		case 's':
			printed_chars += print_string(args);
			break;
		case 'd':
		case 'i':
			printed_chars += print_int(args);
			break;
		case 'u':
			printed_chars += print_unsigned(args);
			break;
		case 'o':
			printed_chars += print_octal(args);
			break;
		case 'x':
			printed_chars += print_hex(args, 0);
			break;
		case 'X':
			printed_chars += print_hex(args, 1);
			break;
		case 'p':
			printed_chars += print_pointer(args);
			break;
		case '%':
			printed_chars += print_percent(args);
			break;
		default:
			printed_chars += print_unknown_specifier(format[*i]);
			break;
	}

	return (printed_chars);
}

/**
* print_unknown_specifier - prints unknown format specifiers
* @specifier: the unknown specifier
*
* Return: the number of characters printed
*/
int print_unknown_specifier(char specifier)
{
	_putchar('%');
	_putchar(specifier);
	return (2);
}
