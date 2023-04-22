/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyupar <sohyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 22:01:30 by yongmipa          #+#    #+#             */
/*   Updated: 2023/03/22 18:12:09 by sohyupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;

	if (!to_find[0])
		return ((char *) str);
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
			return ((char *) str + i - j);
		i -= j;
		i++;
	}
	return (NULL);
}
