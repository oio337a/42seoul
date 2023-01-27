/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:59:01 by suhwpark          #+#    #+#             */
/*   Updated: 2022/12/04 16:09:51 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *src, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;

	i = 0;
	if (!len || ft_strlen(src) <= start)
		return (ft_strdup(""));
	if (ft_strlen(src) < start + len)
		len = ft_strlen(src) - start + 1;
	res = (char *)malloc(len + 1);
	if (!res)
		return (0);
	src = src + start;
	while (i < len && src[i])
	{
		res[i] = src[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
