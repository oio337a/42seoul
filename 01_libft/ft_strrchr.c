/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmipa <yongmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 17:45:22 by yongmipa          #+#    #+#             */
/*   Updated: 2022/07/08 19:23:26 by yongmipa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*temp;

	temp = (char *)s;
	i = ft_strlen(temp) - 1;
	if (i == -1 && c == 0)
		return (temp);
	else if (c == 0)
		return (temp + i + 2);
	else if (i == -1)
		return (NULL);
	while (s[i])
	{		
		if (s[i] == c)
			return (temp + i);
		i--;
	}
	return (NULL);
}
