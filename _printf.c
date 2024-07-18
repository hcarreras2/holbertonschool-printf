#include "main.h"
/**
 * _printf - a typical printf
 * @format: is a character string
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{

	int i = 0, len = 0, ret = 0;
	va_list arg;

	if (format == NULL || (strlen(format) == 1 && format[0] == '%'))
	{
		return (-1);
	}
	va_start(arg, format);
	while (format && format[i])
	{
		if (format[i] != '%')
		{
			putchar(format[i]);
			len++;
		}
		if (format[i] == '%' && format[i + 1] != 'K' && format[i + 1] != '!')
		{
			ret = get_func(*(format + (i + 1)), arg);
			if (ret != 0)
				len += ret;
			i += 2;
			continue;
		}
		else if ((format[i] == '%' && format[i + 1] == 'K') ||
		 (format[i] == '%' && format[i + 1] == '!'))
		{
			putchar(format[i]);
			len++;
		}
		i++;
	}
	va_end(arg);
	return (len);
}
