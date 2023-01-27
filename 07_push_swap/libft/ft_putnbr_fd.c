/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:07:55 by suhwpark          #+#    #+#             */
/*   Updated: 2022/11/23 19:26:27 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_nbr(long long nbr, int fd)
{
	if (!nbr)
		return ;
	if (nbr > 9)
		print_nbr(nbr / 10, fd);
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
	print_nbr(nbr, fd);
}
