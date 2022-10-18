#include "main.h"
#include <stdlib.h>

/**
 */

int (*_print_form(const char *format))(va_list)
{
	int i = 0;
	p_type p[] = {
		{"c", print_c},
		{"s", print_s},
		{"d", print_d},
		{"i", print_d},
		{"u", print_unsigned},
		{"%", print_per},
		{NULL, NULL}
	};

	while (p[i].cc)
	{
		if (*p[i].cc == *format)
			break;
		i++;
	}
	return (p[i].f);
}

int _printf(const char *format, ...)
{
	unsigned int i = 0, count = 0;
	va_list args;
	int(*f)(va_list);

	if (!format)
		return (-1);

	va_start(args, format);

	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;

			/*while (format[i] == ' ')
			{
				i++;
			}*/

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
				{
					_putchar(format[i]);
				}
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
