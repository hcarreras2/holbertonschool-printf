#include "main.h"

/**
* print_int - prints an integer
* @args: The arguments list containing the integer to print
*
* Return: The number of characters printed
*/
int print_int(va_list args)
{
	int num = va_arg(args, int);

	int count = 0;

	if (num < 0)
	{
		_putchar('-');
		num = -num;
		count++;
	}
	count += print_number(num);
	return (count);
}

/**
* print_unsigned - prints an unsigned integer
* @args: The arguments list containing the unsigned integer to print
*
* Return: The number of characters printed
*/
int print_unsigned(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);

	return (print_number(num));
}

/**
* print_octal - prints an unsigned integer in octal
* @args: The arguments list containing the unsigned integer to print
*
* Return: The number of characters printed
*/
int print_octal(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);

	return (print_base(num, 8, "01234567"));
}

/**
* print_hex - prints an unsigned integer in hexadecimal
* @args: The arguments list containing the unsigned integer to print
* @uppercase: 1 if the hexadecimal letters should be uppercase, 0 otherwise
*
* Return: The number of characters printed
*/
int print_hex(va_list args, int uppercase)
{
	unsigned int num = va_arg(args, unsigned int);

	if (uppercase)
		return (print_base(num, 16, "0123456789ABCDEF"));
	else
		return (print_base(num, 16, "0123456789abcdef"));
}

/**
* print_pointer - prints a pointer address
* @args: The arguments list containing the pointer to print
*
* Return: The number of characters printed
*/
int print_pointer(va_list args)
{
	void *ptr = va_arg(args, void *);

	unsigned long int addr = (unsigned long int)ptr;

	_putchar('0');
	_putchar('x');
	return (2 + print_base(addr, 16, "0123456789abcdef"));
}
