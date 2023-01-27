/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyupar <sohyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:52:14 by sohyupar          #+#    #+#             */
/*   Updated: 2023/01/20 15:07:00 by sohyupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
//
static int	check_range(long long num)
{
	if (num > 2147483647L || num < -2147483648L)
		exit(error());
	return (num);
}

static int	ft_whitespace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	ft_atoi2(const char *str)
{
	long long	num;
	int			sign;
	size_t		i;

	num = 0;
	sign = 1;
	i = -1;
	while (ft_whitespace(str[i]))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			sign *= -1;
		if (!ft_isdigit(*str))
			exit(error());
	}
	while (*str == '0')
		str++;
	while (str[++i] && i <= 10)
	{
		if (!ft_isdigit(str[i]))
			exit(error());
		num = num * 10 + str[i] - '0';
	}
	return (check_range(num * sign));
}
