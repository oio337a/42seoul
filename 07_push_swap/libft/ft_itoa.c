/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 20:04:52 by yoson             #+#    #+#             */
/*   Updated: 2022/10/25 19:58:50 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	find_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static long long	ft_abs(int n)
{
	long long	ret;

	ret = n;
	if (n < 0)
		ret *= -1;
	return (ret);
}

static char	*integer_to_ascii(char *ret, int n, int len)
{
	long long	abs;

	if (n == 0)
	{
		ret[0] = '0';
		ret[1] = '\0';
		return (ret);
	}
	abs = ft_abs(n);
	ret[len--] = '\0';
	while (abs)
	{
		ret[len--] = abs % 10 + '0';
		abs /= 10;
	}
	return (ret);
}

char	*ft_itoa(int n)
{
	char		*ret;
	int			len;

	len = find_len(n);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	ret = integer_to_ascii(ret, n, len);
	if (n < 0)
		ret[0] = '-';
	return (ret);
}
