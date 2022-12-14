#include "main.h"
#include <stdlib.h>

/**
 * _print_form - links character to proper function.
 * @format: pointer to character to be tested.
 * Return: Matched function.
 */

int (*_print_form(const char *format))(va_list)
{
	int i = 0;
	p_type p[] = {
		{"c", print_c},
		{"s", print_s},
		{"d", print_d},
		{"i", print_d},
		{"b", print_b},
		{"u", print_unsigned},
		{"o", print_oct},
		{"x", print_x},
		{"X", print_X},
		{"S", print_S},
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
