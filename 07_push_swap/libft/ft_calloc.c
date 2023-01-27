/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 16:03:38 by yoson             #+#    #+#             */
/*   Updated: 2022/10/12 12:41:27 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdint.h>
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ret;

	if (size && count > SIZE_MAX / size)
		return (NULL);
	ret = malloc(count * size);
	if (!ret)
		return (NULL);
	return (ft_memset(ret, 0, count * size));
}
