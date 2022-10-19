#include "main.h"
#include <stdlib.h>

/**
 * _printf - prints output according to format
 * @format: pointer to arguments.
 * Return: number of printed characters.
 */

int _printf(const char *format, ...)
{
	unsigned int i = 0, count = 0;
	va_list args;
	int (*f)(va_list);

	va_start(args, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);

	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;

			f = _print_form(&format[i]);
			if (f)
			{
				count += f(args);
				i += 1;
				continue;
			}
			i++;

			if (format[i] != '\0')
			{
				if (format[i] == ' ')
					_putchar(format[i]);
			}
		}

		else
		{
			_putchar(format[i]);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
