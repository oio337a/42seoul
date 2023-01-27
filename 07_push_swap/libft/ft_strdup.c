/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 21:27:52 by suhwpark          #+#    #+#             */
/*   Updated: 2022/11/23 19:15:53 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*result;
	char	*tmp_str;

	tmp_str = (char *)str;
	result = (char *)malloc(ft_strlen(str) + 1);
	if (!result)
		return (0);
	while (*tmp_str)
		*result++ = *tmp_str++;
	*result = '\0';
	return (result - ft_strlen(str));
}
