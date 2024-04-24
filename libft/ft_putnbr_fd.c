/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:03:04 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/01/15 18:36:23 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	l_n;

	l_n = n;
	if (fd < 0)
		return ;
	if (l_n < 0)
	{
		write(fd, "-", 1);
		l_n *= -1;
	}
	if (l_n > 9)
		ft_putnbr_fd(l_n / 10, fd);
	ft_putchar_fd((l_n % 10) + '0', fd);
}
