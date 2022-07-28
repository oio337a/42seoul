#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
	va_list ap;
	int print_len;

	va_start(ap, format);
	print_len = parse_format(ap, format);
	va_end(ap);
	return (print_len);
}
