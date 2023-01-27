/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 00:45:33 by yoson             #+#    #+#             */
/*   Updated: 2022/07/12 21:46:57 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

static void	put_nbr(long long nbr, int fd)
{
	if (!nbr)
		return ;
	put_nbr(nbr / 10, fd);
	write(fd, &"0123456789"[nbr % 10], 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long long	nbr;

	if (!n)
	{
		write(fd, "0", 1);
		return ;
	}
	nbr = n;
	if (n < 0)
	{
		nbr *= -1;
		write(fd, "-", 1);
	}
	put_nbr(nbr, fd);
}
