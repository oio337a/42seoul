/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmipa <yongmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 17:45:22 by yongmipa          #+#    #+#             */
/*   Updated: 2022/07/18 17:32:03 by yongmipa         ###   ########seoul.kr  */
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
