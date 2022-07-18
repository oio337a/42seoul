/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmipa <yongmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 22:01:30 by yongmipa          #+#    #+#             */
/*   Updated: 2022/07/18 16:17:02 by yongmipa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

// char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
// {
// 	size_t	i;

// 	if (!needle[0])
// 		return ((char *)haystack);
// 	while (len-- && *haystack)
// 	{
// 		i = 0;
// 		while (*(haystack + i) == *(needle + i) && *haystack && i < len)
// 			i++;
// 		if (!*(needle + i))
// 			return ((char *)haystack);
// 		haystack++;
// 	}
// 	return (NULL);
// }

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;

	if (!to_find[0])
		return ((char *) str);
	i = 0;
	while (i < len && str[i])
	{
		j = 0;
		while (str[i] == to_find[j] && str[i] && i < len)
		{
			i++;
			j++;
		}
		if (!to_find[j])
			return ((char *) str + i - j);
		i -= j;
		i++;
	}
	return (NULL);
}