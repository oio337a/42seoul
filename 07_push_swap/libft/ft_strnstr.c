/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 00:44:27 by yoson             #+#    #+#             */
/*   Updated: 2022/10/11 05:43:01 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;

	if (!to_find[0])
		return ((char *)str);
	i = 0;
	while (i < len && str[i])
	{
		j = 0;
		while (str[i] == to_find[j] && str[i] && i < len)
		{
			i++;
			j++;
		}
		if (!to_find[j])
			return ((char *)str + i - j);
		i -= j;
		i++;
	}
	return (NULL);
}
