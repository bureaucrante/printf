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
