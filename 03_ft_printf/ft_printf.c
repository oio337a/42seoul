/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmipa <yongmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 16:15:51 by yongmipa          #+#    #+#             */
/*   Updated: 2022/07/31 17:04:01 by yongmipa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parsing(char form, va_list ap)
{
	int	count;

	if (form == 'c')
		count = ft_putchar(va_arg(ap, int));
	else if (form == 's')
		count = ft_putstr(va_arg(ap, char *));
	else if (form == 'p')
		count = pprocessor(va_arg(ap, void *), "0123456789abcdef");
	else if (form == 'd' || form == 'i')
		count = ft_putnbr(va_arg(ap, int));
	else if (form == 'u')
		count = ft_putunsignednbr(va_arg(ap, int));
	else if (form == 'x' || form == 'X')
		count = xprocessor(va_arg(ap, unsigned int), form);
	else if (form == '%')
		count = ft_putchar('%');
	else
		count = -1;
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
				return (0);
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

#include <stdio.h>

int main()
{
	
}
