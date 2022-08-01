/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmipa <yongmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 16:58:27 by yongmipa          #+#    #+#             */
/*   Updated: 2022/07/31 18:21:20 by yongmipa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char str)
{
	return (write(1, &str, 1));
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			ft_putchar(str[i]);
			i++;
		}
		return (i);
	}
	write(1, "(null)", 6);
	return (6);
}

static int	ft_nbrrec(long c, int count)
{
	if (c >= 10)
	{
		count = ft_nbrrec(c / 10, ++count);
		c = c % 10;
	}
	ft_putchar(c + '0');
	return (count);
}

int	ft_putnbr(int n)
{
	long	num;
	int		count;

	num = n;
	count = 1;
	if (n < 0)
	{
		write(1, "-", 1);
		num = num * (-1);
		++count;
	}
	return (ft_nbrrec(num, count));
}

int	ft_unsignednbr(unsigned int nbr)
{
	return (ft_nbrrec(nbr, 1));
}
