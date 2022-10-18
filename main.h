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
int print_unsigned(va_list utype);
int print_per(va_list pertype);
/**
 */

typedef struct format_type
{
	char *cc;
	int(*f)(va_list);
} p_type;

#endif
