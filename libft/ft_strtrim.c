/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 13:35:55 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/01/17 23:12:51 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int static	check_c_in_set(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
		if (c == set[i++])
			return (1);
	return (0);
}

int static	calculate_start_idx(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && check_c_in_set(set, s1[i]))
		i++;
	return (i);
}

int static	calculate_end_idx(char const *s1, char const *set)
{
	size_t	i;

	i = ft_strlen(s1);
	while (i-- >= 0)
		if (!check_c_in_set(set, s1[i]))
			break ;
	return ((int) i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		start;
	int		end;

	if (!s1)
		return (0);
	if (!set || !*s1)
		return (ft_strdup(s1));
	i = 0;
	start = calculate_start_idx(s1, set);
	end = calculate_end_idx(s1, set);
	if (start > end)
		return (ft_strdup(""));
	return (ft_substr(s1, start, end - start + 1));
}
