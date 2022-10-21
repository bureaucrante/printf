#include "main.h"
#include <stdarg.h>
#include <stdlib.h>

/**
 * hex_sym - converst non ascii characters to uppercase hexadecimal
 * @c: the charcter to tbe converted.
 * Return: number of printed characters (Always 2)
 */
static int hex_sym(char c)
{
	int count;
	char range = 'A' - ':';
	char a[2];

	a[0] = c / 16;
	a[1] = c % 16;

	for (count = 0; count < 2; count++)
	{
		if (a[count] >= 10)
			_putchar('0' + range + a[count]);
		else
			_putchar('0' + a[count]);
	}
	return (count);
}
/**
 * print_S - prints the hexadecimal symbols of non ASCII characters
 * @S: function matching argument.
 * Return: number of printed character.
 **/

int print_S(va_list S)
{
	unsigned int i;
	int count = 0;
	char *str = va_arg(S, char *);

	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i]; i++)
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			_putchar('\\');
			_putchar('x');
			count += 2;
			count += hex_sym(str[i]);
		}
		else
		{
			_putchar(str[i]);
			count++;
		}
	}
	return (count);
}

/**
 * _exp - evaluates the exponent of a number
 * @base: starting value
 * @exponent: exponent of number
 * Return: result
 */
static unsigned long _exp(unsigned int base, unsigned int exponent)
{
	unsigned int i;
	unsigned long ans = base;

	for (i = 1; i < exponent; i++)
	{
		ans *= base;
	}
	return (ans);
}

/**
 * print_p - prints the value of a pointer
 * @ptype: matching argument.
 * Return: number of printed cahracters.
 */

int print_p(va_list ptype)
{
	int count = 0;
	unsigned int a[16];
	unsigned int i, sum;
	unsigned long n, m;
	char *str = "(nil)";

	n = va_arg(ptype, unsigned long);
	if (n == 0)
	{
		for (i = 0; str[i]; i++)
		{
			_putchar(str[i]);
			count++;
		}
		return (count);
	}
	_putchar('0');
	_putchar('x');
	count = 2;
	m = _exp(16, 15); /* 16 ^ 15 */
	a[0] = n / m;
	for (i = 1; i < 16; i++)
	{
		m /= 16;
		a[i] = (n / m) % 16;
	}
	for (i = 0, sum = 0; i < 16; i++)
	{
		sum += a[i];
		if (sum || i == 15)
		{
			if (a[i] < 10)
				_putchar('0' + a[i]);
			else
				_putchar('0' + ('a' - ':') + a[i]);
			count++;
		}
	}
	return (count);
}
