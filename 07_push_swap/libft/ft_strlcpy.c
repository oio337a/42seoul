/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 19:44:57 by yoson             #+#    #+#             */
/*   Updated: 2022/10/11 04:35:39 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	src_len;

	src_len = ft_strlen(src);
	if (!n)
		return (src_len);
	while (*src && n - 1)
	{
		*dest++ = *src++;
		n--;
	}
	*dest = '\0';
	return (src_len);
}
