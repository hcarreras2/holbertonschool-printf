#include "main.h"

/**
* print_base - prints an unsigned integer in a given base
* @num: The unsigned integer to print
* @base: The base to print the number in
* @digits: The characters representing the digits of the base
*
* Return: The number of characters printed
*/
int print_base(unsigned long int num, int base, const char *digits)
{
	int count = 0;

	char buffer[50];

	int i = 49;

	buffer[i] = '\0';
	i--;

	if (num == 0)
	{
		_putchar('0');
		return (1);
	}

	while (num != 0)
	{
		buffer[i] = digits[num % base];
		num /= base;
		i--;
	}

	while (buffer[++i] != '\0')
	{
		_putchar(buffer[i]);
		count++;
	}

	return (count);
}

/**
* print_number - prints an integer
* @num: The integer to print
*
* Return: The number of characters printed
*/
int print_number(unsigned long int num)
{
	int count = 0;

	char buffer[20];

	int i = 19;

	buffer[i] = '\0';
	i--;

	if (num == 0)
	{
		_putchar('0');
		return (1);
	}

	while (num != 0)
	{
		buffer[i] = (num % 10) + '0';
		num /= 10;
		i--;
	}

	while (buffer[++i] != '\0')
	{
		_putchar(buffer[i]);
		count++;
	}

	return (count);
}
