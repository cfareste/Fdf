/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:27:23 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/01/17 22:18:11 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*char_dst;
	unsigned const char	*char_src;

	i = 0;
	if (!dst && !src)
		return (0);
	char_dst = dst;
	char_src = src;
	while (i < n)
	{
		char_dst[i] = char_src[i];
		i++;
	}
	return (dst);
}
