/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmipa <yongmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 22:46:19 by yongmipa          #+#    #+#             */
/*   Updated: 2022/07/31 15:00:28 by yongmipa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strdup(const char *src)
{
	char	*str;
	size_t	src_len;

	src_len = ft_strlen(src);
	str = (char *) malloc(src_len + 1);
	if (!str)
		return (NULL);
	while (*src)
		*str++ = *src++;
	*str = '\0';
	return (str - src_len);
}

char	*ft_strchr(const char *str, int c)
{
	while (*str != '\0')
	{
		if (*str == (char) c)
			return ((char *) str);
		str++;
	}
	if ((char) c == '\0')
		return ((char *) str);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	str_len;

	str_len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *) malloc(str_len + 1);
	if (!str)
		return (NULL);
	while (*s1 != '\0')
		*str++ = *s1++;
	while (*s2 != '\0')
		*str++ = *s2++;
	*str = '\0';
	return (str - str_len);
}

char	*ft_substr(char const *src, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (ft_strlen(src) <= start)
		return (ft_strdup(""));
	if (ft_strlen(src) < start + len)
		len = ft_strlen(src) - start;
	str = (char *) malloc(len + 1);
	if (!str)
		return (NULL);
	src += start;
	i = 0;
	while (src[i] && len--)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
