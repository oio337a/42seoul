/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:12:04 by suhwpark          #+#    #+#             */
/*   Updated: 2023/01/11 19:30:10 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_word(char word, char c)
{
	if (word == c)
		return (0);
	else
		return (1);
}

static size_t	get_size(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if (is_word(*s, c))
		{
			count++;
			while (*s && is_word(*s, c))
				s++;
		}
		else
			s++;
	}
	return (count);
}

static char	**all_free(char **res)
{
	size_t	i;

	i = 0;
	while (res[i])
		free(res[i++]);
	free(res);
	return (0);
}

char	**ft_split(const char *s, char c)
{
	char		**res;
	const char	*tmp;
	size_t		i;

	i = 0;
	res = (char **)malloc(sizeof(char *) * (get_size(s, c) + 1));
	if (!res)
		return (0);
	while (*s)
	{
		if (is_word(*s, c))
		{
			tmp = s;
			while (*s && is_word(*s, c))
				s++;
			res[i] = (char *)malloc(sizeof(char) * (s - tmp + 1));
			if (!res[i])
				return (all_free(res));
			ft_strlcpy(res[i++], tmp, (s - tmp + 1));
		}
		else
			s++;
	}
	res[i] = 0;
	return (res);
}
