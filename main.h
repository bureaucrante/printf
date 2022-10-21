#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
int _printf(const char *format, ...);
int _putchar(char c);
int print_c(va_list ctype);
int print_s(va_list stype);
int print_d(va_list dtype);
int print_b(va_list bargs);
int print_unsigned(va_list utype);
int print_per(va_list pertype);
int print_oct(va_list octype);
int print_x(va_list xargs);
int print_X(va_list Xargs);
int print_S(va_list S);
int print_p(va_list ptype);
int (*_print_form(const char *format))(va_list);

/**
 * struct format_type - holds conv. char and matching fuction.
 * @cc: pointer to conv. char.
 * @f: corresponding called function.
 */
typedef struct format_type
{
	char *cc;
	int (*f)(va_list);
} p_type;

#endif
