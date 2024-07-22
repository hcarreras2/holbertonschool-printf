#include "main.h"

/**
* write_char - Prints a single character.
* @list: The arguments list containing the character.
*
* Return: The number of characters printed.
*/
int write_char(va_list list)
{
	char c = va_arg(list, int);

	return (_putchar(c));
}

/**
* write_string - Prints a string.
* @list: The arguments list containing the string.
*
* Return: The number of characters printed.
*/
int write_string(va_list list)
{
	char *s = va_arg(list, char *);

	int count;

	if (s == NULL)
		s = "(null)";

	for (count = 0; s[count] != '\0'; count++)
		_putchar(s[count]);

	return (count);
}

/**
* write_number - Prints an integer.
* @list: The arguments list containing the integer.
*
* Return: The number of characters printed.
*/
int write_number(va_list list)
{
	int n = va_arg(list, int);

	unsigned int num, temp, i;

	int digits = 0;

	if (n < 0)
	{
		_putchar('-');
		num = -n;
		digits++;
	}
	else
		num = n;

	temp = num;
	i = 1;
	while (temp / 10 > 0)
	{
		temp /= 10;
		i *= 10;
	}

	while (i > 0)
	{
		_putchar((num / i) % 10 + '0');
		i /= 10;
		digits++;
	}

	return (digits);
}

/**
* print_mod - Prints a percent sign.
* @list: The arguments list (unused).
*
* Return: The number of characters printed.
*/
int print_mod(va_list list)
{
	(void)list;
	return (write(1, "%", 1));
}
