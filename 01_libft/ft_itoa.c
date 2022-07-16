/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmipa <yongmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 21:26:46 by yongmipa          #+#    #+#             */
/*   Updated: 2022/07/09 22:20:38 by yongmipa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_len(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (++len);
	else if (n < 0)
		len++;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static char	*change(char *new_str, long long n)
{
	if (n / 10)
		new_str = change(new_str, n / 10);
	*new_str = (char)(n % 10) + '0';
	return (++new_str);
}

char	*ft_itoa(int n)
{
	char		*new_str;
	int			len;
	long long	nb;

	len = get_len(n);
	new_str = malloc(len + 1);
	if (!new_str)
		return (0);
	if (n < 0)
	{
		*new_str = '-';
		nb = -n;
		change(new_str, nb);
	}
	else
		change(new_str, n);
	new_str[len] = '\0';
	return (new_str);
}
