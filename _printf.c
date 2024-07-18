#include "main.h"
#include <unistd.h>

/**
* _printf - produces output according to a format
* @format: format string containing the characters and the specifiers
* Description: this function will call the corresponding print function
* to handle the specified format
* _putchar - Putchar
* Return: length of the formatted output string
*/
int _printf(const char *format, ...)
{
	 int i = 0; 
	 int printed_chars = 0;

	va_list args;

	__builtin_va_start(args, format);

	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
				printed_chars += print_char(args);
			else if (format[i] == 's')
				printed_chars += print_string(args);
			else if (format[i] == '%')
				printed_chars += print_percent(args);
			else
			{
				_putchar('%');
				_putchar(format[i]);
				printed_chars += 2;
			}
		}
		else
		{
			_putchar(format[i]);
			printed_chars++;
		}
		i++;
	}
	va_end(args);
	return (printed_chars);
}

/**
* _putchar - writes the character c to stdout
* @c: The character to print
*
* Return: On success 1.
* On error, -1 is returned, and errno is set appropriately.
*/
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
* print_char - prints a character
* @args: The arguments list containing the character to print
*
* Return: The number of characters printed
*/
int print_char(va_list args)
{
	char c = va_arg(args, int);

	return (_putchar(c));
}

/**
* print_string - prints a string
* @args: The arguments list containing the string to print
*
* Return: The number of characters printed
*/
int print_string(va_list args)
{
	int i;

	char *str = va_arg(args, char *);

	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
	return (i);
}

/**
* print_percent - prints a percent sign
* @args: The arguments list (unused)
*
* Return: The number of characters printed
*/
int print_percent(va_list args __attribute__((unused)))
{
	return (_putchar('%'));
}
