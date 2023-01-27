/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:09:21 by suhwpark          #+#    #+#             */
/*   Updated: 2022/11/23 19:25:33 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_len(long long nb)
{
	int	len;

	len = 0;
	if (nb < 0)
	{
		len++;
		nb *= -1;
	}
	while (nb > 0)
	{
		len++;
		nb /= 10;
	}
	return (len);
}

static char	*zero(void)
{
	char	*res;

	res = (char *)malloc(2);
	res[0] = '0';
	res[1] = '\0';
	return (res);
}

char	*ft_itoa(int n)
{
	int			num_len;
	char		*res;
	long long	nb;

	nb = (long long)n;
	num_len = get_len(nb);
	if (nb == 0)
		return (zero());
	res = (char *)malloc(sizeof(char) * num_len + 1);
	if (!res)
		return (NULL);
	res[num_len--] = '\0';
	if (nb < 0)
	{
		res[0] = '-';
		nb *= -1;
	}
	while (nb > 0)
	{
		res[num_len] = (nb % 10) + '0';
		num_len--;
		nb /= 10;
	}
	return (res);
}
