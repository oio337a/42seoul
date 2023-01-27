/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:36:18 by yoson             #+#    #+#             */
/*   Updated: 2022/10/11 05:41:21 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{	
	unsigned char	*dest_tmp;
	unsigned char	*src_tmp;

	if (dest == src)
		return (dest);
	dest_tmp = (unsigned char *)dest;
	src_tmp = (unsigned char *)src;
	while (n--)
		*dest_tmp++ = *src_tmp++;
	return (dest);
}
