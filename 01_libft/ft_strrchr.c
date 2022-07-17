/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmipa <yongmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 17:45:22 by yongmipa          #+#    #+#             */
/*   Updated: 2022/07/17 22:01:15 by yongmipa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s) - 1;
	if (i == -1 && c == 0)
		return ((char *)s);
	else if (c == 0)
		return ((char *)s + i + 1);
	else if (i == -1)
		return (NULL);
	while (i + 1)
	{		
		if (s[i] == c)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}
