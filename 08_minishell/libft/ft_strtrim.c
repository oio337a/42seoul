/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyupar <sohyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 18:04:10 by yongmipa          #+#    #+#             */
/*   Updated: 2023/03/22 18:12:10 by sohyupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char *s1, char c)
{
	size_t	s;
	size_t	e;

	s = 0;
	e = ft_strlen(s1) - 1;
	while (s1[s] != '\0' && s1[s] == c)
		s++;
	if (s >= (e + 1))
		return ((char *)ft_calloc(1, 1));
	while (s1[e] == c)
		e--;
	free(s1);
	return (ft_substr(s1, s, (e - s + 1)));
}
