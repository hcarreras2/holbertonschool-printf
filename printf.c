#include "main.h"

/**
* _printf - Produces output according to a format.
* @format: The format string containing text and format specifiers.
*
* Return: The number of characters printed (excluding the null byte).
*/
int _printf(const char *format, ...)
{
	int printed_chars;

	va_list list;

	if (format == NULL)
		return (-1);

	va_start(list, format);
	printed_chars = get_op(format, list);
	va_end(list);

	return (printed_chars);
}

/**
* get_op - Gets the format and calls corresponding function.
* @format: The format string containing text and format specifiers.
* @list: List of arguments.
*
* Return: The number of characters printed.
*/
int get_op(const char *format, va_list list)
{
	int i = 0, j, printed_chars = 0;

	ck func_type[] = {
		{"c", write_char}, {"s", write_string}, {"\%%", print_mod},
		{"d", write_number}, {"i", write_number}, {NULL, NULL}
	};

	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			for (j = 0; func_type[j].input != NULL; j++)
			{
				if (format[i] == *func_type[j].input)
				{
					printed_chars += func_type[j].f(list);
					break;
				}
			}
			if (func_type[j].input == NULL && format[i] != '\0')
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
	return (printed_chars);
}
