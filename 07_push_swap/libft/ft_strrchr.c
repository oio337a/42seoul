/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:34:43 by suhwpark          #+#    #+#             */
/*   Updated: 2022/11/23 19:17:59 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*str_end;

	str_end = (char *)str + ft_strlen(str);
	while (str <= str_end)
	{
		if (*str_end == (char)c)
			return (str_end);
		str_end--;
	}
	return (0);
}
