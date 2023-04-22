/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyupar <sohyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 20:19:10 by yongmipa          #+#    #+#             */
/*   Updated: 2023/03/22 18:12:02 by sohyupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	arr_size(const char *s, char c)
{
	size_t	num;

	num = 0;
	while (*s)
	{
		if (*s != c)
		{
			while (*s && *s != c)
				s++;
			num++;
		}
		else
			s++;
	}
	return (num);
}

static size_t	alloc_size(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static void	*free_answer(char **answer, size_t index)
{
	size_t	i;

	i = 0;
	while (i < index)
	{
		free(answer[i]);
		i++;
	}
	free(answer);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**answer;
	size_t	arr_cnt;
	size_t	alloc_cnt;
	size_t	index;

	index = 0;
	arr_cnt = arr_size(s, c);
	answer = (char **)malloc(sizeof(char *) * (arr_cnt + 1));
	if (!answer)
		return (NULL);
	while (arr_cnt--)
	{
		while (*s && *s == c)
			s++;
		alloc_cnt = alloc_size(s, c) + 1;
		answer[index] = (char *)malloc(alloc_cnt);
		if (!answer[index])
			return (free_answer(answer, index));
		ft_strlcpy(answer[index++], s, alloc_cnt);
		s = ft_strchr(s, c);
	}
	answer[index] = NULL;
	return (answer);
}
