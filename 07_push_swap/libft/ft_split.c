/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 15:15:57 by yoson             #+#    #+#             */
/*   Updated: 2022/10/11 19:12:19 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	is_word(char c, char sep)
{
	if (c == sep)
		return (0);
	else
		return (1);
}

static size_t	find_size(const char *str, char sep)
{
	size_t	size;

	size = 0;
	while (*str)
	{
		if (is_word(*str, sep))
		{
			size++;
			while (*str != '\0' && is_word(*str, sep))
				str++;
		}
		else
			str++;
	}
	return (size);
}

static char	**free_all(char **str_arr)
{
	size_t	i;

	i = 0;
	while (str_arr[i])
		free(str_arr[i++]);
	free(str_arr);
	return (NULL);
}

static char	**split(char **str_arr, char const *str, char sep)
{
	const char	*tmp;	
	size_t		i;

	i = 0;
	while (*str)
	{
		if (is_word(*str, sep))
		{
			tmp = str;
			while (*str && is_word(*str, sep))
				str++;
			str_arr[i] = (char *)malloc(sizeof(char) * (str - tmp + 1));
			if (!str_arr[i])
				return (free_all(str_arr));
			ft_strlcpy(str_arr[i++], tmp, str - tmp + 1);
		}
		else
			str++;
	}
	str_arr[i] = NULL;
	return (str_arr);
}

char	**ft_split(char const *str, char sep)
{
	char		**ret;

	ret = (char **)malloc(sizeof(char *) * (find_size(str, sep) + 1));
	if (!ret)
		return (NULL);
	ret = split(ret, str, sep);
	return (ret);
}
