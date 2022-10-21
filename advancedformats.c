#include "main.h"
#include <stdarg.h>
#include <stdlib.h>

/**
 * print_b - prints a number in base 2
 * @bargs: binary type argument.
 * Return: Number of characters printed.
 */

int print_b(va_list bargs)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	n = va_arg(bargs, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			_putchar('0' + a[i]);
			count++;
		}
	}
	return (count);
}

/**
 * print_oct - prints octal number
 * @octype: octal argument to be printed.
 * Return: number of printed chars.
 */

int print_oct(va_list octype)
{
	unsigned int rem[11];
	unsigned int i, m, n, sum;
	int count;

	n = va_arg(octype, unsigned int);
	m = 1073741824; /* (8 ^ 10) */
	rem[0] = n / m;
	for (i = 1; i < 11; i++)
	{
		m /= 8;
		rem[i] = (n / m) % 8;
	}
	for (i = 0, sum = 0, count = 0; i < 11; i++)
	{
		sum += rem[i];
		if (sum || i == 10)
		{
			_putchar('0' + rem[i]);
			count++;
		}
	}
	return (count);
}

/**
 * print_hex - prints a hexadecimal number
 * @n: number to be printed.
 * @c: print case determiner.
 * Return: number of printed chars.
 */

int print_hex(unsigned int n, unsigned int c)
{
	unsigned int a[8];
	unsigned int i, m, sum;
	char diff;
	int count;

	m = 268435456; /* (16 ^ 7) */
	if (c)
		diff = 'A' - ':';
	else
		diff = 'a' - ':';
	a[0] = n / m;
	for (i = 1; i < 8; i++)
	{
		m /= 16;
		a[i] = (n / m) % 16;
	}
	for (i = 0, sum = 0, count = 0; i < 8; i++)
	{
		sum += a[i];
		if (sum || i == 7)
		{
			if (a[i] < 10)
				_putchar('0' + a[i]);
			else
				_putchar('0' + diff + a[i]);
			count++;
		}
	}
	return (count);
}

/**
 * print_x - prints lowercase hexadecimals.
 * @x: hexadecimal argument to be printed.
 * Return: main printer function.
 */
int print_x(va_list x)
{
	return (print_hex(va_arg(x, unsigned int), 0));
}

/**
 * print_X - prints uppercase hexadecimals.
 * @X: hex argument to be printed.
 * Return: main printer function.
 */
int print_X(va_list X)
{
	return (print_hex(va_arg(X, unsigned int), 1));
}
