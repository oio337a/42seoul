/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_safe_malloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyupar <sohyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:11:16 by suhwpark          #+#    #+#             */
/*   Updated: 2023/03/22 18:12:02 by sohyupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_safe_malloc(size_t	size)
{
	void	*ret;

	ret = malloc(size);
	if (!ret)
	{
		ft_putendl_fd("malloc failed", 2);
		exit(EXIT_FAILURE);
	}
	return (ret);
}
