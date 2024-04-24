/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:00:06 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/01/17 19:08:05 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dst_lght;
	size_t	src_lght;

	i = 0;
	dst_lght = ft_strlen(dst);
	src_lght = ft_strlen(src);
	dst += dst_lght;
	if (!dstsize || dstsize <= dst_lght)
		return (src_lght + dstsize);
	while (src[i] != '\0' && i < dstsize - dst_lght - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst_lght + src_lght);
}
