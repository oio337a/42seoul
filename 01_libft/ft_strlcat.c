/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmipa <yongmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:57:13 by yongmipa          #+#    #+#             */
/*   Updated: 2022/07/07 15:09:12 by yongmipa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h";

size_t	strlcat(char *dest, const char *src, size_t size)
{
	size_t		result;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	result = 0;
	while (dest[i])
		i++;
	while (src[result])
		result++;
	if (size <= i)
		result += size;
	else
		result += i;
	while (src[j] && (i + 1) < size)
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (result);
}
