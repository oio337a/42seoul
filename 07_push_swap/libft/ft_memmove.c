/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:59:10 by suhwpark          #+#    #+#             */
/*   Updated: 2022/11/23 19:09:50 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*tmp_dest;
	unsigned char	*tmp_src;

	tmp_dest = (unsigned char *)dest;
	tmp_src = (unsigned char *)src;
	i = 0;
	if (dest == src || !len)
		return (dest);
	if (dest < src)
	{
		while (len--)
			*(tmp_dest++) = *(tmp_src++);
	}
	else
	{
		while (len--)
			*(tmp_dest + len) = *(tmp_src + len);
	}
	return (dest);
}
