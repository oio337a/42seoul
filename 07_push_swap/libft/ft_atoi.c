/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 00:43:10 by yoson             #+#    #+#             */
/*   Updated: 2022/10/11 18:35:33 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft.h"

static int	check_over_range(unsigned long long num, int sign)
{
	if (num > (unsigned long long)LONG_MAX + 1 && sign == -1)
		return (0);
	if (num > LONG_MAX && sign == 1)
		return (-1);
	return (num * sign);
}

int	ft_atoi(const char *str)
{
	int					sign;
	unsigned long long	num;
	int					i;

	sign = 1;
	num = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str == '0')
		str++;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9' && i < 19)
	{
		num *= 10;
		num += str[i] - '0';
		i++;
	}
	return (check_over_range(num, sign));
}
