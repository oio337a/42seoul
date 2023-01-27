/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 21:23:42 by suhwpark          #+#    #+#             */
/*   Updated: 2022/11/23 14:29:02 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*result;

	if (size && count > SIZE_MAX / size)
		return (0);
	result = malloc(count * size);
	if (!result)
		return (0);
	ft_memset(result, 0, count * size);
	return (result);
}
