/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmipa <yongmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 20:54:25 by yongmipa          #+#    #+#             */
/*   Updated: 2022/07/17 21:47:31 by yongmipa         ###   ########seoul.kr  */
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
