/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:25:38 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/01/17 12:34:17 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;

	i = 0;
	while (i < n && s1[i] != '\0' && s2[i] != '\0')
	{
		if ((unsigned char) s1[i] > (unsigned char) s2[i])
			return (1);
		else if ((unsigned char) s1[i] < (unsigned char) s2[i])
			return (-1);
		i++;
	}
	if (i != n && (unsigned char) s1[i] > (unsigned char) s2[i])
		return (1);
	else if (i != n && (unsigned char) s1[i] < (unsigned char) s2[i])
		return (-1);
	return (0);
}
