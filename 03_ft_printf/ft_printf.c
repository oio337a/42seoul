/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmipa <yongmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 16:15:51 by yongmipa          #+#    #+#             */
/*   Updated: 2022/08/01 18:43:58 by yongmipa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_hex(unsigned long long num, char *hex, int count)
{
	if (num >= 16)
	{
		count = printf_hex(num / 16, hex, count + 1);
		num %= 16;
	}
	ft_putchar(hex[num]);
	return (count);
}

int	form_p(void *addr, char *hex)
{
	ft_putstr("0x");
	return (printf_hex((long long)addr, hex, 1) + 2);
}

int	form_x(unsigned int num, char form)
{
	if (form == 'x')
		return (printf_hex(num, "0123456789abcdef", 1));
	else
		return (printf_hex(num, "0123456789ABCDEF", 1));
}

int	parsing(char form, va_list ap)
{
	int	count;

	if (form == 'c')
		count = ft_putchar(va_arg(ap, int));
	else if (form == 's')
		count = ft_putstr(va_arg(ap, char *));
	else if (form == 'p')
		count = form_p(va_arg(ap, void *), "0123456789abcdef");
	else if (form == 'd' || form == 'i')
		count = ft_putnbr(va_arg(ap, int));
	else if (form == 'u')
		count = ft_unsignednbr(va_arg(ap, int));
	else if (form == 'x' || form == 'X')
		count = form_x(va_arg(ap, unsigned int), form);
	else if (form == '%')
		count = ft_putchar('%');
	else
		count = 0;
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		idx;
	int		count;
	int		temp;

	idx = -1;
	va_start(ap, str);
	count = 0;
	while (str[++idx])
	{
		if (str[idx] == '%')
		{
			temp = parsing(str[++idx], ap);
			if (temp < 0)
				return (-1);
			count += temp;
		}
		else
		{
			ft_putchar(str[idx]);
			++count;
		}
	}
	va_end(ap);
	return (count);
}
