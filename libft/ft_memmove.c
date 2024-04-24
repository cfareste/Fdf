/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:36:15 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/01/18 17:55:53 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*char_dst;
	const char	*char_src;

	i = 0;
	char_dst = dst;
	char_src = src;
	if (dst == src)
		return (dst);
	if (dst > src)
		while (len-- > i)
			char_dst[len] = char_src[len];
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
