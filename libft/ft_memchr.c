/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:54:15 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/01/18 18:04:10 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	chr;
	size_t			i;

	chr = c;
	i = 0;
	while (i < n)
	{
		if (chr == ((unsigned char *) s)[i])
			return (&((unsigned char *) s)[i]);
		i++;
	}
	return (0);
}
