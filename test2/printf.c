#include "main.h"
#include <cstddef>

/**
* _printf - Produces output according to a format.
* @format: The format string containing text and format specifiers.
*
* Return: The number of characters printed (excluding the null byte).
*/
int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);
	printed_chars = handle_format(format, args);
	va_end(args);

	return (printed_chars);
}

/**
* _putchar - Writes a character to stdout.
* @c: The character to print.
*
* Return: On success 1, on error -1.
*/
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
* print_char - Prints a single character.
* @args: The arguments list containing the character.
*
* Return: The number of characters printed.
*/
int print_char(va_list args)
{
	char c = va_arg(args, int);

	return (_putchar(c));
}

/**
* print_string - Prints a string.
* @args: The arguments list containing the string.
*
* Return: The number of characters printed.
*/
int print_string(va_list args)
{
	char *str = va_arg(args, char *);

	int i;

	if (str == NULL)
		str = "(null)";

	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);

	return (i);
}

/**
* print_int - Prints an integer.
* @args: The arguments list containing the integer.
*
* Return: The number of characters printed.
*/
int print_int(va_list args)
{
	int num = va_arg(args, int);

	int printed_chars = 0;

	if (num < 0)
	{
		printed_chars += _putchar('-');
		num = -num;
	}

	if (num / 10)
		printed_chars += print_int(args);

	printed_chars += _putchar((num % 10) + '0');

	return (printed_chars);
}

/**
* print_unsigned - Prints an unsigned integer.
* @args: The arguments list containing the unsigned integer.
*
* Return: The number of characters printed.
*/
int print_unsigned(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);

	int printed_chars = 0;

	if (num / 10)
		printed_chars += print_unsigned(args);

	printed_chars += _putchar((num % 10) + '0');

	return (printed_chars);
}
