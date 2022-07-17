/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmipa <yongmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 18:04:10 by yongmipa          #+#    #+#             */
/*   Updated: 2022/07/17 19:01:50 by yongmipa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	is_here(char **s1, char *set, int sign)
{
	while (**s1)
	{
		if (ft_strchr(set, **s1))
			*s1 += sign;
		else
			return ;
	}
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	char	*s_s1;
	char	*e_s1;
	size_t	len;

	if (!*set)
		return (ft_strdup(s1));
	if (!s1)
		return (NULL);
	s_s1 = (char *)s1;
	e_s1 = (char *)s1 + ft_strlen(s1) - 1;
	is_here(&s_s1, (char *)set, 1);
	if (!*s_s1)
		return (ft_strdup(""));
	is_here(&e_s1, (char *)set, -1);
	len = ft_strlen(s_s1) - ft_strlen(e_s1) + 2;
	str = (char *)malloc(len);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s_s1, len);
	return (str);
}
