/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:38:56 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/01/15 18:36:51 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	char	*newstr;
	size_t	length;
	size_t	i;

	i = 0;
	if (!s || !f)
		return (0);
	length = ft_strlen(s);
	newstr = malloc((length + 1) * sizeof(char));
	if (!newstr)
		return (0);
	while (i < length)
	{
		newstr[i] = f(i, s[i]);
		i++;
	}
	newstr[i] = 0;
	return (newstr);
}
