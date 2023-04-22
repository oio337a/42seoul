/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyupar <sohyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 20:54:25 by yongmipa          #+#    #+#             */
/*   Updated: 2023/03/22 18:11:55 by sohyupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t	tmp_len;

	if (dest == src || len == 0)
		return (dest);
	if (dest > src)
	{
		dest = (unsigned char *)dest + len - 1;
		src = (unsigned char *)src + len - 1;
		while (len--)
			*(unsigned char *)dest-- = *(unsigned char *)src--;
		return (dest + 1);
	}
	else
	{
		tmp_len = len;
		while (len--)
			*(unsigned char *)dest++ = *(unsigned char *)src++;
		return (dest - tmp_len);
	}
}
