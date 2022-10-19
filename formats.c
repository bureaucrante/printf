#include "main.h"
#include <stdarg.h>
#include <stdlib.h>

/**
 * print_c - prints a character.
 * @ctype: the va_list argument that corresponds with the function.
 * Return: 1
 */

int print_c(va_list ctype)
{
	char ch = (char)va_arg(ctype, int);

	_putchar(ch);
	return (1);
}

/**
 * print_s - the string will be printed.
 * @stype: the va_list type (string)
 * Return: number of printed characters.
 */

int print_s(va_list stype)
{
	int count = 0;
	char *string = va_arg(stype, char *);

	if (!string)
	{
		string = "(null)";
	}

	while (string[count])
	{
		_putchar(string[count]);
		count++;
	}

	return (count);
}

/**
 * print_per - prints percentage character.
 * @pertype: arguments matching function specifier.
 * Return: 1
 */
int print_per(__attribute__((unused))va_list pertype)
{
	_putchar('%');
	return (1);
}

/**
 * print_d - prints a decimal
 * @dargs: arguments matching function specifier.
 * Return: Number of printed characters.
 */

int print_d(va_list dargs)
{
	int digit, d, count;
	unsigned int num;

	digit  = va_arg(dargs, int);
	d = 1;
	count = 0;

	num = digit;

	if (digit < 0)
	{
		_putchar('-');
		num = digit * -1;
		count++;
	}

	for (; num / d > 9; )
		d *= 10;

	for (; d != 0; )
	{
		_putchar('0' + num / d);
		num %= d;
		d /= 10;
		count++;
	}

	return (count);
}

/**
 * print_unsigned - prints unsigned integer
 * @utype: arguments matching function specifier.
 * Return: number of printed characters.
 */

int print_unsigned(va_list utype)
{
	int d = 1, count = 0;
	unsigned int num;

	num = va_arg(utype, unsigned int);

	if (num < 1)
	{
		if (num != 0)
			return (-1);
	}

	for (; num / d > 9; )
		d *= 10;

	for (; d != 0; )
	{
		_putchar('0' + num / d);
		num %= d;
		d /= 10;
		count++;
	}

	return (count);
}

