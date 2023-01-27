/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 20:56:18 by yoson             #+#    #+#             */
/*   Updated: 2022/10/11 05:43:09 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*str_rear;

	str_rear = (char *)str + ft_strlen(str);
	while (str <= str_rear)
	{
		if (*str_rear == (char)c)
			return (str_rear);
		str_rear--;
	}
	return (NULL);
}
