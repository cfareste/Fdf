/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:39:59 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/01/18 18:01:44 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		str_lght;
	char	chr;

	chr = c;
	str_lght = (int) ft_strlen(s);
	while (str_lght >= 0)
	{
		if (chr == s[str_lght])
			return ((char *) &s[str_lght]);
		str_lght--;
	}
	return (0);
}
