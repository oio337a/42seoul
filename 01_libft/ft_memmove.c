/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmipa <yongmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 20:54:25 by yongmipa          #+#    #+#             */
/*   Updated: 2022/07/08 21:18:38 by yongmipa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char	*temp;

	temp = (char *)dest;
	if (!dest && !src)
		return (NULL);
	if (dest > src && src + len > dest)
	{
		temp += len;
		src += len;
		while (len--)
			*--temp = *(char *)--src;
	}
	else
		while (len--)
			*temp = *(char *)src++;
	return (dest);
}
