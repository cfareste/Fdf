/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:09:17 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/01/11 19:13:37 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_match(const char *haystack, const char *needle)
{
	int	i;

	i = 0;
	while (haystack[i] != '\0' && needle[i] != '\0')
	{
		if (haystack[i] != needle[i])
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	char	*hs_ptr;

	i = 0;
	hs_ptr = 0;
	if (ft_strlen(needle) == 0)
		return ((char *) haystack);
	if (ft_strlen(needle) > ft_strlen(haystack))
		return (0);
	while (haystack[i] != '\0')
	{
		if (i == len || len - i < ft_strlen(needle))
			return (0);
		if (check_match(haystack + i, needle))
		{
			hs_ptr = (char *) haystack + i;
			break ;
		}
		i++;
	}
	return (hs_ptr);
}
