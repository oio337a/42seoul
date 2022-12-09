/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmipa <yongmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 18:04:10 by yongmipa          #+#    #+#             */
/*   Updated: 2022/07/18 22:12:14 by yongmipa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	s;
	size_t	e;

	s = 0;
	e = ft_strlen(s1) - 1;
	while (s1[s] != '\0' && ft_strchr(set, s1[s]))
		s++;
	if (s >= (e + 1))
		return ((char *)ft_calloc(1, sizeof(char)));
	while (ft_strchr(set, s1[e]))
		e--;
	return (ft_substr(s1, s, (e - s + 1)));
}
